#include <stdio.h>

int a = 0;
int b = 3;

void f1 ( void );

void main () {

    int x = 0;
 
    printf ( "in main a = %d;\n", a );    
    printf ( "in main b = %d;\n", b );    

    f1 ();

    printf ( "after f1 a = %d;\n", a );
    printf ( "after f1 b = %d;\n", b );

    f1 ();

    printf ( "after f1 a = %d;\n", a );
    printf ( "after f1 b = %d;\n", b );


}

void f1 ( void ) {

    int a = 1;
    int i = 0;
    static int b = 5;
    
    printf ( "---in f1 a = %d;\n", a );

    for ( i = 0; i < 3; i++ ) {
        printf ( "in f1 b = %d; i = %d;\n", b, i );
        b++;
    };



}


