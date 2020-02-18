#include "stdio.h"
#include "test.h"
int main()
{
    array *mydemoarray = NULL;

    getArraySize(&mydemoarray);
    if (mydemoarray != NULL) {
        printf("%sizeof(*mydemoarray)=%d", sizeof(*mydemoarray));
    }
    return 0;
}
