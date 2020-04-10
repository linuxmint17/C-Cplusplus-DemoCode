#include "stdio.h"
#include "stdlib.h"
// puts apples  into buckets ,  there can exist empty buckets , but buckets and apples are no difference.
int apple2bucket(int apples ,int buckets)
{
    //if only one apple or one bucket , only one solution.
    // if (buckets == 1 ||  /* apples == 0 || */  apples == 1) {
    if (buckets == 1 ||  apples == 0 ||  apples == 1) {
        return 1;
    }
    if (apples >= buckets) // no empty buckets 
        return apple2bucket(apples - buckets, buckets) + apple2bucket(apples, buckets-1);
    else 
        return apple2bucket(apples, apples);
}
int main(int argc, char **argv)
{
  if (argc != 3) {
      return -1;
  }
  int a = atoi(argv[1]), b = atoi(argv[2]);
 // scanf("hellO%d%d",&a,&b);
 //scanf("%d%d",&a,&b);
 // printf("%d,%d",a,b);
 printf("%d\n",apple2bucket(a, b));
 // system("pause");
}
// 7 apples 3 buckets  ps: this case can the put to the case apples >= buckets
/* 1. 0 个空bucket，each bucket put one apple , 
        then we get 4 apples 3 buckets to deal with: this is the #subproblem
   2. 1 个空bucket, two 
        problem become : 5 apples 2 buckets  #subproblem
        7 = a+ b ,a,b>0  a>=b
   3. 2 个空bucket
        problem become : buckets = 1, only on solution ,this is one special case
*/
// 4 apples 3 buckets
/*
  1. 0个空的,each bucket put one apple , 
     left 1 apples 3 buckets
     
  2. 1个空的
     4 apples 2 buckets subproblem
     
  3  2个空的
     4 apples 1 buckets subproblem
*/
/*
  1.  1 apples 1 buckets
     return 1
  
*/
/*
  不能全空，全空就没有地方放苹果了
    4 apples 2 buckets 
  1. 0个空的  
     become 2 apples 2 buckets #subproblem
  1. 1个空的
     return  1 
*/
/*2 apples 2 buckets
 1.  0个空的
     become 0 apples 0 buckets #subproblem 
 2.  1个空的
     become 2 apples 1 buckets #subproblem
     1个桶只能有一种方法
 
*/

/* 1. 不存在空的 bucket，every bucket at least one apple , 
        then we get （apples-buckets）apples （buckets）buckets to deal with:
        this is the #subproblem 
   2. 存在空bucket, <=>at least on bucket is empty , we dont care or don't konw what to deal with the reset buckets
        problem become : （apples）apples （buckets-1）buckets  #subproblem
   then 1+ 2 is the apples >= buckets 的解
*/
/*
  化未知为已知，从特殊到一般
  分类解决，逐个击破
  边界情况要考虑清楚
*/

// this is a good blog
// https://blog.csdn.net/u012283461/article/details/52761238
 // install command
// 算法是什么
// 是 做成某事的确定步骤 和 出现的比计算机要早 ，比如说 gcd 算法，只不过计算机的出现，给算法增加了威力赋能了
// 赋能 是神马意思？
// 使用计算机编写算法 是 个翻译的过程
// 1 首先要会用自然语言表述问题的解法 或者能够手动解决某类问题的一些情况，然后从中归纳（提取）出通用的部分，就是算法
// 2 把你将来 重复干的事（算法）交给计算机去干，将你的理解使用特定的计算机语言 描述出来，让计算机为你工作
// fedora 30
// man core 
// echo "core%e.%p" >/proc/sys/kernel/core_pattern 生成 core file used to debug
