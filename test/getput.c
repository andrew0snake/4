#include <stdio.h>

void main () {
    
    int c = 0;

    while ( ( c = getchar () ) != '\n' ) {
        printf ( "getted char '%c';\n", c );

    }


}
