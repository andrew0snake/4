#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE_STRING 10000

int atoi_my ( char s [ MAXSIZE_STRING ] );
void getline_my ( char s [ MAXSIZE_STRING ] );
void clear_string ( char string [ MAXSIZE_STRING ] );

const char source [ 71 ] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','@','#','$','%','&','*','(',')','!','@','#','$','%','&','*','(',')','\0'};

void main () {
 
    int i = 0;
    int len_pass = 0;
    int size_int = 0;
    short int len_endur = 0;
    short int tmp = 0;
    char exit = 0;
    char endurance [ MAXSIZE_STRING ];
    char size [ MAXSIZE_STRING ];
    char password [ MAXSIZE_STRING ];

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
//    getchar ();

    printf ( "What kind of endurance of password& Strong ( s ), middle ( m )  or easy ( e )?\n" );
    exit = 0;
    while ( exit == 0 ) {
        getline_my ( endurance );
//        printf ( "start\n" );
        if ( endurance [ 0 ] == 's' ) {
            len_endur = 70;
            exit = 1;
//            printf ( "first if\n" ); 
//            getchar ();
        }
        else {
//            printf ( "first else\n" );
            if ( endurance [ 0 ]  == 'm' ) {
                len_endur = 51;
                exit = 1;
//                printf ( "second if\n" ); 
//                getchar ();
 
            }
            else {
//                printf ( "second else\n" );
                if ( endurance [ 0 ] = 'e') {
                    len_endur = 25;
                    exit = 1;
                }
                else {
                    printf ( "Wrong input, try again.\n" );
                    exit = 0;
                    clear_string ( endurance );
                };
//                getchar ();
            };
        };
    };   

//    printf ( "After check len_endur = %d;\n", len_endur );
    for ( i = 0; i < len_pass; i++ ) {
        
        tmp = rand ( ) % len_endur; 
        password [ i ] = source [ tmp ];
        tmp = 0;

    };
    password [ i ] = '\0';
    printf ( "Getted string = %s;\n", password );

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
    
//    return 0;

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

