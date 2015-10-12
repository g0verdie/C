#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include "matrix/matrix_types.h"
#include "matrix/matrix.h"
#include "FEVtypes.h"
#include "FEV.h"




face_t file_make_structs(FILE *FP)

{
    int serial, fev;
    face_t f1;
    fscanf(FP,"%d ", &fev);     //reads the fev
    f1 = (face_t) malloc( sizeof(struct face));     //giving memory to the head pointer
    f1->fev_type = fev;
    fscanf(FP,"%d ", &serial);      //serial number reading
    f1->serial = serial;
    f1->next_edge = read_make_edge(FP);     //start reading the edges
    face_t temp_face = f1;          //this is used to properly link the faces together
    int flag=0;     //helps to break the do loop
    do 
    {                   //looks for other faces and links them together
        flag=1;
        temp_face->next_face = next_face(FP);       
        if(temp_face->next_face != NULL)
        {
            temp_face=temp_face->next_face;
            flag=0;
        }
    } 
    while(flag==0);
    temp_face->next_face = f1;      //links the last face to the first one
	return f1;
    }

face_t next_face(FILE *FP)      //used to properly create a linked list of faces. returns a face_t
{
    int fev=10, serial;
    if(fscanf(FP, "%d ", &fev)!=1)          //stops reading the faces when the file ends
        return NULL;
    fscanf(FP, "%d ", &serial);
    face_t next_face = (face_t) malloc( sizeof(struct face));
    next_face->fev_type = fev;
    next_face->serial = serial;
    next_face->next_edge = read_make_edge(FP);
    return next_face;
}


edge_t read_make_edge(FILE *FP )        //used to read the edges from a file and link them together
{
    int type, ser;
    vertex_t from_vert, to_vert;
    fscanf(FP, "%d ", &type);
    fscanf(FP, "%d ", &ser); 
    from_vert=read_make_vertex(FP);     //reads in the from and to vertices
    to_vert=read_make_vertex(FP);
    edge_t newedge = new_edge(from_vert, to_vert, ser);     //links the consecutive edges together
    edge_t temp_edge = newedge;     //used to properly create a linked list of edges
    int flag=0;     //same purpose as in the face builder
    do
    {
        temp_edge->next_edge = next_edge(FP);       //starts linking the edges together 
        flag=1;
        if(temp_edge->next_edge != NULL)
        {
            temp_edge=temp_edge->next_edge;
            flag=0;
        }
    } 
    while(flag==0);
    temp_edge->next_edge = newedge; //links the last edge to the first one
    return newedge;
}

edge_t next_edge(FILE *FP)      //very similar to read_make_edge, used to properly create a linked list
{
    const long pos = ftell(FP);     //remembers the fscanf position
    int fev, serial;
    vertex_t from_vert, to_vert;
    if(fscanf(FP, "%d ", &fev)!=1 || fev!=11)       //tells the read_make_edge that the edges have ended
    {
        fseek(FP, pos, SEEK_SET);       //returns the fscanf to the pre-reading position
        return NULL;
    }
    fscanf(FP, "%d ", &serial);
    from_vert=read_make_vertex(FP);
    to_vert=read_make_vertex(FP);
    edge_t newedge = new_edge(from_vert, to_vert, serial);
    return newedge;
}

vertex_t read_make_vertex(FILE *FP)     //reads in the vertex. pretty self explanatory
{
    int fev, ser;
    double x, y, z;
    fscanf(FP, "%d %d %lf %lf %lf ", &fev, &ser, &x, &y, &z);
    vertex_t vert =new_vert(x,y,z,ser);
    return vert;
}

