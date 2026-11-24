#include "dynamic_m.h"
#include <malloc.h>
#include <stdbool.h>

void Create(int ***x, int n) {
    *x = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(n * sizeof(int));
    }
    return;
}

void Vvod(FILE *in, int **x, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(in, "%i", &x[i][j]);
        }
    }
    return;
}

void Vivod(FILE *out, int **x, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(out, "%4i ", x[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

int est_nad(int **x, int n) {
    bool fl = true;
    int i = 0;
    while (i < n && fl) {
        int j = i + 1;
        while (j < n && fl) {
            if (x[i][j] < 0) {
                fl = false;
            } else {
                j++;
            }
        }
        if (fl) {
            i++;
        }
    }
    return !fl;
}

int est_pod(int **x, int n) {
    bool fl = true;
    int i = 0;
    while (i < n && fl) {
        int j = 0;
        while (j < i && fl) {
            if (x[i][j] < 0) {
                fl = false;
            } else {
                j++;
            }
        }
        if (fl) {
            i++;
        }
    }
    return !fl;
}

int sum_nad(int **x, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i][j] < 0) {
                s += x[i][j];
            }
        }
    }
    return s;
}

int sum_pod(int **x, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (x[i][j] < 0) {
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
