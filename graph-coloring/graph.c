/* graph.c
 * implements functions declared in graph.h
 *
 * Your task (which you have no choice but to accept):
 * Fill in the definitions of the functions contained below 
 * (every place where you see "TODO: Your code here")
 *
 * NOTE: For purposes of writing modular code,
 * this file does NOT contain high-level
 * functions for reading a graph from stdin
 * or writing a graph to stdout.
 * These functions are contained in main.c.
 *
 * Vishnu Chittari
 * CSC 173 Fall 2015 -- Graph Coloring project
 * TODO: WRITE THE DATE YOU SUBMITTED THE ASSIGNMENT HERE
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"

// C functions that are declared in graph.h
// Creates a new vertex from an ID, name, and color
vertex_t new_vertex(int id, char *name, char *color) {

	vertex_t vert = (vertex_t) malloc( sizeof(struct vertex));
	vert -> id = id;
	vert -> name = name;
	vert -> color = color;
    // stub (delete when you implement this function)
    return vert;
    /* TODO: Your code here */
}

// Creates a new edge from an ID, name, and source/destination vertices
edge_t new_edge(int id, char *name, vertex_t src, vertex_t dst) {

	edge_t edge_now = (edge_t) malloc( sizeof(struct edge));
	edge_now -> id = id;
    edge_now -> name = name;
	edge_now -> source = src;
	edge_now -> dest = dst;
    // stub (delete when you implement this function)
    return edge_now;
    /* TODO: Your code here */
}

// Creates a new graph from a list of vertices and edges
graph_t new_graph(vertex_t *vertices, edge_t *edges) {
    graph_t graph = (graph_t)malloc( sizeof(struct graph));
    graph->vertices = vertices;
    graph->edges = edges;
    return graph;
}

// Prints a vertex to stdout
void print_vertex(vertex_t vertex) {
	printf("VName: %s  ", vertex -> name);
	printf ("VID: %d   ", vertex ->id);
	printf("VColor: %s.\n", vertex -> color);
    /* TODO: Your code here */
}

// Prints an edge to stdout
void print_edge(edge_t edge) {
	printf("EName: %s  ", edge -> name);
	printf("EID: %d\n",edge-> id);
	printf("Source Vertex:\n");
	print_vertex(edge->source);
	printf("Destination Vertex:\n");
	print_vertex(edge->dest);
    /* TODO: Your code here */
}

// Prints a graph to stdout
void print_graph(graph_t graph) {

	for(int i=0; i < graph->vertex; i++)
        print_vertex(graph->vertices[i]);
    //printf("Finished printing out the vertices\nedge count = %d\n", graph->edge);
    for(int j=0; j < graph->edge; j++)
        print_edge(graph->edges[j]);
    /* TODO: Your code here */
}

// Prints all bad edges to stdout
void print_bad_edges(edge_t *edges) {

   int size = sizeof(edges) / sizeof(struct edge);
   for(int i=0; i<size; i++)
        print_edge(edges[i]);
}

// returns the number of distinct colors found within the graph's vertices
int num_colors(graph_t graph) {
    char* colors = (char*)(malloc( sizeof(char)*graph->vertex));
    bool match = false;
    int count = 0;
    for(int i=0; i< graph->vertex; i++)
    {
        for(int j=0; j < graph->vertex; j++)
            if(&colors[j] == graph->vertices[i]->color)
                match=true;
        if(match==false)
        {
            colors[count] = *(graph->vertices[i]->color);
            count++;
        }
    }
    return count;
    /* TODO: Your code here */
}

// returns true if the graph has a valid coloring, false otherwise
// NOTE: A graph is colored correctly *if and only if*
// each edge contains vertices of a different color
bool has_valid_coloring(graph_t graph) {
    if((num_colors(graph)==graph->edge)
        && *get_bad_edges(graph)==NULL)
    return true;
    return false;
    /* TODO: Your code here */
}

// returns an array of the bad edges in the graph
// i.e. the edges where its two vertices have the same color
edge_t *get_bad_edges(graph_t graph) {
    printf("Entered get_bad_edges!\n");
    int bad_id[graph->edge];
    int count=0;
    char* src = malloc( sizeof(char)*20);
    char* dest = malloc( sizeof(char)*20);
    //printf("Entering the first forloop!\n");
    for(int i=0; i<graph->edge; i++)
    {
        //print_edge(graph->edges[i]);
        //printf("iterating...\n");
        src = graph->edges[i]->source->color;
        dest = graph ->edges[i]->dest->color;
        //printf("got the colors of source and destination!\n");
        //printf("Source color is %s\n Dest color is %s\n", src, dest);
        if(strcmp(src, dest)!=0)
        {
            printf("found a bad edge!\n");
            bad_id[count] = graph->edges[i]->id;
            count++;
        }
    }
    //printf("got all my bad_id's\n");
    if (count==0)
        return NULL;
    edge_t *bad_edges = (edge_t*)malloc( sizeof(struct edge)*count);
    for(int j=0; j<count; j++)
        bad_edges[j] = graph->edges[bad_id[j]];
    // stub (delete when you implement this function)
    return bad_edges;
    /* TODO: Your code here */
}

// TODO: Definitions of other functions you have 
// defined in graph.h go here



