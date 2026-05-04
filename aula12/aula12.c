#include <stdio.h>

int main()
{
    int a = 1;

    switch (a)
    {
    case 1:
        printf("\nA = 1");
        break;
    case 2:
        printf("\nA = 2");
        break;
    case 3:
        printf("\nA = 3");
        break;
    case 4:
        printf("\nA = 4");
        break;
    case 5:
        printf("\nA = 5");
        break;
    default:
        printf("\nA= %d", a);
        break;
    }

    printf("\n\n\n\n\n");
    return 0;
}