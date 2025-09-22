# Pointers, Arrays, and Strings

This document summarizes key concepts in **pointers, arrays, and strings** in C programming.  

---

## Arrays

An **array** in C is a collection of elements of the same type stored in **contiguous memory locations**.  
Each element is accessed using an **index**, starting from `0`.

---

### Array Initialization
1. **Full Initialization**
```c
int arr[5] = {0};   // all elements set to 0
```

**Output**

```
a[0]: 0
a[1]: 0
a[2]: 0
a[3]: 0
a[4]: 0
```

2. **Partial Initialization**

```c
int arr[5] = {1, 2};  // rest filled with 0
```

3. **Specific Index Initialization**

```c
int arr[5] = {1, 2, [4] = 4};
```

---

### Size of an Array

Memory allocated = **element size × number of elements**.

Example:

```c
int arr[5] = {1, 2, 3, 4, 5};
printf("Size: %ld\n", sizeof(arr));   // 20 bytes (5 × 4)
```

---

### Accessing Array Elements

```c
int n[5];
for (int i = 0; i < 5; i++) {
    n[i] = i + 100;
    printf("n[%d] = %d\n", i, n[i]);
}
```

---

### More on Arrays

1. **Multidimensional arrays**
2. **Passing arrays to functions**
3. **Returning arrays (via pointers)**
4. **Pointer to an array**

---

## Pointers

A **pointer** is a variable that stores the **address of another variable**.
They allow:

* Direct access and modification of memory.
* Efficient parameter passing between functions.
* Creation of **dynamic data structures** (linked lists, trees, graphs).

---

### Pointer Declaration

```c
type *var_name;
```

Examples:

```c
int    *ip;   // pointer to int
double *dp;   // pointer to double
float  *fp;   // pointer to float
char   *cp;   // pointer to char
```

---

### Pointer Initialization

Use the **address-of operator `&`**:

```c
int x = 10;
int *ptr = &x;
```

---

### Referencing & Dereferencing

* `&` → get the address of a variable.
* `*` → access the value at a memory address.

Example:

```c
int x = 10;
int *ptr = &x;

printf("%d\n", *ptr);  // 10
*ptr = 20;
printf("%d\n", *ptr);  // 20
```

---

### Using Pointers with Different Types

```c
int x = 10;
float y = 1.3f;
char z = 'p';

int *ptr_x = &x;
float *ptr_y = &y;
char *ptr_z = &z;

printf("%d\n", *ptr_x);
printf("%f\n", *ptr_y);
printf("%c\n", *ptr_z);
```

---

### Size of a Pointer

Pointer size depends on the **system architecture**, not the type.
(Usually **8 bytes on 64-bit systems**).

---

### Examples

**Basic Pointer**

```c
int var = 20;
int *ip = &var;

printf("Address: %p\n", ip);
printf("Value: %d\n", *ip);
```

**Integer Pointer**

```c
int var = 100;
int *intptr = &var;

printf("%d\n", *intptr);   // 100
```

**Float Pointer**

```c
float var1 = 10.55;
float *floatptr = &var1;

printf("%f\n", *floatptr);   // 10.55
```

---

### Pointer to Pointer

![Pointer to pointer illusteration](https://www.tutorialspoint.com/cprogramming/images/pointer_variable.jpg)

A pointer can store the address of another pointer.

```c
int var = 10;
int *p = &var;
int **pp = &p;

printf("%d\n", **pp);   // 10
```

---

### NULL Pointer

If no valid address is assigned, initialize with `NULL`:

```c
int *ptr = NULL;
if (!ptr) {
    printf("Pointer is NULL\n");
}
```

---

### Print Value & Address of Pointer

```c
#include <stdio.h>

int main(){

   int var = 100;
   
   printf("Variable: %d \t Address: %p", var, &var);
   
   return 0;   
}
```

**Output:**
```
Variable: 100   Address: 0x7ffc62a7b844
```

---

### Pointer Applications

1. **Pointer arithmetic** (`++`, `--`, `+`, `-`).
2. **Array of pointers**.
3. **Pointer to pointer**.
4. **Passing pointers to functions** (pass by reference).
5. **Returning pointers from functions**.


---

#### Passing Pointers to Functions (Different Ways)

```c
#include <stdio.h>

// Pass pointer to modify a single value
void increment(int *p) {
    (*p)++;
}

```

**Fixed Number of Rows:**


```c
void print_chessboard(char (*a)[8]);
```

is a **pointer to an array** (specifically, an array of 8 `char`s). This is commonly used for **2D arrays with fixed column size**.

below is an example of Chess board.

---

#### Passing Pointer to Array (2D Array Example)

```c
#include <stdio.h>

// Function that accepts pointer to array of 8 chars
void print_chessboard(char (*board)[8], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize an 8x8 chessboard
    char chessboard[8][8] = {
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'}
    };

    // Pass chessboard to function
    print_chessboard(chessboard, 8);

    return 0;
}
```

---

✅ **Explanation:**

1. `char (*board)[8]` means:

   * `board` is a pointer to an array of 8 `char`s.
   * This is useful for **2D arrays where the number of columns is fixed**.

2. `chessboard` (2D array) decays to a pointer to its first row (`char (*)[8]`) when passed to the function.

3. The function can then iterate row by row and column by column safely.

---

💡 **Note:** This method is **better than `char **`** for fixed-size 2D arrays because memory is contiguous, making it safer and faster.


#### Pointer to Function

```c
#include <stdio.h>

// Function that matches the pointer type
int add(int a, int b) {
    return a + b;
}

int main() {
    // Pointer to function
    int (*funcPtr)(int, int) = &add;

    // Call the function using the pointer
    int result = funcPtr(5, 3);
    printf("Result using pointer to function: %d\n", result);

    return 0;
}
```

---

#### Pointer Pointing to Function (Passing Function Pointer)

```c
#include <stdio.h>

// Functions to be pointed to
int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

// Function that accepts a function pointer as argument
void operate(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y);
    printf("Operation Result: %d\n", result);
}

int main() {
    // Pass pointer to multiply function
    operate(&multiply, 6, 4);

    // Pass pointer to subtract function
    operate(&subtract, 10, 3);

    return 0;
}
```

---

**Explanation:**

1. **Pointer to Function:** Stores the address of a function and allows calling it through the pointer.
2. **Pointer Pointing to Function (Function Pointer as Parameter):** Lets you pass functions as arguments to other functions, enabling dynamic behavior.


---

## Strings in C


A **string** in C is a one-dimensional array of `char` values, terminated by the **null character** `'\0'`.  
Example:  
```c
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
![String stored in memory](https://www.tutorialspoint.com/cprogramming/images/string_representation.jpg)

### Creating and Initializing Strings

* Strings can be created either by manually specifying characters with `'\0'` at the end, or by using double quotes:

```c
char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
char str2[] = "Hello"; // Compiler adds '\0' automatically
```

### Accessing and Printing Strings

* You can loop through a string like a char array.
* Use `%s` with `printf()` to print the whole string until the null terminator.

Example:

```c
char greeting[] = "Hello World";
printf("%s\n", greeting);   // Output: Hello World
```

### String Input

* `scanf("%s", str)` → reads a string until whitespace.
* `gets(str)` → (deprecated, unsafe).
* `fgets(str, size, stdin)` → recommended, supports spaces.
* `scanf("%[^\n]s", str)` → alternative way to read until newline.


---

#### 1. Using `scanf("%s", str)`

Reads input **until a whitespace** (space, tab, newline).

```c
#include <stdio.h>

int main() {
    char str[20];

    printf("Enter a word: ");
    scanf("%s", str);   // stops at whitespace

    printf("You entered: %s\n", str);
    return 0;
}
```

**Input:**

```
Hello World
```

**Output:**

```
You entered: Hello
```

---

#### 2. Using `gets(str)` (⚠️ Deprecated / Unsafe)

Reads a full line including spaces, but unsafe (can cause buffer overflow).

```c
#include <stdio.h>

int main() {
    char str[20];

    printf("Enter a line: ");
    gets(str);   // unsafe!

    printf("You entered: %s\n", str);
    return 0;
}
```

**Input:**

```
Hello World
```

**Output:**

```
You entered: Hello World
```

---

#### 3. Using `fgets(str, size, stdin)` ✅ (Recommended)

Safe alternative — reads up to `size-1` characters and includes spaces.

```c
#include <stdio.h>

int main() {
    char str[20];

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);

    printf("You entered: %s\n", str);
    return 0;
}
```

**Input:**

```
Hello World
```

**Output:**

```
You entered: Hello World
```

*(Note: `fgets` keeps the trailing newline `\n` unless buffer is full.)*

---

#### 4. Using `scanf("%[^\n]s", str)`

Reads input until a **newline** (`\n`) is encountered.

```c
#include <stdio.h>

int main() {
    char str[20];

    printf("Enter a line: ");
    scanf("%[^\n]s", str);   // reads until newline

    printf("You entered: %s\n", str);
    return 0;
}
```

**Input:**

```
Hello World
```

**Output:**

```
You entered: Hello World
```


### String Output

* `printf("%s", str)` → common way.
* `puts(str)` → prints with newline (deprecated in newer standards).
* `fputs(str, stdout)` → safer alternative.

---


## Memory Layout in C

When a C program is compiled and executed, it is loaded into memory and divided into **different segments**. Each segment has a specific purpose and set of rules (read-only, writable, auto-managed, or manual). Understanding this is crucial for debugging, optimization, and preventing issues like segmentation faults.

Each segment of C code has its own read,write, execute permissions that is set by the operationg system & compiler. if a program tries to access a memory in a way that's not allowed a **Segmentation fault** occurs.

**Segmentation fault**: common problem causes the program to crash. A core dumped file is associated with this fault to help the programmer know the root of the problem.

---

### 1. Text Segment (Code Section)
- Contains the **executable instructions** of your program.
- Usually marked **read-only** → prevents accidental overwriting of instructions.
- Also stores **string literals** (constant strings).
- Example:
```c
printf("Hello, World!"); // "Hello, World!" resides in the text segment
```

---

### 2. Data Segment

Holds **global** and **static variables**. Split into two parts:

#### a) Initialized Data Segment

* Stores variables that are explicitly initialized.

```c
int x = 10;        // stored in initialized data
static int y = 20; // also stored here
```

#### b) Uninitialized Data Segment (BSS)

* Holds variables that are uninitialized or initialized to zero.
* At runtime, memory is automatically set to **zero**.

```c
int count;        // stored in BSS, default = 0
static int flag;  // stored in BSS, default = 0
```

---

### 3. Heap

* Region used for **dynamic memory allocation** (`malloc`, `calloc`, `realloc`).
* Grows **upwards** at runtime.
* Must be freed manually using `free()`.
* If memory is not freed → **memory leak**.

```c
int *ptr = malloc(5 * sizeof(int)); 
// allocated on heap
```

---

### 4. Stack

* Stores:

  * Function call info (return addresses).
  * Local variables.
  * Parameters passed to functions.
* Grows **downwards** (towards lower memory addresses).
* Managed automatically — memory is allocated when a function is called and released when it returns.

```c
void foo() {
   int a = 10;  // stored on stack
}
```

⚠️ If recursion is too deep or local variables are too large → **stack overflow**.

---

### 5. Command-Line Arguments & Environment

* Stored above the stack.
* Includes:

  * `argv[]` → arguments passed to `main(int argc, char *argv[])`.
  * `environ[]` → environment variables.

---

### Memory Layout Schematic

```
+-------------------------+ High Memory Addresses
| Command-Line Arguments  |
| Environment Variables   |
+-------------------------+
|         Stack           |  <- grows downward
|  (local vars, return    |
|   addresses, frames)    |
+-------------------------+
.			  .
.	    |		  .
	    v


.	  Empty		  .


	    ^
	    |
.			  .
.			  .
+-------------------------+
|         Heap            |  <- grows upward
|  (dynamic allocation)   |
+-------------------------+
|   BSS Segment (0-init)  | Uninitialized data segment
+-------------------------+
| Initialized Data Segment|
+-------------------------+
|       Text Segment      |
|  (code + constants)     |
+-------------------------+ Low Memory Addresses
```

---

### Key Points

* **Stack vs Heap**

  * Stack is faster, auto-managed, limited in size.
  * Heap is larger, manually managed, but slower.
* **Global/Static variables** are always stored in **Data Segment** (not stack/heap).
* **String literals** and compiled instructions go into **Text Segment**.
* Mismanagement of heap memory → leaks, dangling pointers, crashes.

👉 [Detailed Reference](https://aticleworld.com/memory-layout-of-c-program/)

