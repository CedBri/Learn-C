#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 7;
    printf("Value of x: %d\n", x);
    
    // Defining pointer
    int *ptr = &x;
    printf("Pointer value: %x\nAddress of x: %x\n", ptr, &x);

    *ptr = 10;
    printf("Value of x is now: %d\n", x);
    printf("Pointer value: %x\nAddress of x: %x\n", ptr, &x);
    return 0;
}
