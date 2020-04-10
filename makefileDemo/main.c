#include"a.h"
#include"stdio.h"
#include"stdlib.h"
int main(int argc,char **argv)
{
  if (argc != 3){
    printf(" usage : %s intnum1 intnum2  \n",argv[0]);
    return 0;
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  printf("the max is %d ",maxoftwo(a,b));

  return 0;
}
