#include "stdio.h"
inline int maxOfTwo(int num1, int num2)
{
   return (num1 > num2) ? num1 : num2; 
}
int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    int max = maxOfTwo(num1, num2);
}
