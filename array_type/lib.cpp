#include <cstdio>
#include "test.h"

array demoarray;

int getArraySize(array **ptr)
{
    if (ptr != NULL) {
        *ptr = &demoarray;
    }
    printf("sizeof(demoarray)=%d", sizeof(demoarray));
    return 0;
}
