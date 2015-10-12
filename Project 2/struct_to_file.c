#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "matrix/matrix_types.h"
#include "matrix/matrix.h"
#include "FEVtypes.h"
#include "FEV.h"

void face_to_file_internal(FILE *FP, face_t head_face)
{
    fprintf(FP, "%d %d\n", 10, head_face->serial);

    edge_t temp=head_face->next_edge;       //same procedure as in the face_to_file
    int edge_serial = temp->serial;
    do
    {
    edge_to_file(FP, temp);
    temp=temp->next_edge;

    }
    while(edge_serial != temp->serial);
}

void face_to_file(FILE *FP, face_t head_face)
{
    face_t temp = head_face;        //temporary face holder
    int face_serial = temp->serial;     //records the first face's serial number
    do
    {               
    face_to_file_internal(FP, temp);        //calls onto the internal method. 
    temp=temp->next_face;
    }
    while(face_serial != temp->serial);
}

void edge_to_file(FILE *FP, edge_t current_edge)        
{

    fprintf(FP, "%d %d\n", 11, current_edge->serial); //writes in the edge info

    vertex_to_file(FP, current_edge->from_vertex);  //calls onto the vertex function to print out the vertex info
    vertex_to_file(FP, current_edge->to_vertex);
}

void vertex_to_file(FILE *FP, vertex_t current_vertex)      //prints out vertex info
{
    fprintf(FP, "%d %d %lf %lf %lf\n", 12, current_vertex->serial,
    current_vertex->vertex_coords->mat[0][0],
    current_vertex->vertex_coords->mat[1][0],
    current_vertex->vertex_coords->mat[2][0]);
}


