#include <stdio.h>

void main () {

    int i = 0;
    int j = 0;

    for ( i = 0; i < 5; i++ ) {
        printf ( "Value i in cycle for = %d;\n", i );
        j = 0; 
        while ( j < 1 ) {
            j++;
            int i = 7;
            printf ( "And inside cycle while i = %d;\n", i );
        };
    };



}
