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
printf("You are %lf years old.\n",age);
}
```

# Arrays
An array can be thought of as a groupe of variables of the same type.
```C
int name[size];
```
To avoid having the array filled with garbage data and fill it with 0's' when first allocating it we can use:
```C
int name[size] = {};
```
We can also initialize the array with data by putting the values in order inside `{}`.
```C
int name[5] = {1,2,3,4,5}
```

#### 2D arrays
We can initialize a 2D array using:
```C
int my_2d[3][2] = {};
/*
In this case the array would look like
[0][0]
[0][0]
[0][0]
*/
```
The first number is the rows, the second is the columns.

To populate a 2D array when it's initialize we can use a similar structure as the 1D array.
```C
int my_2d[3][2] = {
    {1,2},
    {3,4},
    {5,6}
};
```

#### Array addresses
If we print the address of the first element and the address of the whole array we can see it's the same.
```C
int my_arr[5] = {1,2,3,4,5};
printf("%p %p", %my_arr[0], my_arr);
// Would return 0x7ffc35879690 0x7ffc35879690 for example
```

# String (char arrays)
A string is actually an array of chars.

To initialize a string we can use:
```C
char firstName[] = {"CedBri"}
```
A string always ends with a Null Terminator (`\0`).

To initialize an empty string (avoid having it filled with garbage) we can do:
```C
char firstName[5] = {};
```
Which will fill it with Null terminators.

We can also import "string tools" by `#include`-ing `<string.h>`.

`string.h` contains many utilities like `strlen()` which outputs the length of the string.
More info [here](https://www.tutorialspoint.com/c_standard_library/string_h.htm).

To copy a string using
```C
char og_string[7] = "CedBri";
char copy_string[7] = og_string;
```
Will throw an error. Hence why we use:
```C
char og_string[7] = "CedBri";
strcpy(copy_string,og_string);
```
We can also concatenate 2 strings using 
```C
strcat(string1,string2);
```
Finally we use `strcmp()` to compare strings.
```C
strcmp(string1,string2);
//if both strings are the same it will return 0
//if not it returns anything else
```
#### <ctype.h>
Thanks to `ctype.h`, we get access to these functions:
- `isalpha()` to check if the char is in the alphabet
- `isnum()` to check if the char is a number
- `isalnum()` to check if the char is alphanumerical
- `islower()` to check if the char is lowercase
- `isupper()` to check if the char us uppercase
- `tolower()` to make the char lowercase
- `toupper()` to make string uppercase
And much more [here](https://www.tutorialspoint.com/c_standard_library/ctype_h.htm)

To convert a whole string to lowercase for example we could use:
```C
#include <ctype.h>
char badStr[] = {"MyBadCase"};
for(int i = 0;i < strlen(badStr);i++){
    if(isupper(badStr[i])){
        badStr[i] = tolower(badStr[i]);
    }
}
```

# Operators
- `=` is an assignment operator
- arithmetic operators
    * `+` for additions
    * `-` for substractions
    * `/` for divisions
    * `*` for multiplications
    * `%` for modulo operations (returns the remainder of the division)
    * `!` not
- compound assignment operators
    * `+=` adds(`a += 2` = `a = a + 2`)
    * `-=` substracts
    * `*=` multiplies with the original variable (`a *= 2+3` = `a = a*(2+3)`)
- `++` increments
- `--` decrements
- relationals operators
    * `==` checks for equality
    * `!=` not equal
    * `>` greater than
    * `<` smaller than
    * `>=` greater or equal
    * `<=` smaller or equal
- logical operators
    * `&&` and
    * `||` or
- `sizeof` or `sizeof` operator lets us see the data type or variable size in bytes
- operator precedence
    * PEDMAS

# Control flow
#### If/else statement
The default if statement resembles this:
```C
if(condition){
    something();
}
else{
    somethingelse();
}
```
#### Switch
The default switch statement resembles this:
```C
switch(var){
    case condition:
        printf("bla");
        break;
    case condition2:
        printf("bla2");
        break;
    default: // if none of the conditions are matched
        printf("default");
};
```

#### Ternary operator

Say we have this code which will return the biggest number of x and y:
```C
int x = 4;
int y = 10;
max = 0;

if(x > y){
    max = x;
}
else{
    max = y;
}
return max;
```
Instead of doing a if/else statement like this we can use ternary operator `?`

The code turns into this:
```C
int x = 4;
int y = 10;
int max = (x > y) ? x:y;
```
In this case we declare x and y. With the ternary operator we then evaluate the result of `x > y`.
If the result is true, it will then get assigned to x (`operation returns true : operation returns false`) otherwise it gets assigned y.
