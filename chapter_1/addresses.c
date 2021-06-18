#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    double y = 3.0;

    printf("x=%d\n",x);
    printf("y=%lf\n",y);

    printf("The address of x is: %p\n",&x);
    printf("The address of y is: %p\n", &y);

    return 0;
}

