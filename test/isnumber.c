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
       if ( c == NUMBER )
           printf ( "c == NUMBER;\n" );
       else {
           if ( c == '\n' )
               printf ( "c == \\n;\n" );
           else
               printf ( "c is NOT NUMBER;\n" ); 
           }
    
    
        switch ( c ){ 
           case NUMBER:   
               printf ( "1. c == NUMBER;\n" );
               break;
           case 'q':
               printf ( "2. c == q;\n" );
               break;
        }
     }

    for ( i = 0; i < 100; ++i ){
        printf ( "i = %d in digit and = %c in char;\n", i, i );
 
    }


}
