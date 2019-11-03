#include "module_demo_file2.h"
#include "share.h"
#include "stdio.h"

int functionB(void) 
{
    g_handle = 200;
    printf("In [%s:%s] &g_handle == [%p] g_handle == [%d]\n", __FILE__, __FUNCTION__, &g_handle, g_handle);
    return0;
}
