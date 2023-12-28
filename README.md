[![Language: C++17](https://img.shields.io/badge/Language-C%2B%2B20-yellow)](https://cppreference.com)

# `BigInt`: Arbitrary-Precision Integer Library for C++20

By Matin Yousefabadi\
Email: <mtnusf97@gmail.com>\
GitHub: <https://github.com/mtnusf97>

* [Introduction](#introduction)
    * [Overview of operations](#overview-of-operations)

* [Demo of features](#demo-of-features)
    * [Construction](#construction)
    * [Addition](#addition)
    * [Subtraction](#subtraction)
    * [Multiplication](#multiplication)
    * [Negation](#negation)
    * [Assignment](#assignment)
    * [Insertion](#insertion)

* [Acknowledgement](#acknowledgement)

## Introduction

This library enables the creation of integers with a customizable number of digits, allowing for the execution of fundamental arithmetic operations on them.

### Overview of operations

* **Addition (`+` and `+=`)**
    * You can perform an addition (`+`) operation on any two objects where at least one is a `BigInt` object.
    * You can perform an assignment addition (`+=`) operation on a `BigInt` where the left operand is a `BigInt` object.

* **Subtraction (`-` and `-=`)**
    * You can perform a subtraction (`-`) operation between any two objects, provided at least one is a `BigInt` object.
    * You can perform an assignment subtraction (`-=`) operation on a `BigInt` where the left operand is a `BigInt` object.

* **Multiplication (`*` and `*=`)**
    * You can perform a multiplication (`*`) operation between any two objects, as long as at least one is a `BigInt` object.
    * You can perform an assignment multiplication (`*=`) operation on a `BigInt` where the left operand is a `BigInt` object.

* **Negation (unary `-`)**
    * You can perform a unary negation (`-`) operation on a `BigInt` object to change its sign.

* **Comparison (`==`, `!=`, `<`, `>`, `<=`, and `>=`)**
    * You can perform comparison operations between `BigInt` objects or between a `BigInt` and another comparable object. This includes equality (`==`), inequality (`!=`), less than (`<`), greater than (`>`), less than or equal to (`<=`), and greater than or equal to (`>=`).

* **Assignment (`=`)**
    * You can assign a value to a `BigInt` object using the assignment (`=`) operator. The right operand should be a value or object that is compatible with `BigInt`.

* **Insertion (`<<`, to print the `integer` to a `stream` such as `std::cout` or a file)**
    * You can insert a `BigInt` into a stream using the insertion (`<<`) operator. This is commonly used to print a `BigInt` object to standard output (`std::cout`) or to write it into a file or other output stream.


## Demo of features

### Construction

You can initialize a `BigInt` with an `integer`, `string`, or another `BigInt` object.

```cpp
BigInt bigint1;
BigInt bigint2 = 136124642;
BigInt bigint3("00005125123561263163514124213561261");
BigInt bigint4(bigint3);
```


### Addition

```cpp
bigint1 += bigint2;
bigint1 += 136124642;
bigint1 += "00005125123561263163514124213561261";
```
```cpp
bigint1 += bigint2 + bigint3;
bigint1 += bigint2 + 136124642;
bigint1 += 136124642 + bigint2;
bigint1 += bigint2 + "00005125123561263163514124213561261";
bigint1 += "00005125123561263163514124213561261" + bigint2;
```


### Subtraction

```cpp
bigint1 -= bigint2;
bigint1 -= 25123561263;
bigint1 -= "512512356126316351412421";
```
```cpp
bigint1 -= bigint2 - bigint3;
bigint1 -= bigint2 - 25123561263;
bigint1 -= 25123561263 - bigint2;
bigint1 -= bigint2 - "512512356126316351412421";
bigint1 -= "512512356126316351412421" - bigint2;
```

### Multiplication

```cpp
bigint1 *= bigint2;
bigint1 *= 25123561263;
bigint1 *= "512512356126316351412421";
```
```cpp
bigint1 *= bigint2 * bigint3;
bigint1 *= bigint2 * 25123561263;
bigint1 *= 25123561263 * bigint2;
bigint1 *= bigint2 * "512512356126316351412421";
bigint1 *= "512512356126316351412421" * bigint2;
```

### Negation

```cpp
BigInt negbigint1 = -bigint1;
```

### Comparison

```cpp
if (bigint1 == bigint2) {}
if (25123561263 != bigint3) {}
if (bigint1 < "512512356126316351412421") {}
if ("512512356126316351412421" > bigint1) {}
if (bigint1 <= 25123561263) {}
if (bigint2 >= bigint1) {}
```

### Assignment

```cpp
bigint1 = bigint2;
bigint1 = 25123561263;
bigint1 = "512512356126316351412421";
```

### Insertion

```cpp
std::cout << bigint1 << "\n";
std::ofstream file("BigIntOutput.txt");
file << bigint1;
file.close();
```


## Acknowledgement

This library was developed as the final project of the course CSE 701 - Advanced Scientific Computing, instructed by [Prof. Barak Shoshany](https://baraksh.com/). The comprehensive [lecture notes](https://baraksh.com/CSE701/notes.php) provided by Prof. Shoshany were instrumental in the creation of this project. The structure and approach of this `README` have been significantly influenced by [thread pool library](https://github.com/bshoshany/thread-pool/tree/master).