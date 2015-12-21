#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE_STRING 10000

int atoi_my ( char s [] );
void getline_my ( char s [ MAXSIZE_STRING ] );
void clear_string ( char string [ MAXSIZE_STRING ] );

const char source [ 61 ] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','!','@','#','$','%','&','*','(',')','\0'};

void main () {
 
    int i = 0;
    int j = 0;
    char size [ MAXSIZE_STRING ];

    clear_string ( size );
    printf ( "Input number: ");
    getline_my ( size );
    printf ( "getted string :%s;\n", size );
    i = atoi_my ( size );
    printf ( "Your number is %d;\n", i );

/*    for ( j = 'a'; j <= 'z'; j++ ) {
        printf ( "'%c',", j );

    };
    for ( j = 'A'; j <= 'Z'; j++ ) {
        printf ( "'%c',", j );

    };
    printf ( "\n" );

    for ( j = 1; j <= 100; j++ ) {
        printf ( "j = %d = %c;\n", j, j );
    };
  */
    j = 0;
    while ( ' && j < strlen (source ) ) {
        printf ( "source [ j ] = %c; j = %d;\n", source [ j ], j );
        j++;
    };
    printf ( "lenght of string source = %d;\n", strlen ( source ) );

}

void clear_string ( char string [ MAXSIZE_STRING ] ) {

    int i = 0;

    while ( i < MAXSIZE_STRING ) {
//    while ( i < strlen ( string ) ) {
        string [ i ] = 0;
        i++;
    }

}

void getline_my ( char s [] ) {

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

int atoi_my ( char s [] )

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

