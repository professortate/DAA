#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int partition(int a[], int low, int high) {
    int i = low + 1, j = high, temp, pivot = a[low];
    while (1) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}

void quick_sort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

int main() {
    int i, n;
    int a[200000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records: \n");
    scanf("%d", &n);

    if (n > 200000) {
        printf("Number of records exceeds the maximum allowed size (200000).\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("The roll numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    starttime = clock();
    quick_sort(a, 0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Sorted roll numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
