#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop ( char s [ MAXVAL ] ) {

    int i = 0;
    int c = 0;
    int bufp = 0;
    char buf [ MAXVAL ];
    
//  bufp = 0;
     
    printf ( "In function getop bufp = %d; buf [ bifp - 1 ] = %c.\n", bufp, buf [ bufp - 1 ] );

    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        ;
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( c ) && c != '.' ){
        return c; /* is not a number */
    };
    i = 0;
    
    if ( isdigit ( c ) )        /* getting whole part */
        while ( isdigit ( s [ ++i ] = c = getch () ) )
//            ++i;
        ;
    
    if ( c == '.' )             /* getting fractional part */
        while ( isdigit ( s [ ++i ] = c = getch () ) ){
            printf ( "s [ i = %d ] = %d in digit and %c in char;\n", i, s [ i ], s [ i ] );
        };
        

    s [ i ] = '\0';
    if ( c != EOF )
        ungetch ( c );
    printf ( "Whole string is:%s;\n", s );    
    return NUMBER;

}


