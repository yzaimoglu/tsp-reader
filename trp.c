#include <stdio.h>
#include <stdlib.h>
#include "tsp_file.h"

int main(int argc, char *argv[]) {
    if(argc == 2) {
        char* file_name = argv[1];
        tsp_file_ptr file_ptr = get_tsp_file(file_name);
        tsp_matrix_ptr matrix_ptr = init_tsp_matrix_ptr();

        add_nodes_to_tsp_matrix(matrix_ptr, file_ptr);
        for(int i = 0; i < matrix_ptr->size; i++) {
            set_tsp_matrix_for_node(matrix_ptr, matrix_ptr->nodes[i]);
            pretty_print_node(matrix_ptr->nodes[i]);
        }

        pretty_print_matrix(matrix_ptr);

        free(file_ptr);
        free(matrix_ptr);  
    } else {
        printf("Usage: trp <filename>\n");
    }
    return 0;
}