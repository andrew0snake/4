#include <stdio.h>
#include <string.h>

void itoa_my ( int i, char string [ 1000 ] );

void main () {

    int i = 0;
    char string_to [ 1000 ];
    char c = 0;
    char d = 0;

    printf ( "Input digit, which you want to convert to string:" );
    scanf ( "%d", &i );
    printf ( "getted i = %d; and i %% 10 = %d;\n", i, i % 10 );

    c = '0';
<<<<<<< HEAD
    printf ( "0 = %d, 1 = %d;\n", c, 1 );
    itoa_my ( i, string_to );
    printf ( "returned string = %s;\n", string_to );
=======
    d = '1';
    printf ( "0 = %d, 1 = %d;\n", c, d );
    itoa_my ( i, string_to );
>>>>>>> a2b6d9420373033a071e96e319a30f7963a47a64

}

void itoa_my ( int digit, char string [ 1000 ] ) {

    int i = 0;
    int j = 0;
<<<<<<< HEAD
    int len = 0;
    int value = 0;
    int residual = 0;
    char tmp [ 1000 ];
    char rev [ 1000 ];   

    value = digit;

    printf ( "before cycle value = %d;\n" ,value );
    while ( value > 0 ) {
        residual  = value % 10;
        value /= 10;
        tmp [ i ] = residual + '0';
        i++;
        printf ( "tmp [ %d } = %c; value = %d;residual = %d;\n", i, tmp [ i ], value, residual );
    }    
    i--;
    len = i;
    for ( j = 0; j <= len; j++, i-- ) {
        rev [ j ] = tmp [ i ];
        printf ( "in reverse rev [ %d ] = %c; tmp [ %d ] = %c;\n", j, rev [ j ], i, tmp [ i ] );
    }
 
    strcpy ( string, rev );
=======
    int value = 0;
    int residual = 0;
    int len = 0;
    char tmp [ 1000 ];
    char rev [ 1000 ];
    
    value = digit;

    while ( value >= 1 ) {
        residual  = value % 10;
        value /= 10; 
        tmp [ i ] = residual + 48;
        printf ( "tmp [ %d ] = %c;\n", i, tmp [ i ] );
        i++;
    };    
    len = strlen ( tmp );
    printf ( "lenght of string tmp = %d;and half of it = %d;\n", len, len / 2 );

    for ( i = 0; i < len; i++ ) {
        if ( ( tmp [ len - i ] != '\n' ) && ( tmp [ len - i ] != ' ' ) && ( tmp [ len - i ] != '\t' ) ) {
            rev [ j ] = tmp [ len - i ];
            j++;
        }
//        printf ( "at step %d tmp [ %d ] = %3c in char and %d in digital; rev [ %d ] = %c in char and %d in digital;\n", i, i, tmp [ i ], tmp [ i ], j, rev [ j ], rev [ j ] );
    }
>>>>>>> a2b6d9420373033a071e96e319a30f7963a47a64

}
