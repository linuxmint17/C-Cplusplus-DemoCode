#include <cstdio>

// want  value var from 0 to 10 [0,10]
int main()
{
    const int MAX_VALUE = 10;
    int value = 5;
    int flag = 1;
    printf("enter 1 or 2 alter value enter 3 to exit\n");
    while(flag) {
        scanf("%d", &flag);
        if (flag == 1) {
            value = ((value % (MAX_VALUE + 1)) + 1) % (MAX_VALUE + 1);
            printf("value =%d\n", value);
        } else if (flag == 2) {
            // value = (value - 1 + MAX_VALUE + 1) % (MAX_VALUE + 1);
            value = (value + MAX_VALUE) % (MAX_VALUE + 1);
            printf("value =%d\n", value);
        } else if (flag == 3) {
            break;
        }
    }
    return 0;
}