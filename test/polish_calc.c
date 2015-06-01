#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

#define BUFSIZE 100

int sp = 0;
double val [ MAXVAL ];
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch

int getop ( char [] );
void push_my ( double );
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
            push_my ( atof ( s ) );
            break;
        case '+':
            push_my ( pop () + pop () );
            break;
        case '*':
            push_my ( pop () * pop () );
            break;
        case '-':
            op2 = pop ();
            push_my ( pop () - op2 );
            break;
        case '/':
            op2 = pop();
            if ( op2 != 0.0 )
                push_my ( pop () / op2 );
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


void push_my ( double f )

{
    if ( sp < MAXVAL )
        val [ sp++ ] = f;
    else 
        printf ( "Error:stack is full. %g not contain.\n", f );

}

double pop ( void ) 

{

    if ( sp > 0 )
        return ( val [ --sp ] );
    else 
        printf ( "Error. Stack is empty.\n" );

    return 0.0;


}

int getop ( char s [] )

{
    int i = 0;
    int  c = 0;
    
    while (  s [ 0 ] = ( c =  getch () ) == ' ' || c  == '\t'  ) 
        ;
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( c ) && c != '.' ){
        printf ( "in getop c is NOT a digit and = %c;\n", c );
        return c; /* is not a number */
    };
    i = 0;
    
    if ( isdigit ( c ) ){	/* getting whole part */
        printf ( "first check, whole part, c = %c; i = %d; s [ i = %d ] = %c;\n", c, i, i, s [ i ] );
        while ( isdigit ( s [ i ] = c = getch () ) ){
            printf ( "at step %d symbol = %c; s [ i ] = %c;  whole search.\n", i, c, s [ i ] );
            ++i;
        };
        printf ( "after while s [ i = %d ] = %c; and s [ i - 1 = %d ] = %c; \n", i, s [ i ], i - 1, s [ i - 1 ] );
    };
    if ( c == '.' )		/* getting fractional part */
        while ( isdigit ( s [ ++i ] = c = getch () ) ){
            printf ( "at step %d symbol = %c;frational search.\n", i, c );
        };

    s [ i ] = '\0';
    if ( c != EOF )
        ungetch ( c );
        
    return NUMBER;

}

int getch ( void )

{
    printf ( "in getch bufp = %d;\n", bufp );
    return ( ( bufp > 0 ) ? ( buf [ --bufp ] ) : getchar () );

}

void ungetch ( int c )

{
    if ( bufp >= BUFSIZE )
        printf ( "ungetch: too much symbols.\n" );
    else 
        buf [ bufp++ ] = c;

}
