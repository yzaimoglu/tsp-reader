#include <stdio.h>

#ifndef __tsp_file_h__
#define __tsp_file_h__

typedef struct tsp_file{
    int line_size;
    char* lines[200]; 
} TSPFile, *tsp_file_ptr;

typedef struct tsp_node {
    int id;
    double x;
    double y;
    double distance;
} TSPNode, *tsp_node_ptr;

typedef struct tsp_matrix {
    int size;
    tsp_node_ptr nodes[200];
    double matrix[200][200];
} TSPMatrix, *tsp_matrix_ptr;

tsp_file_ptr get_tsp_file(char* name);

tsp_file_ptr init_tsp_file_ptr();

tsp_node_ptr init_tsp_node_ptr();

tsp_node_ptr get_tsp_node(char* line);

tsp_matrix_ptr init_tsp_matrix_ptr();

void add_nodes_to_tsp_matrix(tsp_matrix_ptr tsp_matrix, tsp_file_ptr tsp_file);

void set_tsp_matrix_for_node(tsp_matrix_ptr matrix, tsp_node_ptr node);

void pretty_print_matrix(tsp_matrix_ptr matrix);

void pretty_print_node(tsp_node_ptr node);

#endif