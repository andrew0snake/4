#include <stdio.h>

void main () {

    char buff [ 10 ];
    int per = 0;
    int x = 123;

    per = sprintf ( buff, "%i", x );
    printf ( "per = %d;\nstring = %s;\n", per, buff );



}
