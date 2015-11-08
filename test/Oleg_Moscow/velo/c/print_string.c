#include <stdio.h>
#include <string.h>

void main () {

    short int i = 0; 
    char string [ 1000 ];

    FILE *file1;

    file1 = fopen ( "first_string", "r" );
    
    for ( i = 0; i < 1000; i++ )
        string [ i ] = 0;

    fgets ( string, 400, file1 );

    for ( i = 0; i < strlen ( string ); i++ ) {
        printf ( "char [ i = %d ] = %d in digital and %c in char;\n", i, string [ i ], string [ i ] );

    }    











}
