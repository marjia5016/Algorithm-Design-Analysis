
#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[] = {42, 16, 75, 8, 31, 59, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array Before Sorting: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nArray After Sorting:  ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
