#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE_STRING 10000

int atoi_my ( char s [ MAXSIZE_STRING ] );
void getline_my ( char s [ MAXSIZE_STRING ] );
void clear_string ( char string [ MAXSIZE_STRING ] );
//int gen_rand ( int argc, char **argv, int size );
int gen_rand ( unsigned short int size );

const char source [ 82 ] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','@','#','$','%','&','*','(',')','!','@','#','$','%','&','*','(',')'};
char endurance_size = 0;


void main () {
 
    int i = 0;
    int j = 0;
    int len_pass = 0;
    int size_int = 0;
    unsigned short int len_endur = 0;
    short int tmp = 0;
    char exit = 0;
    char endurance [ MAXSIZE_STRING ];
    char size [ MAXSIZE_STRING ];
    char password [ MAXSIZE_STRING ];

    printf ( "source [ %d ] = %c;\n", 61, source [ 61 ] );
    while ( exit == 0 ) {
        clear_string ( size );
        printf ( "Input lenght of string: ");
        getline_my ( size );
        len_pass = atoi_my ( size );
 
        if ( len_pass < 1 ) {
            printf ( "Wrong number, try again. " );
            exit = 0;
        }
        else {
            printf ( "Lenght of string = %d;\n", len_pass );
            exit = 1;
        };
    };

    printf ( "What kind of endurance of password& Strong ( s ), middle ( m )  or easy ( e )?\n" );
    exit = 0;
    while ( exit == 0 ) {
        getline_my ( endurance );
        if ( endurance [ 0 ] == 's' ) {
            len_endur = 79;
            endurance_size = 3;
            exit = 1;
        }
        else {
            if ( endurance [ 0 ]  == 'm' ) {
                len_endur = 61;
                endurance_size = 2;
                exit = 1;
 
            }
            else {
                if ( endurance [ 0 ] = 'e') {
                    len_endur = 35;
                    endurance_size = 1;
                    exit = 1;
                }
                else {
                    printf ( "Wrong input, try again.\n" );
                    exit = 0;
                    clear_string ( endurance );
                };
            };
        };
    };   

    for ( j = 0; j < 10; j++ ) {
        clear_string ( password );
        for ( i = 0; i < len_pass; i++ ) {
            tmp = gen_rand (  len_endur ); 
             password [ i ] = source [ tmp ];
             tmp = 0;
     
         };
         password [ i ] = '\0';
         printf ( "Getted string = %s\n", password );
    }
}

void clear_string ( char string [ MAXSIZE_STRING ] ) {

    int i = 0;

    while ( i < MAXSIZE_STRING ) {
//    while ( i < strlen ( string ) ) {
        string [ i ] = 0;
        i++;
    }

}

void getline_my ( char s [ MAXSIZE_STRING ] ) {

    int c = 0;
    int i = 0;
    int lim = MAXSIZE_STRING;
    
    while ( ( --lim > 0 ) && ( ( c = getchar() ) != EOF ) && c != '\n' )
        s [ i++ ] = c;

    if ( c == '\n' ){
        s [ i++ ] = '\n';
    };

    s [ i ] = '\0';
    

}

int atoi_my ( char s [ MAXSIZE_STRING ] )

{
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

//int gen_rand ( int argc, char **argv, int size ) {
int gen_rand ( unsigned short int size ) {

    unsigned int randval;
    unsigned int devider = 0;
    FILE *f;
//for bsd uncomment this string 
//    f = fopen ( "/dev/random", "r" );

//for linux using urandom
    f = fopen ( "/dev/urandom", "r" );
    fread ( &randval, sizeof ( randval ), 1, f );
    fclose ( f );
 
    if ( endurance_size == 1 ) {
        devider = 11;
    }
    else {
        if ( endurance_size == 2 ) {
            devider = 3;
        }
        else {
            if ( endurance_size == 3 ) {
                devider = 7;
            }
        }
    };

    if ( ( randval % 2 ) == 0 ) {
        devider = 111;
    };
    

    while ( randval > size ) {
        randval /= devider;
    };

    return randval;
 }

