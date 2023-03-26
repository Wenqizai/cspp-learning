#include <stdio.h>

int main() {}

int frist(int x) { return !~x; }

int second(int x) { return !x; }

/** ~0xff = 0xffffff00*/
int third(int x) { return !~(x | ~0xff); }

int four(int x) { return !!~(x | 0x00ffffff); }