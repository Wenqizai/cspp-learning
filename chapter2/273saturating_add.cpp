#include <stdio.h>
#include <limits.h>

/*
	Addition that saturates to TMin or TMax
*/
int saturating_add(int x, int y) {
    int sum = x + y;

    // Check for positive overflow
    if (y > 0 && sum < x) {
        return INT_MAX;  // TMax
    }

    // Check for negative overflow
    if (y < 0 && sum > x) {
        return INT_MIN;  // TMin
    }

    // No overflow, return the sum
    return sum;
}