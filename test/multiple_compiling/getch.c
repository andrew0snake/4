#include <stdio.h>
#define BUFSIZE 100

static char buf [ BUFSIZE ];
static int bufp = 0;

int getch  ( void ) {
    printf ( "In function getch bufp = %d; buf [ bifp - 1 ] = '%c'.\n", bufp, buf [ bufp - 1 ] );
    return ( ( bufp > 0 ) ? ( buf [ --bufp ] ) : getchar () );

}

void ungetch ( int c ) {

    printf ( "In function ungetch bufp = %d; buf [ bifp  ] = '%c'.\n", bufp, buf [ bufp ] );

    if ( bufp >= BUFSIZE )
        printf ( "ungetch: too much symbols.\n" );
    else 
        buf [ bufp++ ] = c;

}
