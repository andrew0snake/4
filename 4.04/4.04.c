#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER_0 '0'
#define NUMBER_1 '1'
#define MAXVAL 100
#define MAXSIZE 1000

#define BUFSIZE 100

char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch
char command [ BUFSIZE ];
unsigned short int com_p;
unsigned short int eq_p;
double val_a;
double val_b;
double val_c;
double val_d;

int val_a_p;
int val_b_p;
int val_c_p;
int val_d_p;


int getop ( char [] );
void push_my ( double );
double pop ( void );

int getch ( void );
void ungetch ( int );
int getop ( char s [] );
void clear_string ( char string [ MAXSIZE ] );
unsigned short int isletter ( char c );

void main ()

{
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    char s [ MAXOP ];
 
    com_p = 0; 
    eq_p = 0;
    val_a = 0.0;
    val_b = 0.0;
    val_c = 0.0;
    val_d = 0.0;

    val_a_p = 0;
    val_b_p = 0;
    val_c_p = 0;
    val_d_p = 0;

    printf ( "\nThis is polish notation calculator.\nIn it you can use binary functions '+', '-', '*', '/', '%%'.\n" );
    printf ( "Also in it may be used values 'a', 'b', 'c', 'd'; values are using by expression a = 5 \"enter\";\n" );

    while ( ( type = getop ( s ) ) != EOF ){
        switch ( type ){
        case NUMBER_0:
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
        case '=':
            eq_p = 1;
            break;
        case '\n':
            printf ( "\nResult = %.8g; neg = %d;\n", pop (), neg );
            break;
        case NUMBER_1:
            printf ( "Getted values:\na = %f, b = %f, c = %f, d = %f.\n" );
            break;
        case 0:
            printf ( "Wrong input, symbol(s) is not command, function or value. May be you will try again?\n" );
            break;
        default:
            printf ( "Error, unknown operation %s.\n", s );
            break;
        };
    };
};


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
    char tmp_str [ MAXSIZE ];
    
    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        ;
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( c ) && c != '.' ){
        if ( c == '=' || c == '\n' || c == EOF || c == '%' || c == '+' || c == '-' || c == '*' || c == '/' ) {
        return c; /* is not a number */
        }
        else {
            if ( isletter ( c ) ) {
                printf ( "The result of isletter = %d;\n", isletter ( c ) );
                if ( val_a_p == 0 && c == 'a' ) {
                   val_a_p = 1;
                }
                else {
                    if ( val_b_p == 0 && c == 'b' ) {
                        val_b_p = 1;
                    }
                    else {
                        if ( val_c_p == 0 && c == 'c' ) {
                           val_c_p = 1;
                        }
                        else {
                            if ( val_d_p == 0 && c == 'd' ) {
                                val_d_p = 1;
                            }
                            else {
                                if ( val_a_p == 1 && c == 'a' ) {
                                     
                                }
                                command [ com_p++ ] = c;
                            };
                        };
                    };
                };
                printf ( "End of check cycle.\n" );
                return NUMBER_1;
            }
            else {
                return 0;
            }
        }
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
    return NUMBER_0;

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


void clear_string ( char string [ MAXSIZE ] ) {

    int i = 0;

    while ( i < MAXSIZE ) {
        string [ i ] = 0;
        i++;
    };

}


unsigned short int isletter ( char c ) {

    int i = 0;

    if ( ( c == 'a' ) || ( c == 'b' ) || ( c == 'c' ) || ( c == 'd' ) || ( c == 'e' ) || ( c == 'i' ) || ( c == 'n' ) || ( c == 'o' ) || ( c == 'p' ) || ( c == 's' ) || ( c == 'w') ) {
        return 1;
    }
    else {
        return 0;
    }


}


