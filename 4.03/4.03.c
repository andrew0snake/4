#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

#define BUFSIZE 100

char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch

int getop ( char [] );
void push_my ( double );
double pop ( void );

int getch ( void );
void ungetch ( int );
int getop ( char s [] );
int double2int ( double );


void main ()

{
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    char s [ MAXOP ];
 
    while ( ( type = getop ( s ) ) != EOF ){
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


void push_my ( double f )

{
    if ( sp < MAXVAL ){
        val [ sp++ ] = f;
        printf ( "After addition stack pointer sp = %d; and pushing   value = %4.0lf;\n", sp, val [ sp - 1 ] );
    }
    else 
        printf ( "Error:stack is full. %g not contain.\n", f );

}

double pop ( void ) 

{

    if ( sp > 0 ){
        printf ( "After decrease stack pointer sp = %d; and returning value = %4.0lf;\n", sp - 1, val [ sp - 1 ] );
        return ( val [ --sp ] );
    }
    else 
        printf ( "Error. Stack is empty.\n" );

    return 0.0;


}

int getop ( char s [] )

{
    int i = 0;
    int c = 0;
    
    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        ;
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( c ) && c != '.' ){
        return c; /* is not a number */
    };
    i = 0;
    
    if ( isdigit ( c ) )	/* getting whole part */
        while ( isdigit ( s [ ++i ] = c = getch () ) )
//            ++i;
        ;
    
    if ( c == '.' )		/* getting fractional part */
        while ( isdigit ( s [ ++i ] = c = getch () ) ){
            printf ( "s [ i = %d ] = %d in digit and %c in char;\n", i, s [ i ], s [ i ] );
        };
        

    s [ i ] = '\0';
    if ( c != EOF )
        ungetch ( c );
    printf ( "Whole string is:%s;\n", s );    
    return NUMBER;

}

int getch ( void )

{
    return ( ( bufp > 0 ) ? ( buf [ --bufp ] ) : getchar () );

}

void ungetch ( int c )

{
    if ( bufp >= BUFSIZE )
        printf ( "ungetch: too much symbols.\n" );
    else 
        buf [ bufp++ ] = c;

}


int double2int ( double source) {

    int i = 0;
    int dest = 0;
    double per = 0;
  

    if ( source > 0 ) {
        if ( source < 0.5 )
            dest = 0;
        else {
            if ( source >= 0.5 && source <=1 )
                dest = 1;
            else {
                per = source;
                while ( per >= 1.0 ){
                    per = per / 10;
                    
                    
                    
                }
                    
            }
        }
    
    }



}


