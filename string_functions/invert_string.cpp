#include <cstdio>
#include <cstring>

// 双指针
void inverse(char *p)
{
    if (p == NULL) {
        return;
    }
    char *head = NULL;
    char *tail = NULL;
    head = p;
    tail = p + strlen(p) - 1;
    char tmp;
    while (head < tail) {
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }
}

// 递归版本
void inverse(const char *src, char *dst)
{
    if (src == NULL || dst == NULL) {
        return;
    }
    if (*src == '\0') {
        return;
    }
    inverse(src + 1, dst);
    strncat(dst, src, 1);
}

int main()
{
    const char *src = "1234567890abcdefghijklmnopqrstuvwxyz";
    char dst[27]= { 0 };
    inverse(src, dst);
    puts(dst);
//    memcpy((void *)dst, (void *)src, sizeof("1234567890abcdefghijklmnopqrstuvwxyz"));
    inverse(dst);
    puts(dst);
    return 0; 
}

