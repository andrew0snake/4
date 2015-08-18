#include <stdio.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    int c = 0;


    while ( ( c = getchar () ) != EOF ){
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




}
