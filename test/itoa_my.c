#include <stdio.h>
#include <string.h>

void itoa_my ( int digit, char string [ 1000 ] );

void main () {

    int i = 0;
    char string_to [ 1000 ];
    char c = 0;

    printf ( "Input digit, which you want to convert to string:" );
    scanf ( "%d", &i );
    printf ( "getted i = %d; and i % 10 = %d;\n", i, i % 10 );
    c = '0';
    printf ( "0 = %d, 1 = %d;\n", c, 1 );
//    itoa_my ( i, string_to );

}

void itoa_my ( int digit, char string [ 1000 ] ) {

    int value = 0;
    int residual = 0;
    
    value = digit;

    while ( value > 1 ) {
        residual  = value % 10;

    }    


}
