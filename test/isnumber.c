#include <stdio.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    int c = 0;


    while ( ( c = getchar () ) != EOF ){
<<<<<<< HEAD
<<<<<<< HEAD
        switch ( c ) {
            case NUMBER:
                printf ( "c == NUMBER == %c;\n", c );
            case 'w':
                printf ( "c == w == %c;\n", c );

        } 
=======
       if ( c == NUMBER )
           printf ( "c == NUMBER;\n" );
       else {
           if ( c == '\n' )
               printf ( "c == \\n;\n" );
           else
               printf ( "c is NOT NUMBER;\n" ); 
           }
    
>>>>>>> c1c9a4cdbb85cace554b2744828bbbc6a4cc1e80
    }
=======
        switch ( c ){ 
           case NUMBER:   
               printf ( "1. c == NUMBER;\n" );
               break;
           case 'q':
               printf ( "2. c == q;\n" );
               break;
        }
     }

>>>>>>> 8f669f38a9d2deeff6882d14f7a2e0a11b5e1d44




}
