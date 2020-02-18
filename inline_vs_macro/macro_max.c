#include "stdio.h"

#define MAXOFTWO(num1, num2) (((num1) > (num2)) ? (num1) : (num2))

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int max = MAXOFTWO(num1, num2);
    printf("max of two is [%d]", max);
}
