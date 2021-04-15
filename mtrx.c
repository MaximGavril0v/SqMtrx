#include "mtrx.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <corecrt_malloc.h>

SqMatrix *init(int dimension, matrixmeta *meta) {
    assert(dimension != 0);
    SqMatrix *res = calloc(1, sizeof(SqMatrix));
    res->dimension = dimension;
    res->meta = meta;
    res->data = calloc(dimension * dimension, meta->type_m->size);
    return res;
}

void delete(SqMatrix *this) {
    free(this->data);
    free(this);
}

void *get_ij(int i, int j, SqMatrix *this) {
    assert(i >= 0 && i < this->dimension && "Impossible");
    assert(j >= 0 && j < this->dimension && "Impossible");
    return (char *) (this->data) + this->meta->type_m->size * (i * this->dimension + j);
}

void print(SqMatrix *this) {
    for (int i = 0; i < this->dimension; i++) {
        for (int j = 0; j < this->dimension; j++) {
            if (j != 0)printf(" ");
            this->meta->type_m->print_EL(get_ij(i, j, this));
        }
        printf("\n");
    }

}

SqMatrix *sum(SqMatrix *a, SqMatrix *b) {
    assert(a->dimension == b->dimension && a->dimension == b->dimension);
    SqMatrix *res = init(a->dimension, a->meta);
    for (int i = 0; i < a->dimension; i++) {
        for (int j = 0; j < a->dimension; j++) {
            void *temp = a->meta->type_m->sum(get_ij(i, j, a), get_ij(i, j, b));
            memcpy(get_ij(i, j, res), temp, a->meta->type_m->size);
            free(temp);
        }
    }
    return res;
}

SqMatrix *mult(SqMatrix *a, SqMatrix *b) {
    assert(a->dimension == b->dimension && "Impossible");
    SqMatrix *res = init(a->dimension, a->meta);
    for (int i = 0; i < res->dimension; i++) {
        for (int j = 0; j < res->dimension; j++) {
            for (int r = 0; r < b->dimension; r++) {
                void *temp = a->meta->type_m->mult(get_ij(i, r, a), get_ij(r, j, b));
                void *temp1 = a->meta->type_m->sum(get_ij(i, j, res), temp);
                memcpy(get_ij(i, j, res), temp1, a->meta->type_m->size);
                free(temp);
                free(temp1);
            }
        }
    }
    return res;
}

SqMatrix *scMult(SqMatrix *a, void *scalar) {
    SqMatrix *res = init(a->dimension, a->meta);
    for (int i = 0; i < res->dimension; i++) {
        for (int j = 0; j < res->dimension; j++) {
            void *temp = a->meta->type_m->mult(get_ij(i, j, a), scalar);
            memcpy(get_ij(i, j, res), temp, a->meta->type_m->size);
            free(temp);
        }
    }
    return res;
}

SqMatrix *addLinComb(SqMatrix *a, int row, void *coeffs) {
    SqMatrix *res = init(a->dimension, a->meta);
    for(int j = 0; j < a->dimension; j++) {
        for(int i = 0; i < a->dimension; i++) {
            if (i != row)
                memcpy(get_ij(i, j, res), get_ij(i, j, a), a->meta->type_m->size);
            int8_t *coef = (int8_t *)coeffs + i * a->meta->type_m->size;
            void *temp = a->meta->type_m->mult((void *)coef, get_ij(i, j, a));
            void *temp1 = a->meta->type_m->sum(get_ij(row, j, res), temp);
            memcpy(get_ij(row, j, res), temp1,  a->meta->type_m->size);
            free(temp);
            free(temp1);
        }
    }
    return res;
}


void set_ij(int i, int j, void *data, SqMatrix *this) {
    assert(i >= 0 && i < this->dimension && "Impossible");
    assert(j >= 0 && j < this->dimension && "Impossible");
    memcpy(get_ij(i, j, this), data, this->meta->type_m->size);
}

SqMatrix *init_from_arr(int dimension, void *data, matrixmeta *meta) {
    assert(dimension != 0);
    SqMatrix *res = init(dimension, meta);
    memcpy(res->data, data, dimension * dimension * meta->type_m->size);
    return res;
}

int compare(SqMatrix *c, SqMatrix *t) {
    if (c->dimension != t->dimension) {
        return 0;
    }
    for (int i = 0; i < c->dimension; i++) {
        for (int j = 0; j < c->dimension; j++) {
            int T = 1;
            void *temp1 = calloc(1, c->meta->type_m->size);
            void *temp2 = calloc(1, c->meta->type_m->size);
            memcpy(temp1, c->meta->get_ij(i, j, c), c->meta->type_m->size);
            memcpy(temp2, c->meta->get_ij(i, j, t), c->meta->type_m->size);
            char *temp3 = (char *)temp1;
            char *temp4 = (char *)temp2;
            for (int k = 0; k < c->meta->type_m->size; ++k) {
                if (*(temp3++) != *(temp4++)) {
                    T = 0;
                    break;
                }
            }
            if (!T) {
                return 0;
            }
            free(temp1);
            free(temp2);
        }
    }
    return 1;


}

