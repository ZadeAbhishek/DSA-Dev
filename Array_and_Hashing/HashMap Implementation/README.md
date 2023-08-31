# Hash Table Theory Part

## What is a Hash Table?

A hash table, also known as a hash map, is a data structure that maps keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the corresponding value can be found.

[Check out my Hash Table Implementation](https://github.com/ZadeAbhishek/DSA-Dev/blob/master/Array_and_Hashing/HashMap%20Implementation/706.%20Design%20HashMap.cpp)

## Operations Complexity

Here are the operations complexities specific to C++ STL map and unordered_map:

|                  | map                                   | unordered_map     |
| --------         | -------                               |  -------          |
| Ordering         | Increasing order of keys (by default)  | No ordering       |
| Implementation   | Self-balancing BST like Red-Black Tree | Hash Table        |
| Search time      | log(n)                                 | O(1) -> Average   | 
|                  |                                        | O(n) -> Worst Case|
| Insertion time   | log(n) + Rebalance                     | Same as search    |
| Deletion time    | log(n) + Rebalance                     | Same as search    |

## Hash Function (Source GFG and Book)

A hash function is a function that converts a given numeric or alphanumeric key to a small practical integer value. The mapped integer value is used as an index in the hash table. In simple terms, a hash function maps a significant number or string to a small integer that can be used as the index in the hash table.

The pair is of the form (key, value), where for a given key, one can find a value using some kind of a "function" that maps keys to values. The key for a given object can be calculated using a function called a hash function.

### Types of Hash Functions

- Division Method
- Mid Square Method
- Folding Method (Fold Shift Hashing)
- Fold Boundary Hashing
- Multiplication Method
- Direct Method
- Substracting Method
- Digit Extraction Method
- Rotation Hashing
- Pseudorandom Generation Hashing

#### Division Method (Simple but poor performance)

The most simple method to generate a hash value is to divide the key with the size of the hash.

```
h(k) = k MOD M
```

Where:
- k = key value
- M = Size of the Hash Table 

The best suitable M is any bigger prime which ensures keys are more uniformly distributed.

#### Mid Square Method

The mid-square method is a very good hashing method. It involves two steps to compute the hash value:

1. Square the value of the key k, i.e., k^2
2. Extract the middle r digits as the hash value.

```
h(K) = h(k x k)

Here,
k is the key value.
```

**Example**

```
k = 60
k x k = 60 x 60 = 3600
h(60) = 60

The hash value obtained is 60.
```

The size of the key is one of the limitations of this method, as the key is of big size then its square will double the number of digits.

#### Digit Folding Method

This method involves two steps:

1. Divide the key-value k into a number of parts, i.e., k1, k2, k3, …, kn, where each part has the same number of digits except for the last part that can have lesser digits than the other parts.
2. Add the individual parts. The hash value is obtained by ignoring the last carry if any.

```
k = k1, k2, k3, k4, ….., kn
s = k1 + k2 + k3 + k4 + …. + kn
h(K) = s

Here,
s is obtained by adding the parts of the key k.
```

**Example**

```
k = 12345
k1 = 12, k2 = 34, k3 = 5
s = k1 + k2 + k3
  = 12 + 34 + 5
  = 51 
h(K) = 51
```

The number of digits in each part varies depending upon the size of the hash table. Suppose, for example, the size of the hash table is 100, then each part must have two digits except for the last part which can have a lesser number of digits.

#### Fold Boundary Hashing

The key is divided into parts whose size matches the size of the required address. Then the left and right parts are reversed and added to the middle part to obtain the address.

#### Multiplication Method

This method involves the following steps:

1. Choose a constant value A such that 0 < A < 1.
2. Multiply the key value with A.
3. Extract the fractional part of kA.
4. Multiply the result of the above step by the size of the hash table, i.e., M.
5. The resulting hash value is obtained by taking the floor of the result obtained in step 4.

```
h(K) = floor(M * (kA mod 1))

Here,
M is the size of the hash table.
k is the key value.
A is a constant value.
```

**Example**

```
k = 12345
A = 0.357840
M = 100

h(12345) = floor(100 * (12345 * 0.357840 mod 1))
               = floor(100 * (4417.5348 mod 1))
               = floor(100 * 0.5348)
               = floor(53.48)
               = 53
```

The advantage of the multiplication method is that it can work with any value between 0 and 1, although there are some values that tend to give better results than the rest. The multiplication method is generally suitable when the table size is a power of two, then the whole process of computing the index by the key using multiplication hashing is very fast.

#### Direct Hashing

In direct hashing, the key is the address without any algorithmic manipulation.

#### Subtraction Hashing

The key is transformed to any address by subtracting a fixed number from it.

#### Digit Extraction Hashing

Selected digits are extracted from the key and used as an address.

#### Rotation Hashing

The rightmost digit of the key is rotated to the left to determine an address. However, this method is usually used in combination with other methods.

#### Pseudorandom Generation Hashing

The key is used as a seed to generate a pseudorandom number. The result is then scaled to obtain the address.

## What is Collision?

Since a hash function gets us a small number for a key, which is a big integer or string, there is a possibility that two keys result in the

 same value. The situation where a newly inserted key maps to an already occupied slot in the hash table is called collision and must be handled using some collision handling technique.

## How to Handle Collisions?

There are mainly two methods to handle collisions: Separate Chaining and Open Addressing.

## Separate Chaining

When we use chaining to resolve collisions, we simply allow each slot in the hash table to accept more than one value. The linked list data structure is used to implement this technique. So what happens is, when multiple elements are hashed into the same slot index, then these elements are inserted into a singly-linked list which is known as a chain.

### Advantages of Separate Chaining

- Simple to implement.
- Hash table never fills up, we can always add more elements to the chain.
- Less sensitive to the hash function or load factors.
- It is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.

### Disadvantages of Separate Chaining

- The cache performance of chaining is not good as keys are stored using a linked list. Open addressing provides better cache performance as everything is stored in the same table.
- Wastage of space (some parts of the hash table are never used).
- If the chain becomes long, then search time can become O(n) in the worst case.
- Uses extra space for links.

### Performance of Chaining

```
m = Number of slots in the hash table
n = Number of keys to be inserted in the hash table
Load factor α = n/m
Expected time to search = O(1 + α)
Expected time to delete = O(1 + α)
Time to insert = O(1)
Time complexity of search insert and delete is O(1) if α is O(1)
```

#### Data Structures for Storing Chains

- Linked lists
  - Search: O(l) where l = length of the linked list
  - Delete: O(l)
  - Insert: O(l)
  - Not cache-friendly
- Dynamic Sized Arrays (Vectors in C++, ArrayList in Java, list in Python)
  - Search: O(l) where l = length of the array
  - Delete: O(l)
  - Insert: O(l)
  - Cache-friendly
- Self-Balancing BST (AVL Trees, Red-Black Trees)
  - Search: O(log(l)) where l = length of the linked list
  - Delete: O(log(l))
  - Insert: O(l)
  - Not cache-friendly

## Open Addressing

Open addressing is a method for handling collisions. In Open Addressing, all elements are stored in the hash table itself. So at any point, the size of the table must be greater than or equal to the total number of keys (Note that we can increase table size by copying old data if needed). This approach is also known as closed hashing. This entire procedure is based upon probing.

```
Insert(k): Keep probing until an empty slot is found. Once an empty slot is found, insert k. 

Search(k): Keep probing until the slot's key doesn't become equal to k or an empty slot is reached. 

Delete(k): Delete operation is interesting. If we simply delete a key, then the search may fail. So slots of deleted keys are marked specially as "deleted". 
The insert can insert an item in a deleted slot, but the search doesn't stop at a deleted slot. 
```

### Different Ways of Open Addressing

#### Linear Probing

In linear probing, the hash table is searched sequentially, starting from the original location of the hash. If the location that we get is already occupied, then we check for the next location.

```
The function used for rehashing is as follows: rehash(key) = (n + 1) % table-size. 
```

##### Applications

- Symbol Tables
- Caching
- Databases
- Compiler design
- Spell Checking

#### Challenges in Linear Probing

- Primary Clustering: One of the problems with linear probing is Primary clustering, many consecutive elements form groups and it starts taking time to find a free slot or to search for an element.
- Secondary Clustering: Secondary clustering is less severe, two records only have the same collision chain (Probe Sequence) if their initial position is the same.

#### Quadratic Probing

If you observe carefully, then you will understand that the interval between probes will increase proportionally to the hash value. Quadratic probing is a method with the help of which we can solve the problem of clustering that was discussed above. This method is also known as the mid-square method. In this method, we look for the i^2th slot in the ith iteration. We always start from the original hash location. If only the location is occupied then we check the other slots.

```
let hash(x) be the slot index computed using the hash function.  

If slot hash(x) % S is full, then we try (hash(x) + 1*1) % S
If (hash(x) + 1*1) % S is also full, then we try (hash(x) + 2*2) % S
If (hash(x) + 2*2) % S is also full, then we try (hash(x) + 3*3) % S
```

#### Double Hashing

The intervals that lie between probes are computed by another hash function. Double hashing is a technique that reduces clustering in an optimized way. In this technique, the increments for the probing sequence are computed using another hash function. We use another hash function hash2(x) and look for the i * hash2(x) slot in the ith rotation.

```
let hash(x) be the slot index computed using the hash function.  

If slot hash(x) % S is full, then we try (hash(x) + 1 * hash2(x)) % S
If (hash(x) + 1 * hash2(x)) % S is also full, then we try (hash(x) + 2 * hash2(x)) % S
If (hash(x) + 2 * hash2(x)) % S is also full, then we try (hash(x) + 3 * hash2(x)) % S
```

## Performance of Open Addressing

```
m = Number of slots in the hash table
n = Number of keys to be inserted in the hash table
Load factor α = n/m  ( < 1 )
Expected time to search/insert/delete < 1/(1 - α) 
So Search, Insert, and Delete take (1/(1 - α)) time
```

## Commonly Used Hash Functions

- SHA (Secure Hash Algorithm)
- CRC (Cyclic Redundancy Check)