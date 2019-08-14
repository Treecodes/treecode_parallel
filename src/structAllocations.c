#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <mpi.h>
#include <string.h>

#include "array.h"
#include "tools.h"
#include "particles.h"
#include "sort.h"
#include "tnode.h"
#include "batch.h"



void reallocate_sources(struct particles *sources, int newlength){

	sources->num = newlength;
	realloc_vector(sources->x, newlength);
	realloc_vector(sources->y, newlength);
	realloc_vector(sources->z, newlength);
	realloc_vector(sources->q, newlength);
	realloc_vector(sources->w, newlength);

	return;

}  /* END of function reallocate_sources */

void allocate_sources(struct particles *sources, int length)  {

	sources->num = length;
	make_vector(sources->x, length);
	make_vector(sources->y, length);
	make_vector(sources->z, length);
	make_vector(sources->q, length);
	make_vector(sources->w, length);

    return;
}   /* END of function allocate_sources */


void allocate_cluster(struct particles *clusters, int length)  {

    make_vector(clusters->x, length);
    make_vector(clusters->y, length);
    make_vector(clusters->z, length);
    make_vector(clusters->q, length);
    make_vector(clusters->w, length);  // will be used in singularity subtraction
    clusters->num=length;

    return;
}   /* END of function allocate_cluster */


void reallocate_cluster(struct particles *clusters, int newlength)  {

	realloc_vector(clusters->x, newlength);
	realloc_vector(clusters->y, newlength);
	realloc_vector(clusters->z, newlength);
	realloc_vector(clusters->q, newlength);
	realloc_vector(clusters->w, newlength);  // will be used in singularity subtraction
    clusters->num=newlength;

    return;
}   /* END of function reallocate_cluster */

void allocate_tree_array(struct tnode_array *let_tree_array, int length)  {

	let_tree_array->numnodes = length;
	make_vector(let_tree_array->ibeg, length);
	make_vector(let_tree_array->iend, length);
	make_vector(let_tree_array->numpar, length);
	make_vector(let_tree_array->x_mid, length);
	make_vector(let_tree_array->y_mid, length);
	make_vector(let_tree_array->z_mid, length);
	make_vector(let_tree_array->x_min, length);
	make_vector(let_tree_array->y_min, length);
	make_vector(let_tree_array->z_min, length);
	make_vector(let_tree_array->x_max, length);
	make_vector(let_tree_array->y_max, length);
	make_vector(let_tree_array->z_max, length);
	make_vector(let_tree_array->level, length);
	make_vector(let_tree_array->cluster_ind, length);
	make_vector(let_tree_array->radius, length);

    return;
}   /* END of function allocate_tree_array */

void free_tree_array(struct tnode_array *let_tree_array)  {

	free_vector(let_tree_array->ibeg);
	free_vector(let_tree_array->iend);
	free_vector(let_tree_array->numpar);
	free_vector(let_tree_array->x_mid);
	free_vector(let_tree_array->y_mid);
	free_vector(let_tree_array->z_mid);
	free_vector(let_tree_array->x_min);
	free_vector(let_tree_array->y_min);
	free_vector(let_tree_array->z_min);
	free_vector(let_tree_array->x_max);
	free_vector(let_tree_array->y_max);
	free_vector(let_tree_array->z_max);
	free_vector(let_tree_array->level);
	free_vector(let_tree_array->cluster_ind);
	free_vector(let_tree_array->radius);
	let_tree_array=NULL;

    return;
}   /* END of function allocate_tree_array */


void reallocate_tree_array(struct tnode_array *let_tree_array, int newlength)  {

	let_tree_array->numnodes = newlength;
	realloc_vector(let_tree_array->ibeg, newlength);
	realloc_vector(let_tree_array->iend, newlength);
	realloc_vector(let_tree_array->numpar, newlength);
	realloc_vector(let_tree_array->x_mid, newlength);
	realloc_vector(let_tree_array->y_mid, newlength);
	realloc_vector(let_tree_array->z_mid, newlength);
	realloc_vector(let_tree_array->x_min, newlength);
	realloc_vector(let_tree_array->y_min, newlength);
	realloc_vector(let_tree_array->z_min, newlength);
	realloc_vector(let_tree_array->x_max, newlength);
	realloc_vector(let_tree_array->y_max, newlength);
	realloc_vector(let_tree_array->z_max, newlength);
	realloc_vector(let_tree_array->level, newlength);
	realloc_vector(let_tree_array->cluster_ind, newlength);
	realloc_vector(let_tree_array->radius, newlength);

	return;

}   /* END of function allocate_tree_array */
