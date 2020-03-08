/* 
Big Endian Byte Order: 
  The most significant byte (the "big end") of the data is placed at the byte with the lowest address. The rest of the data is placed in order in the next three bytes in memory.

Little Endian Byte Order:
  The least significant byte (the "little end") of the data is placed at the byte with the lowest address. The rest of the data is placed in order in the next three bytes in memory.
*/
#include <cstdio>
#include <cstdint>
#include <iostream>
#ifdef linux
#include <endian.h>
#endif
void demo1(void)
{
    int a = 0x04030201;
    int b = 0x0400;
    char *p = (char *)&a;
    // on the little endian machine 
    //a is low address 01 02 03 04  hight address
    //b is low address 00 04 00 00  hight address    
    for(int i = 0; i < 4; i++)
    //%0n means at least n bits,if not enough the put some 0 on the left
    printf("%02X ", *(p + i));
    p = (char *)&b;
    for(int i = 0; i < 4; i++)
    printf("%02X ", *(p + i));
    
}
#ifdef linux
// from man page on linux man endian
void demo2(void)
{
  union {
    uint32_t u32;
    uint8_t array[4];
  } x;

  x.array[0] = 0x11;    /* Lowest-address byte */
  x.array[1] = 0x22;
  x.array[2] = 0x33;
  x.array[3] = 0x44;    /* Highest-address byte */

  printf ("x.u32 = 0x%x\n", x.u32);
  printf ("htole32(x.u32) = 0x%x\n", htole32(x.u32));
  printf ("htobe32(x.u32) = 0x%x\n", htobe32(x.u32));
}
#endif
/*return 1: little-endian, return 0: big-endian*/
int checkCPUendian0()
{
  union {
    unsigned int a;
    unsigned char b; 
  } c;
  c.a = 1;
  return ((unsigned int)c.b == 1); 
}
// endtiantest3.c
int checkCPUendian1()
{

    union u_t {
        uint8_t u8;
        uint16_t u16;
        uint32_t u32;
        uint64_t u64;
    } u = { .u8 = 0x4A};

    puts(u.u8==u.u16 && u.u8==u.u32 ? "true" :"false");
    return u.u8==u.u16 && u.u8==u.u32;
}
// from linux-5.4.3\arch\arm\kernel\setup.c 中161行的一个宏，
// 内核中的写法稍有不同稍加修改可以正常编译
int checkCPUendian2()
{
static union { char c[4]; unsigned long l; } endian_test = { { 'l', '?', '?', 'b' } };
#define ENDIANNESS ((char)endian_test.l)
//if ENDIANNESS=='l'  the CPU is little-endian if ENDIANESS=='b' the
//CPU is big-endian
    printf("%ld\n", endian_test.l);
    printf("%lx\n", endian_test.l);
    printf("%c\n", (char)endian_test.l);
    return ENDIANNESS == 'l';
}

int checkCPUendian3()
{
    int a = 1;
    char *p = (char *)&a;
    if (*p == 1)
    printf("Little-endian\n");
    else
    printf("Big-endian\n");
    return *p == 1;
}
// from libcanard/canard.c  不知道确切版本
//refer to gcc online doc  3.7.2 Common Predefined Macros 
bool isBigEndian(void)
{
#if defined(BYTE_ORDER) && defined(BIG_ENDIAN)
  return BYTE_ORDER == BIG_ENDIAN; // Some compilers offer this neat shortcut
  // after search on google find out gcc and clang or boost lib offer some predefined
  // marcos used to determine the endianness
  /*
    __BYTE_ORDER__
    __ORDER_LITTLE_ENDIAN__
    __ORDER_BIG_ENDIAN__
    __ORDER_PDP_ENDIAN__
  */
  /*
    在clang-9.0.1.src\lib\Frontend\InitPreprocessor.cpp 文件734~750行可以看到如下内容
      // Initialize target-specific preprocessor defines.
  // __BYTE_ORDER__ was added in GCC 4.6. It's analogous
  // to the macro __BYTE_ORDER (no trailing underscores)
  // from glibc's <endian.h> header.
  // We don't support the PDP-11 as a target, but include
  // the define so it can still be compared against.
  Builder.defineMacro("__ORDER_LITTLE_ENDIAN__", "1234");
  Builder.defineMacro("__ORDER_BIG_ENDIAN__",    "4321");
  Builder.defineMacro("__ORDER_PDP_ENDIAN__",    "3412");
  if (TI.isBigEndian()) {
    Builder.defineMacro("__BYTE_ORDER__", "__ORDER_BIG_ENDIAN__");
    Builder.defineMacro("__BIG_ENDIAN__");
  } else {
    Builder.defineMacro("__BYTE_ORDER__", "__ORDER_LITTLE_ENDIAN__");
    Builder.defineMacro("__LITTLE_ENDIAN__");
  }
  */
#else
  union {
    uint16_t a;
    uint8_t b[2];
  } u;
  u.a = 1;
  return u.b[1] == 1; // Some don't...
#endif
}
int main(void)
{
    checkCPUendian2();
    return 0;
}

