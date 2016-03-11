#include <stdio.h>

#define one 1
#define is_a(a,b) (a||b?a:b)
#define is_int(a,b) ()

void main () {

    char stringi_int [] = "int";
    char stringi_bdl [] = "double";
    char rez [ 10 ] ;
    
    int x = 0;
    int y = 0;

    x = 9;
    y = 13;

    printf ( "is_a result = %d;\n", is_a ( x, y ) );

//    rez = gettype_my ( string_int );
}
