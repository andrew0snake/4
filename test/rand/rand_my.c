#include <stdlib.h>
#include <stdio.h>

//#define RAND_MAX 150

int countlines(char *filename);
int gen_rand ( unsigned short int size ); 


void main () {

    srand ( time ( 0 ) );

    int rez = 0;
    int rez2 = 0;
    int range = 150;
    int min = 0;
    int string_count = 0;

    char keywords_file [ 100 ] = "keywords";

    rez = rand () % range + min;

    printf ( "rez = %d;\n", rez );
    string_count = countlines ( keywords_file );
//    printf("LINES: %d\n",countlines(argv[1]));         
    printf ( "number of string in file keywords = %d;\n", string_count );
    rez2 = gen_rand ( string_count );

    printf ( "" );

}


int gen_rand ( unsigned short int size ) {

    unsigned int randval;
    FILE *f;
//for bsd uncomment this string 
    f = fopen ( "/dev/random", "r" );

//for linux using urandom
//    f = fopen ( "/dev/urandom", "r" );
    fread ( &randval, sizeof ( randval ), 1, f );
    fclose ( f );
 
    while ( randval > size ) {
        randval /= 11;
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


