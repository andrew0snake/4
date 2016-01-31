#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795

void main () {

    char c = 0;
    double deg = 0;
    double rad = 0;
    double rez = 0;

    printf ( "one rad = %lf degrees;\n", 180/PI );

    deg = 45;
    printf ( "deg = %lf;\n", deg );

    rad = ( 180 / PI );
    printf ( "first step rad = %lf;\n", rad );
    
    rad = deg / rad;
    printf ( "second step rad = %lf;\n", rad );

    rez = sin ( deg );

    printf ( "rez of sin ( deg ) = %lf;\n", rez );
    printf ( "rez of sin ( rad ) = %lf;\n", sin ( rad ) );

}
