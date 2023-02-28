#include <stdio.h>
#include <stdlib.h>
#include "tsp_file.h"

void berlin52() {
  tsp_file_ptr file_berlin = get_tsp_file("berlin52.txt");
  tsp_matrix_ptr matrix_berlin = init_tsp_matrix_ptr();

  add_nodes_to_tsp_matrix(matrix_berlin, file_berlin);
  for(int i = 0; i < matrix_berlin->size; i++) {
    set_tsp_matrix_for_node(matrix_berlin, matrix_berlin->nodes[i]);
    pretty_print_node(matrix_berlin->nodes[i]);
  }

  pretty_print_matrix(matrix_berlin);

  free(file_berlin);
  free(matrix_berlin);  
}