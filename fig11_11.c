/* Fig. 11.11: Creating a random-access file sequentially */
#include <stdio.h>
struct clientData { /* clientData structure definition */
   int acctNum;          /* account number */
   char lastName[ 15 ];  /* account last name */
   char firstName[ 10 ]; /* account first name */
   double balance;       /* account balance */
};
int main()
{  int i; /* counter used to count from 1-100 */
   /* create clientData with default information */
   struct clientData blankClient = { 0, "", "", 0.0 }; 
   FILE *cfPtr; /* credit.dat file pointer */
   if ( ( cfPtr = fopen( "credit.dat", "wb" ) ) == NULL ) {
      printf( "File could not be opened.\n" );
   }
   else { 
      /* output 100 blank records to file */
      for ( i = 1; i <= 100; i++ ) {
         fwrite( &blankClient, sizeof( struct clientData ), 
		 1, cfPtr );
      }
      fclose ( cfPtr ); /* fclose closes the file */
   }
   return 0; }zzz