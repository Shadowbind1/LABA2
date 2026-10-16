#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

void task1()
{
    printf("\n===== ЗАДАНИЕ 1. ИСПОЛЬЗОВАНИЕ ФОРМАТИРОВАНИЯ =====\n\n");

    printf("123\n");

    printf("1\n");
    printf("2\n");
    printf("3\n");

    printf("1\n");
    printf("\t2\n");
    printf("\t\t3\n");

    printf("%1d\n", 1);
    printf("%3d\n", 2);
    printf("%5d\n", 3);
    printf("%7d\n", 4);

    printf("%10.3f\n", 12.234657);
    printf("%10.5f\n", 12.234657);

    printf("Остаток от деления %d на %d равен %d\n",
        5, 2, 5 % 2);

    printf("7 / 5 = %d\n", 7 / 5);
    printf("2000 * 4 = %d\n", 2000 * 4);

    printf("\n--- Спецификаторы формата ---\n");

    printf("%g разделить %e равно %f\n",
        5., 2000000., 5. / 2000000.);

    printf("%f разделить %f равно %f\n",
        5., 2000000., 5. / 2000000.);

    printf("%g разделить %g равно %g\n",
        5., 2000000., 5. / 2000000.);

    printf("%e разделить %e равно %e\n",
        5., 2000000., 5. / 2000000.);
}

void task2()
{
    int N, K;
    time_t currentTime;
    struct tm* localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    if (localTime == NULL)
    {
        printf("Не удалось получить текущее время.\n");
        return;
    }

    N = localTime->tm_hour;
    K = localTime->tm_min;

    printf("\n===== ЗАДАНИЕ 2. ВРЕМЯ =====\n\n");

    printf("Сейчас %d часов %d минут 00 секунд\n", N, K);

    printf("Идет %d минута суток\n", N * 60 + K);

    int minutesToMidnight = 24 * 60 - (N * 60 + K);

    printf("До полуночи осталось %d часов и %d минут\n",
        minutesToMidnight / 60,
        minutesToMidnight % 60);

    int secondsFrom8;

    if (N >= 8)
    {
        secondsFrom8 = (N - 8) * 3600 + K * 60;

        printf("С 8.00 прошло %d секунд\n", secondsFrom8);
    }
    else
    {
        printf("С 8.00 еще не прошло времени\n");
    }

    printf("Текущий час = %.2f суток\n", N / 24.0);
    printf("Текущая минута = %.2f часа\n", K / 60.0);
}

void task3()
{
    int L = 331;
    int n = 2;
    int k = 3;
    int m = 3;

    double result = (double)n / L;

    printf("\n===== ЗАДАНИЕ 3 =====\n\n");

    printf("L = %*d, n = %*d, k = %*d, m = %*d\n%-+10.*f\n",
        3, L,
        3, n,
        3, k,
        3, m,
        m, result);
}

void dz()
{
    double A, K;
    int N;
    double S;

    printf("\n===== ДОМАШНЕЕ ЗАДАНИЕ =====\n\n");

    printf("Введите длину стены A (м): ");

    if (scanf("%lf", &A) != 1 || A <= 0)
    {
        printf("Ошибка: длина стены должна быть положительным числом.\n");
        return;
    }

    printf("Введите цену одного рулона K (руб.): ");

    if (scanf("%lf", &K) != 1 || K < 0)
    {
        printf("Ошибка: цена не может быть отрицательной.\n");
        return;
    }

    N = (int)ceil(A / 2.0);
    S = N * K;

    printf("Количество рулонов: %d\n", N);
    printf("Стоимость обоев: %.2f руб.\n", S);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    task1();
    task2();
    task3();
    dz();

    system("pause");

    return 0;
}