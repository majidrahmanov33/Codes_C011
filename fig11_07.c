/* Fig. 11.7: Reading and printing a sequential file */
#include <stdio.h>
int main()
{  int account;     /* account number */
   char name[ 30 ]; /* account name */
   double balance;  /* account balance */
   FILE *cfPtr;     /* cfPtr = clients.dat file pointer */

   if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
      printf( "File could not be opened\n" );
   } 
   else { 
      printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
      fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
      while ( !feof( cfPtr ) ) { 
         printf( "%-10d%-13s%7.2f\n", account, name, balance );
         fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
      } 
      fclose( cfPtr ); 
   } 
   return 0; }