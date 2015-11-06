#include <stdio.h>
#include <string.h>
//void concat_my ()

void clean_str ( char str [] );
void del_sys_symb ( char str_to [], char str_from [] );
void put_str ( char str [] );

void main () {

    FILE *tmp_file, *source_file;

    char str1 [ 5000 ];
    char str2 [ 5000 ];
    char str_tmp [ 5000 ];

    int i = 0;
    int j = 0;
    short int str_num = 0;
    short int index_of_symbol = 0;
    short int sc = 0;
    short int prev = 0;

    source_file = fopen ( "source_file", "r" );
    
    for ( sc = 0; sc < 50; sc++ ){
        while ( fgets ( str1, 400, source_file) != NULL ){
            printf ( "getted string = %s,\n", str1 );
            if ( str1 [ 0 ] == '<' ) { 
//                if ( strlen ( str_tmp ) != NULL )
                    put_str ( str_tmp );
                del_sys_symb ( str2, str1 );
                printf ( "after deleting system symbols string = %s;\n", str2 );
//                printf ( "last symbol of string = %d in digital and %c in char;\n", str2 [ strlen ( str2 ) - 1 ],  str2 [ strlen ( str2 ) - 1 ] );
                str2 [ strlen ( str2 ) -1 ] = ' ';
                clean_str ( str_tmp );
                strcpy ( str_tmp, str2 );
                
                clean_str ( str2 );
                clean_str ( str1 );
            }
            else {
               strcat ( str_tmp, str1 );
               put_str ( str_tmp );
               clean_str ( str1 );
            };
        };
    fclose ( source_file );
    }
}

void  clean_str ( char str [] ) {

    short int i = 0;

    for ( i = 0; i < strlen ( str ); i++ ){
        str [ i ] = 0;       
    }
    str [ 0 ] = EOF;
}

void del_sys_symb ( char str_to [], char str_from [] ) {

    short int i = 0;
    short int j = 0;

    for ( i = 0, j = 0; i < strlen ( str_from ); i ++ ) {
        if ( str_from [ i ] == '<' )
            while ( str_from [ i ] != '>' )
                i ++;
        else {
            str_to [ j ] = str_from [ i ];
            j ++;
        };
    };
}

void put_str ( char str [] ) {

    FILE *tmp_file;

    tmp_file = fopen ( "tmp_file", "a" );
    fputs ( str, tmp_file );
    fclose ( tmp_file );

    printf ( "putted string = %s;\n", str );

}


