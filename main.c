#include <stdio.h>
#include <stdlib.h>
#include "mtrx.c"
#include "mtrx_int.c"
#include "mtrx_float.c"

int main() {
    int number;
    int Pause = 0;
    int type;
    int dimension_1;
    int dimension_2;
    SqMatrix *a;
    SqMatrix *b;
    matrixmeta *matrixmeta_int = NULL;
    matrixmeta *matrixmeta_float = NULL;
    int *el = NULL;
    float *el_f = NULL;
    int scalar;
    float scalar_f;
    int row;
    int *lambda;
    float *lambda_f;
    while (Pause == 0) {
        printf("For integer elements write 0, for float elements write 1 -> ");
        scanf("%d", &type);

        if ((type == 0) || (type == 1)) {
            Pause = 1;
        } else {
            printf("Write 0 or 1:\n");
        }
        while (Pause == 1) {
            printf("Enter the dimension of matrix #1 -> ");
            scanf("%d", &dimension_1);
            printf("Enter the dimension of matrix #2 -> ");
            scanf("%d", &dimension_2);
            if (dimension_1 > 0 && dimension_2 > 0) {
                Pause = 2;
            } else {
                printf("Enter positive numbers:\n");
            }
        }
    }

    if (type == 0) {
        matrixmeta_int = init_matrixmeta_int();
        el = calloc(dimension_1 * dimension_1, sizeof(int));
        for (int i = 0; i < dimension_1 * dimension_1; ++i) {
            printf("Enter integer number:");
            scanf("%d", &el[i]);
        }
        a = matrixmeta_int->set_from_arr(dimension_1, el, matrixmeta_int);
        printf("First matrix\n");
        a->meta->print(a);
        for (int i = 0; i < dimension_2 * dimension_2; ++i) {
            printf("Enter integer number:");
            scanf("%d", &el[i]);
        }
        b = matrixmeta_int->set_from_arr(dimension_2, el, matrixmeta_int);
        printf("\nSecond matrix\n");
        a->meta->print(b);
        printf("\n");

    } else if (type == 1) {
        matrixmeta_float = init_matrixmeta_float();
        el_f = calloc(dimension_1 * dimension_1, sizeof(float));
        for (int i = 0; i < dimension_1 * dimension_1; ++i) {
            printf("Enter float number:");
            scanf("%f", &el_f[i]);
        }
        a = matrixmeta_float->set_from_arr(dimension_1, el_f, matrixmeta_float);
        printf("First matrix\n");
        a->meta->print(a);
        for (int i = 0; i < dimension_2 * dimension_2; ++i) {
            printf("Enter float number:");
            scanf("%f", &el_f[i]);
        }
        b = matrixmeta_float->set_from_arr(dimension_2, el_f, matrixmeta_float);
        printf("\nSecond matrix\n");
        b->meta->print(b);
        printf("\n");


    }
    printf("\n");
    printf("Menu:\n1 -> Sum matrices\n2 -> Multiply matrices\n3 -> Multiply matrix #1 by a scalar\n4 -> Multiply matrix #2 by a scalar\n5 -> Add linear combination in matrix #1\n6 -> Add linear combination in matrix #2\nElse -> Exit\n");
    scanf("%d", &number);
    if (number == 1) {
        if (dimension_1 == dimension_2) {
            SqMatrix *c = a->meta->sum(a, b);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        } else {
            printf("\nDimensions of the matrices are not equal\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }
    }
    if (number == 2) {
        if (dimension_1 == dimension_2) {
            SqMatrix *c = a->meta->mult(a, b);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        } else {
            printf("\nDimensions of the matrices are not equal\n");
            a->meta->delete(a);
            b->meta->delete(b);
        }
    }
    if (number == 3) {
        if (type == 0) {
            printf("Enter integer scalar: ");
            scanf("%d", &scalar);
            SqMatrix *c = a->meta->scMult(a, &scalar);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1) {
            printf("Enter float scalar: ");
            scanf("%f", &scalar_f);
            SqMatrix *c = a->meta->scMult(a, &scalar_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }
    if (number == 4) {
        if (type == 0) {
            printf("Enter integer scalar: ");
            scanf("%d", &scalar);
            SqMatrix *c = b->meta->scMult(b, &scalar);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1) {
            printf("Enter float scalar: ");
            scanf("%f", &scalar_f);
            SqMatrix *c = b->meta->scMult(b, &scalar_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }
    if (number == 5) {
        if (type == 0) {
            lambda = calloc(dimension_1, sizeof(int));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < dimension_1; i++) {
                printf("Enter integer coefficient:");
                scanf("%d", &lambda[i]);
            }
            SqMatrix *c = a->meta->addLinComb(a, row, lambda);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1){
            lambda_f = calloc(dimension_1, sizeof(float));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < dimension_1; i++) {
                printf("Enter float coefficient:");
                scanf("%f", &lambda_f[i]);
            }
            SqMatrix *c = a->meta->addLinComb(a, row, lambda_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }
    if (number == 6) {
        if (type == 0) {
            lambda = calloc(dimension_1, sizeof(int));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < dimension_1; i++) {
                printf("Enter integer coefficient:");
                scanf("%d", &lambda[i]);
            }
            SqMatrix *c = b->meta->addLinComb(b, row, lambda);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
        if (type == 1){
            lambda_f = calloc(dimension_1, sizeof(float));
            printf("Enter a number of a row:");
            scanf("%d", &row);
            for (int i = 0; i < dimension_1; i++) {
                printf("Enter float coefficient:");
                scanf("%f", &lambda_f[i]);
            }
            SqMatrix *c = b->meta->addLinComb(b, row, lambda_f);
            c->meta->print(c);
            printf("\nDone\n");
            a->meta->delete(a);
            b->meta->delete(b);
            c->meta->delete(c);
        }
    }
    else {
        printf("\nExit...\n");
        a->meta->delete(a);
        b->meta->delete(b);
        printf("Done\n");
    }
    free(matrixmeta_float);
    free(matrixmeta_int);
    free(el);
    free(el_f);
    free(lambda);
    free(lambda_f);
    return 0;
}
