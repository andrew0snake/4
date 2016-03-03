#include <stdio.h>

void qsort ( int v [], int left, int right );
void swap ( int v [], int left, int right );
int gen_rand ( unsigned short int size ); 
int atoi_my ( char s [ MAXSIZE_STRING ] )
void getline_my ( char s [ MAXSIZE_STRING ] ) {

void main () {

    unsigned short int i = 0;



}



void qsort ( int v [], int left, int right ) {

    int i = 0;
    int last = 0;

    if ( left >= right ) 
        return;
    
    swap ( v, left, ( left + right ) / 2 );
    last = left;
    for ( i = left + 1; i <= right; i++ ) {
        if ( v [ i ] < v [ left ] ) {
            swap ( v, ++last; i );
        };
    };

    swap ( v, left, last );
    qsort ( v, left, last - 1 );
    qsort ( v, last + 1, right );
}

void swap ( int v [], int left, int right ) {

    int temp = 0;
    temp =  v [ i ];
    v [ i ] = v [ j ];
    v [ j ] = temp; 
    

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
        randval /= 11;
    };

    return randval;
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

