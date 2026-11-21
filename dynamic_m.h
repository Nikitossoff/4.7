#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H

#include <stdio.h>

void Create(int ***x, int n);
void Vvod(FILE *in, int ***x, int n);
void Vivod(FILE *out, int ***x, int n);
int kol_otr(int **x, int n);
int sum_otr(int **x, int n);
void Ochistka(int ***x, int n);

#endif
