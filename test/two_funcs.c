#include <stdio.h>

void f1 ( void );
void f2 ( char line [ 10 ], int pointer );

void main () {

    f1 ();

}

void f1 ( void ) {

    char string [ 10 ] = "string1";
 
    int pointer = 0;

    printf ( "before f2 string = %s;\n", string );
    f2 ( string, pointer );
    printf ( "after f2 string = %s;\n", string );
    
}

void f2 ( char line [ 10 ], int pointer ) {

    

}
