#include <stdio.h>
#define MAXLINE 1000

int getline_my ( char line [], int max );
int strindex_1 ( char source [], char searchfor [] );
int strindex_2 ( char source [], char searchfor [] );

char pattern [] = "ould";

int main ()

{

    char line [ MAXLINE ];
    int found = 0;
    
    while ( getline_my ( line, MAXLINE ) > 0 ){
        if ( strindex_2 ( line, pattern ) >= 0 ){
            printf ( "%s", line );
            printf ( "---Using function 1 found that pattern is in position = %3d;---\n", strindex_1 ( line, pattern ) );
            printf ( "---Using function 2 found that pattern is in position = %3d;---\n", strindex_2 ( line, pattern ) );
            found ++;
        };
    };
    
    return found;

}

int getline_my ( char s [], int lim )

{

    int c = 0;
    int i = 0;
    
    while ( ( --lim > 0 ) && ( ( c = getchar() ) != EOF ) && c != '\n' )
        s [ i++ ] = c;

    if ( c == '\n' ){
        s [ i++ ] = '\n';
    };

    s [ i ] = '\0';
    
    return i;

}


int strindex_1 ( char s [], char t [] )

{
    int i = 0;
    int j = 0;
    int k = 0;
    int len_s = 0;
    int len_t = 0;
    
    for ( len_s = 0; s [ len_s ] != '\0'; len_s++ )
        ;
    for ( len_t = 0; t [ len_t ] != '\0'; len_t++ )
        ;
    
    for ( i = 0; s [ i ] != '\0'; i++ ){
        for ( j = i, k = 0; t [ k ] != '\0' && s [ j ] == t [ k ]; j++, k++ )
        ;
        if ( ( k > 0 ) && t [ k ] == '\0' )
            return i;
    };
    
    return -1;

}

int strindex_2 ( char s [], char t [] )

{
    int i = 0;
    int j = 0;
    int k = 0;
    int len_t = 0;
        
    for ( i = 0; s [ i ] != '\0'; i++ ){
        len_t = 0;
        for ( j = i, k = 0; t [ k ] != '\0' && s [ j ] == t [ k ]; j++, k++ )
            len_t++;
        if ( ( k > 0 ) && t [ k ] == '\0' )
            return ( i + len_t );
    };
    
    return -1;
}
