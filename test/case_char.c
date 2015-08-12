#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    char c = 0;
    
    printf ( "NUMBER = %c;\n", NUMBER );

    while ( ( c = getchar () ) != EOF ){
        switch ( c ) {
        case NUMBER:
            printf ( "NUMBER = %c;\n", c );
            break;
        default:
            printf ( "Not NUMBER.\n");
            break;        
        }
    }

}