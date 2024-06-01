#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SIZE 500000
int a[MAX_SIZE];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int b[high - low + 1];

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= high) {
        b[k++] = a[j++];
    }
    for (i = low, k = 0; i <= high; i++, k++) {
        a[i] = b[k];
    }
}

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records:\n");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Number of records exceeds the maximum allowed size (%d).\n", MAX_SIZE);
        return 1;
    }

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("The Employee IDs are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Employee IDs in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
