#include <stdio.h>

void swap ( int a, int b );
void swap_p ( int *a, int *b );

int c = 8;
int d = 10;

void main () {

    int i = 0;
    int j = 0;

    int a = 5;
    int b = 7;

    
    printf ( "before swap a = %d; b = %d;\n", a, b );
    swap ( a, b );
    printf ( "after swap a = %d; b = %d;\n", a, b );

    printf ( "------------------------------------\n" );
    printf ( "before swap c = %d; d = %d;\n", c, d );
    swap ( c, d );
    printf ( "after swap c = %d; d = %d;\n", c, d );
    printf ( "------------------------------------\n" );


    printf ( "------------------------------------\n" );
    printf ( "before swap c = %d; d = %d;\n", c, d );
    swap_p ( &c, &d );
    printf ( "after swap c = %d; d = %d;\n", c, d );
    printf ( "------------------------------------\n" );


}


void swap ( int a, int b ) {

    int temp = 0;

    printf ( "in func before swap a = %d; b = %d;\n", a, b );

    temp = a;
    a = b;
    b = temp;

    printf ( "in func after swap a = %d; b = %d;\n", a, b );

}


void swap_p ( int *a, int *b ) {

    int temp = 0;

    printf ( "in func before swap *a = %d; *b = %d;\n", *a, *b );

    temp = *a;
    *a = *b;
    *b = temp;

    printf ( "in func after swap *a = %d; *b = %d;\n", *a, *b );

}



