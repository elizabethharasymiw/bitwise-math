# Bitwise Math
Command line calculator program written without arithmetic operators in C

## How to Use
- Note: This project does not have any shipped releases yet
- Note: No support on Windows
- Use GNU Make to build: ``` make ```
- Start Program: ``` make run ```
- The program takes in two numbers and runs multiple arithmetic operations

## Developer Build Instructions
- Note: Build System requires GNU Make
- Note: No support on Windows
- Normal build: ``` make ```
- Manual Test: ``` make run ```
- Clean Environment: ``` make clean ```

# Bitwise Cheat sheet

## C bitwise examples
```
int x = 4;    // initialize x
x |= 1;       // Set the 0th bit
x |= 1 << 4;  // Set the 4th bit
x ^= 1 << 4;  // Flip the 4th bit
x &= 1 << 5;  // Get the 5th bit
x  =   ~(x);  // Flip all bits
```

## C bitwise operators
|  ==  Binary OR

^  ==  Binary XOR

&  ==  Binary AND

~  ==  One's Complement / Flip 0s to 1s, and 1s to 0s

<< ==  Left Shift operator

\>\> ==  Right Shift operator

## Binary math
   0110 + 0111 = 1101
   
   6 +    7 =   13

## Getting, Setting, and Flipping Bits
Getting (AND)

    0 & 0 == 0
    
    0 & 1 == 0
    
    1 & 0 == 0
    
    1 & 1 == 1
Setting (OR)

    0 | 0 == 0
    
    0 | 1 == 1
    
    1 | 0 == 1
    
    1 | 1 == 1
Flipping (XOR)

    0 ^ 0 == 0
    
    0 ^ 1 == 1
    
    1 ^ 0 == 1
    
    1 ^ 1 == 0
