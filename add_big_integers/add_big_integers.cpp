// 正大数整数相加 数组实现
#include <cstdio>
#include <cstring>

const int MAX_LEN = 15;

// if there is a '\0' in string 
void reverse(char *str, int len)
{
    // 数组下标从0开始，到strlen() - 1结束
    int i = len - 1;
    int j = 0; 
    char tmp[MAX_LEN] = {0};
    char *p = str;
    while (i >= 0) {
        tmp[j++] = str[i--];
    }
    tmp[++j] = '\0';
    i = 0;
    while (*p = tmp[i]) {
        i++;
        p++;
    }
    p++;
    *p = '\0';
}

void reverse(char *str)
{
    int i = strlen(str) - 1;
    int j = 0; 
    char tmp[MAX_LEN]={0};
    char *p = str;
     while (i >= 0) { // i-- must after the copy operation 
        tmp[j++]=str[i];
        i--;
    }
    tmp[++j] = '\0';
    i = 0;
    while (*p=tmp[i]) {
        i++;
        p++;
    }
}

int big_number_add(char a[], char b[], char result[])
{
    int val = 0;
    int carry = 0;
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;

    while (i >= 0 && j >= 0) {
        val = (a[i] - '0') + (b[j]- '0') + carry;
        result[k] = val % 10 + '0';
        carry = val / 10;
        i--;
        j--;
        k++;
    }
    // 两个数字的位数相同,计算完成判断一下有没有进位直接返回
    if (i == j) {
        result[k] = carry + '0';
        result[++k] = '\0';
        reverse(result);
        return 0;
    }
    char *p = i > j ? a : b;
    int t = i > j ? i : j;
    for (;t>=0;t--) {
        val = p[t] - '0' + carry;
        result[k] = val % 10 + '0';
        carry = val / 10;
        k++;
    }
    if (carry > 0) {
        result[k++] = carry + '0';
    }
    result[k] = '\0';
    reverse(result);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        puts("need three parameters\n");
        return -1;
    }

    char a[MAX_LEN] ={'\0'};
    char b[MAX_LEN] ={'\0'};
    char result[MAX_LEN+1]={'\0'};
    strcpy(a, argv[1]);
    strcpy(b, argv[2]);

    big_number_add(a, b, result);
    for (int i = 0; i < MAX_LEN + 1; i++) {
        putchar(result[i]);
    }
    putchar('\n');
    return 0;
}
