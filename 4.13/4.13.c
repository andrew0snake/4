#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

char string [ ] = "string one plus two";

void reverse_my ( char string [ MAXSIZE ], int start );

void main () {

    int start = 0;

    printf ( "string before reverse = '%s';\n", string );
    reverse_my ( string, start );
    printf ( "string after reverse = '%s';\n", string );

}

void reverse_my ( char string [ MAXSIZE ], int start ) {

    char temp = 0;
    unsigned short int len = 0;

    len = strlen ( string ) - 1;
    printf ( "start = %d;\n", start );

    if ( start < ( len / 2 - 1 ) ) {
        reverse_my ( string, start + 1 );
    }; 

    temp = string [ len - start ];
    string [ len - start ] = string [ start ];
    string [ start ] = temp;
   
}


