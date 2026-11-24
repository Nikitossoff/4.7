#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void Create(int ***x, int n);
void Vvod(FILE *in, int **x, int n);
void Vivod(FILE *out, int **x, int n);
int est_nad(int **x, int n);
int est_pod(int **x, int n);
int sum_nad(int **x, int n);
int sum_pod(int **x, int n);
void Ochistka(int ***x, int n);

#endif
