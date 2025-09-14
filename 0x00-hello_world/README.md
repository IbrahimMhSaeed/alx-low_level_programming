# C Programming Basics

This section provides a **high-level overview of C syntax and program structure**.

---

## Program Structure

```c
#include <stdio.h>   // Preprocessor directive

int main(void) {
    printf("Hello, World!\n");  // Standard output
    return 0;
}
```

* **Preprocessor Directives** (`#include`, `#define`)
  Resolved before compilation; similar to macros in assembly or imports in higher-level languages, but more primitive.

* **Entry Point** (`main`)
  Returns an `int` to the host environment. Unlike some modern languages, execution always begins here.

* **Statements** end with `;`.

* **Blocks** are enclosed in `{ }`.

---

## Syntax Essentials

| Concept       | Notes (C-specific)                                                                    |
| ------------- | ------------------------------------------------------------------------------------- |
| **Types**     | Primitive and fixed: `int`, `float`, `char`, `double`, `void`. No dynamic typing.     |
| **Variables** | Must be declared before use; storage duration & scope matter (stack, static, global). |
| **Comments**  | `//` single-line, `/* ... */` multi-line.                                             |
| **Functions** | Must be declared before use unless a prototype is provided.                           |
| **Headers**   | Bring in library declarations (no namespace/module system).                           |

---

## Example: Variables and I/O

```c
#include <stdio.h>

int main(void) {
    int age = 30;
    double salary = 85000.75;
    char grade = 'A';

    printf("Age: %d\nSalary: %.2f\nGrade: %c\n", age, salary, grade);
    return 0;
}
```

---

## Key Differences for Engineers

* **Manual memory management** (`malloc`, `free`), no GC.
* **Pointers** are first-class; you manipulate memory addresses directly.
* **No built-in OOP**; struct + function composition is the idiomatic way.
* **Undefined behavior** is part of the spec — compiler optimizations may exploit this.
* **Standard Library is minimal** (I/O, string handling, math, memory ops).

---


# C Compilation Process

When we compile a C program, it goes through **four major stages** before producing an executable. These stages are handled by different components of the build toolchain: **Preprocessor → Compiler → Assembler → Linker**.

---

## 1. Preprocessor
The **preprocessor** runs first. It processes the source code before actual compilation.  
Tasks:
- **Remove comments** from the source code.
- **Expand macros** (replace `#define` symbols with their values).
- **Include header files** (replacing `#include` directives with the actual content of the headers).

📄 Example transformation:

```c
// Original source
#include <stdio.h>   // header
#define PI 3.14

int main(void) {
    printf("PI = %f\n", PI);
    return 0;
}
```

➡️ After preprocessing, the code has **no comments**, the `#include` is replaced by the actual `<stdio.h>` content, and `PI` is expanded to `3.14`.

---

## 2. Compiler

The **compiler** takes the preprocessed code and:

* Checks syntax and semantics.
* Translates C code into **assembly code** (architecture-specific, human-readable mnemonics).

📄 Example snippet of generated assembly (for x86-like target):

```asm
mov eax, 1
mov edi, 1
lea rsi, [rip+msg]
mov edx, len
syscall
```

---

## 3. Assembler

The **assembler** converts the assembly code into **machine code** (binary instructions).

* Produces an **object file** (`.o` on Linux / `.obj` on Windows).
* Object files are not yet complete executables — they may contain **unresolved references** (e.g., calls to library functions like `printf`).

---

## 4. Linker

The **linker** combines one or more object files and external libraries into a single executable.

Roles:

* **Combine multiple object files** (e.g., from large projects with several modules).
* **Resolve external symbols** (link function calls like `printf` with the C standard library).
* Produce the **final executable** (`a.out` by default on Linux, `.exe` on Windows).

Types of linking:

* **Static linking**: Copies the library code into the executable (larger file, no runtime dependency).
* **Dynamic linking**: References shared libraries at runtime (smaller executable, requires shared library available).

---

## Compilation Pipeline Summary

```
Source Code (.c)
   │
   ▼
Preprocessor  →  Compiler  →  Assembler  →  Linker
   │              │             │             │
   ▼              ▼             ▼             ▼
Expanded C   Assembly Code   Object Code   Executable
(.i file)     (.s file)       (.o file)    (a.out / exe)
```

---

✅ **Key Point**: Unlike many modern languages, the C toolchain is modular. Each step (preprocessing, compilation, assembling, linking) can be invoked separately — useful for debugging, optimization, or build system customization.

---


# Betty Coding Style

The **Betty Style** is a set of coding guidelines for writing clean, consistent, and readable **C programs**.  
It enforces formatting rules, naming conventions, and documentation standards.  

---

## Key Rules

- **File Header Comments**  
  Each file must start with a comment block describing the file, author, and purpose.  

- **Function Documentation**  
  Every function must include a description, parameters, and return value in a comment block.  

- **Line Length**  
  Maximum of **80 characters per line**.  

- **Indentation**  
  Use **4 spaces per indentation level** (no tabs).  

- **Braces Style**  
  Opening brace on the **same line** as the statement. Example:
  ```c
  if (x > 0) {
      printf("Positive\n");
  }
  ```

* **Spacing**

  * One space after `if`, `while`, `for`, etc.
  * No trailing whitespace.
  * Only one statement per line.

* **Function Size**
  Functions should be short and do **one thing**.

* **Variable Names**

  * Lowercase with underscores (`snake_case`).
  * Constants in **UPPERCASE**.
  * Avoid single-letter names (except simple loop counters).

---

## Example: Bad vs Good

❌ **Bad Style**

```c
int main(){int x=5;if(x>0){printf("Hello\n");}return 0;}
```

✅ **Betty Style**

```c
#include <stdio.h>

/**
 * holla - Print "Hello" at a condition
 *
 * @number: number to be checked
 *
 * Return: Always 0 (Success)
 */

int holla(int number)
{

    if (number > 0)
    {
        printf("Hello\n");
    }

    return (0);
}
```

---

## Betty Linter

The **Betty Linter** is used to automatically check code for style violations.


### Usage

```bash
betty my_file.c        # Run style checks on a single file
betty *.c              # Run style checks on all C files
```

The linter will display errors and suggestions to make your code Betty-compliant.

---



## Shebang (`#!`) Directive

The **shebang (`#!`)** is a special sequence recognized directly by the **kernel**.  
When a script file begins with the byte sequence `0x23 0x21` (`#!`), the kernel interprets the remainder of the line as the **path to the interpreter** that should execute the file.  

For example:
```bash
#!/bin/bash
echo "Hello from Bash"
```

* `#!/bin/bash` tells the kernel to run the script using the **Bash shell**.
* Without it, the script must be invoked explicitly with the interpreter (e.g., `bash script.sh`).

This mechanism was first introduced in **Research Unix (January 1980)** in a message from **Dennis Ritchie**, making it a long-standing feature across Unix-like systems.


---


# Linus Torvalds on C vs C++

Linus Torvalds, the creator of Linux and Git, has been very outspoken about his dislike of **C++** for system-level projects like the Linux kernel or Git.
 
The main reason Linus Torvalds rejects **C++** for projects like Linux and Git is simple:  
👉 **C++ makes it easy to create complex, inefficient, and hard-to-maintain code.**  

In contrast, **C is simple, explicit, and predictable**, which is critical for system-level software where performance and control matter most.

---

## The Problems with C++

1. **Hidden Behavior**
   - C++ features like exceptions, operator overloading, or constructors can hide what the code is really doing.  
   - Example:  
     ```cpp
     std::string s = "hello";
     s += "world";  // hidden memory allocations, possible copies
     ```
     In C, you would explicitly manage memory for strings, so nothing happens "behind your back."

2. **Over-abstracted Design**
   - Using STL or Boost encourages heavy abstractions that look nice but can lock you into bad designs.  
   - Example:  
     ```cpp
     std::vector<int> data;
     // If you later realize you need a linked list, changing the design is painful.
     ```

3. **Portability and Stability**
   - Different compilers implement C++ features differently (especially in the 2000s).  
   - Complex templates or Boost features often broke across platforms.  
   - With C, the language and standard library are smaller and more consistent.

4. **Efficiency**
   - C++ abstractions can add overhead that you don’t always see.  
   - Example: exception handling adds hidden code paths and runtime costs.  
   - In C, performance is more predictable because nothing is inserted automatically.

---

## Why C Wins

- **Full control**: You manage memory and structures explicitly.  
- **Simplicity**: The language is small; fewer surprises.  
- **Transparency**: No hidden allocations or behaviors.  
- **Portability**: Compiles the same way almost everywhere.  
- **Discipline**: Forces you to design data structures and interfaces carefully.  

---

## Bottom Line

Linus’ point is not that *nobody should ever use C++*. His argument is that for **low-level, performance-critical software** like Linux and Git, C++ encourages bad habits and unnecessary complexity.  


---



# GCC and Common Output Functions

When working in C, you’ll frequently use the **GCC compiler** to build your programs and standard library functions to display output.  
Here’s a quick overview:

---

## GCC (GNU Compiler Collection)
- **`gcc`** is the most widely used C compiler.  
- It translates your C source code into an executable program.  

### Basic usage:

```bash
# Compile program.c into a.out
gcc program.c

# Compile and specify output name
gcc program.c -o my_program

# Stop after preprocessing, compilation, or assembling
gcc -E program.c    # Preprocess only
gcc -S program.c    # Compile to assembly
gcc -c program.c    # Compile to object file
```

---

## `printf(3)`

* A **formatted output function** from the C standard library (`stdio.h`).
* The `(3)` notation refers to the **manual section** for library functions.

Example:

```c
#include <stdio.h>

int main(void)
{
    printf("Name: %s, Age: %d\n", "Alice", 25);
    return 0;
}
```

Output:

```
Name: Alice, Age: 25
```

---

## `puts`

* Simpler than `printf`.
* Prints a string followed by a newline.

Example:

```c
#include <stdio.h>

int main(void)
{
    puts("Hello, World!");
    return 0;
}
```

Output:

```
Hello, World!
```

---

## `putchar`

* Prints a single character.
* Useful in loops or when building custom output.

Example:

```c
#include <stdio.h>

int main(void)
{
    putchar('A');
    putchar('\n');
    return 0;
}
```

Output:

```
A
```



