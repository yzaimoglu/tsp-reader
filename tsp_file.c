#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tsp_file.h"
#include "util.h"


tsp_file_ptr init_tsp_file_ptr() {
    tsp_file_ptr tsp_file = (tsp_file_ptr) malloc(sizeof(TSPFile));
    tsp_file->line_size = 0;
    return tsp_file;
}

tsp_file_ptr get_tsp_file(char name[30]) {
    char file_path[60] = "./instances/";
    strcat(file_path, name);

    FILE* file_ptr = fopen(file_path, "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Reading file %s\n", file_path);
    
    if(file_ptr == NULL) {
        printf("Error opening file %s\n", file_path);
    }

    tsp_file_ptr tsp_file = init_tsp_file_ptr();
    int read_status = 0;
    while ((read = getline(&line, &len, file_ptr)) != -1) {        
        if(starts_with("1", line)) read_status = 1;
        else if(starts_with("EOF", line)) read_status = 2;

        if(read_status == 1) {
            tsp_file->line_size++;
            printf("Found coordinates with ID %d\n", tsp_file->line_size);
            tsp_file->lines[tsp_file->line_size - 1] = (char*) malloc(sizeof(char) * read);
            strcpy(tsp_file->lines[tsp_file->line_size - 1], line);
        } else if(read_status == 2) break;
    }

    fclose(file_ptr);
    if (line)
        free(line);
    printf("Finished reading file %s\n", file_path);
    return tsp_file;
}

tsp_node_ptr init_tsp_node_ptr() {
    tsp_node_ptr tsp_node = (tsp_node_ptr) malloc(sizeof(TSPNode));
    tsp_node->id = 0;
    tsp_node->x = 0;
    tsp_node->y = 0;
    tsp_node->distance = 0;
    return tsp_node;
}

tsp_node_ptr get_tsp_node(char* line) {
    tsp_node_ptr tsp_node = init_tsp_node_ptr();
    char** sub_str = (char**) malloc(sizeof(char*) * 4);
    int sub_str_size = split(line, ' ', &sub_str);

    int id = atoi(sub_str[0]);
    double x = atof(sub_str[1]);
    double y = atof(sub_str[2]); 
    double distance = fabs(x - y);

    tsp_node->id = id;
    tsp_node->x = x;
    tsp_node->y = y;
    tsp_node->distance = distance;
    free(sub_str);
    return tsp_node;
}

tsp_matrix_ptr init_tsp_matrix_ptr() {
    tsp_matrix_ptr tsp_matrix = (tsp_matrix_ptr) malloc(sizeof(TSPMatrix));
    tsp_matrix->size = 0;
    return tsp_matrix;
}

void add_nodes_to_tsp_matrix(tsp_matrix_ptr tsp_matrix, tsp_file_ptr tsp_file) {
    for(int i = 0; i < tsp_file->line_size; i++) {
        tsp_node_ptr tsp_node = get_tsp_node(tsp_file->lines[i]);
        tsp_matrix->nodes[i] = tsp_node;
        tsp_matrix->size++;
    }
}

void set_tsp_matrix_for_node(tsp_matrix_ptr matrix, tsp_node_ptr node) {
    int size = matrix->size;
    tsp_node_ptr* nodes = matrix->nodes;
    tsp_node_ptr current_node = nodes[0];
    for(int i = 0; i < size; i++) {
        double distance = fabs(nodes[i]->x - node->x) + fabs(nodes[i]->y - node->y);
        matrix->matrix[node->id - 1][i] = distance;
    }
}

void pretty_print_matrix(tsp_matrix_ptr matrix) {
    int size = matrix->size;
    for(int i = 0; i < size; i++) {
        printf("[ ");
        for(int j = 0; j < size; j++) {
            printf("%.1lf ", matrix->matrix[i][j]);
        }
        i == size - 1 ? printf("]\n") : printf("]\n\n");
    }
}

void pretty_print_node(tsp_node_ptr node) {
    printf("%d %.1lf %.1lf\n", node->id, node->x, node->y);
}