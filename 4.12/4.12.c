#include <stdio.h>

#define MAXSIZE 100

unsigned short int pointer = 0;

void printd ( int n );
void itoa_rec ( int a, char array [ MAXSIZE ] );
void clear_array ( char array [ MAXSIZE ] );

void main () {
 
    int i = 0;
    int s = 0;
    char digit [ MAXSIZE ];    

    i = 123798;
    clear_array ( digit );   
 
    printf ( "i = %d.\n", i );

    itoa_rec ( i, digit );

    for ( s = 0; s < pointer; s++ ) {
        printf ( "at step %d digit [ %d ] = %c;\n", s, s, digit [ s ] );

    }

}

void itoa_rec ( int a, char array [ MAXSIZE ] ) {

    if ( a < 0 ) {
        array [ pointer ] = '-';
        pointer++;
        a = -a;
    };

    if ( a / 10 ) {
        itoa_rec ( a / 10, array );

    };

    array [ pointer ++ ] = ( a % 10 + '0' );

}

void clear_array ( char array [ MAXSIZE ] ) {

    int i = 0;
 
    for ( i = 0; i < MAXSIZE; i++ ) {
        array [ i ] = 0;
        
    };

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
