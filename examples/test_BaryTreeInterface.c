#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#include "../src/interface/BaryTreeInterface.h"

int main(int argc, char **argv)
{
    int rank, numProcs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcs);

    int numSources = 20000;
    int numTargets = 20000;

    KERNEL kernel                = YUKAWA;
    SINGULARITY singularity      = SKIPPING;
    APPROXIMATION approximation  = LAGRANGE;
    COMPUTE_TYPE compute_type    = PARTICLE_CLUSTER;

    BOUNDARY_CONDITION boundary_type_x = NON_PERIODIC;
    BOUNDARY_CONDITION boundary_type_y = NON_PERIODIC;
    BOUNDARY_CONDITION boundary_type_z = NON_PERIODIC;

    double boundary_length_x=2.0;
    double boundary_length_y=2.0;
    double boundary_length_z=2.0;


    int numParams = 1;
    double kernelParams[1] = {0.5};

    int interpOrder = 5;
    double theta = 0.8;

    int maxPerLeaf = 500;
    int maxPerBatch = 500;
    double sizeCheck = 1.0;

    int verbosity = 0;

    double *xS = malloc(numSources * sizeof(double));
    double *yS = malloc(numSources * sizeof(double));
    double *zS = malloc(numSources * sizeof(double));
    double *qS = malloc(numSources * sizeof(double));
    double *wS = malloc(numSources * sizeof(double));

    double *xT = malloc(numTargets * sizeof(double));
    double *yT = malloc(numTargets * sizeof(double));
    double *zT = malloc(numTargets * sizeof(double));
    double *qT = malloc(numTargets * sizeof(double));

    double *potential = malloc(numTargets * sizeof(double));

    for (int i = 0; i < numSources; ++i) {
        xS[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        yS[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        zS[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        qS[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        wS[i] =  1.;
    }

    for (int i = 0; i < numTargets; ++i) {
        xT[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        yT[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        zT[i] =  ((double)rand()/(double)(RAND_MAX)) * 2. - 1.;
        qT[i] =  1.;
    }

    BaryTreeInterface(numTargets, numSources, xT, yT, zT, qT,
                      xS, yS, zS, qS, wS, potential,
                      kernel, numParams, kernelParams,
                      singularity, approximation, compute_type,
                      boundary_type_x, boundary_type_y, boundary_type_z,
                      boundary_length_x, boundary_length_y, boundary_length_z,
                      interpOrder, theta, maxPerLeaf, maxPerBatch,
                      sizeCheck, verbosity);

    printf("[test BaryTree interface] BaryTree has finished.\n");

    free(xS);
    free(yS);
    free(zS);
    free(qS);
    free(wS);
    free(xT);
    free(yT);
    free(zT);
    free(qT);
    free(potential);

    MPI_Finalize();

    return 0;
}
