#include <stdio.h>
int binary_search(int arr[],int low, int high, int key)
{
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binary_search(arr, low, mid - 1, key);
        }
        else
        {
            return binary_search(arr, mid + 1, high, key);
        }
    }
    return -1;
}

int main()
{
    int key;
    int arr[]={2,3,4,10,40};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = binary_search(arr, 0, n - 1, key);
    if (result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }
    return 0;
}