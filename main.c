#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *inA = fopen("t1_A.txt", "r");
    FILE *inB = fopen("t1_B.txt", "r");
    if (inA == NULL || inB == NULL) {
        printf("Ошибка открытия входных файлов!\n");
        if (inA != NULL) fclose(inA);
        if (inB != NULL) fclose(inB);
        return 1;
    }

    int na, nb;

    do {
        printf("Введите размерность N квадратного массива A: ");
        scanf("%i", &na);
        if (na <= 1 || na > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (na <= 1 || na > 100);

    do {
        printf("Введите размерность N квадратного массива B: ");
        scanf("%i", &nb);
        if (nb <= 1 || nb > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (nb <= 1 || nb > 100);

    int **A = NULL, **B = NULL;
    Create(&A, na);
    Create(&B, nb);

    Vvod(inA, A, na);
    Vvod(inB, B, nb);

    int fa = est_nad(A, na) || est_pod(A, na);
    int fb = est_nad(B, nb) || est_pod(B, nb);

    FILE *out = fopen("output.txt", "w");

    fprintf(out, "Исходный массив A:\n");
    Vivod(out, A, na);
    fprintf(out, "Исходный массив B:\n");
    Vivod(out, B, nb);
    fprintf(out, "==================================\n");

    if (fa && !fb) {
        int sa = sum_nad(A, na) + sum_pod(A, na);
        fprintf(out, "Отрицательные элементы вне главной диагонали есть только в A (сумма = %i)\n", sa);
        fprintf(out, "В массиве B таких элементов нет, сравнение невозможно\n");
    }
    else if (fb && !fa) {
        int sb = sum_nad(B, nb) + sum_pod(B, nb);
        fprintf(out, "Отрицательные элементы вне главной диагонали есть только в B (сумма = %i)\n", sb);
        fprintf(out, "В массиве A таких элементов нет, сравнение невозможно\n");
    }
    else if (fa && fb) {
        int sa = sum_nad(A, na) + sum_pod(A, na);
        int sb = sum_nad(B, nb) + sum_pod(B, nb);
        fprintf(out, "Сумма отрицательных элементов вне главной диагонали в A = %i\n", sa);
        fprintf(out, "Сумма отрицательных элементов вне главной диагонали в B = %i\n", sb);

        if (sa > sb) {
            fprintf(out, "Сумма в A больше суммы в B\n");
        } else if (sa < sb) {
            fprintf(out, "Сумма в A меньше суммы в B\n");
        } else {
            fprintf(out, "Сумма в A равна сумме в B\n");
        }
    }
    else {
        fprintf(out, "Ни в одном из массивов нет отрицательных элементов вне главной диагонали\n");
    }

    fclose(inA);
    fclose(inB);
    fclose(out);

    printf("Результат успешно записан в output.txt!\n");

    Ochistka(&A, na);
    Ochistka(&B, nb);

    return 0;
}
