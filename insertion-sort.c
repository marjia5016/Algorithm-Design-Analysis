
#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {38, 15, 72, 6, 49, 21, 84};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array Before Sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);

    printf("\n\nArray After Sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
