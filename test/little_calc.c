#include <ctype.h>
#include <stdio.h>

#define MAX_LINE 1000

//void getline_my ( char line [], int size );
//double atof ( char s [] );

void main ()

{

    char line [ MAX_LINE ];
    int i = 0;
    int getline_my ( char line [], int max );	
    double digit = 0.0;
    double sum = 0.0;
    double atof ( char [] );
    
    sum = 0.0;
    while ( getline_my ( line, MAX_LINE ) > 0 )
        printf ( "\t%g\n", sum += atof ( line ) );
    

}


double atof ( char s [] )

{
    
    double val = 0.0;
    double power = 0.0;
    int i = 0;
    short int sign = 0;
    
    for ( i = 0; isspace ( s [ i ] ); i++ )
        ;
    
    sign = ( s [ i ] == '-' ) ? ( - 1 ) : ( 1 );
    
    if ( ( s [ i ] == '-' ) || ( s [ i ] == '+' ) )
        i++;
        
    for ( val = 0.0; isdigit ( s [ i ] ); i++ ){
        val = 10.0 * val + ( s [ i ] - '0' );
    };
    
    if ( s [ i ] == '.' )
        i++;
        
    for ( power = 1.0; isdigit ( s [ i ] ); i++ ){
        val = 10.0 * val + ( s [ i ] - '0' );
        power *= 10;
    }
    
    return ( sign * val / power );

}


void getline_my ( char line [], int size )

{
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n'; ++i ){
        line [ i ] = c;
//        printf ( "line[%d] = %c; i = %d;\n", i, line[i], i );
    };
}
