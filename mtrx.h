#pragma once

typedef struct typemeta typemeta;
typedef struct matrixmeta matrixmeta;
typedef struct SqMatrix SqMatrix;


struct typemeta {
    int size;

    void (*print_EL)(void *);

    void *(*mult)(void *, void *);

    void *(*sum)(void *, void *);

};

struct matrixmeta {
    typemeta *type_m;

    SqMatrix *(*init)(int, matrixmeta *);

    int (*compare)(SqMatrix *, SqMatrix *);

    void (*delete)(SqMatrix *);

    void *(*get_ij)(int, int, SqMatrix *);

    void (*print)(SqMatrix *);

    void (*set_ij)(int, int, void *, SqMatrix *);

    SqMatrix *(*set_from_arr)(int, void *, matrixmeta *);

    SqMatrix *(*sum)(SqMatrix *, SqMatrix *);

    SqMatrix *(*mult)(SqMatrix *, SqMatrix *);

    SqMatrix *(*scMult)(SqMatrix *, void *);

    SqMatrix *(*addLinComb)(SqMatrix *, int, void *);

};

struct SqMatrix {
    matrixmeta *meta;
    int dimension;
    void *data;

};

SqMatrix *init(int, matrixmeta *);

void delete(SqMatrix *);

void *get_ij(int, int, SqMatrix *);

void print(SqMatrix *);

void set_ij(int, int, void *, SqMatrix *);

int compare(SqMatrix *a, SqMatrix *b);

SqMatrix *init_from_arr(int, void *data, matrixmeta *meta);

SqMatrix *sum(SqMatrix *, SqMatrix *);

SqMatrix *mult(SqMatrix *, SqMatrix *);

SqMatrix *scMult(SqMatrix *, void *);

SqMatrix *addLinComb(SqMatrix *, int, void *);


