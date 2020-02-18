static inline void demoinline(int a, int b)
{ 
    int c = a + b;
    printf("c=%d", c);
}
int a;
//extern inline void demoinline(int a, int b)
//static inline void demoinline(int a, int b)
//to compile it under gcc  define it in hedear files as static
/*
inline void demoinline(int a, int b)
{
    int c = a + b;
    printf("c=%d", c);
}
*/
/*
Arithmetic types and pointer types are collectively called scalar types. Array and
structure types are collectively called aggregate types. 37)
*/
int test()
{
    int b =300;

//extern inline void demoinline(int a, int b);
    demoinline(a, b);
    demoinline(a+1, b++);
}
//reentrant functions
//Multi Thread Safe  MT-Safe
/*
C++
Names of functions, classes, templates, variables, namespaces, enumerations, and enumerators
must be used consistently across all translation units unless they are explicitly specified to be local
By default, const objects (§7.5), constexpr objects (§10.4), type aliases (§6.5), and anything
declared static (§6.3.4) in a namespace scope have internal linkage
*/

/*
about inline functions  in c / c++
it should be consist 
should be define in header , note define not declaration

use inline functions is different corss different compliers such as gcc and clang 

sometimes the problems answer are from the compiler's manual
*/