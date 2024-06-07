#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int a[100], int length);

int main() {
   int n;
   int a[100];
   double clk;
   clock_t starttime, endtime;
   printf("Enter the number of elements:");
   scanf("%d",&n);
   printf("The elements are:\n");
   for(int i=0; i<n;i++){
   // Generate a random number between 100000000 and 999999999 (inclusive)
    a[i]=rand()% 900000000 + 100000000;
    printf("%d\t\n",a[i]);
    }
    starttime =clock();    
    insertion_sort(a, n);
    endtime= clock();
    clk=(double) (endtime -starttime)/CLOCKS_PER_SEC;
    printf("The sorted elements are:\n");
    for (int i = 0; i < 8; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("The run time is %f seconds\n",clk);
    return 0;
}

void insertion_sort(int a[], int length) {
    for (int i = 1; i < length; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
