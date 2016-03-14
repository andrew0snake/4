#include <stdlib.h>
#include <stdio.h>

//#define RAND_MAX 150
#define A_S 10000
//define external values
int string_count = 0;
int random_array [ A_S ];

int countlines(char *filename);
int gen_rand ( unsigned short int size ); 
void full_rand_array ( int size_of_array, int rand_array [ A_S ] );
void print_array ( int rand_array [ A_S ] );


void main () {

    srand ( time ( 0 ) );

    int rez = 0;
    int rez2 = 0;
    int range = 150;
    int min = 0;

    char keywords_file [ 100 ] = "keywords";

    string_count = countlines ( keywords_file );
//    printf("LINES: %d\n",countlines(argv[1]));         
    printf ( "number of string in file keywords = %d;\n", string_count );
    rez2 = gen_rand ( string_count );

    printf ( "rez2 = %d;\n", rez2 );

    full_rand_array ( string_count, random_array );

}


int gen_rand ( unsigned short int size ) {

    unsigned int randval;
    FILE *f;
//for bsd uncomment this string 
//    f = fopen ( "/dev/random", "r" );

//for linux using urandom
    f = fopen ( "/dev/urandom", "r" );
    fread ( &randval, sizeof ( randval ), 1, f );
    fclose ( f );
 
    while ( randval > size ) {
        randval /= 111;
    };

    return randval;
}


///*void main(int argc, char *argv[])
//{
//  printf("LINES: %d\n",countlines(argv[1]));         
//}
//*/

int countlines ( char *filename ) {
  // count the number of lines in the file called filename                                    
   
    printf ( "getted filename = %s;\n", filename );
 
    FILE *fp = fopen ( filename, "r" );
    int ch = 0;
    int lines = 0;

/*    if (fp == NULL) {
        printf ( "fp = %d;\n", fp );
        return 0;
    };
*/
    lines++;
    while ( ( ch = fgetc ( fp ) ) != EOF ) {
//        printf ( "getted char = %c;\n", ch );
        if ( ch == '\n' )
            lines++;
    };
    fclose( fp );
    return lines;
}

void full_rand_array ( int size_of_array, int rand_array [ 10000 ] ) {

    int i = 0;
    int j = 0;
    char exit = 0;
    char par = 0;
    int temp = 0;

    for ( i = 0; i < size_of_array; i++ ) {
        exit = 0;
        while ( exit == 0 ) {
            par = 0;
            temp = gen_rand ( string_count );
           
            for ( j = 0; j < i; j++ ) { 
                if ( temp == rand_array [ j ] ) {
                    par = 1;
                };
            };
            if ( par == 0 ) {
                rand_array [ i ] = temp;
                exit = 1;
            }
            else {
                exit = 0;
            };
        };
        printf ( "at step %d rand_array [ %d ] = %d;\n", i, i, rand_array [ i ] );
    };


}

void print_array ( int rand_array [ A_S ] ) {

    int i = 0;

    for ( i = 0; i < A_S; i++ ) {
        printf ( "rand_array [ %d ] = %d;\n", i, rand_array [ i ] );
    };

}

