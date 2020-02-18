#include <iostream>
#include <cstring>

namespace demo {
char* strstr(const char *str,const char *substr)
{
    if (str == NULL || substr == NULL) {
        std::cout << "error NULL\n";
        return NULL;
    }
    if ( strlen(str) < strlen(substr)) {
        return NULL;
    }
    char *cp = str;
    char *subcp = substr;
    while (*cp != '\0') {
        while(*cp && *subcp && !(*cp-*subcp)) {
            subcp++;
        }
    cp++;
    }
}
}
int main()
{
    std::cout <<< demo::strstr("aaabccc", "b") << std::endl;
}