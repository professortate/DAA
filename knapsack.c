#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knap(int n, int* w, int* value, int m, int* v) {
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = m; j >= w[i]; j--)
            v[j] = max(v[j], value[i] + v[j - w[i]]);
    return v[m];
}

int main() {
    clock_t starttime, endtime;
    double clk;
    int n, i, m, result;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int* w = malloc((n + 1) * sizeof(int));
    int* value = malloc((n + 1) * sizeof(int));

    printf("Enter the weights of %d items:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    printf("Enter the value of %d items: ", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    int* v = malloc((m + 1) * sizeof(int));
    for (i = 0; i <= m; i++) {
        v[i] = 0;
    }

    starttime = clock();
    result = knap(n, w, value, m, v);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("\nThe table for solving the knapsack problem using dynamic programming is:\n");
    for (i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d\t", v[j]);
        }
        printf("\n");
    }

    printf("Optimal solution for the knapsack problem is %d\n", result);
    printf("Time taken: %f seconds\n", clk);

    free(w);
    free(value);
    free(v);

    return 0;
}
