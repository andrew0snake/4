#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100
char neg = 0;

main () {
    int sp = 0;
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    char s [ MAXOP ];
 
    while ( ( type = getop ( s ) ) != EOF ){
        printf ( "type = '%c' in char and %d in digit.\n", type, type );
        switch ( type ){
        case NUMBER:
            if ( neg == 0 ) {
                printf ( "push in stack %lf; neg = %d;\n", atof ( s ), neg );
            }
            else {
                printf ( "push in stack -%lf; neg = %d;\n", atof ( s ), neg );
            };
            if ( neg == 0 )
                push_my ( atof ( s ) );
            else {
                push_my ( - atof ( s ) );
                neg = 0;
            }
           break;
        case '+':
            push_my ( pop () + pop () );
            break;
        case '*':
            push_my ( pop () * pop () );
            break;
        case '-':
            if ( sp == 2 ) {
                printf ( "Operation minus.\n" );
                op2 = pop ();
                push_my ( pop () - op2 );
            }
            else {
                printf ( "sp = %d; and neg = 1.\n", sp );
                neg = 1;
            }
            break;
        case '/':
            op2 = pop ();
            if ( op2 != 0.0 )
                push_my ( pop () / op2 );
            else 
                printf ( "Error, division by zero.\n" );
            break;
        case '%':
            op2_int = ( int )  pop ();
            push_my ( ( ( int )  pop () ) % op2_int );
            break;
        case '\n':
            printf ( "Result = %.8g; neg = %d;\n", pop (), neg );
            break;
        default:
            printf ( "Error, unknown operation %s.\n", s );
            break;
        };
    };
}
