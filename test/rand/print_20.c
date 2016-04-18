#include <stdio.h>
#include <stdlib.h>

void main () {

    int i = 0;
    char string1 [ 10 ] = "";
 
    FILE *f = fopen ( "test_file1", "a+" );
    

    for ( i = 0; i < 256; i++ ) {
        printf ( "i in char = '%c' and %d in digit;\n", i, i );
        string1 [ 0 ] = i;
        string1 [ 1 ] = '\n';
        fputs ( string1, f );
        string1 [ 0 ] = string1 [ 1 ] = 0;
    }

    fclose ( f );
}
