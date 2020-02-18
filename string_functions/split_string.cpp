#include <cstdio>
#include <cstring>

int splitstring(const char *buf1, char c, char buf2[10][30], int *ncount)
{
    char* p = nullptr;
    char* pTmp = nullptr;
    in tmpcount=0;
    p = buf1;
    // 1. p 和 ptmp初始化
    pTmp=buf1;
    do {
        //2 检索符合条件的位置p后移，形成差值挖字符串
        p = strchr(p,c);
        if (p != nullptr) {
            if(p - pTmp > 0) {
                strncpy(buf2[tmpcount], pTmp, p-pTmp);
                buf2[tmpcount][p-pTmp] = '\0';
                tmpCount++;
                //3重新让P和pTmp达到下一次检索的条件
                pTmp = p = p + 1;
            }
        } else {
            break;
        }
    } while(*p!='\0');
    *count = tmpcount;
}

int splitstring1(const char *buf1, char c, char buf2[10][30], int *ncount)
{
    if (buf1 == nullptr||buf2 == nullptr||ncount == nullptr) {
        printf("error\n");
        return -1;
    }
    int count=0;
    char tmp[1024];
    char *p = nullptr;
    int i = 0;
    strcpy(tmp, buf1);
//  strcpy(buf1,tmp);
    if (p=strtok(tmp,&c)) {
        strcpy(buf2[0],tmp);
        count++;
    } else {
        printf("error not found\n");
        return -2;
    }
    while (p = strtok(nullptr, &c)) {
        strcpy(buf2[1+i],p);
        i++;
        count++;
    }
  
    *ncount = count;
    return 0;
}

int main()
{
    int ret = 0,i = 0;
    char *p1="abcdef,acccd,eeee,aaaa,e3eeeee,ssss,";
    char cTem=',';
    int nCount=0;
    char mArray[10][30];
    ret = splitstring(p1,cTem,mArray,&nCount);
    if (ret < 0) {
        printf("error call splitstring\n");
        return 0;
    }
        printf("count=%d\n",nCount);
    for (i = 0;i < nCount;i++) {
        printf("%s\n", mArray[i]);
    }
    return 0;
}
