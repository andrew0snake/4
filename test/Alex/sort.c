#include <stdio.h>
#include <string.h>
#define MAXSIZE_STRING 50000

    char string_note [ 23 ] = { '<','a',' ','t','y','p','e','=','"','n','o','t','e','"',' ','l',':','h','r','e','f','=','"' };
    char string_notes [ 19 ] = { '<','b','o','d','y',' ','n','a','m','e','=','"','n','o','t','e','s','"','>' };

int get_str_conj ( char str1 [ MAXSIZE_STRING ], char str2 [ MAXSIZE_STRING ] );


void main () {

    FILE *source_file, *dest_file;
    
    int i = 0;
    int j = 0;
    short int pointer = 0;

    char string_tmp [ MAXSIZE_STRING ];

    source_file = fopen ( "source_file", "r" );

    while ( fgets ( string_tmp, MAXSIZE_STRING, source_file) != 0 ) {
//        pointer = strstr ( string_tmp, string_note );
        if ( pointer != 0 ) {
            printf ( "In string %d found note at position %d;\n", i, pointer );
         }
        i++;
        pointer = 0;
    }


//    printf ( "lenght of string_note = %d; and string_notes = %d;\n", strlen ( string_note ), strlen ( string_notes ) );
//    printf ( "string string_note = %s;\n and string_notes = %s;\n", string_note, string_notes ); 
}

int get_str_conj ( char str1 [ MAXSIZE_STRING ], char str2 [ MAXSIZE_STRING ] ) {

    int i = 0;
    int j = 0;
    int k = 0; 
    int l = 0;
    int len1 = 0;
    int len2 = 0;
    int diff_len = 0;
    char check_conj = 0;
    
    diff_len = strlen ( str1 ) - strlen ( str2 ); 
    
    if ( diff_len < 0 )
        return EOF;    

    if ( ( ( len1 = strlen ( str1 ) ) != 0 ) && ( ( len2 = strlen ( str2 ) ) != 0 ) )
        while (  i < diff_len ) {
            if ( str2 [ 0 ] == str1 [ i ] ) {
                k = i + 1;
                for ( j = 1; ( j < strlen ( str2 ) ) || ( check_conj == 0 ); j++, k++ ) {
                    if ( str2 [ j ] == str1 [ k ] ) {
                        check_conj = 0;
                    } 
                    else {
                        check_conj = 1;
                    }
                }
                if ( check_conj == 0 ) 
            }          
            i +=1;
        }
}
























