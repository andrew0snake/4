#include <stdio.h>

#define max(A,B) ((A)>(B)?(A):(B))
#define square(x) (x*x)
#define dprint(expr) printf(#expr " = %3d\n",expr)


void main () {

    int x = 0;
    int y = 0;
    int z = 0; 
    int g = 0;
    int h = 0;

    x = 1;
    y = 4;
    z = 5;
    g = 3;
    h = 2;

    printf ( "max ( x + y, z + g ) = %d;\n", max ( x + y, z + g ) );

    printf ( "g = %d; square ( g+2 ) = %d;\n", g, square ( g + 2 ) );

    dprint ( y * h );

}
