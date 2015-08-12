#include <stdio.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    int c = 0;


    while ( ( c = getchar () ) != EOF ){
       if ( c == NUMBER )
           printf ( "c == NUMBER;\n" );
       else {
           if ( c == '\n' )
               printf ( "c == \\n;\n" );
           else
               printf ( "c is NOT NUMBER;\n" ); 
           }
    
    }




}
