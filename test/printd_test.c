#include <stdio.h>

void printd ( int n );

void main () {
 
    int i = 0;
    
    i = 123;

    printd ( i ); 
    printf ( "\n" );
   
    printf ( "1 \% 10 = %d;\n", 1 % 10 );
 
}

void printd ( int n ) {

    if ( n < 0 ) {
        putchar ( '-' );
        n = -n;
    }

    if ( n / 10 ) {
        printf ( "inside second check n = %d;\n", n );
        printd ( n / 10 );
    };

    printf ( "at this step n = %d;\n", n );
    putchar ( n % 10 + '0' );
    printf ( "\n\n" ); 
    
}
