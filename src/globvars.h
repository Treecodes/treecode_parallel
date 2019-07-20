#ifndef H_GLOBALVARS_H
#define H_GLOBALVARS_H

/* declaration of external global variables */
extern int torder, torderlim, torderflat;
extern double *cf, *cf1, *cf2, *cf3;
extern double ***a1, ***b1;

extern int minlevel, maxlevel;
extern int maxpars, minpars;
extern int numleaves;

extern double tarpos[3];
extern double thetasq, tarposq;

extern int *orderarr;

extern double dglobx, dgloby, dglobz;
extern int xglobdim, yglobdim, zglobdim;

extern int numnodes;

extern double *tt, *ww;

extern double *unscaledQuadratureWeights;

#endif /* H_GLOBALVARS_H */
