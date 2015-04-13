#include <ctype.h>
#include <stdio.h>

#define MAX_LINE 1000

void getline_my ( char line [], int size );
double atof ( char s [] );
void clear_line ( char line [] );
int atoi ( char s [] );

void main ()

{

    char line [ MAX_LINE];
    int i = 0;
    double digit = 0.0;

    printf ( "Input please line to convert:" );
    getline_my ( line, MAX_LINE );
    digit = atof ( line );
    
    printf ( "Getted from line = %s digit if double = %G;\n", line, digit );

    
    printf ( "Getted from line = %s digit if double = %G;\n", line, digit );

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

void clear_line ( char line [] )

{
    int i = 0;
    
    for ( i = 0; line [ i ] != '\0'; i++ ){
        line [ i ] = 0;
    };

}

int atoi ( char line [] )

{

    double atof ( char line [] );
    return ( int ) atof ( line );
    
}


