#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 500000
int a[MAX_SIZE];

void insertion_sort(int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        // Move elements of a[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("INSERTION SORT\n");
    printf("Enter the number of employee records:\n");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Number of records exceeds the maximum allowed size (%d).\n", MAX_SIZE);
        return 1;
    }

    srand(time(0)); // Initialize random seed

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("The Employee IDs are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    starttime = clock();
    insertion_sort(n);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Employee IDs in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
