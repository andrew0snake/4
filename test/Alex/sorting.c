#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXSIZE_STRING 100000
#define MAX_NOTES_AMOUNT 100000
#define MAX_NOTE_SIZE 100000
    char string_note [ 23 ] = { '<','a',' ','t','y','p','e','=','"','n','o','t','e','"',' ','l',':','h','r','e','f','=','"' };
    char string_notes [ 19 ] = { '<','b','o','d','y',' ','n','a','m','e','=','"','n','o','t','e','s','"','>' };
    char section_id_string [ 16 ] = { '<','s','e','c','t','i','o','n',' ','i','d','=','"','n','_' };
    const char dest_filename [ 12 ] = { 'd','e','s','t','_','f','i','l','e' };
//    const char tmp_filename [ 8 ] = { 't', 'm', 'p', '_', 'f', 'i', 'l', 'e' };
    const char tmp_filename [ 9 ] = { 't','m','p','_','f','i','l','e' };
    const char string_section_id [ 18 ] = { ' ',' ','<','s','e','c','t','i','o','n',' ','i','d','=','"','n','_' };

    int note_array [ MAX_NOTES_AMOUNT ];
    int note_array_length = 0;


int get_str_conj ( int start, char str_where [ MAXSIZE_STRING ], char str_what [ MAXSIZE_STRING ] );
int get_note_number ( int pointer, char string [ MAXSIZE_STRING ] );
void clear_string ( char string [ MAXSIZE_STRING ] );
void clear_array ( int array [ MAX_NOTES_AMOUNT ] );
void replacement_notes ( int true_note,  int pointer, int note_number, char string_from [ MAXSIZE_STRING ] , char string_whole [ MAXSIZE_STRING ] );
void itoa_my ( int digit, char string [ MAXSIZE_STRING ] ); 
int replace_same_note ( char string_same_note [ MAXSIZE_STRING ] );
void reverse_string ( char srting [ MAXSIZE_STRING ] );
void replace_p ( int note, char srting [ MAXSIZE_STRING ] );


void main () {

    FILE *source_file, *dest_file;
    
    int string_number= 0;
    int i = 1;
    int j = 0;
    int note_number = 0;
    int pointer = 0;
    int pointer_end = 0;
    int note_array_size = 0;
    int true_note = 0;
    short int exit_check = 0;

//    int note_array [ MAX_NOTES_AMOUNT ];
    char string_tmp [ MAXSIZE_STRING ];
    char string_repl [ MAXSIZE_STRING ];
    char string_concat [ MAXSIZE_STRING ];

    clear_array ( note_array );

    source_file = fopen ( "source_file", "r" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "=====================================================\n" );
    printf ( "strlen ( string_note ) =  %5lu;\n", strlen ( string_note ) );
    printf ( "strlen ( string_notes ) = %5lu;\n", strlen ( string_notes ) );

/*
    In first while cycle we find and reorder notes in text of book.
    Also we fill array of notes with index as true note number and previous false as content
*/

    remove ( dest_filename );
    remove ( tmp_filename );

    while ( fgets ( string_tmp, MAXSIZE_STRING, source_file ) != 0 ) {
//        printf ( "getted string = %s;\n", string_tmp );
        exit_check = 0;
        while ( exit_check == 0 ) {
            pointer = get_str_conj ( pointer + 1, string_tmp, string_note );
           if ( pointer == -2 ) {
                dest_file = fopen ( "tmp_file", "a+" );
                fputs ( string_tmp, dest_file );
                fclose ( dest_file );
                exit_check = 1;
            }
            else {
                if ( pointer > 0 ) {
//                    printf ( "In string %d found note at position %d;\n", string_number, pointer );
                    pointer_end = pointer + strlen ( string_note );
                    note_number = get_note_number ( pointer, string_tmp );
//                    printf ( "note = %d;true_note = %d;\n", note_number, i );
                    note_array [ i ] = note_number;
                    replacement_notes ( i, pointer_end, note_number, string_tmp, string_repl );   
//                    printf ( "string with replaced note = %s;\n", string_repl );
                    clear_string ( string_tmp );
                    strcpy ( string_tmp, string_repl );    
           
                    i++;
                }
            
                else {
                    dest_file = fopen ( "tmp_file", "a+" );
                    fputs ( string_tmp, dest_file );
                    fclose ( dest_file );
                    exit_check = 1;
                };
            };
        };
        string_number++;
        pointer = 0;
 
    }

    fclose ( source_file );
    note_array_size = i;
    note_array_length = i;
    for ( j = 1; j < i; j++ ) {
        printf ( "note_array [ %d ] = %d;\n", j, note_array [ j ] );

    }

/* 
    In second part we search in notes section for same notes and replace false indexes with true from array
    
*/

    source_file = fopen ( "tmp_file", "r" );

    i = 0;
    while ( fgets ( string_tmp, MAXSIZE_STRING, source_file ) != 0 ) {
//        printf ( "second search;\nstring is:%s;\n", string_tmp );
        pointer = get_str_conj ( 0, string_tmp, section_id_string );
        if ( pointer > 0 ) {
            printf ( "section_id_string found on position %d;\n", pointer );
            true_note = replace_same_note ( string_tmp );

            dest_file = fopen ( "dest_file", "a+" );
            fputs ( string_tmp, dest_file );

            clear_string ( string_tmp );
            fgets ( string_tmp, MAXSIZE_STRING, source_file );
            fputs ( string_tmp, dest_file );

            clear_string ( string_tmp );
            fgets ( string_tmp, MAXSIZE_STRING, source_file );
            replace_p ( true_note, string_tmp );
            fputs ( string_tmp, dest_file );

            fclose ( dest_file );
        }
        else {
            dest_file = fopen ( "dest_file", "a+");
            fputs ( string_tmp, dest_file );
            fclose ( dest_file);
        }
        i++;
    }

   fclose ( source_file );
   printf ( "===================================================\n" );

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
    char note_number_chars [ MAX_NOTES_AMOUNT ];

    len = pointer + strlen ( string_note ) + 3;
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

void clear_string ( char string [ MAXSIZE_STRING ] ) {

    int i = 0;

    while ( i < MAXSIZE_STRING ) {
//    while ( i < strlen ( string ) ) {
        string [ i ] = 0;
        i++;
    }

}

 void clear_array ( int array [ MAX_NOTES_AMOUNT ] ) {

    int i = 0;

    for ( i = 0; i < MAX_NOTES_AMOUNT; i++ ) {
        array [ i ] = 0;
    }
}


void itoa_my ( int digit, char string [ MAXSIZE_STRING ] ) {

    int i = 0;
    int j = 0;
    int len = 0;
    int value = 0;
    int residual = 0;
    char tmp [ MAXSIZE_STRING ];
    char rev [ MAXSIZE_STRING ];   

    value = digit;

    while ( value > 0 ) {
        residual  = value % 10;
        value /= 10;
        tmp [ i ] = residual + '0';
        i++;
    }    
    i--;
    len = i;
    for ( j = 0; j <= len; j++, i-- ) {
        rev [ j ] = tmp [ i ];
    }
 
    strcpy ( string, rev );

}

void replacement_notes ( int true_note, int pointer, int note_number, char string_from [ MAXSIZE_STRING ] , char string_replaced [ MAXSIZE_STRING ] ) {


    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    char string_whole [ MAXSIZE_STRING ];
    char true_note_string [ MAXSIZE_STRING ];    

    for ( i = 0; i < pointer + 3; i++ ) {
        string_whole [ i ] = string_from [ i ];

    };
    itoa_my ( true_note, true_note_string );
    strcat ( string_whole, true_note_string );

    i++;
    while ( string_from [ i ] != '"' ) {
        i++;
    }
    j = i;
    k = strlen ( string_whole ) ;
    while ( string_from [ j ] != '[' ) {
        string_whole [ k ] = string_from [ j ];
        j++;
        k++;
    }
    string_whole [ k ] = string_from [ j ];
//    j++;
    k++;
    strcat ( string_whole, true_note_string );
    
    while ( string_from [ j ] != ']' ) {
        j++;
    };
//    j++;
    k = strlen ( string_whole );
    string_whole [ k ] = string_from [ j ];
    j++;
    k++;
    
    while ( string_from [ j ] != '\0' ) {
        string_whole [ k ] = string_from [ j ];
        k++;
        j++;
    }    

//    printf ( "string_whole  : %s;\n", string_whole );

    clear_string ( string_replaced );
    strcpy ( string_replaced, string_whole );

}

int replace_same_note ( char string_same_note [ MAXSIZE_STRING ] ) {

    int i = 0;
    int j = 0;
    int k = 0;
    int start = 0;
    int position = 0;
    int false_note_int = 0;
    short int found = 0;

    char false_note [ MAXSIZE_STRING ];    
    char true_note [ MAXSIZE_STRING ];
    char string_full [ MAXSIZE_STRING ];

    clear_string ( false_note );

    while ( string_same_note [ i ] != '_' ) {
        i++;
    };
    i++;
    start = i;
 
    while ( string_same_note [ i ] != '"' ) {
        false_note [ j ] = string_same_note [ i ]; 
        i++;
        j++;
    };
    
    printf ( "false_note string :%s;\n", false_note );

    false_note_int = atoi ( false_note );

    k = 1;
    while ( k < note_array_length && found == 0 ) {
        if ( note_array [ k ] == false_note_int ) {
            found = 1;
        }
        else {
            k++;
        };
    };
    position = k;

    itoa_my ( k, true_note );
  
    k = 0;
    clear_string ( string_full );
    while ( k < start ) {
        string_full [ k ] = string_same_note [ k ];
        k++;
    };
    j = k;

    strcat ( string_full, true_note );
    j += strlen ( true_note );
    
    while ( string_same_note [ k ] != '"' ) {
        k++;
    };
    
    while ( string_same_note [ k ] != '\0' ) {
        string_full [ j ] = string_same_note [ k ];
        j++;
        k++;
    };
    
    clear_string ( string_same_note );
    strcpy ( string_same_note, string_full );

    printf ( "full string is:%s;\n", string_full );

    printf ( "Note found in position %d;\n", position ); 

    return true_note;

}


void reverse_string ( char string [ MAXSIZE_STRING ] ) {

    int i = 0;
    int j = 0;
    int len = 0;
    char string_tmp [ MAXSIZE_STRING ];
    
    clear_string ( string_tmp );

    len = strlen ( string ) ;
    
    while ( i < len ) {
        string_tmp [ i ] = string [ i ];
        i++;
    };

    clear_string ( string );

    j = len - 1;
    i = 0;

    while ( i < len ) {
        string [ i ] = string_tmp [ j ];
        i++;
        j--;
    };
    i++;
    string [ i ] = '\0';
}

void replace_p ( int true_note, char string [ MAXSIZE_STRING ] ) {	

    int i = 0;
    int j = 0;
    char note_string [ MAXSIZE_STRING ];
    char full_string [ MAXSIZE_STRING ];

    clear_string ( full_string );
    while ( string [ i ] != '>' ) {
        full_string [ j ] = string [ i ]; 
        i++;
        j++;
    };
    full_string [ j ] = string [ i ]; 
    i++;
    j++;
    printf ( "1.i = %d;j = %d; full_string [ %d ] = %c; string [ %d ] = %c; full_string:%s;\n", i, j, j, full_string [ j ], i, string [ i ], full_string );
  
    clear_string ( note_string );
    itoa_my ( true_note, note_string );
    j += strlen ( note_string );
    strcpy ( full_string, note_string );
    printf ( "2.i = %d;j = %d; full_string [ %d ] = %c; string [ %d ] = %c; true_note = %d;note_string:%s;full_string:%s;\n", i, j, j, full_string [ j ], i, string [ i ], true_note,  note_string, full_string );

    while ( string [ i ] != '<' ) {
        i++;
    };

    while ( string [ i ] != '\0' ) {
        full_string [ j ] = string [ i ];
        j++;
        i++;
    };

    clear_string ( string );
    i = 0;
    while ( full_string [ i ] != '\0' ) {
        string [ i ] = full_string [ i ];
        i++;
    };
    printf ( "string with replaced p:%s;\n", string );
}












