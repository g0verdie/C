/* main.c
 * contains the main method, which basically
 * calls your other functions
 *
 * Your mission (which you have no choice but to accept):
 * Modify the functions below (marked with TODO) so that
 * your program correctly reads graphs from stdin and
 * writes the correct output to stdout.
 *
 * Vishnu Chittari
 * CSC 173 Fall 2015 -- Graph Coloring project
 * TODO: WRITE THE DATE YOU SUBMITTED THE ASSIGNMENT HERE
 */

// Instructions on running the executable
// The makefile will produce an executable file called
// 'coloring', which you can run to see if your code is
// correct.
// 'coloring' takes its input from stdin (by default,
// your terminal) and prints its output to stdout
// (also your terminal by default). To run it this way,
// type './coloring' at your command line (without the quotes),
// then type in an input graph. Press enter, and your program's
// result should appear right below.
// However, this requires you to type in an input graph every
// time you want to run your program. There is a quicker way...
// To run your program against the first test case, for example,
// redirect the input graph to stdin, and connect stdout to a file.
// To do this, type './coloring < tests/in/test_1.txt > tests/out/test_1.txt'
// (without the quotes).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "graph.h"

int main() {
    // read in the graph from stdin
    //printf("Hello world!\n");
    graph_t graph = stdin_to_graph();
    printf("Yay I got the graph and am back at the main function!!\n");
    // do the necessary computations, and
    // write the result to stdout
    //print_graph(graph);
    printf("time to jump into graph_to_stdout!\n");
    graph_to_stdout(graph);
}

// reads in the graph from stdin and 
// stores it in a graph_t struct
graph_t stdin_to_graph() 

{
    int id, vertex, edge;
    char* name = malloc( sizeof(char)*20);
    char* color = malloc( sizeof(char)*10);
    //printf("declared name and color arrays\n");
    fscanf(stdin, "%d\n%d", &vertex, &edge);
    //printf("got the amnt of vertices and edges\n");
    //printf("%d vertices, %d edges\n", vertex, edge);
    vertex_t* vertices = (vertex_t*) malloc( sizeof(struct vertex)*vertex);
    edge_t* edges = (edge_t*) malloc( sizeof(struct edge)*edge);
    //printf("created vertices and edges\n");
    for(int i=0; i<vertex; i++) //looking at the vertices
    {
        fscanf(stdin, "%d\n%s\n%s", &id, name, color);
        printf("Got a new vertex!\n");
        vertices[i] = new_vertex(id, name, color);
        print_vertex(vertices[i]);
    }
    //printf("Getting ready to retrieve edges!\n");
    free(name);
    free(color);

    char* e_name = malloc( sizeof(char)*20);
    int source, dest;
    char* holder = malloc( sizeof(char)*20);
    for (int i=0; i<edge; i++)//looking at the edges
    {
        fscanf(stdin, "%d\n%s %s\n%d\n%d", &id, holder, e_name, &source, &dest);
        printf("Edge name is %s\n", name);
        edges[i] = new_edge(id, e_name, vertices[source], vertices[dest]);
        printf("Got a new edge!\n");
        print_edge(edges[i]);
    }
    graph_t graph = new_graph(vertices, edges);

    graph ->vertex = vertex;
    graph -> edge = edge;
    //printf("Get the graph organized!\n");
    // stub (delete when you implement this function)
    return graph;
    /* TODO: Your code here */
}

// writes the result of our computations
// to stdout
void graph_to_stdout(graph_t graph) {
    // get a list of bad edges in the graph

    edge_t *bad_edges = get_bad_edges(graph);
    printf("retrieved the bad edges!\n");

    // get the number of colors in the graph
    //int colors = num_colors(graph);
    printf("retrieved the number of colors!\n");
    // falsely assume that the graph is colored correctly, and print out a YES message

        printf("Seems like you have bad edges!\n");
        int size = sizeof(bad_edges)/sizeof(struct edge);
        printf("size is %d\n", size);
        for(int i=0; i<size; i++)
            print_edge(bad_edges[i]);
    /* TODO: Modify the code above so that it correctly
     * computes whether the graph is colored correctly,
     * and if not, correctly prints the list of bad edges
     * in order of increasing edge IDs
     */
}






