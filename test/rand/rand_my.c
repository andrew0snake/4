#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//#define RAND_MAX 155
#define A_S 10000
#define S_S 155
//defining external values
int count_of_strings_of_keywords = 0;
int random_array [ A_S ];
int count_of_lines = 0;
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
void create_xml ( void );
//end of definition of functions

void main () {

    srand ( time ( 0 ) );

    int rez = 0;
    int rez2 = 0;
    int range = 150;
    int min = 0;

    char keywords_file [ 100 ] = "keywords";
    char temp [ S_S ];

    count_of_strings_of_keywords = countlines ( keywords_file );
//    printf("LINES: %d\n",countlines(argv[1]));         
    printf ( "number of string in file keywords = %d;\n", count_of_strings_of_keywords );

    clear_string( temp );
    printf ( "Input count of lines for to generate:\n" );
    getline_my ( temp, S_S );
    count_of_lines = atoi_my ( temp );    
    printf ( "Count of random lines for to generate = %d;\n", count_of_lines );

    full_list_of_names ();
    
    create_xml ();
}


int gen_rand ( unsigned short int size ) {

    unsigned int randval;
    FILE *f;
    unsigned short int exit = 0;

    while ( exit == 0 ) {
//for bsd uncomment this string 
//         f = fopen ( "/dev/random", "r" );

//for linux using urandom
         f = fopen ( "/dev/urandom", "r" );
         fread ( &randval, sizeof ( randval ), 1, f );
         fclose ( f );
 
         while ( randval > size && randval > count_of_strings_of_keywords ) {
//             printf ( "size = %d, randval = %d\n", size, randval );
//    this option is for big size of array
             randval /= 1111;
//    and this option is for small size of array
//            randval /= 17;
         };

//        printf ( "getted random value = %d\n", randval );
        if ( randval == 0 ) {
            exit = 0;
        }
        else {
            exit = 1;
        };
    }
//    printf ( "generated random value = %d;\n", randval );
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

//    lines++;
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

    printf ( "Fulling of random array...\n" );

//  this option is for small size of archive
//    for ( i = 0; i < size_of_array - 1 ; i++ ) {

//  this option is for big size of archive
    for ( i = 0; i < size_of_array - 10 ; i++ ) {
        exit = 0;
        while ( exit == 0 ) {
            temp = gen_rand ( count_of_strings_of_keywords );
            par = 0;
           
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
        if ( rand_array [ i ] == 0 ) {
            printf ( "ERROR!!!\n" );
        };
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


void clear_string ( char string [ A_S ] ) { 

    int i = 0;
    
    for ( i = 0; i < S_S; i++ ) {
        string [ i ] = 0;
    };
//    printf ( "String is cleared.\n" );
}


void full_list_of_names ( void ) {

    int i = 0;
    int pointer = 0;
    int step = 0;
    unsigned short int string_counter = 0;
    char temp_string [ S_S ];
    char concat_string [ S_S ];

    FILE *f; 

    if ( access ( "names_of_strings_list", F_OK ) != -1 ) {
        i = remove ( "names_of_strings_list" );
        i = 0;
    };

    pointer = 0; 
    step = 0;
    full_rand_array ( count_of_strings_of_keywords, random_array );
    while ( string_counter <= count_of_lines ) {
        pointer++;
//    this option is for small size archives ( less then 12 )
//        if ( pointer == ( count_of_strings_of_keywords - 1 ) ) {
//    this option is for big size archives
        if ( pointer == ( count_of_strings_of_keywords - 11 ) ) {
            printf ( "pointer = %d and array is recalculating.\n", pointer );
            full_rand_array ( count_of_strings_of_keywords, random_array );
            pointer = 0;
        }
        
        clear_string ( temp_string );
        printf ( "=====================================================\n" );
        printf ( "at step %d ( pointer ) in get_numbered_line_of_file send position %d;\n", pointer, random_array [ pointer ] );
        get_numbered_line_of_file ( temp_string, random_array [ pointer ] );
        printf ( "after get_numbered_line_of_file string temp_string = '%s';\n", temp_string );
        if ( step == 0 ) {
            clear_string ( concat_string );
//            temp_string [ 1 ] = 0;
        }
        
        if ( strlen ( concat_string ) + strlen ( temp_string ) < S_S ) {
            strcat ( concat_string, temp_string );
        }
        else {
            strcat ( concat_string, "\n" );
            f = fopen ( "names_of_strings_list", "a+" );
            fputs ( concat_string, f ); 
            printf ( "\nin file names_of_strings_list added string = '%s';\n\n", concat_string );
            printf ( "string_counter = %d and whole lenght of added string is:%d;\n", string_counter, strlen ( concat_string ) );
            fclose ( f );
            clear_string ( concat_string );
            string_counter++;
        }
        step ++;
    }
}

void get_numbered_line_of_file ( char line [ S_S ], int number ) {

    int i = 0;
    char temp [ S_S ];

    FILE *f = fopen ( "keywords", "r" );

    for ( i = 0; i < number; i++ ) {
        clear_string ( temp );
        fgets ( temp, S_S, f );

    };
    temp [ strlen ( temp ) - 1 ] = ' ';
    printf ( "lenght of string temp = %d;\n", strlen ( temp ) );
    printf ( "temp [ strlen ( temp ) = %d - 1 ] = '%c';\n",  strlen ( temp ) - 1, temp [ strlen ( temp ) - 1 ] );
    printf ( "after cycle position = %d; and getted string = %s;\n", i, temp );
    strcat ( line, temp );
    fclose ( f );

}

void create_xml ( void ) {

    FILE *f;
    FILE *f_source;
   
    int i = 0; 
    char first_string [ 100 ] = "<opml version=\"1.1\">\n";
    char second_string [ 100 ] = "    <body>\n";

    char first_part [ 100 ] = "        <outline stringname=\"";
    char second_part [ 100 ] = "\">\n";
    char second_part_2 [ 100 ] = "\" />\n";

    char final_string_1 [ 100 ] = "        </outline>\n";
    char final_string_2 [ 100 ] = "    </body>\n";
    char final_string_3 [ 100 ] = "</opml>\n";

    char full_string [ 600 ] = "";
    char getted_string [ 200 ] = "";

    if ( access ( "names_of_strings.xml", F_OK ) != -1 ) {
        i = remove ( "names_of_strings.xml" );
        i = 0;
    };

    f = fopen ( "names_of_strings.xml", "a+" );
    fputs ( first_string, f );
    fputs ( second_string, f );
//    fclose ( f );
    
    f_source = fopen ( "names_of_strings_list", "r" );

    while ( fgets ( getted_string, 155, f_source ) != NULL ) {
        clear_string ( full_string );
        getted_string [ strlen ( getted_string ) - 1 ] = 0; 
        strcat ( full_string, first_part );
        strcat ( full_string, getted_string );
        if ( i == 0 ) {
            strcat ( full_string, second_part );
        }
        else {
            strcat ( full_string, second_part_2 );
        }
        fputs ( full_string, f );
        printf ( "in file names_of_string.xml send string %s\n", full_string );
        clear_string ( getted_string );
        clear_string ( full_string );
        i++;
    }
    
    fputs ( final_string_1, f );
    fputs ( final_string_2, f );
    fputs ( final_string_3, f );

    fclose ( f_source );
    fclose ( f );

//*/





}

