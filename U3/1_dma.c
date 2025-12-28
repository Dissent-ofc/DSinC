#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *arr, i, n, m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("Enter the array elements:\n");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter the additional array elements: ");
        scanf("%d", &m);
        arr = (int *)realloc(arr,m);
        printf("Enter the additional elements: ");
        for (i = n; i < n + m; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    printf("The final array elements are:\n");
    for (i = 0; i < n + m; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
}