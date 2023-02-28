#include <stdio.h>
#include <stdlib.h>
#include "tsp_file.h"

void eil101() {
    tsp_file_ptr file_eil = get_tsp_file("eil101");
    tsp_matrix_ptr matrix_eil = init_tsp_matrix_ptr();

    add_nodes_to_tsp_matrix(matrix_eil, file_eil);
    for(int i = 0; i < matrix_eil->size; i++) {
        set_tsp_matrix_for_node(matrix_eil, matrix_eil->nodes[i]);
        pretty_print_node(matrix_eil->nodes[i]);
    }

    pretty_print_matrix(matrix_eil);

    free(file_eil);
    free(matrix_eil);
}