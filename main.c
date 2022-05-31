#include <stdio.h>

int myfunc(int x, int y)
{
    int z;

    z = 2 * x - y;
    return z;
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b, c;

    printf("c=%d, a1=%d, a5=%d\n", c, a[1], a[5]);
    c = a[1] + a[5];
    printf("c=%d, a1=%d, a5=%d\n", c, a[1], a[5]);

    printf("b=%d, c=%d, a1=%d\n", b, c, a[1]);
    b = c + a[1];
    printf("b=%d, c=%d, a1=%d\n", b, c, a[1]);

    b = myfunc(b, c);

    printf("b=%d\n", b);

    return 0;
}
