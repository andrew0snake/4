#include <stdio.h>
#define BUFSIZE 100


//int i = 0;
int j = 0;

int array [ BUFSIZE ];

void clean_array ( int a [ BUFSIZE ] );
void swap_my ( int a [ BUFSIZE ], int left, int right );


void main () {

//    int array [ BUFSIZE ];

    int a = 0;
    int b = 0;

    clean_array ( array );

    array [ 0 ] = 5;
    array [ 1 ] = 7;
    array [ 2 ] = 9;

    for ( a = 0; a < 3; a++ ) {
        printf ( "array [ a = %d ] = %d;\n", a, array [ a ] );
    };

    a = 0;
    b = 2;
    swap_my ( array , ++a, b );

    printf ( "after swap_my:\n" );
    for ( a = 0; a < 3; a++ ) {
        printf ( "array [ a = %d ] = %d;\n", a, array [ a ] );
    };


}

void swap_my ( int a [ BUFSIZE ], int left, int right ) 

{
    int temp = 0;
 
    printf ( "in swap.\n" );
//    printf ( "left = %d; right = %d; temp = %d.\n", left, right, temp );
    printf ( "a [ left = %d ] = %d; a [ right = %d ] = %d; temp = %d.\n", left, a [ left ], right, a [ right ], temp );

    temp = a [ left ];
//    printf ( "left = %d; right = %d; temp = %d.\n", left, right, temp );
    printf ( "a [ left = %d ] = %d; a [ right = %d ] = %d; temp = %d.\n", left, a [ left ], right, a [ right ], temp );

    a [ left ] = a [ right ];
//    printf ( "left = %d; right = %d; temp = %d.\n", left, right, temp );
    printf ( "a [ left = %d ] = %d; a [ right = %d ] = %d; temp = %d.\n", left, a [ left ], right, a [ right ], temp );

    a [ right ] = temp;
//    printf ( "left = %d; right = %d; temp = %d.\n", left, right, temp );
    printf ( "a [ left = %d ] = %d; a [ right = %d ] = %d; temp = %d.\n", left, a [ left ], right, a [ right ], temp );

}

void clean_array ( int a [ BUFSIZE ] )

{

    int i = 0;

    printf ( "in clean_array;\n" );

    for ( i = 0; i < BUFSIZE; i++ ) {
//        printf ( "at step %d a [ %d ] = %d;\n", i, i, a [ i ] );
        a [ i ] = 0;
    };

}
