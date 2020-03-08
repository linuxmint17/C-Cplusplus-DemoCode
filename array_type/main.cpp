#include <cstdio>
#include "lib.h"

int main()
{
    array *mydemoarray = nullptr;

    getArraySize(&mydemoarray);
    if (mydemoarray != nullptr) {
        printf("%sizeof(*mydemoarray)=%d", sizeof(*mydemoarray));
    }
    return 0;
}
