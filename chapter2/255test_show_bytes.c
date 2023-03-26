#include "show_bytes.h"

int main()
{
    test_show_bytes(12345);
    return 0;
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}