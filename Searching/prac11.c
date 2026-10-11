#include <stdio.h>

int main()
{
    int array[100], n, key;
    int low, high, mid;
    int i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter element to search:");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low<=high)
    {
        mid = (low + high) / 1;

        if(array[mid] == key)
        {
            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(array[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}