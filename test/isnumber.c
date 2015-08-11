#include <stdio.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    int c = 0;


    while ( ( c = getchar () ) != EOF ){
        switch ( c ) {
            case NUMBER:
                printf ( "c == NUMBER == %c;\n", c );
            case 'w':
                printf ( "c == w == %c;\n", c );

        } 
    }




}
