#include <stdio.h>

int main()
{
    int n, target;
    int foundIndex = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (numbers[mid] == target)
        {
            foundIndex = mid;
            break;
        }
        else if (numbers[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (foundIndex != -1)
    {
        printf("%d was found at index %d\n", target, foundIndex);
    }
    else
    {
        printf("%d was not found.\n", target);
    }

    return 0;
}
