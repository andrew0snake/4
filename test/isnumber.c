#include <stdio.h>

#define NUMBER '0'

void main ()
{
    int i = 0;
    int c = 0;


    while ( ( c = getchar () ) != EOF ){
        switch ( c ){ 
           case NUMBER:   
               printf ( "1. c == NUMBER;\n" );
               break;
           case 'q':
               printf ( "2. c == q;\n" );
               break;
        }
     }





}
