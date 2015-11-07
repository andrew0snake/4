#include <stdio.h>
#include <string.h>
//void concat_my ()

void clean_str ( char str [] );
void del_sys_symb ( char str_to [], char str_from [] );
void put_str ( char str [] );
void clean_first_string ( char str_to [], char str_from [] );

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
    char concat = 0;

    source_file = fopen ( "source_file", "r" );
    
    for ( sc = 0; sc < 50; sc++ ){
        while ( fgets ( str1, 800, source_file) != 0 ){
            if ( str1 [ 0 ] == '<' ) { 
               if ( strlen ( str_tmp ) != 0 )
                    put_str ( str_tmp );
                clean_str ( str2 );
                del_sys_symb ( str2, str1 );
                clean_str ( str_tmp );
                strcpy ( str_tmp, str2 );
                
                clean_str ( str2 );
                clean_str ( str1 );
                prev = 1;
                concat = 0;
            }
            else {
               str_tmp [ strlen ( str_tmp ) - 1 ] = ' '; 
               strcat ( str_tmp, str1 );
               clean_str ( str1 );
               del_sys_symb ( str1, str_tmp );
               clean_str ( str_tmp );
               strcpy ( str_tmp, str1 );
               clean_str ( str1 );
               prev = 0;
               concat = 1;
            };
        };
   }

    put_str ( str_tmp );
    fclose ( source_file );

}

void  clean_str ( char str [] ) {

    short int i = 0;
    for ( i = 0; i < 800; i++ ){
        str [ i ] = 0;       
    }
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


}

void clear_first_string ( char str_to [], char str_from [] ) {

    short int i = 0;
    short int j = 0;
    short int position = 0;

    for ( i = 0; ( i < strlen ( str_from ) ) || ( position > 0 ) ; i++ ) {
        if ( str_from [ i ] == 'p' && str_from [ i + 1 ] == 'a' && str_from [ i + 2 ] == 'g' && str_from [ i + 3 ] == 'e' ) 
            position = i + 12;
    }
    
    for ( i = position, j = 0; i < strlen ( str_from ); i++, j++ ){

        str_to [ j ] = str_from [ i ];
    }

}
