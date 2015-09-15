#include <stdio.h>
#define BUFSIZE  100

int bufp = 0;
char buf [ BUFSIZE ];
int getch ( void );
void ungetch ( int c );

void main ()

{

    int i = 0;
    char c = 0;

    char symbols [ 10 ];

    for ( i = 0; i < 10; i++ ){
        ungetch ( i * 10 );
        printf ( "i = %d; buf [ %d ] = %d; bufp = %d;\n", i, i, buf [ i ], bufp );
    }

    printf ( "--------------------\n");
    printf ( "bufp = %d;\n", bufp );
    printf ( "--------------------\n");


    while ( ( c = getch () ) != EOF ){
        printf ( "bufp = %d; getch ( c ) = %d;\n", bufp, c );
    }
}

int getch ( void )

{
    return ( ( bufp > 0 ) ? ( buf [ -- bufp ] ) : getchar () );


}

void ungetch ( int c )

{
    if ( bufp >= BUFSIZE )
        printf ( "Too much.\n" );
    else 
        buf [ bufp ++ ] = c;

}


