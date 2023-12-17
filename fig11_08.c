/* Fig. 11.8: fig11_08.c Credit inquiry program */
#include <stdio.h>
int main()
{  int request, account;
   double balance;  /* account balance */
   char name[ 30 ]; /* account name */
   FILE *cfPtr;     /* clients.dat file pointer */
   if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
      printf( "File could not be opened\n" );
   }
   else { /* display request options */
      printf( "Enter request\n"
         " 1 - List accounts with zero balances\n"
         " 2 - List accounts with credit balances\n"
         " 3 - List accounts with debit balances\n"
         " 4 - End of run\n? " );
      scanf( "%d", &request );
      /* process user's request */
      while ( request != 4 ) { 
         /* read account, name and balance from file */
         fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
         switch ( request ) { 
            case 1:
               printf( "\nAccounts with zero balances:\n" );
               /* read file contents (until eof) */
               while ( !feof( cfPtr ) ) { 
                  if ( balance == 0 ) {
                     printf( "%-10d%-13s%7.2f\n", 
                        account, name, balance );
                  } /* end if */
                  /* read account, name and balance from file */
                  fscanf( cfPtr, "%d%s%lf", 
                     &account, name, &balance );
               } /* end while */
               break;
            case 2:
               printf( "\nAccounts with credit balances:\n" );
               /* read file contents (until eof) */
               while ( !feof( cfPtr ) ) { 
                  if ( balance < 0 ) {
                     printf( "%-10d%-13s%7.2f\n", 
                        account, name, balance );
                  } /* end if */
                  /* read account, name and balance from file */
                  fscanf( cfPtr, "%d%s%lf", 
                     &account, name, &balance );
               } /* end while */
               break;
            case 3:
               printf( "\nAccounts with debit balances:\n" );
               /* read file contents (until eof) */
               while ( !feof( cfPtr ) ) { 
                  if ( balance > 0 ) {
                     printf( "%-10d%-13s%7.2f\n", 
                        account, name, balance );
                  } /* end if */
                  /* read account, name and balance from file */
                  fscanf( cfPtr, "%d%s%lf", 
                     &account, name, &balance );
               } /* end while */
               break;
         }
         rewind( cfPtr ); /* return cfPtr to beginning of file */
         printf( "\n? " );
         scanf( "%d", &request );
      } 
      printf( "End of run.\n" );
      fclose( cfPtr ); /* fclose closes the file */
   }
   return 0; }