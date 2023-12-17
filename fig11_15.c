/* Fig. 11.15: Reading a random access file sequentially */
#include <stdio.h>
struct clientData { /* clientData structure definition */
   int acctNum;          /* account number */
   char lastName[ 15 ];  /* account last name */
   char firstName[ 10 ]; /* account first name */
   double balance;       /* account balance */
};
int main()
{  FILE *cfPtr; /* credit.dat file pointer */
   struct clientData client = { 0, "", "", 0.0 };
   if ( ( cfPtr = fopen( "credit.dat", "rb" ) ) == NULL ) {
      printf( "File could not be opened.\n" );   }
   else { 
      printf( "%-6s%-16s%-11s%10s\n", "Acct", "Last Name",
         "First Name", "Balance" );
      while ( !feof( cfPtr ) ) { 
         fread( &client, sizeof( struct clientData ), 1, cfPtr );
         if ( client.acctNum != 0 ) {
            printf( "%-6d%-16s%-11s%10.2f\n", 
               client.acctNum, client.lastName, 
               client.firstName, client.balance );   }
      }
      fclose( cfPtr ); 
   }
   return 0;   }