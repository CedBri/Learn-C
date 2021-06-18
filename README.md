# Chapter 1: basic definition of a function & comments


## General definition of a function
A default function would be defined as such:
```C
#include <stdio.h>
#include <stdio.h>
// This is my first comment
int main(){
    printf("Hello world!\n");
    return 0;
}
```
#### Function type
In this example, `int` is the **type** of the function and `main` is the function name.

#### Main
`main` is **always** the main function of the program. (As stupid as it sounds this is important)

#### Statements
A "line" that ends with a semi-colon is refered to as a **statement**.

#### Return
When the program has normally finished and no errors has occured it should return 0.

#### Comments
A single line comment can be done by using `//` before it.

A multiline comment can be used by typing:
```C
/*
This is a multiline comment
as you can see
*/
```

# Chapter 2: The build process
By default, when compiled, the compiler will generate `a.out`.

An example would be:
>clang skeleton.c

Or
>gcc skeleton.c

To specify an output executable name we would use:
>gcc skeleton.c -o skeleton

Or
>clang skeleton.c -o skeleton

# Chapter 3: Variables and data types

#### Declarations
When declaring a variable, the type should always be indicated.

```C
// type name = var;
int my_int = 0;
double my_dub = 3.5;
char c = 'A'; // Characters are always defined between single quotes
char my_str[] = "This is a string.\n";
_Bool b = 0; // 0 = false, 1 = true
/* To use 'true' and 'false' we need to import stdbool.h
```

Memory will by default be stored in RAM.

#### Assignment
An assignment is when you change the value of the variable.
Note: by casting 3.5 to a var typed as int it will be converted to 3. (Rounding down)

# Constants and Addresses
Example code for this chapter:
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    double y = 3.0;

    printf("x=%d\n",x);
    printf("y=%d\n",y);

    // Print the addresses
    printf("The address of y in memory is: %d", &y); // Use & to get the address

    return 0;
}
```
We can define a constant variable using `const`.
```C
const int = 30;
```
We can also define constants with the `#define` tag.
```C
#define PI 3.14
```

# Input and output

#### Output
To output text, we use `printf("something")`.

To print values, we need to use **format specifiers**.

Here is a short list of format specifiersL
- `%c` for charachters
- `%d` and `%i` for decimals and integers
- * `%d` assumes it's an integer while `%i` auto-detects the decimal type.
- `%u` for unsigned integers (0-4294967296)
- `%f`, `%e` and `%E` for floating-points
- * `%f` for the "fractional form" (1.000001)
- * + We can also specify the number of decimals after the `.` to use by doing
`printf('n=%.2f')` to use 2 decimal after the dot for example.
- * `%e`and `%E` for the "exponential form" (1.1e+6)
- `%o` for octals
- `%x` or `%X` for hexadecimals
- `%s` for strings
- `%p` for address printing (as seen above)

We can also print multiple variables in the same `printf()` by adding a comma and the variable name.
```C
int main() {
    int x = 3;
    double y = 3.5;
    
    printf("Value of x is: %d\nValue of y is %lf",x ,y);
    
    return 0;
}
```

#### Input
**scanf()**
`scanf` lets us get user input.

The two default arguments `scanf` takes are the "string type" and the address of where to store the value at.
```C
int main() {
double age;
printf("Enter your age: ");
scanf("%lf", &age);
printf("You are %lf years old.\n",age)
}
```
