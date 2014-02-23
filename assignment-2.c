/*
Name: Timothy Baker
S/N:  11380666
Date: 18OCT13
*/

#include <stdio.h>
#include <string.h> /* Required for various string manipulation functions */

#define MAK_SIZ  15 /* Amount of characters in the element 'make' of structure 'Car' */
#define MAX_CARS 10 /* Maximum amount of cars able to be stored */

/* User-defined type definitions */

typedef struct {
   int day;
   int month;
   int year;
} Date;

typedef struct {
   char make[MAK_SIZ];
   Date manufactureDate;
   Date purchaseDate;
   double purchasePrice;
} Car;

/* Function prototypes - see bottom for individual descriptions */

void welcome(void); /* Prompt functions */
void menu(void);
void quit(void);

void readFleet(Car fleet[]); /* Input functions */
void getDate(Date *dateIn);
void addCar(Car *carIn);

void saveFleet(Car fleet[]); /* Output functions */
void showDate(Date *dateOut);
void showCar(Car *carOut);
void showFleet(Car fleet[]);

/* Main function */

int main(void)
{
   char inp; /* User input command */
   int i; /* Flag variable to determine where sentinel value is stored */

   Car fleet[MAX_CARS + 1];
   strcpy(fleet[0].make, "END"); /* Make the first element the sentinel value - i.e. empty fleet */

   welcome();
   menu();

   while (!0)
   {
      scanf("%c", &inp);
      switch(inp)
      {
         case 'D': /* Display currently loaded fleet */
            if (strcmp(fleet[0].make, "END")) /* Check for empty fleet array data */
            {
               showFleet(fleet);
            }
            else
            {
               printf("\nFleet empty, add a car before displaying fleet.\n\n");
            }
            break;
         case 'r': /* Read fleet from file */
            readFleet(fleet);
            printf("Successfully opened \"fleet.bin\"!\n\n");
            break;
         case 's': /* Save fleet to file */
            saveFleet(fleet);
            printf("Successfully saved to \"fleet.bin\"!\n\n");
            break;
         case 'a': /* Add car to currently loaded fleet */
            i = 0;
            while (strcmp(fleet[i].make, "END")) /* Check where sentinel value "END" is stored */
            {
               i += 1;
            }
            if (i < MAX_CARS) /* Memory space for new car */
            {
               addCar(&fleet[i]);
               strcpy(fleet[i + 1].make, "END");
            }
            else /* No memory space for new car */
            {
               printf("\nFleet full, delete a car from fleet.\n\n");
            }
            break;
         case 'd': /* Delete the last car of the currently loaded fleet */
            i = 0; /* Flag to find location of sentinel value */
            while (strcmp(fleet[i].make, "END")) /* Check where the sentinel value is stored */
            {
               i += 1;
            }
            if (i == 0) /* Fleet was empty to start with */
            {
               printf("\nFleet already empty, add a car to fleet.\n\n");
            }
            else if (i == 1) /* Fleet now becomes empty */
            {
               strcpy(fleet[i - 1].make, "END");
               printf("\nFleet now empty, add a car to fleet.\n\n");
            }
            else /* Fleet has some data still stored in it */
            {
               strcpy(fleet[i - 1].make, "END");
               showFleet(fleet); /* For user-friendly and intuitive interface */
            }
            break;
         case 'm': /* Display menu options */
            menu();
            break;
         case 'q': /* Quit program */
            quit();
            return(0);
            break;
      }
   }
   return (0);
}

void welcome(void) /* Print welcome message */
{
   printf("================================================================================\n");
   printf("=========================== CAR FLEET DATABASE v0.1  ===========================\n");
   printf("================================================================================\n");
   printf("\n");
   printf("Load, save and edit (add to, or delete from) a fleet by following the\n");
   printf("instructions:\n");
}

void menu(void) /* Prints menu */
{
   printf("\n 'D' display fleet\n");
   printf(" 'r' read fleet from file\n");
   printf(" 's' save fleet to file\n");
   printf(" 'a' add new car to fleet\n");
   printf(" 'd' delete last car from fleet\n");
   printf(" 'm' display menu\n");
   printf(" 'q' quit\n\n");
}

void quit(void) /* Prints quit message */
{
   printf("\n================================================================================\n");
   printf("================== Thanks for using Car Fleet Database v0.1! ===================\n");
   printf("================================================================================");
}

void getDate(Date *dateIn) /* Takes pointer to struct Date input and scans values
                              (in appropriate ranges) into 'year', 'month' and 
                              'day' struct elements */
{
   do
   {
      printf(" Enter year: ");
      scanf("%d", &(*dateIn).year);
   } while ((*dateIn).year < 0); /* Error checking in case of negative year value */
   
   do
   {
      printf(" Enter month: ");
      scanf("%d", &(*dateIn).month);
   } while ((*dateIn).month < 1 ||
            (*dateIn).month > 12); /* Error checking for month value range 1-12 inclusive */
   
   if ((*dateIn).month == 2) /* Month is February (requires leap year test) */
   {
      if ((*dateIn).year % 400 == 0) /* Is a leap year */
      {
         do
         {
            printf(" Enter day: ");
            scanf("%d", &(*dateIn).day);
         } while ((*dateIn).day < 1 ||
                  (*dateIn).day > 29); /* Error checking for day value range 1-29 inclusive */
      }
      else if ((*dateIn).year % 100 == 0) /* Is NOT a leap year */
      {
         do
         {
            printf(" Enter day: ");
            scanf("%d", &(*dateIn).day);
         } while ((*dateIn).day < 1 ||
                  (*dateIn).day > 28); /* Error checking for day value range 1-28 inclusive */
      }
      else if ((*dateIn).year % 4 == 0) /* Is a leap year */
      {
         do
         {
            printf(" Enter day: ");
            scanf("%d", &(*dateIn).day);
         } while ((*dateIn).day < 1 ||
                  (*dateIn).day > 29); /* Error checking for day value range 1-29 inclusive */
      }
      else /* Is NOT a leap year */
      {
         do
         {
            printf(" Enter day: ");
            scanf("%d", &(*dateIn).day);
         } while ((*dateIn).day < 1 ||
                  (*dateIn).day > 28); /* Error checking for day value range 1-28 inclusive */
      }
   }
   else if ((*dateIn).month == 4 ||
            (*dateIn).month == 6 ||
            (*dateIn).month == 9 ||
            (*dateIn).month == 11) /* Months with 30 days */
   {
      do
      {
         printf(" Enter day: ");
         scanf("%d", &(*dateIn).day);
      } while ((*dateIn).day < 1 ||
               (*dateIn).day > 30); /* Error checking for day value range 1-30 inclusive */
   }
   else if ((*dateIn).month == 1 || 
            (*dateIn).month == 3 ||
            (*dateIn).month == 5 ||
            (*dateIn).month == 7 ||
            (*dateIn).month == 8 ||
            (*dateIn).month == 10 ||
            (*dateIn).month == 12) /* Months with 31 days */
   {
      do
      {
         printf(" Enter day: ");
         scanf("%d", &(*dateIn).day);
      } while ((*dateIn).day < 1 ||
               (*dateIn).day > 31); /* Error checking for day value range 1-31 inclusive */
   }
}

void addCar(Car *carIn) /* Allows user to add car to the fleet array */
{
   printf("\nEnter the make: "); /* Prompt user to enter each data field */
   scanf("%s", (*carIn).make);
   printf("Manufacture date:\n");
   getDate(&(*carIn).manufactureDate);
   printf("Purchase date:\n");
   getDate(&(*carIn).purchaseDate);
   do
   {
      printf("Enter the purchase price (e.g. '10000.00' to represent '$10000.00'): ");
      scanf("%lf", &(*carIn).purchasePrice);
   } while ((*carIn).purchasePrice < 0); 
   printf("\n"); /* Error checking in case of negative price value */
}

void readFleet(Car fleet[]) /* Reads fleet array data from a binary file */
{
   FILE *fileRead;
   fileRead = fopen("fleet.bin", "rb"); /* Open file "fleet.bin" in binary read-mode */
   if (fileRead == NULL) /* Error checking in case of missing file */
   {
      printf("\nFailed to open \"fleet.bin\"...\n");
   }
   else
   {
      fread(fleet, sizeof(Car), MAX_CARS + 1, fileRead); /* Read data from "file.bin" */
      printf("\nOpening \"fleet.bin\"...\n");
   }
   fclose(fileRead); /* Close file "fleet.bin" before continuing */
   showFleet(fleet);
}

void saveFleet(Car fleet[]) /* Save fleet array data to a binary file */
{
   FILE *fileSave;
   fileSave = fopen("fleet.bin", "wb"); /* Open file "fleet.bin" in binary write-mode */
   if (fileSave == NULL) /* Error checking in case of missing file */
   {
      printf("\nFailed to save \"fleet.bin\"...\n\n");
   }
   else
   {
      fwrite(fleet, sizeof(Car), MAX_CARS + 1, fileSave); /* Write data to "file.bin" */
      printf("\nSaving to \"fleet.bin\"...\n\n");
   }
   fclose(fileSave); /* Close file "fleet.bin" before continuing */
}

void showDate(Date *dateOut) /* Used in showCar - Prints out Date data in an appropriately formatted manner */
{
   printf("%02i/%02i/%04i\n", (*dateOut).day,
                              (*dateOut).month,
                              (*dateOut).year);
}

void showCar(Car *carOut) /* Used in showFleet - Prints out Car data in an appropriately formatted manner. */
{
   printf("  Make:             %s\n", (*carOut).make);
   printf("  Manufacture date: ");
   showDate(&(*carOut).manufactureDate);
   printf("  Purchase date:    ");
   showDate(&(*carOut).purchaseDate);
   printf("  Purchase price:   $%.2f\n", (*carOut).purchasePrice);
}

void showFleet(Car fleet[]) /* Prints out entire fleet array data in a user-friendly format */
{
   int i = 0; /* Flag/counter to cycle through each car in fleet array and ... */

   printf("\n");
   printf(" ==============================\n");
   printf(" ========= CAR FLEET ==========\n");
   printf(" ==============================\n\n");

   while (strcmp(fleet[i].make, "END")) /* ... check for sentinel value "END" before printing car data */
   {
      int j;
      j = i + 1;
      printf(" Car ID: #%d\n\n", j);
      showCar(&fleet[i]);
      printf("\n");
      i += 1;
   }
}

/*
================================================================================
=========================== Car Fleet Database v0.1  ===========================
================================================================================

A program to keep track of a fleet of up to 10 cars!

Load, save and edit (add to, or delete from) a fleet by following the
instructions:

 'D' display fleet
 'r' read fleet from file
 's' save fleet to file
 'a' add new car to fleet
 'd' delete last car from fleet
 'm' display menu
 'q' quit

D

Fleet empty, add a car before displaying fleet.

d

Fleet already empty, add a car to fleet.

a

Enter the make: Honda
Manufacture date:
 Enter year: -2000
 Enter year: -100
 Enter year: 2008
 Enter month: -6
 Enter month: 3
 Enter day: 32
 Enter day: 31
Purchase date:
 Enter year: 2012
 Enter month: 5
 Enter day: 4
Enter purchase price (e.g. '10000.00' to represent '$10000.00'): 34990.00

D

 ==============================
 ========= CAR FLEET ==========
 ==============================

 Car ID: #1

  Make:             Honda
  Manufacture date: 31/03/2008
  Purchase date:    04/05/2012
  Purchase price:   $34990.00

d

Fleet now empty, add a car to fleet.

r

Opening "fleet.bin"...

 ==============================
 ========= CAR FLEET ==========
 ==============================
 
 Car ID: #1

  Make:             Toyota
  Manufacture date: 26/02/2001
  Purchase date:    15/08/2007
  Purchase price:   $8000.00

 Car ID: #2

  Make:             Audi
  Manufacture date: 31/03/2012
  Purchase date:    17/10/2013
  Purchase price:   $96990.00

 Car ID: #3

  Make:             Holden
  Manufacture date: 18/02/2005
  Purchase date:    29/02/2012
  Purchase price:   $24990.00

 (...)

 Car ID: #10

  Make:             Honda
  Manufacture date: 08/03/2009
  Purchase date:    04/05/2010
  Purchase price:   $43000.00

Succuessfully opened "fleet.bin"!

a

Fleet full, delete a car from fleet.

d

 ==============================
 ========= CAR FLEET ==========
 ==============================

 Car ID: #1

  Make:             Toyota
  Manufacture date: 26/02/2001
  Purchase date:    15/08/2007
  Purchase price:   $8000.00

 Car ID: #2

  Make:             Audi
  Manufacture date: 31/03/2012
  Purchase date:    17/10/2013
  Purchase price:   $96990.00

 Car ID: #3

  Make:             Holden
  Manufacture date: 18/02/2005
  Purchase date:    29/02/2012
  Purchase price:   $24990.00

 (...)

 Car ID: #9

  Make:             Suzuki
  Manufacture date: 02/10/2007
  Purchase date:    15/06/2011
  Purchase price:   $14990.00

s

Saving to "fleet.bin"...

Successfully saved to "fleet.bin"!

m

 'D' display fleet
 'r' read fleet from file
 's' save fleet to file
 'a' add new car to fleet
 'd' delete last car from fleet
 'm' display menu
 'q' quit

q

================================================================================
===================== Thanks for using Car Fleet Database! =====================
================================================================================
*/
