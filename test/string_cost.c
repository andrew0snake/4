# include <stdio.h>

void main () {

    char string [ 15 ];

    int i = 0;
    char c = 0;

    printf ( "Input string:" );

    i = 0;
    while ( c != EOF ) {
        c = getchar ();
        string [ i ] = c;
        i++;
    };

    printf ( "\n" );
    for ( i = 0; i <= 10; i++ ) {
        printf ( "string [ i = %d ] = %c in char and %d in digital;\n", i, string [ i ], string [ i ] );

    };

    printf ( "whole string is:%s;\n", string );

    string [ 4 ] = '\0';

    printf ( "after handly modifiyng string is:%s;\n", string );
    
    string [ 3 ] = 0;

    printf ( "after second handly modifiyng string is:%s;\n", string );

}
