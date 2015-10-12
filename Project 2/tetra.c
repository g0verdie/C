#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "FEVtypes.h"
#include "FEV.h"

face_t new_tetrahedron()

{
edge_t edges[3];
vertex_t tv0, tv1, tv2, tv3;
 face_t tf012, tf132, tf023, tf031;
 face_t tetrahedron;

/* note tv0 = new_vert(0, 0, 0, "v0"); won't work -- ints! yikes */


/* The nice thing about string names is you can represent the topology (like
   name an e01 if it goes from v. 0 to v. 1 and e20 if it goes from 2 to 0.) hmmm */


tv0 = new_vert(0.0, 0.0, 0.0,0);
tv1 = new_vert(2.0, 2.0, 0.0,1);
tv2 = new_vert(2.0, 0.0, 2.0,2);
tv3 = new_vert(0.0, 2.0, 2.0,3);

edges[0] = new_edge(tv0, tv1,0);
edges[1] = new_edge(tv1, tv2, 1);
edges[2] = new_edge(tv2, tv0, 2);

tf012 = new_face(edges, 3, 0);

edges[0] = new_edge(tv1, tv3, 3);
edges[1] = new_edge(tv3, tv2, 4);
edges[2] = new_edge(tv2, tv1,5);


tf132 = new_face(edges, 3, 1);


edges[0] = new_edge(tv0, tv2,6);
edges[1] = new_edge(tv2, tv3, 7);
edges[2] = new_edge(tv3, tv0, 8);

tf023 = new_face(edges, 3, 2);

edges[0] = new_edge(tv0, tv3,9);
edges[1] = new_edge(tv3, tv1, 10);
edges[2] = new_edge(tv1, tv0, 11);

tf031 = new_face(edges, 3, 3);



/* 
   debugging 

short_face_pr(tf012);
printf("\n");
short_face_pr(tf132);
printf("\n");

short_face_pr(tf023);
printf("\n");
short_face_pr(tf031);
printf("\n");

*/




 tetrahedron = tf012;
 tf012->next_face = tf132;
 tf132->next_face = tf023;
 tf023->next_face = tf031;
 tf031->next_face = tf012;

return(tetrahedron);

}


