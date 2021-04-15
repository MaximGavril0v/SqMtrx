#include <stdlib.h>
#include <stdio.h>
#include "../mtrx.c"
#include "../mtrx_float.c"
#include "../mtrx_int.c"

void test1() {
    int dimension_1 = 2, dimension_2 = 2;
    float testIn_1[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float testIn_2[4] = {4.0f, 3.0f, 2.0f, 1.0f};
    float testOut[4] = {5.0f, 5.0f, 5.0f, 5.0f};
    matrixmeta *matrixmeta_float_1 = init_matrixmeta_float();
    SqMatrix *a = matrixmeta_float_1->set_from_arr(dimension_1, testIn_1, matrixmeta_float_1);
    SqMatrix *b = matrixmeta_float_1->set_from_arr(dimension_2, testIn_2, matrixmeta_float_1);
    SqMatrix *t = matrixmeta_float_1->set_from_arr(2, testOut, matrixmeta_float_1);
    SqMatrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_1: pass\n");
    } else {
        printf("\ntest_1: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_1);
}

void test2() {
    int dimension_1 = 3, dimension_2 = 3;
    int testIn_1[9] = {0, -1, 1, 0, -1, -1, 0, 0, -1};
    int testIn_2[9] = {0, 0, -1, 1, 1, -1, 1, 2, -2};
    int testOut[9] = {0, -1, 0, 1, 0, -2, 1, 2, -3};
    matrixmeta *matrixmeta_int_1 = init_matrixmeta_int();
    SqMatrix *a = matrixmeta_int_1->set_from_arr(dimension_1, testIn_1, matrixmeta_int_1);
    SqMatrix *b = matrixmeta_int_1->set_from_arr(dimension_2, testIn_2, matrixmeta_int_1);
    SqMatrix *t = matrixmeta_int_1->set_from_arr(3, testOut, matrixmeta_int_1);
    SqMatrix *c = a->meta->sum(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_2: pass\n");
    } else {
        printf("\ntest_2: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_int_1);
}

void test3() {
    int dimension_1 = 3, dimension_2 = 3;
    float testIn_1[9] = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    float testIn_2[9] = {3.0f, -7.0f, 2.8f, 5.4f, -2.9f, 1.6f, 1.7f, 10.65f, 1.777f};
    float testOut[9] = {3.0f, -7.0f, 2.8f, 5.4f, -2.9f, 1.6f, 1.7f, 10.65f, 1.777f};
    matrixmeta *matrixmeta_float_2 = init_matrixmeta_float();
    SqMatrix *a = matrixmeta_float_2->set_from_arr(dimension_1, testIn_1, matrixmeta_float_2);
    SqMatrix *b = matrixmeta_float_2->set_from_arr(dimension_2, testIn_2, matrixmeta_float_2);
    SqMatrix *t = matrixmeta_float_2->set_from_arr(3, testOut, matrixmeta_float_2);
    SqMatrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_3: pass\n");
    } else {
        printf("\ntest_3: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_2);
}

void test4() {
    int dimension_1 = 3, dimension_2 = 3;
    int testIn_1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int testIn_2[9] = {76, -91, 87, 120, 9, -876, 109, 1, 0};
    int testOut[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    matrixmeta *matrixmeta_int_2 = init_matrixmeta_int();
    SqMatrix *a = matrixmeta_int_2->set_from_arr(dimension_1, testIn_1, matrixmeta_int_2);
    SqMatrix *b = matrixmeta_int_2->set_from_arr(dimension_2, testIn_2, matrixmeta_int_2);
    SqMatrix *t = matrixmeta_int_2->set_from_arr(3, testOut, matrixmeta_int_2);
    SqMatrix *c = a->meta->mult(a, b);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_4: pass\n");
    } else {
        printf("\ntest_4: fail\n");
    }
    a->meta->delete(a);
    b->meta->delete(b);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_int_2);
}

void test5() {
    int dimension = 2;
    float scalar = 1.0f;
    float testIn[4] = {0.0f, -2.9f, -0.023f, 4.56f};
    float testOut[4] = {0.0f, -2.9f, -0.023f, 4.56f};
    matrixmeta *matrixmeta_float_3 = init_matrixmeta_float();
    SqMatrix *a = matrixmeta_float_3->set_from_arr(dimension, testIn, matrixmeta_float_3);
    SqMatrix *t = matrixmeta_float_3->set_from_arr(2, testOut, matrixmeta_float_3);
    SqMatrix *c = a->meta->scMult(a, &scalar);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_5: pass\n");
    } else {
        printf("\ntest_5: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_3);
}

void test6() {
    int dimension = 2;
    int scalar = 1333;
    int testIn[4] = {0, 0, 0, 0};
    int testOut[4] = {0, 0, 0, 0};
    matrixmeta *matrixmeta_int_3 = init_matrixmeta_int();
    SqMatrix *a = matrixmeta_int_3->set_from_arr(dimension, testIn, matrixmeta_int_3);
    SqMatrix *t = matrixmeta_int_3->set_from_arr(2, testOut, matrixmeta_int_3);
    SqMatrix *c = a->meta->scMult(a, &scalar);
    int Y = t->meta->compare(t, c);
    if (Y == 1) {
        printf("\ntest_6: pass\n");
    } else {
        printf("\ntest_6: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_int_3);
}

void test7() {
    int dimension = 2;
    int row = 0;
    float testIn[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float coeffs[2] = {1.0f, 1.0f};
    float testOut[4] = {4.0f, 6.0f, 3.0f, 4.0f};
    matrixmeta *matrixmeta_float_4 = init_matrixmeta_float();
    SqMatrix *a = matrixmeta_float_4->set_from_arr(dimension, testIn, matrixmeta_float_4);
    SqMatrix *t = matrixmeta_float_4->set_from_arr(dimension, testOut, matrixmeta_float_4);
    SqMatrix *c = a->meta->addLinComb(a, row, coeffs);
    int Y = t->meta->compare(c, t);
    if (Y == 1) {
        printf("\ntest_7: pass\n");
    } else {
        printf("\ntest_7: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_float_4);
}

void test8() {
    int dimension = 3;
    int row = 1;
    int testIn[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
    int coeffs[3] = {929, 23, 98};
    int testOut[9] = {0, 0, 0, 23, 23, 23, 0, 0, 0};
    matrixmeta *matrixmeta_int_4 = init_matrixmeta_int();
    SqMatrix *a = matrixmeta_int_4->set_from_arr(dimension, testIn, matrixmeta_int_4);
    SqMatrix *t = matrixmeta_int_4->set_from_arr(dimension, testOut, matrixmeta_int_4);
    SqMatrix *c = a->meta->addLinComb(a, row, coeffs);
    int Y = t->meta->compare(c, t);
    if (Y == 1) {
        printf("\ntest_8: pass\n");
    } else {
        printf("\ntest_8: fail\n");
    }
    a->meta->delete(a);
    t->meta->delete(t);
    c->meta->delete(c);
    free(matrixmeta_int_4);
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}



