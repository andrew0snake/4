#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
//if rezult of recognizing of string is digit returning value is '0'
#define NUMBER_0 '0'
//if rezult of recognizing of string is 'a'  returning value is '1'
#define NUMBER_1 '1'
//if rezult of recognizing of string is 'b' returning value is '2'
#define NUMBER_2 '2'
//if rezult of recognizing of string is 'c' returning value is '3'
#define NUMBER_3 '3'
//if rezult of recognizing of string is 'd' returning value is '4'
#define NUMBER_4 '4'
//if rezult of recognizing of string is sin returning value is '5'
#define NUMBER_5 '5'
//if rezult of recognizing of string is exp returning value is '6'
#define NUMBER_6 '6'
//if rezult of recognizing of string is pow returning value is '7'
#define NUMBER_7 '7'
//if rezult of recognizing of string is pow returning value is '8'
#define NUMBER_8 '8'
//if rezult of recognizing of string is pow returning value is '9'
#define NUMBER_9 '9'
//if rezult of recognizing of string is pow returning value is '10'
#define NUMBER_10 '10'
//if rezult of recognizing of string is pow returning value is '11'
#define NUMBER_11 '11'
//if rezult of recognizing of string is pow returning value is '12'
#define NUMBER_12 '12'


#define MAXVAL 100
#define MAXSIZE 1000

#define BUFSIZE 100

char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch
char symb_string [ MAXSIZE ];
unsigned short int symbstr_p = 0;
unsigned short int eq_p;
unsigned short int ex_val = 0;
unsigned short int ended_exp;
unsigned short int last_val = 0;
unsigned short int pre_last_val = 0;

double val_a;
double val_b;
double val_c;
double val_d;
double val_last;

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
unsigned short int isvalue ( char string [ MAXSIZE ] );
unsigned short int iscommand ( char string [ MAXSIZE ] );
unsigned short int isoperator ( char c );
unsigned short int recognize_string ( char c [ MAXSIZE ] );
void put_digit_in_value ( unsigned short int value );
void put_values_in_stack ( void );
void put_pre_last_value_in_stack ( void );
void def_last_val ( unsigned short int );
void def_pre_last_val ( unsigned short int );

void main ()

{
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    char s [ MAXOP ];
 
    symbstr_p = 0; 
    eq_p = 0;
    ended_exp = 0;
    val_a = 0.0;
    val_b = 0.0;
    val_c = 0.0;
    val_d = 0.0;

    val_a_p = 0;
    val_b_p = 0;
    val_c_p = 0;
    val_d_p = 0;

    printf ( "---------------------------------------------------------------------------------------------\n");
    printf ( "This is polish notation calculator.\nIn it you can use binary functions '+', '-', '*', '/', '%%'.\n" );
    printf ( "Also in it may be used values 'a', 'b', 'c', 'd'; values are using by expression \"a 5 = \" and \"enter\".\n" );
    printf ( "And also it's possible to use a functions sin, exp and pow in syntax \"4 pow\" \"enter\".\n" );
    printf ( "---------------------------------------------------------------------------------------------\n\n");


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
            if ( last_val > 0 || pre_last_val > 0 ) {
                printf ( "in + last_val = %d; pre_last_val = %d, sp = %d.\n", last_val, pre_last_val, sp );
                put_values_in_stack ();
                push_my ( pop () + pop () );
            }
            else {
                push_my ( pop () + pop () );
            };
            break;
        case '*':
            if ( last_val > 0 || pre_last_val > 0 ) {
                printf ( "in * last_val = %d; pre_last_val = %d.\n", last_val, pre_last_val );
                put_values_in_stack ();
                push_my ( pop () * pop () );
            }
            else {            
            push_my ( pop () * pop () );
            };
            break;
        case '-':
            if ( last_val > 0 || pre_last_val > 0 ) {
                printf ( "in - last_val = %d; pre_last_val = %d, sp = %d.\n", last_val, pre_last_val, sp );
                put_values_in_stack ();
//                op2 = pop ();
  //              push_my ( pop () - op2 );
            }
 
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
            if ( last_val > 0 || pre_last_val > 0 ) {
                printf ( "in / last_val = %d; pre_last_val = %d, sp = %d.\n", last_val, pre_last_val, sp );
                put_values_in_stack ();
//                op2 = pop ();
//                push_my ( pop () - op2 );
            }
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
            put_digit_in_value ( last_val );
            printf ( "After putting digit in value:\na = %f, b = %f, c = %f, d = %f.\n", val_a, val_b, val_c, val_d );
            break;
        case '\n':
            printf ( "\nResult = %.8g; neg = %d;\n", pop (), neg );
            printf ( "Values:\na = %f, b = %f, c = %f, d = %f, last_val = %d, pre_last_val = %d.\n", val_a, val_b, val_c, val_d, last_val, pre_last_val );

            break;
        case NUMBER_1:
            printf ( "Getted values:\na = %f, b = %f, c = %f, d = %f.\n", val_a, val_b, val_c, val_d );
            break;
        case NUMBER_5:
            op2 = pop ();
            push_my ( sin ( op2 ) );
            op2 = 0; 
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
    int rez = 0;
    char tmp_str [ MAXSIZE ];
    int len_str = 0;
    
    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        ;
    s [ 1 ] = '\0';
    
    if ( ! isdigit ( c ) && c != '.' ){
        if ( isoperator ( c ) == 1 ) {
            return c; /* is not a number or letter */
        }
        else {
            if ( isletter ( c ) == 1 ) {
                symb_string [ symbstr_p++ ] = c;                
                while ( isletter ( symb_string [ symbstr_p++ ] = c = getch () ) )
                ;
                len_str =  strlen ( symb_string ) ; 
                if ( isoperator ( c ) == 1 ) {
                    if ( c != '\n' ) { 
                        ungetch ( c );
                    };
                    symb_string [ --symbstr_p ] = '\0';
                }
                else {
                    if ( c == ' ' || c == '\t' ) {
                        symb_string [ --symbstr_p ] = '\0';
                    }
                    else 
                        if ( isdigit ( c ) ) {
                            ungetch ( c );
                            symb_string [ --symbstr_p ] = '\0';
                        }
                };
                rez = recognize_string ( symb_string );
                clear_string ( symb_string );
                printf ( "string recognized as %c;\n", rez );
                printf ( "before check last_val = %d; pre_last_val = %d;\n", last_val, pre_last_val );
                if ( last_val > 0 && rez >= NUMBER_1 && rez <= NUMBER_4) {
                    def_pre_last_val ( rez );
                    printf ( "After definition pre_last_val = %d; last_val = %d;\n", pre_last_val, last_val );
                }
                else {
                    if ( last_val == 0 && rez >= NUMBER_1 && rez <= NUMBER_4 ) {
                        def_last_val ( rez );
                    };
                }
                if ( rez >= NUMBER_1 ) {
                    if ( rez <=NUMBER_4 )
                        if ( rez == NUMBER_1 ) {
                            last_val = 1;
//                            printf ( "last_val in if = %d;\n", last_val );
                        }
                        else 
                            if ( rez == NUMBER_2 ) {
                                last_val = 2;
                            }
                            else
                                if ( rez == NUMBER_3 ) {
                                    last_val = 3;
                                }
                                else 
                                    if ( rez == NUMBER_4 ) {
                                        last_val = 4;
                                    };
//                    printf ( "last_val = %d;\n", last_val );
                    return rez;
                }
                else {
                    return 0;
                };
                rez = 0;
            }
            else {
                return 0;
            }
        }
    };
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

//    if ( ( c == 'a' ) || ( c == 'b' ) || ( c == 'c' ) || ( c == 'd' ) || ( c == 'e' ) || ( c == 'i' ) || ( c == 'n' ) || ( c == 'o' ) || ( c == 'p' ) || ( c == 's' ) || ( c == 'w') ) {
    if ( c >= 'a' && c <= 'z' ) {
        return 1;
    }
    else {
        return 0;
    }


}

unsigned short int isvalue ( char string [ MAXSIZE ] ) {

    unsigned short int ret = 0;
    char val_a [ MAXSIZE ] = "a";
    char val_b [ MAXSIZE ] = "b";
    char val_c [ MAXSIZE ] = "c";
    char val_d [ MAXSIZE ] = "d";
 
    if ( strcmp ( string, val_a ) == 0 )
        ret = 1;
    else 
        if ( strcmp ( string, val_b ) == 0 )
            ret = 2;
        else 
            if ( strcmp ( string, val_c ) == 0 )
                ret = 3;
            else 
                if ( strcmp ( string, val_d ) == 0 )
                    ret = 4;
                else 
                    ret = 0;
    return ret;

}


unsigned short int iscommand ( char string [ MAXSIZE ] ) {

    unsigned short int ret = 0;
    char sin [ MAXSIZE ] = "sin";
    char exp [ MAXSIZE ] = "exp";
    char pow [ MAXSIZE ] = "pow";
 
    if ( strcmp ( string, sin ) == 0 )
        ret = 1;
    else 
        if ( strcmp ( string, exp ) == 0 )
            ret = 2;
        else 
            if ( strcmp ( string, pow ) == 0 )
                ret = 3;
            else 
                ret = 0;
    return ret;

}

unsigned short int isoperator ( char c ) {

    if ( c == '=' || c == '\n' || c == EOF || c == '%' || c == '+' || c == '-' || c == '*' || c == '/' ) {
        return 1;
    }
    else
        return 0;

}


unsigned short int recognize_string ( char string [ MAXSIZE ] ) {

    char sin [ MAXSIZE ] = "sin";
    char exp [ MAXSIZE ] = "exp";
    char pow [ MAXSIZE ] = "pow";
    char dup [ MAXSIZE ] = "dup";
    char up [ MAXSIZE ] = "up";
    char sw [ MAXSIZE ] = "sw";
    char cs [ MAXSIZE ] = "cs";



    char val_a [ MAXSIZE ] = "a";
    char val_b [ MAXSIZE ] = "b";
    char val_c [ MAXSIZE ] = "c";
    char val_d [ MAXSIZE ] = "d";
 
    int i = 0;
     
    printf ( "getted for rec string is:%s;\n", string );

//    printf ( "rez of strcmp ( val_a, string ) = %d;\n", strcmp ( string, val_a ) );

    if ( strcmp ( string, val_a ) == 0 ) {
        symbstr_p = 0;
//        printf ( "NUMBER_1;\n" );
        return NUMBER_1;
    }
    else
        if ( strcmp ( string, val_b ) == 0 ) {
            symbstr_p = 0;
//            printf ( "NUMBER_2;\n" );
            return NUMBER_2;
        }
        else
            if ( strcmp ( string, val_c ) == 0 ) {
                symbstr_p = 0;
                return NUMBER_3;
            }
            else
                if ( strcmp ( string, val_d ) == 0 ) {
                    symbstr_p = 0;
                    return NUMBER_4;
                }
                else
                    if ( strcmp ( string, sin ) == 0 ) {
                        symbstr_p = 0;
                        return NUMBER_5;
                    }
                    else
                        if ( strcmp ( string, exp ) == 0 ) {
                            symbstr_p = 0;
                            return NUMBER_6;
                        }
                        else
                            if ( strcmp ( string, pow ) == 0 ) {
                                symbstr_p = 0;
                                return NUMBER_7;
                            }
                            else 
                                if ( strcmp ( string, dup ) == 0 ) {
                                    symbstr_p = 0;
                                    return NUMBER_8;
                                }
                                else 
                                    if ( strcmp ( string, up ) == 0 ) {
                                        symbstr_p = 0;
                                        return NUMBER_9;
                                    }
                                    else 
                                        if ( strcmp ( string, dup ) == 0 ) {
                                        symbstr_p = 0;
                                        return NUMBER_8;
                                        }
                                        else 
                                            if ( strcmp ( string, sw ) == 0 ) {
                                            symbstr_p = 0;
                                            return NUMBER_9;
                                            }
                                            else 
                                                if ( strcmp ( string, cs ) == 0 ) {
                                                symbstr_p = 0;
                                                return NUMBER_10;
                                            }
                                                else {
                                                    symbstr_p = 0;
                                                    return 0;
                                                };

}

void put_digit_in_value ( unsigned short int value ) {

    if ( last_val == 1 ) { 
        val_a = pop ();
//        printf ( "val_a = %f;\n", val_a ); 
        last_val = 0;
    }
    else 
        if ( last_val == 2 ) {
            val_b = pop ();
            last_val = 0;
        }
        else
            if ( last_val == 3 ) {
                val_c = pop ();
                last_val = 0;                
            }
            else
                if ( last_val == 4 ) {
                    val_d = pop ();
                    last_val = 0;
                };

//    return 0;
}

void put_last_value_in_stack ( void ) {
    
    double tmp = 0;

        if ( last_val == 1 ) {
            tmp = val_a;
            push_my ( tmp );
            tmp = 0;
            last_val = 0;
//            sp++;
        }
        else 
            if ( last_val == 2 ) {
                tmp = val_b;
                push_my ( tmp );
                tmp = 0;
                last_val = 0;
//                sp++;
            }
            else 
                if ( last_val == 3 ) {
                    tmp = val_c;
                    push_my ( tmp );
                    tmp = 0;
                    last_val = 0;
//                    sp++;
                }
                else 
                    if ( last_val == 4 ) {
                        tmp = val_d;
                        push_my ( tmp );
                        tmp = 0;
                        last_val = 0;
//                        sp++;
                    }
        
}



void put_values_in_stack ( void ) {

    double tmp = 0;

    if ( last_val > 0 ) {
        if ( pre_last_val > 0 ) {
            if ( pre_last_val == 1 ) {
                tmp = val_a;
                push_my ( tmp );
                tmp = 0; 
                pre_last_val = 0;
//                sp++;
                put_last_value_in_stack ();
            }
            else 
                if ( pre_last_val == 2 ) {
                    tmp = val_b;
                    push_my ( tmp );
                    tmp = 0;
                    pre_last_val = 0;
//                    sp++;
                    put_last_value_in_stack ();
 
                }
                else 
                    if ( pre_last_val == 3 ) {
                        tmp = val_c;
                        push_my ( tmp );
                        tmp = 0;
                        pre_last_val = 0;
//                        sp++;
                        put_last_value_in_stack ();
 
                    }
                    else 
                        if ( pre_last_val == 4 ) {
                            tmp = val_d;
                            push_my ( tmp );
                            tmp = 0;
                            pre_last_val = 0;
//                            sp++;
                            put_last_value_in_stack ();
                        }
            
        }
        else {
            put_last_value_in_stack ();
        }
    }
}


void def_last_val ( unsigned short int rez ) {

    if ( rez >= NUMBER_1 ) {
        if ( rez <=NUMBER_4 )
            if ( rez == NUMBER_1 ) {
                last_val = 1;
//              printf ( "last_val in if = %d;\n", last_val );
            }
            else 
                if ( rez == NUMBER_2 ) {
                    last_val = 2;
                }
                else
                    if ( rez == NUMBER_3 ) {
                        last_val = 3;
                    }
                    else 
                        if ( rez == NUMBER_4 ) {
                            last_val = 4;
                        };

    }
}


void def_pre_last_val ( unsigned short int rez ) {

    if ( rez >= NUMBER_1 ) {
        if ( rez <=NUMBER_4 )
            if ( rez == NUMBER_1 ) {
                pre_last_val = last_val;
                last_val = 1;
//              printf ( "last_val in if = %d;\n", last_val );
            }
            else 
                if ( rez == NUMBER_2 ) {
                    pre_last_val = last_val;
                    last_val = 2;
                }
                else
                    if ( rez == NUMBER_3 ) {
                        pre_last_val = last_val;
                        last_val = 3;
                    }
                    else 
                        if ( rez == NUMBER_4 ) {
                            pre_last_val = last_val;
                            last_val = 4;
                        };

    }
}
