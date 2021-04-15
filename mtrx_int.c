#include "mtrx_int.h"
#include <stdlib.h>
#include <stdio.h>


typemeta *init_typemeta_int() {
    typemeta *res = calloc(1, sizeof(typemeta));
    res->size = sizeof(int);
    res->mult = mult_int;
    res->sum = sum_int;
    res->print_EL = print_EL_int;
    return res;
}


void print_EL_int(void *m) {
    printf("%d", *(int *) m);
}

void *mult_int(void *a, void *b) {
    int *res = calloc(1, sizeof(int));
    *res = *(int *) a * *(int *) b;
    return res;
}

void *sum_int(void *a, void *b) {
    int *res = calloc(1, sizeof(int));
    *res = *(int *) a + *(int *) b;
    return res;
}

matrixmeta *init_matrixmeta_int() {
    matrixmeta *res = calloc(1, sizeof(matrixmeta));
    res->get_ij = get_ij;
    res->sum = sum;
    res->init = init;
    res->mult = mult;
    res->compare = compare;
    res->set_ij = set_ij;
    res->print = print;
    res->delete = delete;
    res->type_m = init_typemeta_int();
    res->set_from_arr = init_from_arr;
    res->scMult = scMult;
    res->addLinComb = addLinComb;
    return res;
}

