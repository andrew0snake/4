#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE_STRING 10000

unsigned short int gen_rand ( unsigned short int size );


void main () {
 
    int i = 0;
    int rand = 0;
    int size_int = 0;
    unsigned short int len_endur = 0;
    short int tmp = 0;

    while ( i < 10 ) {
         rand = gen_rand ( 512 );
         printf ( "rand = %d;\n", rand ); 
         i++;
    };
}

unsigned short int gen_rand ( unsigned short int size ) {

    unsigned int randval;
    FILE *f;
 
    f = fopen ( "/dev/urandom", "r" );
    printf ( "file opened;\n" );
    fread ( &randval, sizeof ( randval ), 1, f );
    printf ( "random digit is read;\n" );
    fclose ( f );
    printf ( "file closed;\n" );
 
    while ( randval > size ) {
        randval /= 5;
        printf ( "randval = %u;\n", randval );
    };

    printf ( "%u\n", randval );
//    printf ( "%u\n", size );
    return randval;
//    return size;
 }

