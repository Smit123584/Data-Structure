#include <stdio.h>

int main()
{
    int arr[100], n;
    int *ptr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Array na last element par pointer set karo
    ptr = arr + n - 1;

    printf("Array elements in reverse order are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d", *ptr);
        ptr--;
    }

    return 0;
}