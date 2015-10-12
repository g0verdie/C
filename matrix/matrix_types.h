#ifndef _matrixtypes_h
#define _matrixtypes_h



/*********************general matrix types ***************/
typedef double *dvec;
typedef int *ivec;
typedef double **dmat;

typedef struct matrix {
    int fev_type;  /*mysterious for now, wait a week!*/
	int r;
	int c;
	dmat mat;
	} *matrix_t;

#endif

