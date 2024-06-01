#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, a[1000], key, bottom, top, mid, j, temp;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of Products\n");
    scanf("%d", &n);

    // Generating random product IDs and displaying them
    printf("The Product IDs are: \n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    // Bubble Sort to sort the array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Display the sorted product IDs
    printf("Sorted Product ID List is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Reading the key to be searched
    printf("Enter the Product ID to be searched:\n");
    scanf("%d", &key);

    // Binary Search
    starttime = clock();
    bottom = 0;
    top = n - 1;
    while (bottom <= top) {
        mid = (bottom + top) / 2;
        if (key < a[mid]) {
            top = mid - 1;
        } else if (key > a[mid]) {
            bottom = mid + 1;
        } else {
            printf("Product found!!\n");
            printf("Product %d found in position: %d\n", key, mid + 1);
            break;
        }
    }
    if (bottom > top) {
        printf("Search failed\n%d not found\n", key);
    }
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The run time is %f seconds\n", clk);

    return 0;
}
