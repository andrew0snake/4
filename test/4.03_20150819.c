#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define WORDS 'a'
#define MAXVAL 100

#define BUFSIZE 100

int sp = 0;             //stack pointer, pointer at free position of 
double val [ MAXVAL ];
char buf [ BUFSIZE ];   //buffer for ungetch
int bufp = 0;           //next free position for ungetch

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

    while ( ( type = getop ( s ) ) != EOF  ){
       if ( type == NUMBER ){
          printf ( "type = NUMBER;\n" );
       } 
       else
           if ( type == '+' ){
               printf ( "type = +;\n" );
           } 
           else
               if ( type == '-' ){
                   printf ( "type = -;\n" );
               } 
               else
                   if ( type == '*' ){
                       printf ( "type = *;\n" );
                   } 
                   else
                       if ( type == '/' ){
                            printf ( "type = /;\n" );
                        } 
                       else 
                           if ( type == WORDS )
                               printf ( "type = WORDS;\n" );

    }
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
    int c = 0;
    
    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        printf ( "c = %c;\n" );
    s [ 1 ] = '\0';
    printf ( "after first while s [ 0 ] = %c in char = %d in digit ;\n", s [ 0 ], s [ 0 ] );
    
    if ( ! isdigit ( c ) && c != '.' ){
        printf ( "in getop c is not digit or point and is returned;\n" );
        return c; /* is not a number */
    };
    i = 0;
    
    if ( isdigit ( c ) ){	/* getting whole part */
        while ( isdigit ( s [ ++i ] = c = getch () ) ){
		printf ( "in second while ( if (isdigit ( c ) ) ) s [ i = %d ]  = %c in char = %d in digit;\n", i, c, c );
        }
    };
    printf ( "After second while s [ i = %d ] = %c in char and %d in digit;\n", i, s [ i ], s [ i ] );
    if ( c == '.' )		/* getting fractional part */
        while ( isdigit ( s [ ++i ] = c = getch () ) ){
        };

    s [ i ] = '\0';
    if ( c != EOF )
        ungetch ( c );
    printf ( "Whole string = %s;\n", s );    
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
