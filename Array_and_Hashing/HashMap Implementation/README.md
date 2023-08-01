
# Hash Table Theory Part

### what is Hash Table?
Hash table (also, hash map) is a data structure that basically maps keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the corresponding value can be found.

[My Hash Table Implementation]()


### Operations Complexity
* Specific related to C++ stl

|                 | map                                   | unordered_map |
| --------        | -------                               |  -------      |
|Ordering        | Increasing order of keys(by default)   | no ordering |
|Implementation  | Self balancing BST like Red-Black Tree | Hash Table|
|Search time     | log(n)                                 | O(1) -> Average | 
|                |                                        | O(n) -> Worst Case
|Insertion time  | log(n) + Rebalance                     | Same as search|
|Deletion time   | log(n) + Rebalance                     | Same as search|

### Hash function (Source GFG and Book)
A Hash Function is a function that converts a given numeric or alphanumeric key to a small practical integer value. The mapped integer value is used as an index in the hash table. In simple terms, a hash function maps a significant number or string to a small integer that can be used as the index in the hash table.

The pair is of the form (key, value), where for a given key, one can find a value using some kind of a “function” that maps keys to values. The key for a given object can be calculated using a function called a hash function.

#### Types of Hash Functions
* Division Method
* Mid Square Method
* Folding Method (Fold Shift Hashing)
* Fold Boundary Hashing
* Multiplication Method
* Direct Method
* Substracting Method
* Digit Extraction Method
* Rotation Hashing
* Pseudorandom Generation Hashing

#### Division Method (Simple but poor performance)
Most simple method to generate hash value. Just divide the key with size of hash.
```
h(k) = k MOD M

```

k = key value \
M = Size of Hash Table 

The best Suitable M is any Bigger Prime which ensure keys are more uniformly Distributed.

#### Mid Sqaure Method
The mid-square method is a very good hashing method. It involves two steps to compute the hash value-

* Square the value of the key k i.e. k2 
* Extract the middle r digits as the hash value.

~~~
h(K) = h(k x k)

Here,
k is the key value.

~~~
~~~
Example

k = 60
k x k = 60 x 60
        = 3600
h(60) = 60

The hash value obtained is 60
~~~

* The size of the key is one of the limitations of this method, as the key is of big size then its square will double the number of digits.

#### Digit Folding Method
This method involves two steps:

* Divide the key-value k into a number of parts i.e. k1, k2, k3,….,kn, where each part has the same number of digits except for the last part that can have lesser digits than the other parts.
* Add the individual parts. The hash value is obtained by ignoring the last carry if any.

~~~
k = k1, k2, k3, k4, ….., kn
s = k1+ k2 + k3 + k4 +….+ kn
h(K)= s

Here,
s is obtained by adding the parts of the key k

~~~
~~~
k = 12345
k1 = 12, k2 = 34, k3 = 5
s = k1 + k2 + k3
  = 12 + 34 + 5
  = 51 
h(K) = 51
~~~

* The number of digits in each part varies depending upon the size of the hash table. Suppose for example the size of the hash table is 100, then each part must have two digits except for the last part which can have a lesser number of digits.

#### Fold Boundary Hashing
The key is divided into parts whose size matches the size of the required address. Then the left and right parts are reversed and addedd to middle part to obtain the address.

#### Multiplication Method

This method involves the following steps:

* Choose a constant value A such that 0 < A < 1.
* Multiply the key value with A.
* Extract the fractional part of kA.
* Multiply the result of the above step by the size of the hash table i.e. M.
* The resulting hash value is obtained by taking the floor of the result obtained in step 4.

~~~
h(K) = floor (M (kA mod 1))

Here,
M is the size of the hash table.
k is the key value.
A is a constant value.
~~~

~~~
k = 12345
A = 0.357840
M = 100

h(12345) = floor[ 100 (12345*0.357840 mod 1)]
               = floor[ 100 (4417.5348 mod 1) ]
               = floor[ 100 (0.5348) ]
               = floor[ 53.48 ]
               = 53
~~~
* The advantage of the multiplication method is that it can work with any value between 0 and 1, although there are some values that tend to give better results than the rest.

* The multiplication method is generally suitable when the table size is the power of two, then the whole process of computing the index by the key using multiplication hashing is very fast.

#### Direct Hashing
In Direct Hashing the key is the address without any algorithmic manipulation.

#### Substraction Hashing
The key is trasformed to any address by substractinh a fixed number from it.

#### Digit Extraction Hashing
Selected Digits are extracted from the key and used as an address.

#### Rotation Hashing
The RIGHT most digit of the key is rotated to the left to determined an address. However this method is usually used in combination with other method.

#### Pseudorandom generation Hashing
The key is used as seed to generate a pseudoramdom number. The result is then scaled to obtain the address.

### What is Collision? 
Since a hash function gets us a small number for a key which is a big integer or string, there is a possibility that two keys result in the same value. The situation where a newly inserted key maps to an already occupied slot in the hash table is called collision and must be handled using some collision handling technique. 

### How to handle Collisions? 

There are mainly two methods to handle collision: 

* Separate Chaining 
* Open Addressing 
