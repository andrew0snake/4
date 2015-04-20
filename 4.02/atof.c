#include <ctype.h>
#include <stdio.h>

#define MAX_LINE 1000

void getline_my ( char line [], int size );
double atof ( char s [] );
void clear_line ( char line [] );

void main ()

{

    char line [ MAX_LINE];
    int i = 0;
    int digit_i = 0;
    double digit = 0.0;

    printf ( "Input please line to convert:" );
    getline_my ( line, MAX_LINE );
    digit = atof ( line );
    
    printf ( "Getted from line = %s digit in double = %G;\n", line, digit );


}


double atof ( char s [] )

{
    
    double val = 0.0;
    double power = 0.0;
    double rez = 0.0;
    double seq_rez = 0.0;
    int i = 0;
    short int sign = 0;
    short int seq_sign = 0;
    char seq [ 20 ];
    
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
    
    rez = sign * val / power;

    if ( ( s [ i ] == 'e' ) || ( s [ i ] == 'E') ){
        i++;

        for ( i = 0; isspace ( s [ i ] ); i++ )
            ;

        seq_sign = ( s [ i ] == '-' ) ? ( - 1 ) : ( 1 );
        if ( ( seq_sign == '-' ) || ( seq_sign == '+' ) )
            i++;
        
        clear_line ( seq );
        
        for ( power = 1.0; isdigit ( s [ i ] ); i++ ){
            seq_rez = 10.0 * seq_rez + ( s [ i ] - '0' );
            power *= 10;
        };
        
        if ( seq_sign == '+' )
            rez = rez * ( 10 * seq_rez );
        else 
            rez = rez / ( 10 * seq_rez );
    }
//    return ( sign * val / power );
    return rez;

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



