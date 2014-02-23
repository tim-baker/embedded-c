/* Timothy Baker - 11380666 - Sep 2013 */

/* This program finds and prints all the factors of all perfect numbers within a defined range */

#include <stdio.h>
#define COUNT 10000                                                       /* The value up to which the perfect numbers are tested                */

int perfect(int number);                                                  /* Returns a '1' if the paramter 'number' is perfect                   */
void intro(void);                                                         /* Prints an introduction message to explain the program to the user   */
void twirly(void);                                                        /* Prints a '|', '/', '-' and '\' to indicate all is running correctly */

int main(void)
{
   int num;                                                               /* Counter to test through the numbers 1 to 10000                      */
   int factor_count;                                                      /* Counter to test all factors possible factors of 'num'               */
   int flag;                                                              /* 'Boolean' use of an int - to alert whether number is perfect or not */
   int remaind;                                                           /* Remainder value when testing for factors with modulus operator      */

   intro();

   for (num = 1; num <= COUNT; num++)                                     /* Loop to test all numbers from 1 to 10000, inclusive                 */
   {
      flag = perfect(num);
      if (flag == 1)
      {
         for (factor_count = num - 1; 0 < factor_count; factor_count--)   /* Finds and prints all factors of 'num'                               */
         {                                                                /* then prints the the value of 'num'                                  */
            remaind = num % factor_count;
            if (remaind == 0)
            {
               printf("+ %d ", factor_count);
            }
            else
            {
               /* null statement */
            }
         }
         printf("= %d\n", num);
      }
      else                                                                /* A twirly is printed when 'flag' remains 0 value - i.e. the next     */
      {                                                                   /* perfect number is yet to be found                                   */
         twirly();
      }
   }
   printf(" \r");                                                         /* Clear the remaining '\' character once test loop finishes           */
   return(0);
}

int perfect(int number)                                                   /* Returns a '1' if the paramter 'number' is perfect                   */
{
   int func_counter;                                                      /* Counter to test all possible factors of parameter 'number'          */
   int func_remaind;                                                      /* Remainder value when testing for factors with modulus operator      */
   int func_flag;                                                         /* Return variable for the function                                    */
   int func_factor_sum = 0;                                               /* Sum of the factors found of parameter 'number'                      */

   for (func_counter = number - 1; 0 < func_counter; func_counter--)      /* Finds and sums the factors of 'number'                              */
   {
      func_remaind = number % func_counter;
      if (func_remaind == 0)
      {
         func_factor_sum += func_counter;
      }
      else
      {
         /* null statement */
      }
   }
   if (func_factor_sum == number)
   {
      func_flag = 1;                                                      /* If the sum equals the number, perfect() returns integer value '1'   */
   }
   else
   {
      func_flag = 0;                                                      /* If not, perfect() returns integer value '0'                         */
   }
   return(func_flag);
}

void intro(void)                                                          /* Prints an introduction message to explain the program               */
{
   printf("The perfect numbers from 1 to 10,000 will be printed below:\n\n");
   printf("This is proven by the summation of all factors - excl. the number itself.\n\n");
}

void twirly(void)                                                         /* Prints a '|', '/', '-' and '\' to indicate all is running correctly */
{
   printf("|\r");
   printf("/\r");
   printf("-\r");
   printf("\\\r");
}

/* The perfect numbers from 1 to 10,000 will be printed below:

   This is proven by the summation of all factors - excl. the number itself.

   + 3 + 2 + 1 = 6
   + 14 + 7 + 4 + 2 + 1 = 28
   + 248 + 124 + 62 + 31 + 16 + 8 + 4 + 2 + 1 = 496
   + 4064 + 2032 + 1016 + 508 + 254 + 127 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 8128
     */
