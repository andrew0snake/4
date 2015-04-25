#include <ctype.h>
#include <stdio.h>

#define MAX_LINE 1000

void getline_my ( char line [], int size );
double atof ( char s [] );
void clear_line ( char line [], int size );
double step ( double number, double step_d );

void main ()

{

    char line [ MAX_LINE];
    int i = 0;
    int digit_i = 0;
    double digit = 0.0;

    printf ( "\nInput please line to convert:" );
    clear_line ( line, MAX_LINE );
    getline_my ( line, MAX_LINE );
    digit = atof ( line );
    
    printf ( "Getted from line = %s;\ndigit in double = %f;\n", line, digit );


}


double atof ( char s [] )

{
    
    double val = 0.0;
    double power = 0.0;
    double rez = 0.0;
    double seq_rez = 0.0;
    int i = 0;
    int j = 0;
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
    printf ( "rez = %G;\n\n", rez );

    if ( ( s [ i ] == '+' ) || ( s [ i ] == '-') ){
        seq_sign = ( s [ i ] == '-') ? ( - 1 ) : ( 1 );
        printf ( "s [ i = %d ] = %c; seq_sign = %d\n", i, s [ i ], seq_sign );
        i++;
    };
    
    if ( ( s [ i ] == 'e' ) || ( s [ i ] == 'E') ){
        i++;
        if ( seq_sign != ( -1 ) )
            seq_sign = 1;

//            for ( j = i; isspace ( s [ j ] ); j++ )
//                ;
//            i = j;
//        printf ( "before check s [ i = %d ] = %c;\n", i, s [ i ] );
//        seq_sign = ( s [ i ] == '-' ) ? ( - 1 ) : ( 1 );
//        printf ( "after check seq_sign = %d;\n", seq_sign );
//        if ( ( seq_sign == '-' ) || ( seq_sign == '+' ) )
//            i++;
        
//        clear_line ( seq, MAX_LINE );
        
        for ( power = 1.0; isdigit ( s [ i ] ); i++ ){
            printf ( "power = %G; s [ i = %d ] = %c;\n", power, i, s [ i ] );
            seq_rez = 10.0 * seq_rez + ( s [ i ] - '0' );
            power *= 10;
        };
        
        printf ( "seq_rez = %G; seq_sign = %d;\n\n", seq_rez, seq_sign );
    
        if ( seq_sign == 1 ){
//             rez = rez * ( 10.0 * seq_rez );
            rez = rez * step ( 10, seq_rez );  
            printf ( "seq_sign = + and rez = %f;\n", rez );
        }
        else {
//             rez = rez / ( 10.0 * seq_rez );
            rez = rez / step ( 10, seq_rez );  
            printf ( "seq_sign = - and rez = %f;\n", rez );
        };
    
    };
//    return ( sign * val / power );
    return rez;

}


void getline_my ( char line [], int size )

{
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n'; i++ ){
        line [ i ] = c;
//        printf ( "line[%d] = %c; i = %d;\n", i, line[i], i );
    };
//    i++;
    line [ i ] = '\0';
}

void clear_line ( char line [], int size )

{
    int i = 0;
    
    for ( i = 0; line [ i ] != '\0'; i++ ){
        line [ i ] = 0;
    };

}

double step ( double number, double step_d )

{
    int i = 0; 

    for ( i = 1; i < step_d; i++ ){
        number *= number;
    };

    return number;
}



