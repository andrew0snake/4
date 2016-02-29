#include <stdio.h>

void qsort ( int v [], int left, int right );
void swap ( int v [], int left, int right );

void main () {

    unsigned short int i = 0;



}



void qsort ( int v [], int left, int right ) {

    int i = 0;
    int last = 0;

    if ( left >= right ) 
        return;
    
    swap ( v, left, ( left + right ) / 2 );
    last = left;
    for ( i = left + 1; i <= right; i++ ) {
        if ( v [ i ] < v [ left ] ) {
            swap ( v, ++last; i );
        };
    };

    swap ( v, left, last );
    qsort ( v, left, last - 1 );
    qsort ( v, last + 1, right );
}

void swap ( int v [], int left, int right ) {

    int temp = 0;
    temp =  v [ i ];
    v [ i ] = v [ j ];
    v [ j ] = temp; 
    

}

