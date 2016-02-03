#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER_0 '0'
#define MAXVAL 100

#define BUFSIZE 100

//-----------values
char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch
//-----------values

//-----------functions
int getop ( char [] );
void push_my ( double );
double pop ( void );

int getch ( void );
void ungetch ( int );
int getop ( char s [] );
int double2int ( double );
unsigned short int isoperand ( char symb );
unsigned short int isletter ( char symb );
//-----------functions

void main ()

{
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    char s [ MAXOP ];


    printf ( "---------------------------------------------------------------------------------------------\n");
    printf ( "This is polish notation calculator.\nIn it you can use binary functions '+', '-', '*', '/', '%%'.\n" );
    printf ( "Also in it may be used values 'a', 'b', 'c', 'd'; values are using by expression \"a 5 = \" and \"enter\".\n" );
    printf ( "And also it's possible to use a functions sin, exp and pow in syntax \"4 pow\" \"enter\".\n" );
    printf ( "---------------------------------------------------------------------------------------------\n\n");


 
    while ( ( type = getop ( s ) ) != EOF ){
        switch ( type ){
        case NUMBER_0:
           push_my ( atof ( s ) );
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
        if ( neg == 1 ) {
            val [ sp++ ] = -f;
            neg = 0;
        }
        else {
            val [ sp++ ] = f;
        }
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
    
/*    if ( ! isdigit ( c ) && c != '.' ){
        return c; // is not a number 
    };
*/
    if ( isdigit ( c ) || c == '.' ) {
        i = 0;
    
        if ( isdigit ( c ) )	/* getting whole part */
            while ( isdigit ( s [ ++i ] = c = getch () ) )
            ;
    
        if ( c == '.' )		/* getting fractional part */
            while ( isdigit ( s [ ++i ] = c = getch () ) ){
                printf ( "s [ i = %d ] = %d in digit and %c in char;\n", i, s [ i ], s [ i ] );
            };   

        s [ i ] = '\0';
        if ( c != EOF )
            ungetch ( c );
         printf ( "Whole string is:%s;\n", s );    
        return NUMBER_0;
    }
    else {
        if ( isoperand ( c ) ) {
            return c;
        }
        else {
            if ( isletter ( c ) ) {

            }
            else {
                if ( c == EOF ) {
//                    return 
                };
            }
        }      

    }
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

unsigned short int isoperand ( char symb ) {
    
    if ( symb == '+' || symb == '-' || symb == '*' || symb == '/' || symb == '%' )
        return 1;
    else
        return 0;
}

unsigned short int isletter ( char symb ) {

   if ( symb >= 'a' && symb <= 'z' )
       return 1;
   else
       return 0;
}

