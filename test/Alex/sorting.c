#include <stdio.h>
#include <string.h>
#define MAXSIZE_STRING 50000

    char string_note [ 23 ] = { '<','a',' ','t','y','p','e','=','"','n','o','t','e','"',' ','l',':','h','r','e','f','=','"' };
    char string_notes [ 19 ] = { '<','b','o','d','y',' ','n','a','m','e','=','"','n','o','t','e','s','"','>' };

int get_str_conj ( int start, char str_where [ MAXSIZE_STRING ], char str_what [ MAXSIZE_STRING ] );
int get_note_number ( int pointer, char string [ MAXSIZE_STRING ] );
void clear_string ( char string [] );


void main () {

    FILE *source_file, *dest_file;
    
    int string_number= 0;
    int j = 0;
    int note_number = 0;
    short int pointer = 0;

    char string_tmp [ MAXSIZE_STRING ];

    source_file = fopen ( "source_file", "r" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "strlen ( string_note ) = %5lu;\n", strlen ( string_note ) );
    printf ( "strlen ( string_notes ) = %5lu;\n", strlen ( string_notes ) );


    while ( fgets ( string_tmp, MAXSIZE_STRING, source_file ) != 0 ) {
        printf ( "getted string = %s;\n", string_tmp );
        pointer = get_str_conj ( 0, string_tmp, string_note );
        if ( pointer > 0 ) {
            printf ( "In string %d found note at position %d;\n", string_number, pointer );
            printf ( "and next symbol after string_tmp [ pointer + strlen ( string_note ) = %5lu ] is %c;\n", pointer + strlen ( string_note ), string_tmp [ pointer + strlen ( string_note )  ] );            
            note_number = get_note_number ( pointer, string_tmp );
            printf ( "note = %d;\n", note_number);
         }
        string_number++;
        pointer = 0;
    }

    fclose ( source_file );

}

int get_str_conj ( int start, char str_where [ MAXSIZE_STRING ], char str_what [ MAXSIZE_STRING ] ) {
//  return codes

//  -1 - difference between lenght of string which is checked and string which is looking for in previous string are less then zero (looking string is more than where looking for)
//  -2 - lenght of part from starting position is less then string looking for
//  -3 - lenght of string where = 0
//  -4 - lenght of string what is eq 0


    int i = 0;
    int j = 0;
    int k = 0; 
    int l = 0;
    int len_where = 0;
    int len_what = 0;
    int diff_len = 0;
    char check_conj = 0;
    
    diff_len = strlen ( str_where ) - strlen ( str_what ); 
    
    if ( diff_len < 0 )
        return ( -1 );    

    if ( start > diff_len )
        return ( -2 ); 

    i = start;
    len_where = strlen ( str_where );
    len_what = strlen ( str_what );

    if (len_where == 0 )
        return ( -3 );

    if (len_what == 0 )
        return ( -4 );


    while (  i < diff_len ) {
        if ( str_what [ 0 ] == str_where [ i ] ) {
            k = i + 1;
            j = 1;
            while ( ( check_conj == 0 ) && ( j < len_what ) ) {
//                printf ( "j = %3d, k = %3d, str_where [ %3d ] = %c, check_conj = %d;\n", j, k, k, str_where [ k ], check_conj ); 
                if ( str_what [ j ] == str_where [ k ] ) {
                    check_conj = 0;
                } 
                else {
                    check_conj = 1;
                }
                j++; 
                k++;
            }
            if ( check_conj == 0 ) {
//                printf ( "Found conjuction in position %d. Whole string seems so^%s\n", i, str_where );
                return i;
            };
        }          
        i += 1;
        check_conj = 0;
    }
    return 0;
 
}


int get_note_number ( int pointer, char string [ MAXSIZE_STRING ] ) {

    int i = 0;
    int j = 0;
    int len = 0;
    int note_number = 0;
    char note_number_chars [ 100000 ];

    len = pointer + strlen ( string ) + 2;
    clear_string ( note_number_chars );
    i = len;

    while ( string [ i ] != '"' ) {
        note_number_chars [ j ] = string [ i ];
        i += 1;
        j += 1;
    };

    note_number = atoi ( note_number_chars );

    return note_number;
}

void clear_string ( char string [] ) {

    int i = 0;


    while ( i < strlen ( string ) ) {
        string [ i ] = 0;
        i++;
    }

}


