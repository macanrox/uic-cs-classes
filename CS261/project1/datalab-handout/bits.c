/* 
 * CS:APP Data Lab 
 * 
 * Bresia Prudente, bprude2
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) 
{
	/* We have two masks to check all bits */
	/* m1 is a mask that looks at the 2 LEAST significant bytes 
	   m2 is another mask that will look at the rest of the bytes */
	
	int m1 = 0x11|(0x11 << 8);
	int m2 = m1|(m1 << 16);
	
	/* firstFour will represent the number of 1's in a word */
	int firstFour = x & m2;
	
	/* We compute for the number of bits within the first 4 bits */
	firstFour += (x >> 1) & m2;
	firstFour += (x >> 2) & m2;
	firstFour += (x >> 3) & m2;
	
	/* If there's more than 4 bits, we watch out for overflow and adjust */
	firstFour = firstFour + (firstFour >> 16);
	
	/* Save the current value and then move on to the next byte */
	m1 = 0xF|(0xF << 8);
	
	/* Add the values and 4 bits together */
	firstFour = (firstFour & m1) + ((firstFour >> 4) & m1);
	
	/* We only want a max of 6 bits */
	return (((firstFour + (firstFour >> 8)) & 0x3F));
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) 
{
	/* We define the sign, exp and frac */
	unsigned sign = uf & 0x80000000;
	unsigned exp = (uf >> 23) & 0xFF;
	unsigned frac = uf & 0x007FFFFF;
	
	/* If the argument is NaN, we return it */
	if((exp == 255) || (exp == 0 && frac == 0))		//NaN
	{
		return uf;
	}
	
	/* When it's normalized, we increment the exp */
	if(exp)		//normalized
	{
		exp++;
	}
	else if(frac == 0x7FFFFF)
	{
		frac--;
		exp++;
	}
	/* If it's denormalized, we make sure the result is normalized
	   then we get rid of a bit */
	else	//denormalized
	{
		frac <<= 1;
	}
	
	return (sign | (exp << 23) | frac);
}

/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) 
{
	/* Shift by w-8 */
	int shift_val = (sizeof(int)-1)<<3;
	/* Arithmetic shift */
	int xright = x >> shift_val;
	/* Zero all but LSB */
	return xright & 0xFF;
}
			   
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) 
{
	/* Create the sum */
	int result = x + y;
	
	/* If there's a POSITIVE overflow, return the max possible value */
	int overFlow1 = ((result^x) & (result^y)) >> 31;
	
	/* If there's a NEGATIVE overflow, return the least possible value */
	return (((~overFlow1) & result) | (overFlow1 & ((1 << 31)^(result >> 31))));
}

/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) 
{
	/* neg and pos are 0 or if either are negative or positive */
	int mask1 = 1 << 31;
	int neg = (mask1 & x) >> 31;
	int pos = ~neg;
	int sign = mask1 & x;
	
	/* If it's set, reverse complement neg */
	neg = neg & x;
	pos = pos & x;
	
	neg = ~(neg + ~0);
	
	/* Add up everything to get two's complement */
	return (sign + pos + neg);
	
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) 
{
	return ((((!x) - 1) & y) + ((~((!x) - 1)) & z));
}

/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) 
{
	/* Define variables */
	int a1 = x & ~0x3F;
	int a2 = ((x & 0xF) + 6) & 0x10;
	int a3 = (x & 0x30) ^ 0x30;
	
	/* Combine into a NOT statement */
	return !(a1 | a2 | a3);
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) 
{
    /* sign checks x by masking the sign of the bit */
	int sign = !((1 << 31) & x);
	
	/* Check if x is 0 */
	int isZero = !x;
	
	/* Combine both sign and isZero */
	return (sign^isZero);
	
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) 
{
	/* This will mask whatever is the value and then replace it */
	int nMax = n << 3;
	int shift = c << nMax;
	int mask = 0xff << nMax;
	
	/* Combine everything */
	return ((x & ~mask) | shift);
}

/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) 
{
	/* This calculates how many bits to right-shift */
	int xRightShift = 32 + (~n + 1);
	
	/* Shifting bits */
	int rShift = ((4 << 3) + (~1 + 1));
	
	/* This logically right-shifts the bits (rotates left) */
	return (((x << n) | ((x >> xRightShift) & ~(((x >> rShift) << rShift)) >> (xRightShift + (~1 +1)))));
}

/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) 
{
	/* Mask to get even-numbered bits
	   then use the double negation to change non-zero to 1
	   and 0 to 0*/
	return !!(x & (0x55 + (0x55 << 8) + (0x55 << 16) + (0x55 << 24)));
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) 
{
	/* Define nbyte and mbyte which shifts the number of bytes */
	int mShift = m<<3;
	int nShift = n<<3;
	
	/* Define masks that have 1's at a specific byte
	   This will copy and erase these parts out of the original */
	int maskM = 0xff << mShift;
	int maskN = 0xff << nShift;
	
	/* Copy ONLY the 1's at a byte or bytes to nByte and mByte */
	int mByte = x & maskM;
	int nByte = x & maskN;
	
	/* Set a byte of x to be 0's to copy (other bits won't be affected) */
	x = x & (~maskN);
	x = x & (~maskM);
	
	/* Shift the copied bytes to the beginning */
	mByte = mByte >> mShift;
	nByte = nByte >> nShift;
	
	/* Double check if the next MSB of x is a 1 */
	mByte = mByte & 0xff;
	nByte = nByte & 0xff;
	
	/* Place the copied bytes into the position of the other copied bytes */
	mByte = mByte << nShift;
	nByte = nByte << mShift;
	
	/* Copy the copied bytes back into their new position in x */
	x = x | mByte;
	x = x | nByte;
	
	return x;
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) 
{
	/* Mask the sign bit to get the max bit of x */
	int mask1 = x >> 31;
	
	/* Shift */
	return !(((~x & mask1) + (x & ~mask1)) >> (n + ~0));
}

/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) 
{
	
	/* Define exp and shift */
	int exp = (uf & 0x7f800000) >> 23;
	
	/* When argument is NaN, return it 
	   otherwise return the value */
	if((exp == 0xff) && ((uf & ((1 << 23) - 1)) != 0))		//NaN
	{
		return uf;
	}
	else	//return the value
	{
		return (uf & 0x7fffffff);
	}
}

/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) 
{
	/* We use NOT XOR for equality because XOR measures inequal bits */
	return !(x ^ y);
}

/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) 
{
	/* Define i and j as ~x and ~y respectively */
	int i = ~x;
	int j = ~y; 
	int k = i & j;
	
	return k;
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) 
{
	/* Define i, j, k as equations */
	int i = ~(x & ~y);
	int j = ~(~x & y);
	int k = ~(i & j);
	
	return k;
}

/* 
 * thirdBits - return word with every third bit (starting from the LSB) set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void) 
{
	/* Define x */
	int x = 0x24;
	
	/* Traverse through each third bit, starting from the LSB */
	x = x + (x << 6);
	x = x + (x << 12);
	x = x + (x << 24);
	
	/* Set each third bit as 1 */
	return ((x << 1) + 1);
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) 
{
	/* The max is 0xEFFF so all we do is insert a 1 to the most significant bit */
	return ~(1 << 31);
}

/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) 
{
	/* We shift all the bits (of the left operand) for the first n bits*/
	return ((!!n & 1) << 31) >> (n + (~1 + 1));
}
