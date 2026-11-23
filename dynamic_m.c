#include "dynamic_m.h"
#include <malloc.h>

void Create(int ***x, int n, int m) {
    *x = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(m * sizeof(int));
    }
    return;
}

void Vvod(FILE *in, int ***x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(in, "%i", &(*x)[i][j]);
        }
    }
    return;
}

void Vivod(FILE *out, int ***x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%4i ", (*x)[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

int kol_otr(int **x, int n, int m) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j && x[i][j] < 0) {
                k += 1;
            }
        }
    }
    return k;
}

int sum_otr(int **x, int n, int m) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j && x[i][j] < 0) {
                s += x[i][j];
            }
        }
    }
    return s;
}

void Ochistka(int ***x, int n) {
    for (int i = 0; i < n; i++) {
        free((*x)[i]);
    }
    free((*x));
    return;
}
