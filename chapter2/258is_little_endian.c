#include <stdio.h>

typedef unsigned char *byte_pointer;

int main()
{
    int num = 12345;
    byte_pointer p = (byte_pointer)&num;
    if (p[0] == 0x39)
    {
        printf("Little Endian\n");
        return 1;
    }
    else
    {
        printf("Big Endian\n");
        return 0;
    }
}