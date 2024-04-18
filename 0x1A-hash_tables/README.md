# Hash Tables

**Dictionary**: Abstract Data Type (ADT)

Maintain set of items each with a key

- insert(item): override existing key
- delete(item)
- search(key)
	- if exist return item
	- doesn't exist report *doesn't exist*

Best Search time is `O(log n)` and we will move to => `O(1)`

## Hash Function:
A hash function is any function that can be used to map data of arbitrary size to fixed-size values.

![alt text](https://en.wikipedia.org/wiki/File:Hash_table_4_1_1_0_0_1_0_LL.svg)

A hash function may be considered to perform three functions:
- Convert variable-length keys into fixed length
- Scramble the bits of the key so that the resulting values are uniformly distributed over the keyspace.
- Map the key values into ones less than or equal to the size of the table

A good hash function satisfies two basic properties:
1) it should be very fast to compute
2) it should minimize duplication of output values (collisions).

Hashing is an example of a space-time tradeoff. If memory is infinite, the entire key can be used directly as an index to locate its value with a single memory access. On the other hand, if infinite time is available, values can be stored without regard for their keys, and a binary search or linear search can be used to retrieve the element.

## Motivation:
- docdist (common words between docs, count num of wrods)
- database (some of them use hashing, other use search Trees)
	- This is how u know a word is correctly spelled (you look in a dictionary)
	- How to know to know closest related words (tweaking letters until you find them in the dictionary)
- username (when you login you go through dict that connect ur username with ur infos)
- compilers & interpreters (dictionary change ur variable name (key) to address in memory (value) )
- network router (have a packet need to send it to IP address, look in its dictionary of connected devices for the IP)

## Implementaion

### Simple approach
**Direct-access table**

if I my keys are integers I can store them in one giant array:
|key | Value|
|----|------|
|0   |item a|
|1   |NULL  |
|2   |NULL  |
|3   |item b|
|4   |NULL  |

#### Problems with this approach:
1) keys may not be integers
2) Takes a lot of space

### Solution to 1: prehash
Maps keys to non-negative integers

**Theory:** keys are finite and discrete (strings of bits)

**In Python:** `hash(x)` (is the prehash of `x`)

But there are some problem
`hash('\0B')` = `hash('\0\0C')`

**Ideally:**
hash(x) == hash(y) <=> x = y

You can use the Id of object as its key

### Solution to 2: hashing

Reduce all possible key integers to a reasonable size m for table

         (h)
key space => hash table [0, ...., m-1]

- Hash function maps all numbers to `m` `h: U -> {0, 1, ..., m-1}`
- Your hash funtion needs to know what `m` is
- There will be specific hash function for each `m`
**Idea:** make m (size of hash table) as close as possible to n (number of items present in table)

*You run into the problem of collision when:*
`hash(Ki)` = `hash(Kj)`
where `Ki != Kj` and that will happen A LOT

#### Solve Collision Problem:
When two elements collide store them as linked list

hash function for both `ki` and `kj` produce `1`

`ki => 1`	`kj => 1`
`1 => ki => kj`

**worst case:** hashing sucks and you end up storing all ur element in a linked list. (But this doesn't happend duo to randomization)

##### Simple Uniform Hashing:
A false asumption (but will give you a flavor)

"Each key is equally likely to be hashed to any slot in the table, independent of where other keys hasing."
