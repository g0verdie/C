#ifndef _FEVtypes_h
#define _FEVtypes_h

#include "matrix/matrix_types.h"


/*********************FEV ***************/

#define FACE 10
#define EDGE 11
#define VERTEX 12
#define MATRIX 13



/* in this minimalist representation, things like the
vector direction of edges and the vector normals to faces would need
to be computed from the relevant points.  IF we were
going to do anything real with this graphics representation
we'd want to have fields for
these vectors in the individual structs. */
 

typedef struct vertex {
    int fev_type;
     int serial;
	matrix_t vertex_coords;
     //double x, y, z;
	} *vertex_t;


typedef struct edge {
    int fev_type;
     int serial;
	vertex_t from_vertex;
	vertex_t to_vertex;
   struct edge *next_edge;  /* for edge list */
   	} *edge_t;




typedef struct face {
    int fev_type;
    int serial;
    edge_t next_edge;        /* my edges */
    struct face *next_face;  /* for face list*/
} *face_t;

/* printable structs */

typedef struct p_vertex {   /*already that way! */
    int fev_type;
     int serial;
	//matrix_t vertex_coords;
     double x, y, z;
	} *p_vertex_t;


typedef struct p_edge {
    int fev_type;
     int serial;
	int from_vertex_index;
	int to_vertex_index;
   int next_edge_index;  /* for edge list */
   	} *p_edge_t;



typedef struct p_face {
    int fev_type;
    int serial;
    int next_edge_index;        /* my edges */
    int next_face_index;  /* for face list*/
} *p_face_t;

#endif

