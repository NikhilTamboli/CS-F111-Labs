#include <stdio.h>

/* The function 'negate' takes an integer as input and returns its negation
   Example: negate(10) returns -10.*/
int negate(int x) { return -1*x; }

/* The function 'add' takes two integers as input and returns its sum
   Example: add(10,20) returns 30.*/
int add(int x, int y){  return x+y;}

/* The function 'multiply' takes two integers as input and returns its product
   Example: multiply(10,20) returns 200.*/
int multiply(int x, int y){  return x*y;}

/* The function 'quotient' takes two integers x,y as input and returns the 
   quotient of dividing x by y.
   Example: quotient(25,10) returns 2.*/
int quotient (int x, int y){  return x/y;}

int main(void)
{
  int x = 100;
  int y = 9;
  int z = 10;
  int sum,squareSum,remainder;


  /* 
     Using function calls to the above user-defined functions, do the following:
     1. Calculate x + y and store the result in the variable sum.
     2. Calculate x^2 + y^2 + z^2 and store the result in the variable squareSum.
     3. Calculate the remainder of dividing x by y and store the result in the variable remainder.
     Example: Remainder of dividing 25 by 10 is 5.
  */


  sum = add(x,y); 
  squareSum = add(add(multiply(x,x), multiply(y,y)), multiply(z,z)); 
  remainder = add(100, negate(multiply(quotient(x,y),y))); 


  /*
    Print the values stored in sum, squareSum and remainder in a single line, separated by commas.
  */


  printf("Sum is %d, square sum is %d, and remainder is %d \n", sum, squareSum, remainder);


  
}
