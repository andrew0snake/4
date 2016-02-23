#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

#define BUFSIZE 100

//------------external_values--------------#
char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch
char string_source [ MAXVAL ];
unsigned short int ss_p = 0;
//-----------------------------------------#

//-----------functions---------------------#
int getop ( char [] );
void push_my ( double );
double pop ( void );

//int getch ( void );
//void ungetch ( int );
int getop ( char s [] );
void getline_my ( char string [ MAXVAL ] );
void clear_string ( string );
//-----------------------------------------#

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
            clear_string ( string_source );
            ss_p = 0;
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
    unsigned short int i = 0;
    int c = 0;
    
    getline_my ( string_source );
    while ( ( s [ 0 ] = string_source [ ss_p ] ) == ' ' || s [ 0 ] == '\t' ) {
        ss_p++;
    };
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( string_source [ ss_p ] ) && string_source [ ss_p ] != '.' ){
        return string_source [ ss_p ]; /* is not a number */
    };
    i = 0;
    
    if ( isdigit ( c = string_source [ ss_p ] ) )	/* getting whole part */
        while ( isdigit ( s [ ++i ] = c = string ) )
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

/*int getch ( void )

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
*/
void getline_my ( char string_source [ MAXVAL ] ) {

    char c = 0;
    unsigned short int i = 0;

    while ( ( c = getchar () ) != '\n' && c != EOF ) {
        string_source [ i ] = c;
        i++;
    };
    
    if ( string_source [ i ] == '\n' ) {
        i++;
        string_source [ i ] = EOF;
    }
    

}

void clear_string ( char string [ MAXVAL ]) {

    unsigned short int i = 0;

    for ( i = 0; i < MAXVAL; i++ ) {
        string [ i ] = 0;
    };
}
