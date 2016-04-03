#include <stdio.h>

void main () {

    int c = 5;
    int d = 7;
    int e = 10;
    int i = 0;
    char string [ 10 ] = "string";

    int *p;
    int *p2;
    p = &c;

    printf ( "\naddress of pointer p = %p;\n", p );   
    printf ( "same pointer p = &c = %d;\n", *p);

    p = &d;
    printf ( "\nand now p = &d = %d;\n", *p );

    p = &e;
    printf ( "\nand now p = &e = %d;\n", *p );


    for ( i = 0; i < 6; i++ ) {
        p = string [ i ];
        printf ( "p = string [ i = %d ] = %c;\n", i, string [ i ] );
    }

    p = &c;
    (*p)++;
    printf ( "p++ = %d;\n", *p );
   
    ++*p;
    printf ( "++*p = %d;\n", *p ); 

    p2 = p;
    printf ( "p2 = %d;\n", *p2 );

}
