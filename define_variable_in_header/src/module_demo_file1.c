#include "module_demo_file1.h"
#include "share.h"
#include "stdio.h"

/*
 c99 standard draft 
 A declaration of an identifier for an object that has file scope without an initializer, and
 without a storage-class specifier or with the storage-class specifier static, constitutes a
 tentative definition. If a translation unit contains one or more tentative definitions for an
 identifier, and the translation unit contains no external definition for that identifier, then
 the behavior is exactly as if the translation unit contains a file scope declaration of that
 identifier, with the composite type as of the end of the translation unit, with an initializer
 equal to 0
*/

/*
_ _LINE_ _
_ _FILE_ _
_ _DATE_ _
_ _TIME_ _
_ _STDC_ _
_ _cplusplus // c++特有的 前五个都是标准C的
*/

int functionA(void) 
{
    g_handle = 100;
    printf("In [%s:%s] &g_handle == [%p] g_handle == [%d]\n", __FILE__, __FUNCTION__, &g_handle, g_handle);
    return 0;
}
