# C Programming Notes

This document introduces three important topics in C programming:  
**1. The `write()` Function in C**  
**2. Header Files in C**  
**3. Function Prototypes in C**  

---

## 0. The `write()` Function in C

The `write()` function is a **system call** in C that allows you to write data directly to a file descriptor.  
It is declared in the **`unistd.h`** header file and is commonly used for **low-level I/O operations**.

### Syntax
```c
ssize_t write(int fd, const void *buf, size_t count);
````

### Parameters

1. **`fd` (file descriptor)**

   * An integer that identifies the file where data will be written.
   * Examples:

     * `0` → Standard Input (stdin)
     * `1` → Standard Output (stdout)
     * `2` → Standard Error (stderr)

2. **`buf` (buffer)**

   * A pointer to the data that will be written.
   * Usually a string or array.

3. **`count` (number of bytes)**

   * The number of bytes from the buffer to write.

### Return Value

* On success → returns the **number of bytes written**.
* On error → returns `-1` and sets `errno`.

---

### Example 1: Writing to Standard Output

```c
#include <unistd.h>

int main() {
    char msg[] = "Hello using write()!\n";
    write(1, msg, 21);  // 1 = stdout, 21 = number of bytes
    return 0;
}
```

**Output:**

```
Hello using write()!
```

---

### Example 2: Writing to a File

```c
#include <fcntl.h>   // for open()
#include <unistd.h>  // for write() and close()

int main() {
    int fd;
    char data[] = "This is written using write().\n";

    // open file for writing (create if not exists, truncate if exists)
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        write(2, "Error opening file\n", 19); // write to stderr
        return 1;
    }

    // write data to the file
    write(fd, data, sizeof(data) - 1);

    // close the file
    close(fd);

    return 0;
}
```

This will create a file `output.txt` containing:

```
This is written using write().
```

---

### Key Notes

* `write()` works at the **system call level**, unlike `printf()` which is a **library function** from `stdio.h`.
* It gives more **control over low-level I/O**.
* It does **not automatically add a null terminator (`\0`)**. You must specify the exact number of bytes to write.

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

