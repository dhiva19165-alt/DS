#include <stdio.h>

void insertionSort(int arr[], int n) {

    int i, key, j;

    for (i = 1; i < n; i++) {

           key = arr[i];

           j = i - 1;

           while (j >= 0 && arr[j] > key) {

               arr[j + 1] = arr[j];

               j--;

           }

           arr[j + 1] = key;

    }

}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++)

    printf("%d ", arr[i]);

    printf("\n");

}

int main() {

    int choice, n, i;

    printf("\n-------INSERTION SORT \n ");

    printf("Enter the number of elements: ");

    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements are :\n", n);

    for (i = 0; i < n; i++)

   scanf("%d", &arr[i]);

    printf("\nArray before sorting:\n");

    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nArray after sorting:\n");

    printArray(arr, n);

    return 0;

}
