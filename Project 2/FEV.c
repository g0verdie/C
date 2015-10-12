#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "matrix/matrix_types.h"
#include "matrix/matrix.h"
#include "FEVtypes.h"
#include "FEV.h"



vertex_t new_vert(double x, double y, double z, int serial_no)
{
    vertex_t newvert;

         newvert = (vertex_t) malloc( sizeof(struct vertex));
	 newvert->fev_type = VERTEX;
         newvert->serial = serial_no;
         newvert->vertex_coords = mat_new(3,1);
	 e(newvert->vertex_coords,0,0) = x;
	 e(newvert->vertex_coords,1,0) = y;
	 e(newvert->vertex_coords,2,0) = z;
return(newvert);
}



edge_t new_edge( vertex_t efrom, vertex_t eto, int serial_no)
{
    edge_t newedge;
    
    printf("\n into new-edge\n");
    vert_pr("efrom", efrom);
    vert_pr("eto", eto);
      
         newedge = (edge_t) malloc( sizeof(struct edge));
	 newedge->fev_type = EDGE;
         newedge->serial = serial_no;
         newedge->from_vertex = efrom;
         newedge -> next_edge = NULL;  /* for face circular edge list*/
         newedge->to_vertex = eto;
	 return(newedge);
}

face_t new_face (edge_t edges[], int n, int serial_no)  /* a little klunky, could use list*/
{
    face_t newface;
    int i;


         newface = (face_t) malloc( sizeof(struct face));
         newface->fev_type = FACE;
         newface->serial = serial_no;
	 newface->next_edge = edges[0];  /* we're copying a pointer */
	 /*	 printf("\n set face nextedge to %s", edges[0]->name);*/

	 for (i =0; i<(n-1); i++)
	     { edges[i]->next_edge = edges[i+1];
		 /* printf("\n set edge %d nextedge to %s", i, edges[i+1]->name);*/
              }
         edges[n-1]->next_edge = edges[0];
	 newface->next_face = NULL;  /*filled in at higher level*/
 return(newface);
}


 
int  vert_pr(char *msg, vertex_t v)
  {
  if (msg == NULL) { cberror("null message arg in vert_pr"); return NILARG1;}
  if (v == NULL) { cberror("null vertex arg in vert_pr"); return NILARG2;}
  
  printf("\nVERTEX:  %s  Type: %d , Serial: %d\n", msg, v->fev_type, v->serial);
  
  mat_pr("Vertex Coords", v->vertex_coords);
  printf("\n");
  return OK;
  }



int  edge_pr(char *msg, edge_t edg)
      {
  if (msg == NULL) { cberror("null message arg in edge_pr"); return NILARG1;}
  if (edg == NULL) { cberror("null edge arg in edge_pr"); return NILARG2;}	  
  printf("\nEDGE:  %s  Type: %d, Serial: %d\n", msg, edg->fev_type,edg->serial);
  vert_pr("From Vertex ", edg->from_vertex);
  vert_pr("To Vertex ", edg->to_vertex);
  if (edg->next_edge == NULL) printf("Empty Next Edge.");
  else printf("Next Edge Exists.");  /* don't go recursive yet! */
  printf("\n");
  return OK;
  }




int face_pr(char *msg, face_t f)
    {
  if (msg == NULL) { cberror("null message arg in face_pr"); return NILARG1;}
  if (f == NULL) { cberror("null face arg in face_pr"); return NILARG2;}	  
  printf("\nFACE:  %s  Type: %d, Serial: %d \n", msg, f->fev_type, f->serial);
  if (f->next_edge == NULL) printf("Empty Next Edge.");
  else printf("Next Edge Exists.");  /* don't go recursive yet! */
  printf("\n");
  return OK;
  }



int short_vert_pr (vertex_t v)
{    printf("\n     %d", v->serial);
  return OK;
}

int short_edge_pr (edge_t edg)
{
    printf("\nShortEdgePr ser, from, to:   %d", edg->serial);
    short_vert_pr (edg->from_vertex);
    short_vert_pr (edg->to_vertex);

  return OK;
}

int edge_ring_pr (edge_t edg)

{
    edge_t cur_edg;
    int first_edge_ser;

    first_edge_ser = edg->serial;
    cur_edg = edg;

    printf("\n  check edge ring\n"); 
    do
	{
    printf("%d ,", cur_edg->serial);
    cur_edg = cur_edg->next_edge;
	} 
    while ( cur_edg->serial != first_edge_ser);
    printf("\n  done ring\n"); 
  return OK;
}


int short_face_pr (face_t f)
   { 
      edge_t cur_edge;
      printf("\n %d", f->serial);
   cur_edge = f->next_edge;
   do
       {
	   short_edge_pr(cur_edge);
	   cur_edge = cur_edge->next_edge;
       }
   while (cur_edge != f->next_edge);
  return OK;
   }


  int short_poly_pr(face_t f)
  {
      face_t cur_face;

      cur_face = f;
   do
       {
	   short_face_pr(cur_face);
	   cur_face = cur_face->next_face;
       }
   while (cur_face != f);
  return OK;
}



 void pr_face( p_face_t p_face)

{
    if (p_face == NULL) return;
    printf("\n %d %d %d %d", p_face->fev_type, p_face->serial,
            p_face->next_edge_index, p_face->next_face_index);
}

void pr_edge( p_edge_t p_edge)

{
    if (p_edge == NULL) return;
    printf( "\n %d %d %d %d %d", p_edge->fev_type, p_edge->serial,
            p_edge->from_vertex_index, p_edge->to_vertex_index, 
            p_edge->next_edge_index);
}

//void pr_vert( p_vertex_t p_vert)

//{
  //  matrix_t m;
   // if (p_vert == NULL) return;
  //  m = p_vert->vertex_coords;

   //      printf("\n %d %d %f %f %f", p_vert->fev_type, p_vert->serial,
    //        e(m,0,0), e(m,1,0), e(m,2,0));

//}
