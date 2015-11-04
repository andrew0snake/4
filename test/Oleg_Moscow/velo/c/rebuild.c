#include <stdio.h>
#include <string.h>
//void concat_my ()

void main () {

    FILE *tmp_file, *source_file;

    char str1 [ 5000 ];
    char str2 [ 5000 ];
    char str_tmp [ 5000 ];
    char index_of_string = 0;

    int i = 0;
    int j = 0;
    short int str_num = 0;
    short int index_of_symbol = 0;
    short int sc = 0;

    source_file = fopen ( "source_file", "r" );
    
    for ( sc = 0; sc < 50; sc++ ){
        while ( fgets ( str1, 200, source_file) != NULL ){
            if ( index_of_string == 0 ) {
                strcpy ( str_tmp, str1 );
                index_of_string += 1;
            }
            else {
               if ( str1 [ 0 ] == '<' ) { 
                   tmp_file = fopen ( "tmp_file", "w+" );
                   fputs ( str_tmp, tmp_file );
                   
                   i = 0;
                   j = 0;
 
                   if ( str1 [ i ] == '<' )
                       while ( str1 [ i ] != '>' ){
                           i+=1;
                       };
                   else {
                       str2 [ j ] = str1 [ i ];
                   };
                   


                   fputs ( str1, tmp_file );
               }  
            }
        };
    };


}
