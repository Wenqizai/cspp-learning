#include <stdio.h>
#include <limits.h>

/*
	Determine whether arguments can be without overflow
*/
int tsub_ok(int x, int y) {
	int sub = x - y;
    int sub = x - y;

    // Check for positive overflow
    int pos_overflow = (x > 0 && y < 0 && sub < x) || (x == 0 && y == INT_MIN);

    // Check for negative overflow
    int neg_overflow = x < 0 && y > 0 && sub > x;
	 
    return !(pos_overflow || neg_overflow);
}