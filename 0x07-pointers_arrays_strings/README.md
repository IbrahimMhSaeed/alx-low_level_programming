# Pointers, Arrays, and Strings

This document covers the concepts of pointers, double pointers, and multidimensional arrays in C with examples and explanations.

---

## 1. Pointers in C

A **pointer** is a variable that stores the address of another variable.

### Example: Normal Pointer

```c
#include <stdio.h>

int main() {
    int a = 10;
    int *b = &a;

    printf("a: %d \n", a);
    printf("Pointer to 'a' (b): %p \n", b);
    printf("Value at 'b': %d\n", *b);

    return 0;
}
```

**Output (sample):**

```
a: 10
Pointer to 'a' (b): 0x7ffd1a2c
Value at 'b': 10
```

💡 The `*` operator is the **dereference operator**, used to access the value stored at an address.

---

## 2. Double Pointer (Pointer to Pointer)

A **double pointer** stores the address of another pointer.
Declaration:

```c
int **dptr;
```

* First `*` → points to another pointer
* Second `*` → points to the actual variable

### Example: Double Pointer

```c
#include <stdio.h>

int main() {
    int a = 100;
    int *ptr = &a;
    int **dptr = &ptr;

    printf("Value of a: %d\n", a);
    printf("Using ptr: %d\n", *ptr);
    printf("Using dptr: %d\n", **dptr);

    return 0;
}
```

**Output:**

```
Value of a: 100
Using ptr: 100
Using dptr: 100
```

💡 **Normal pointer vs Double pointer**

* Normal pointer → holds the address of a variable
* Double pointer → holds the address of another pointer

### Memory Layout Example

```
a (value: 10) → address 1000
b (pointer to a) → address 2000
c (pointer to b) → address 3000
```

Accessing `a` via `c`: `**c`.

---

## 3. Multilevel Pointers

Pointers can extend beyond two levels:

```c
int ***triplePtr;
```

Though rarely needed, triple pointers are theoretically possible and sometimes used for arrays of strings or dynamic memory management.

---

## 4. Multidimensional Arrays

A **multidimensional array** is an array of arrays.

### 4.1 Two-Dimensional Arrays (2D)

Declaration:

```c
int arr[3][5];
```

#### Example:

```c
#include <stdio.h>
int main() {
   int arr[3][5] = {
      {1,2,3,4,5}, 
      {10,20,30,40,50}, 
      {5,10,15,20,25}
   };

   for (int i=0; i<3; i++) {
      for (int j=0; j<5; j++) {
         printf("%4d", arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}
```

**Output:**

```
   1   2   3   4   5
  10  20  30  40  50
   5  10  15  20  25
```

---

### 4.2 Three-Dimensional Arrays (3D)

```c
int arr[3][3][3] = {
   {{11,12,13}, {14,15,16}, {17,18,19}},
   {{21,22,23}, {24,25,26}, {27,28,29}},
   {{31,32,33}, {34,35,36}, {37,38,39}}
};
```

📌 Think of a 3D array as `arr[depth][row][col]`.

---

### 4.3 Matrix Multiplication Example

```c
#include<stdio.h>
int main(){
   int mat1[2][2] = {{1,2},{3,4}};
   int mat2[2][2] = {{5,6},{7,8}};
   int result[2][2], i, j, k;

   for(i=0;i<2;i++){
      for(j=0;j<2;j++){
         result[i][j]=0;
         for(k=0;k<2;k++)
            result[i][j] += mat1[i][k] * mat2[k][j];
      }
   }

   printf("Result Matrix:\n");
   for(i=0;i<2;i++){
      for(j=0;j<2;j++)
         printf("%d ", result[i][j]);
      printf("\n");
   }
   return 0;
}
```

**Output:**

```
19 22
43 50
```

---

## 5. Memory Layout of Arrays

* Arrays in C are stored in **contiguous memory locations**.
* **Row-major order**: C stores 2D arrays row by row.

### Address Calculation (Row Major Order)

```
Address(arr[i][j]) = BaseAddress + (i * numCols + j) * sizeOfElement
```

Example: `arr[10][25]`, base = 100, element = 4 bytes.
Find address of `arr[8][6]`:

```
100 + (8*25 + 6)*4 = 924
```

---

## 6. Strings Input in C

Ways to read strings:

```c
scanf("%s", str);        // stops at whitespace
gets(str);               // unsafe, deprecated
fgets(str, size, stdin); // safe, supports spaces
scanf("%[^\n]s", str);   // reads until newline
```

### Example:

```c
char str[50];
fgets(str, 50, stdin);
printf("Input: %s", str);
```

---


## ✅ Key Takeaways

* **Pointers** hold addresses; **double pointers** hold addresses of pointers.
* **Multidimensional arrays** are stored in row-major order in C.
* **Strings** should be read with `fgets()` for safety.
* Pointers and arrays are deeply related: array names act like pointers to their first element.

