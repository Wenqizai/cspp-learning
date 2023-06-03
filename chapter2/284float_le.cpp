/*
 * float-le.c 不懂
 */
#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
    return *(unsigned*)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    unsigned ex = ux << 1 >> 23;
    unsigned ey = uy << 1 >> 23;

    // +-0情况
    if ((ex & ey) == 0) {
        return 1;
    }

    // x 负数 y 正数
    if (sx > sy) {
        return 1;
    }

    // x, y 正数
    if (sx == 0) {
        return ux - uy;
    }

    // sx == 1 =>  x,y 负数
    return !(ux - uy);


    //// ref: https://github.com/DreamAndDead/CSAPP-3e-Solutions/issues/1
    //return (ux << 1 == 0 && uy << 1 == 0) || /* both zeros */
    //    (sx && !sy) ||                         /* x < 0, y >= 0 or x <= 0, y > 0 */
    //    (!sx && !sy && ux <= uy) ||            /* x > 0, y >= 0 or x >= 0, y > 0 */
    //    (sx && sy && ux >= uy);                /* x < 0, y <= 0 or x <= 0, y < 0 */
}

int main(int argc, char* argv[]) {
    int res = f2u(3.14);

    assert(float_le(-0, +0));
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4, -0));
    assert(float_le(-4, 4));
    return 0;
} 