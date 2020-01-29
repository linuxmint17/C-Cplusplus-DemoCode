/* print triangle according to the input value of n
the following triangle is when n equal 4 the program should print to screen
   *
  * *
 *   *
*******
*/
#include <cstdio>

int main()
{
    int n = 3;
    printf("enter n to get a triangle\n");
    scanf("%d",&n); // get n from user input
    if (n < 3) {
        printf("n should be greater than 3");
        return -1;
    }
    // print the first line
    for (int i = 1; i <= n - 1; i++) {
        putchar(' ');
    }
    putchar('*');
    putchar('\n');

    // print the middle n-2 lines
    for (int i = 2 ; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            putchar(' ');
        }
        putchar('*'); // the left *
        for (int j = 1; j <= 2 * i - 3; j++) {  // between left star and right star ,there are 2 * n - 3 blanks
            putchar(' ');
        }
        putchar('*'); // the right *
        putchar('\n');
    }
    
    // print the last line
    for (int i = 1; i <= 2 * n - 1; i++) {
        putchar('*');
    }
    putchar('\n');
    return 0;
}