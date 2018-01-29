/* 
 *Lab of Computer Architecture 
 * 
 * <Please put your name and userid here>
 * Name: Li Minchao
 * ID: 515030910361
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
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  int xtmp = ~x;
  int ytmp = ~y;
  int ans = xtmp | ytmp;
  ans = ~ans;
  return ans;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int movIndex = n << 3;
  int shft = x >> movIndex;
  int ans = shft & 255;
  return ans;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // 0x80000000 to 0x40000000
  int base = 0x80000000;
  base = ~((base >> n) << 1);
  int ans = x >> n;
  return (ans & base);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
  x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
  return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  x = x | (x >> 16);
  x = x | (x >> 8);
  x = x | (x >> 4);
  x = x | (x >> 2);
  x = x | (x >> 1);
  x = (~x) & 0x00000001;
  return x;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31);
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
int fitsBits(int x, int n) {
  int n_copy = n + 0xffffffff;
  int bit = (x >> n_copy) & 1;
  int x_shft = (x >> n_copy);
  return (!(x_shft + bit));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int low_bit = x & (~x + 1);
  int sgn = (x >> 31) & 1; // 1 represent negative
  int sgn2 = !(low_bit >> n); // 1 represent cannot div
  return ((x >> n) + (sgn & sgn2));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ((~x)+1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  int sgn = (x >> 31) & 1;
  return (!sgn) & (!(!x));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int x_sgn = (x >> 31) & 1;
  int y_sgn = (y >> 31) & 1;
  int equal = (x_sgn ^ y_sgn) & 1; // 1 represent not equal
  return ((!equal) & ~((~x + 1 + y) >> 31)) | (equal & x_sgn);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

  // deal with 16 bits
  int sgn_16 = !(!(x >> 16));
  int cnt_16 = sgn_16 << 4; // if x has 1 bit at 16:31, cnt at least has 16
  x = x >> cnt_16;
  // 16 bits left

  // deal with 8 bits
  int sgn_8 = !(!(x >> 8));
  int cnt_8 = sgn_8 << 3;
  x = x >> cnt_8;
  // 8 bits left

  // deal with 4 bits
  int sgn_4 = !(!(x >> 4));
  int cnt_4 = sgn_4 << 2;
  x = x >> cnt_4;
  // 4 bits left

  // deal with 2 bits
  int sgn_2 = !(!(x >> 2));
  int cnt_2 = sgn_2 << 1;
  x = x >> cnt_2;
  // 2 bits left

  // deal with 1 bit
  int sgn_1 = !(!(x >> 1));
  int cnt_1 = sgn_1;
  x = x >> cnt_1;
  // finish

  return (cnt_16 + cnt_8 + cnt_4 + cnt_2 + cnt_1);
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int sgn = uf >> 31;
  int e = (uf >> 23) & 0xff;
  int m = uf & 0x007fffff;
  if(e == 0xff && m) return uf;
  if(sgn) return (uf & 0x7fffffff);
  else return (uf | 0x80000000);
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  // the float is stored in (S, E, M)
  // S occupys one bit, E occupys 8 bits, M occupys 23 bits.
  // the float is interpretered as (-1)^S * M * 2^E
  if(!x) return 0;
  if(x == 0x80000000) return 0xcf000000;
  int ans = 0;
  int sgn = x >> 31;
  if(sgn){x = -x;}
  ans = ans | (sgn << 31);
  
  int bit_msk = 0x40000000;
  int cnt = 30;
  while(1)
  {
	if(bit_msk & x) break;
    else cnt -= 1;
    bit_msk >>= 1;
  }

  if(cnt > 23)
  {
    ans = ans | ((x >> (cnt - 23)) & 0x007fffff);
    int msk = ((1 << (cnt - 23)) - 1) & x;
    if(msk > (1 << (cnt - 24))) 
	{
	  ans += 1; 
	  if(!(ans & 0x007fffff)) {cnt += 1; ans -= 0x00800000;}
	}
    else if(msk == (1 << (cnt - 24)) && (ans & 1))
	{
	  ans += 1; 
	  if(!(ans & 0x007fffff)) {cnt += 1; ans -= 0x00800000;}
	}
  }
  else ans = ans | ((x << (23 - cnt)) & 0x007fffff);
  
  int e = 127 + cnt;
  ans = ans | (e << 23);
  
  return ans;
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
unsigned float_twice(unsigned uf) {
  int e = (uf >> 23) & 0x000000ff;
  int ans;
  if(!e) 
  {
    int m = uf & 0x007fffff;
    return ((uf & 0x80000000) | (m << 1));
  }
  else if(e == 0x000000ff) return uf;
  else
  {
    e += 1;
    ans = (uf & 0x807fffff) ^ (e << 23);
    return ans;
  }
}
