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
    int na, ma, nb, mb;

    do {
        printf("Введите количество строк N массива A: ");
        scanf("%i", &na);
        if (na <= 1 || na > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (na <= 1 || na > 100);

    do {
        printf("Введите количество столбцов M массива A: ");
        scanf("%i", &ma);
        if (ma <= 1 || ma > 100) {
            printf("Ошибка! M должно быть больше 1 и не больше 100.\n");
        }
    } while (ma <= 1 || ma > 100);

    do {
        printf("Введите количество строк N массива B: ");
        scanf("%i", &nb);
        if (nb <= 1 || nb > 100) {
            printf("Ошибка! N должно быть больше 1 и не больше 100.\n");
        }
    } while (nb <= 1 || nb > 100);

    do {
        printf("Введите количество столбцов M массива B: ");
        scanf("%i", &mb);
        if (mb <= 1 || mb > 100) {
            printf("Ошибка! M должно быть больше 1 и не больше 100.\n");
        }
    } while (mb <= 1 || mb > 100);

    int **A = NULL, **B = NULL;
    Create(&A, na, ma);
    Create(&B, nb, mb);

    Vvod(inA, &A, na, ma);
    Vvod(inB, &B, nb, mb);

    int ka = kol_otr(A, na, ma);
    int kb = kol_otr(B, nb, mb);

    FILE *out = fopen("output.txt", "w");

    fprintf(out, "Исходный массив A:\n");
    Vivod(out, &A, na, ma);
    fprintf(out, "Исходный массив B:\n");
    Vivod(out, &B, nb, mb);
    fprintf(out, "==================================\n");

    if (ka > 0 && kb == 0) {
        int sa = sum_otr(A, na, ma);
        fprintf(out, "Отрицательные элементы вне главной диагонали есть только в A (сумма = %i)\n", sa);
        fprintf(out, "В массиве B таких элементов нет, сравнение невозможно\n");
    }
    else if (kb > 0 && ka == 0) {
        int sb = sum_otr(B, nb, mb);
        fprintf(out, "Отрицательные элементы вне главной диагонали есть только в B (сумма = %i)\n", sb);
        fprintf(out, "В массиве A таких элементов нет, сравнение невозможно\n");
    }
    else if (ka > 0 && kb > 0) {
        int sa = sum_otr(A, na, ma);
        int sb = sum_otr(B, nb, mb);
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
