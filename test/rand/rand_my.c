#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define RAND_MAX 150
#define A_S 10000
//defining external values
int string_count = 0;
int random_array [ A_S ];
int count_of_names = 0;
//end of defining values


//definition of functions
int countlines(char *filename);
int gen_rand ( unsigned short int size ); 
void full_rand_array ( int size_of_array, int rand_array [ A_S ] );
void print_array ( int rand_array [ A_S ] );
void getline_my ( char line [], int size );
int atoi_my ( char line [] ); 
void clear_array ( int array [ A_S ] );
void clear_string ( char array [ A_S ] );
void full_list_of_names ( void );
void get_numbered_line_of_file ( char line [ A_S ], int number );
//end of definition of functions

void main () {

    srand ( time ( 0 ) );

    int rez = 0;
    int rez2 = 0;
    int range = 150;
    int min = 0;

    char keywords_file [ 100 ] = "keywords";
    char temp [ A_S ];

    string_count = countlines ( keywords_file );
//    printf("LINES: %d\n",countlines(argv[1]));         
    printf ( "number of string in file keywords = %d;\n", string_count );
//    full_rand_array ( string_count, random_array );

    clear_string( temp );
    printf ( "Input count of names:\n" );
    getline_my ( temp, A_S );
    count_of_names = atoi_my ( temp );    
    printf ( "Count of names = %d;\n", count_of_names );

    full_list_of_names ();

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

    lines++;
//    while ( ( ch = fgetc ( fp ) ) != EOF ) {
    while ( !feof ( fp ) ) {
        ch = fgetc ( fp );
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

    printf ( "Fulling of random array..." );
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
    printf ( "is finished.\n" );

}

void print_array ( int rand_array [ A_S ] ) {

    int i = 0;

    for ( i = 0; i < A_S; i++ ) {
        printf ( "rand_array [ %d ] = %d;\n", i, rand_array [ i ] );
    };

}

void getline_my ( char line [], int size ) {
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n'; ++i ){
        line [ i ] = c;
    };
}

int atoi_my ( char s [] ) {

    int i = 0;
    int n = 0;
    int sign = 0;

    for ( i = 0; isspace ( s [ i ] ); ++i )
        ;

    sign = ( s [ i ] == '-' ) ? ( -1 ) : 1;
    if ( s [ i ] == '+' || s [ i ] == '-' )
        ++i;
    for ( n = 0; isdigit ( s [ i ] ); ++i )
        n = n * 10 + ( s [ i ] - '0' );
    
    return sign * n;

}


void clear_string ( char array [ A_S ] ) { 

    int i = 0;
    
    for ( i = 0; i < A_S; i++ ) {
        array [ i ] = 0;
    };
//    printf ( "String is cleared.\n" );
}


void full_list_of_names ( void ) {

    int i = 0;
    int pointer = 0;
    int step = 0;
    char temp_string [ A_S ];
    char concat_string [ A_S ];

    FILE *f; 

    printf ( "get first %d random strings of file keywords:\n", count_of_names );

    pointer = 0; 
    step = 0;
    full_rand_array ( string_count, random_array );
    while ( step < count_of_names ) {
        if ( pointer == string_count ) {
            full_rand_array ( string_count, random_array );
            pointer = 0;
        }
        
        clear_string ( temp_string );
        printf ( "at step %d in get_numbered_line_of_file send position %d;\n", pointer, random_array [ pointer ] );
        get_numbered_line_of_file ( temp_string, random_array [ pointer ] );
        printf ( "after get_numbered_line_of_file string temp_string = '%s';\n", temp_string );
        pointer++;
        step++;
        
        if ( strlen ( concat_string ) + strlen ( temp_string ) < 150 ) {
            strcat ( concat_string, temp_string );
        }
        else {
            strcat ( concat_string, "\n" );
            f = fopen ( "names_of_strings_list", "a+" );
            fputs ( concat_string, f ); 
            printf ( "in file names_of_strings_list added string = '%s';\n", concat_string );
            fclose ( f );
            clear_string ( concat_string );
        }
    }





}

void get_numbered_line_of_file ( char line [ A_S ], int number ) {

    int i = 0;
    char temp [ A_S ];

    FILE *f = fopen ( "keywords", "r" );

    for ( i = 0; i < number; i++ ) {
        clear_string ( temp );
        fgets ( temp, 150, f );

    };
    temp [ strlen ( temp ) - 1 ] = ' ';
    printf ( "temp [ strlen ( temp ) = %d - 1 ] = '%c';\n",  strlen ( temp ) - 1, temp [ strlen ( temp ) - 1 ] );
    printf ( "after cycle position = %d; and getted string = %s;\n", i, temp );

    fclose ( f );

}

