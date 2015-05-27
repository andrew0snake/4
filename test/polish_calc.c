#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int sp = 0;
double val [ MAXVAL ];

int getop ( char [] );
void push ( double );
double pop ( void );

int getch ( void );
void ungetch ( int );
int getop ( char s [] );


void main ()

{
    int type;
    double op2;
    char s [ MAXOP ];
 
    while ( ( type = getop ( s ) ) != EOF ){
        switch ( type ){
        case NUMBER:
            push ( atof ( s ) );
            break;
        case '+':
            push ( pop () + pop () );
            break;
        case '*':
            push ( pop () * pop () );
            break;
        case '-':
            op2 = pop ();
            push ( pop () - op2 );
            break;
        case '/':
            op2 = pop();
            if ( op2 != 0.0 )
                push ( pop () / op2 );
            else 
                printf ( "Error, division by zero.\n" );
            break;
        case '\n':
            printf ( "\t%.8g\n", pop () );
            break;
        default:
            printf ( "Error, unknown operation %s.\n", s );
            break;
        };
    };
}


void push ( double f )

{
    if ( sp < MAXVAL )
        val [ sp++ ] = f;
    else 
        print ( "Error:stack is full. %g not contain.\n", f );

}

double pop ( void ) 

{

    if ( sp > 0 )
        return ( val [ --sp ] );
    else 
        printf ( "Error. Stack is empty.\n" );

    return 0.0;


}














