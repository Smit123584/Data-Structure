#include <stdio.h>

void callByValue(int a, int b)
{
    int temp;

    // a ane b ni value swap karva mate temporary variable vapray chhe.
    temp = a;
    a = b;
    b = temp;

    printf("\nInside call by value:\n");
    printf("a = %d, b = %d\n", a, b);
}

void callByReference(int *a, int *b)
{
    int temp;

    // Pointer thi original values ne swap karvani.
    temp = *a;
    *a = *b;
    *b = temp;

    printf("\nInside call by Reference:\n");
    printf("a = %d, b = %d\n", *a, *b);
}

int main()
{
    int x, y;

    printf("Enter two numbers:");
    scanf("%d%d", &x, &y);

    printf("\nBefore Function call:\n");
    printf("x = %d, y = %d\n", x, y);

    callByValue(x, y);

    printf("\nAfter call by value:\n");
    printf("x = %d, y = %d\n", x, y);

    callByReference(&x, &y);

    printf("\nAfter call by Reference:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}