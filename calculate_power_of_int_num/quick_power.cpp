#include <iostream>
#include <cstring>
using namespace std;

// 非递归版本，for 循环求幂 时间复杂度 过高无法通过 OJ
long int quick_power(int A, int n)
{
    if (n == 0) return 1;
    long int rslt = 1;

    while (n) {
        // 如果n为奇数
        if (n & 1) {
            rslt *= A;
        }
        // 偶数的时候base 直接相乘，指数减半， 2^10 = 4^5  , result = 4*(4^4) , 4^4 = 16^2, 16*16  1--->0
        A *= A;
        n >>= 1;
    }
    return rslt;
}

int main(int argc,char **argv)
{
    if (argc != 3) {
        cout << "program need two parameters like " << argv[0] <<" 2 3" << endl;
        return 0;
    }
    cout << quick_power(atoi(argv[1]),atoi(argv[2])) <<endl;
}