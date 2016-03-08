#include <stdio.h>
#include <string.h>

void main () {

    char string_1 [ 10 ];
    char string_2 [ 100 ];
    unsigned short int i = 0;
    unsigned short int j = 0;

    FILE *f = fopen ( "1.txt", "r" );

    while ( j < 3 ) {
        fgets ( string_1, 10, f );
        for ( i = 0; i < 10 && string_1 [ i ] != '\n' && string_1 [ i ] != EOF; i++ ) {
            printf ( "string_1 [ i = %d ] = %c;\n", i, string_1 [ i ]  );
        };
        printf ( "------------------------------------\n" );
        printf ( "at step %d string_1 [ 0 ] = %c;\n", j, string_1 [ 0 ] );
        printf ( "and full string = %s;\n\n", string_1 );
        j++;
    };

    fclose ( f );
 
//    return 0;   


}
