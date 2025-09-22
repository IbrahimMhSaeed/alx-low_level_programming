# C Programming Notes

This document introduces three important topics in C programming: **functions**, **header files**, and **function prototypes**.  

---

## 1. Write Function

A **function** in C is a block of code designed to perform a specific task. Functions improve code reusability, readability, and maintainability.

### General Syntax
```c
return_type function_name(parameter_list) {
    // body of the function
    // statements
    return value;   // if return_type is not void
}
```

### Example

```c
#include <stdio.h>

// Function definition
int add(int a, int b) {
    return a + b;
}

int main() {
    int sum = add(5, 10);
    printf("Sum = %d\n", sum);
    return 0;
}
```

**Output:**

```
Sum = 15
```

---

## 2. Header Files in C

The `#include` preprocessor directive is used to include **header files** in a program.
Header files contain **function declarations, constants, and macros**, which can be reused across multiple programs.

### Types of Header Files

1. **System Header Files** – provided by the C compiler (e.g., `stdio.h`, `math.h`).

   ```c
   #include <stdio.h>
   ```
2. **User-defined Header Files** – created by programmers, usually in the same project directory.

   ```c
   #include "myheader.h"
   ```

### Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char s1[20] = "53875";
    char s2[10] = "Hello";
    char s3[10] = "World";

    int res = pow(8, 4);  // from math.h
    printf("Using math.h, value: %d\n", res);

    long int a = atol(s1);  // from stdlib.h
    printf("Using stdlib.h, string to int: %ld\n", a);

    strcpy(s2, s3);  // from string.h
    printf("Using string.h, s2: %s\n", s2);

    return 0;
}
```

**Output:**

```
Using math.h, value: 4096
Using stdlib.h, string to int: 53875
Using string.h, s2: World
```

### Common Standard Header Files

| Header File | Description            | Examples                      |
| ----------- | ---------------------- | ----------------------------- |
| stdio.h     | Input/Output functions | `printf()`, `scanf()`, `FILE` |
| stdlib.h    | General utilities      | `atoi()`, `malloc()`          |
| math.h      | Math functions         | `sin()`, `pow()`              |
| string.h    | String functions       | `strcpy()`, `strlen()`        |
| ctype.h     | Character handling     | `isalpha()`, `isupper()`      |
| time.h      | Date/time functions    | `asctime()`, `mktime()`       |

---

## 3. Purpose of a Function Prototype

A **function prototype** tells the compiler:

1. The **return type** of the function.
2. The **number of arguments**.
3. The **types** of arguments.
4. The **order** of arguments.

### Syntax

```c
return_type function_name(parameter_list);
```

### Example

```c
#include <stdio.h>

// Function prototype
void greet();

int main() {
    greet();  // function call
    return 0;
}

// Function definition
void greet() {
    printf("Hello, World!\n");
}
```

### What if a prototype is missing?

* In **C90**, the compiler assumes return type as `int`.
* In **C99 and later**, implicit function declarations are not allowed, leading to warnings or errors.

#### Example without prototype

```c
#include <stdio.h>

int main() {
    foo(); // called without prototype
    return 0;
}

void foo() {
    printf("foo called\n");
}
```

**Compilation Warning (GCC):**

```
warning: implicit declaration of function ‘foo’
```

This may cause **undefined behavior**, hence **always use function prototypes**.

---

## Summary

* **Functions** make code modular and reusable.
* **Header Files** contain reusable declarations and definitions.
* **Function Prototypes** ensure proper type checking and prevent undefined behavior.

