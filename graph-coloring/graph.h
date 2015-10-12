/* graph.h
 * header file for graph.c
 * The purpose of this file is to declare C functions,
 * structs, and other variables for use in graph.c.
 *
 * TODO: WRITE YOUR NAME HERE
 * CSC 173 Fall 2015 -- Graph Coloring project
 * TODO: WRITE THE DATE YOU SUBMITTED THE ASSIGNMENT HERE
 */

#ifndef _graph_h
#define _graph_h

#include <stdbool.h>

// C structures (structs) for vertices and edges
/* Each vertex has:
 * An integer ID
 * A name
 * A color
 */
typedef struct vertex {
    /* TODO: Your code here */
    int id;
    char* name;
    char* color;
} *vertex_t;

/* Each edge has:
 * An integer ID
 * A name
 * A source vertex
 * A destination vertex
 */
typedef struct edge {
	int id;
	char* name;
	vertex_t source;
	vertex_t dest;


    /* TODO: Your code here */
} *edge_t;

/* Each graph has:
 * An array of vertices
 * An array of edges
 * OPTIONAL: You may want to store some
 * properties of the graph in the struct.
 * For example, the number of colors,
 * whether the graph has a valid coloring,
 * etc.
 */
typedef struct graph 
{
	int vertex, edge;
	vertex_t *vertices;
	edge_t *edges;
    /* TODO: Your code here */
} *graph_t;

// C functions that are defined in graph.c
vertex_t new_vertex(int id, char *name, char *color);
edge_t new_edge(int id, char *name, vertex_t src, vertex_t dst);
graph_t new_graph(vertex_t *vertices, edge_t *edges);
void print_vertex(vertex_t vertex);
void print_edge(edge_t edge);
void print_graph(graph_t graph);
void print_bad_edges(edge_t *edges);
int num_colors(graph_t graph);
bool has_valid_coloring(graph_t graph);
edge_t *get_bad_edges(graph_t graph);

// TODO: Headers of other functions you want 
// to define in graph.c go here







#endif
