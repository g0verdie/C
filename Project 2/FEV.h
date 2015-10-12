
#ifndef _FEV_h
#define _FEV_h


/*
extern dvec dvector();
extern void dvec_free();
extern matrix_t mat_mpy();
extern matrix_t mat_new();
extern int dvec_pr();
extern int mat_pr();
extern void mat_free();
extern void cberr();
*/


/***************external FEV**************/

extern vertex_t new_vert();		//I added a few functions here somewhere...
extern edge_t new_edge();
extern face_t new_face();
extern face_t new_tetrahedron();
extern int vert_pr(); 
extern int edge_pr(); 
extern int face_pr(); 
extern int short_vert_pr(); 
extern int short_edge_pr(); 
extern int short_face_pr(); 
extern int short_poly_pr(); 
extern face_t read_face();
extern edge_t read_edge();
extern face_t next_face();
extern edge_t next_edge();
extern vertex_t read_vertex();
extern void face_to_file();
extern void face_to_file_internal();
extern void edge_to_file();
//extern void edge_to_file_internal();
extern void vertex_to_file();
extern void pr_vert();
extern void pr_edge();
extern void pr_face();
extern edge_ring_pr();

extern vertex_t read_make_vertex();
extern face_t file_make_structs();
 extern edge_t read_make_edge();
extern  face_t read_make_face();

extern  void p_face_to_file();
extern  void p_edge_to_file();

extern  void p_vert_to_file();

extern  face_t fake_face();
extern  void face_to_file();

extern   face_t new_tetrahedron();


#endif
