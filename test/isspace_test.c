#include <ctype.h>
#include <stdio.h>

void getline_my ( char line [] );

void main ()

{

    int i = 0;
    char string [ 20 ];
    
    getline_my ( string );
    
    printf ( "before check string = %s.\n", string );
    for ( i = 0; isspace ( string [ i ] ); ++i )
        printf ( "string [ %d ] = %c = %d; isspace ( string [ %d ] = %d;\n)", i, string [ i ], string [ i ], i, isspace ( string [ i ] ) );
    printf ( "after check string = %s.\n", string );
    



}


void getline_my ( char line [] )

{
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n'; ++i ){
        line [ i ] = c;
//        printf ( "line[%d] = %c; i = %d;\n", i, line[i], i );
    };
}
