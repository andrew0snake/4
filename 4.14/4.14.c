#include <stdio.h>

#define one_float 1.0
#define two_float 2.0
#define one_plus_two_float one_float+two_float

#define type_int int
#define type_double double
#define type(a,b) ((a)||(b)?(a):(b))
//#define swap(type(a,b),c,d) 

#define is_a(a,b) (a||b?a:b)
#define is_int(a,b) ()

#define swap(t,x,y) swap3((t)(z),(t)(x),(t)(y))
#define swap2(t,x,y) printf("%f,%f.\n",(t)(x),(t)(y))
#define swap3(z,x,y) (z=x,x=y,y=z)

void main () {

    char string_int [] = "int";
    char string_dbl [] = "double";
    char rez [ 10 ] ;
    
    int x = 0;
    int y = 0;

    x = 9;
    y = 13;

//    printf ( "is_a result = %d;\n", is_a ( x, y ) );

    printf ( "one_float = %f; two_float = %f; one_float + two_float = %f;\n", one_float, two_float, one_plus_two_float );

//    printf ( "type = %d;\n", type(type_int,type_double) );

//    rez = gettype_my ( string_int );

//    swap(int,5,3);
//    swap2(float,5.0,3.5);

    printf ( "before swap x = %d; y = %d;\n", x, y );
    swap(int,5,3);
//    swap3(x,y);
    printf ( "after swap ( x, y ) x = %d; y = %d;\n", x, y  );

}
