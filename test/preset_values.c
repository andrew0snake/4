#include <stdio.h>

static int val1;
int val2;

void f1 ( void );


void main () {

    static int val3;
    int val4;

    printf ( "val1 = %d;\n", val1 );
    printf ( "val2 = %d;\n", val2 );
    printf ( "val3 = %d;\n", val3 );
    printf ( "val4 = %d;\n", val4 );

    f1 ();

}

void f1 ( void ) {

    static int val5;
    int val6;

    printf ( "in function f1 val1 = %d;\n", val1 );
    printf ( "in function f1 val2 = %d;\n", val2 );
//    printf ( "in function f1 val3 = %d;\n", val3 );
//    printf ( "in function f1 val4 = %d;\n", val4 );
    printf ( "in function f1 val5 = %d;\n", val5 );
    printf ( "in function f1 val6 = %d;\n", val6 );


}
