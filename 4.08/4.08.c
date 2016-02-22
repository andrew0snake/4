#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define MAXLEN 10
#define NUMBER_0 '0'
#define NUMBER_1 '1'
#define NUMBER_2 '2'
#define NUMBER_3 '3'
#define NUMBER_4 '4'
#define NUMBER_5 '5'
#define NUMBER_6 '6'
#define NUMBER_7 '7'
#define NUMBER_8 '8'
#define NUMBER_9 '9'
#define NUMBER_10 '10'
#define NUMBER_11 '11'
#define NUMBER_12 '12' //return string ( ungets ( s ) )
#define NUMBER_13 '13'
#define NUMBER_14 '14'
#define NUMBER_15 '15'



#define BUFSIZE 100

//-----------values
char neg = 0; //negativity pointer
int sp = 0; //stack pointer
double val [ MAXVAL ]; //stack of values
char buf [ BUFSIZE ]; //buffer for ungetch
int bufp = 0; //next free position for ungetch

char string_symb [ MAXVAL ];
char string_unget [ MAXVAL ];
unsigned short int str_symb_p = 0;
unsigned short int str_unget_p = 0;
unsigned short int last_val = 0;
unsigned short int pre_last_val = 0;

double val_a;
double val_b;
double val_c;
double val_d;

//-----------values

//-----------functions
int getop ( char [] );
void push_my ( double );
double pop ( void );

int getch ( void );
void ungetch ( int c );
int getop ( char s [] );
int double2int ( double );
unsigned short int isoperand ( char symb );
unsigned short int isletter ( char symb );
void clear_string ( char string [ MAXVAL ] );
unsigned short int recogn_string ( char string [ MAXVAL ] );
void def_last_val ( unsigned short int match );
void def_pre_last_val ( unsigned short int match );
void put_digit_in_value ( void );
void push_last_and_prelast ( void );
unsigned short int convert_match_to_predefided ( unsigned short int match );
void print_stack ();
void ungets ( char s [ MAXVAL ] );
void print_unget_string ();
//-----------functions

void main ()

{
    int type = 0;
    int op2_int = 0;
    double op2 = 0;
    double op3 = 0;
    double last = 0;
    char s [ MAXOP ];
    unsigned short int i = 0;


    printf ( "---------------------------------------------------------------------------------------------\n");
    printf ( "This is polish notation calculator.\nIn it you can use binary functions '+', '-', '*', '/', '%%'.\n" );
    printf ( "Also in it may be used values 'a', 'b', 'c', 'd'; values are using by expression \"a 5 = \" and \"enter\".\n" );
    printf ( "---------------------------------------------------------------------------------\n" );
    printf ( "IMPORTANT!!! Between digits, values, operands and commands you MUST use spaces!\n" );
    printf ( "---------------------------------------------------------------------------------\n" );
    printf ( "In it you may use next comands:\n" );
    printf ( "ph - print higher element in stack ( with safekeeping this element in stack ).\n" );
    printf ( "sw - switch two higher elements in stack.\n" );
    printf ( "cs - clear stack.\n" );
    printf ( "dbl - double element in stack.\n" );
    printf ( "And also it's possible to use a functions sin, exp and pow in syntax \"4 pow\" \"enter\".\n" );
    printf ( "---------------------------------------------------------------------------------------------\n\n");

    clear_string ( string_symb );
    str_symb_p = 0;
 
    while ( ( type = getop ( s ) ) != EOF ){
        switch ( type ){
        case NUMBER_0:
           push_my ( atof ( s ) );
           break;
        case '+':
            push_last_and_prelast ();
            push_my ( pop () + pop () );
            break;
        case '*':
            push_last_and_prelast ();
            push_my ( pop () * pop () );
            break;
        case '-':
            push_last_and_prelast ();
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
            push_last_and_prelast ();
            op2 = pop ();
            if ( op2 != 0.0 )
                push_my ( pop () / op2 );
            else 
                printf ( "Error, division by zero.\n" );
            break;
        case '%':
            push_last_and_prelast ();
            op2_int = ( int )  pop ();
            push_my ( ( ( int )  pop () ) % op2_int );
            break;
        case '\n':
            last = pop ();
            printf ( "Result = %.8g; neg = %d; sp = %d.\n", last, neg, sp );
            printf ( "Values: val_a = %lf, val_b = %lf, val_c = %lf, val_d = %lf.\n", val_a, val_b, val_c, val_d );
            print_stack ();
            print_unget_string ();
            clear_string ( string_unget );
            str_unget_p = 0;
            break;
        case 0:
            printf ( "Wrong input,may you try again?\n" );
            break;
        case 1:
            printf ( "Inputed value a.\n" );
            break;
        case 2:
            printf ( "Inputed value b.\n" );
            break;
        case 3:
            printf ( "Inputed value c.\n" );
            break;
        case 4:
            printf ( "Inputed value d.\n" );
            break;
        case NUMBER_5:
            op2 = pop ();
            push_my ( op2 );
            printf ( "Highest element in stack is %lf.\n", op2 );
            break;
        case NUMBER_6:
            if ( sp > 1 ) {
                printf ( "Stack before switching:\n" );
                print_stack ();
                op2 = pop ();
                op3 = pop ();
                push_my ( op2 );
                push_my ( op3 );
                printf ( "Stack after switching:\n" );
                print_stack ();
            }
            else {
                printf ( "Stack has too little arguments for switching.\n" );
            }
            break;
        case NUMBER_7:
            if ( sp > 0 ) {
                printf ( "Clearing stack.\n" );
                for ( i = 0; i < sp; i++ ) {
                    val [ i ] = 0;
                };
            }
            else {
                printf ( "Stack is empty, nothing to clear.\n" );
            }
            break;
        case 8:
            push_last_and_prelast ();
            if ( sp > 0 ) {
                push_my ( sin ( pop () ) );
            }
            else {
                printf ( "Stack of digits is empty. nothing to use.\n" );
            };
            break;
        case NUMBER_9:
            push_last_and_prelast ();
            push_my ( exp ( pop () ) );
            op2 = 0;
            break;
        case NUMBER_10:
            push_last_and_prelast ();
            op2 = pop (); 
            push_my ( pow ( pop (), op2 ) );
            op2 = 0;
            break;
        case NUMBER_11:
            push_last_and_prelast ();
            op2 = pop ();
            push_my ( op2 );
            push_my ( op2 );
            op2 = 0;
            break;
        case NUMBER_12:
            printf ( "In case NUMBER_12 here is printing string_unget.\n" );
            print_unget_string ();
            printf ( "And now same ungets function.\n" );
            ungets ( string_unget );
            break;
        case '=':
            if ( sp > 0 ) {
                put_digit_in_value ();
            }
            else {
                printf ( "Too early to equate. Try to input digit at first.\n" );
            };
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
        printf ( "After addition stack pointer sp = %d; and pushing   value = %4lf;\n", sp, val [ sp - 1 ] );
    }
    else 
        printf ( "Error:stack is full. %g not contain.\n", f );

}

double pop ( void ) 

{

    if ( sp > 0 ){
        printf ( "After decrease stack pointer sp = %d; and returning value = %4lf;\n", sp - 1, val [ sp - 1 ] );
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
    int c2 = 0;
    int t = 0;
    unsigned short int match = 0;
    unsigned short int exit = 0;
   
    while ( ( s [ 0 ] = c = getch () ) == ' ' || c == '\t' ) 
        ;
    s [ 1 ] = '\0';
    
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
        if ( c != ' ' ) 
            return 0;
//        if ( c != EOF )
  //          ungetch ( c );
         printf ( "Whole string is:%s;\n", s );    
        return NUMBER_0;
    }
    else {
        if ( isoperand ( c ) || c == '\n' ) {
            return c;
        }
        else {
            if ( isletter ( c ) ) {
                clear_string ( string_symb );
                string_symb [ 0 ] = c;
                str_symb_p = 1;
                if ( ( c2 = getch () ) == ' ' ) {
                    ungetch ( c2 );
                    string_symb [ 1 ] = '\0';
                    str_symb_p = 1;
                    match = 0;
                    if ( ( match = recogn_string ( string_symb ) ) > 0 ) {
                        if ( last_val > 0 ) {
//                            def_pre_last_val ( match );   
                            pre_last_val = last_val;
                            last_val = match;
                        }
                        else {
//                            def_last_val ( match );
                            last_val = match;
                        };
                        clear_string ( string_symb );
                        return convert_match_to_predefided ( match );
//                        return match;
                    }
                    else {
                        return 0;                   
                    }
                }
                else {
                    if ( isletter ( c2 ) == 1 ){
                        string_symb [ 1 ] = c2;
                        str_symb_p = 2;
                        match = 0;
                    }
                    else {
                        clear_string ( string_symb );
                        return 0;
                    };
                    printf ( "2.string_symb = %s. str_symb_p = %d.\n", string_symb, str_symb_p );
                    match = 0;
                    while ( match < 1 ) {
                        if ( str_symb_p > MAXLEN ) {
                            clear_string ( string_symb );
                            return 0;
                        };
                        match = recogn_string ( string_symb );
                        printf ( "after recognizing match = %d, str_symb_p = %d, and string : \'%s\'.\n", match, str_symb_p, string_symb );
                        if ( match == 0 ) {
                           string_symb [ str_symb_p ++ ] = c = getch (); 
                        }
                        else {
                            clear_string ( string_symb );
                            return convert_match_to_predefided ( match );
//                            return match;
                        }
                        if ( isletter ( c ) == 0 ) {
                            clear_string ( string_symb );
                            return 0;
                        }
                    };
                    printf ( "after recogn match = %d, string = %s;\n", match, string_symb );    
                };  
            }
            else {
                if ( c == '=' )
                    return c;
                if ( c == EOF ) {
                    return ( -1 ); 
                }
                else {
                    return 0; 
                };
            }
        }      

    }
}

int getch ( void )

{
    char symb = 0;
    
    if ( bufp > 0 ) {
        symb = buf [ --bufp ];
        if ( symb != ' ' ) {
            string_unget [ str_unget_p ++ ] = symb;
        }
        printf ( "bufp > 0; returning '%c', str_unget_p = %d.\n", symb, str_unget_p );
        return symb;
    }
    else {
        symb = getchar ();
        string_unget [ str_unget_p ++ ] = symb;
        printf ( "bufp < 0; returning '%c', str_unget_p = %d.\n", symb, str_unget_p );
        return symb; 
    }


//    printf ( "In getch: bufp = %d, buf [ bufp - 1 ] = \'%c\'.\n", bufp, buf [ bufp - 1] );
//    return ( ( bufp > 0 ) ? ( buf [ --bufp ] ) : getchar () );

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

void clear_string ( char string [ MAXVAL ] ) {

    int i = 0;

    for ( i = 0; i < MAXVAL; i++ ) {
        string [ i ] = 0;
    };

}

unsigned short int recogn_string ( char string [ MAXVAL ] ) {

    char ph [ MAXVAL ] = "ph"; 
    char sw [ MAXVAL ] = "sw"; 
    char cs [ MAXVAL ] = "cs"; 
    char dbl [ MAXVAL ] = "dbl";
    char sin [ MAXVAL ] = "sin"; 
    char exp [ MAXVAL ] = "exp"; 
    char pow [ MAXVAL ] = "pow"; 
    char ret [ MAXVAL ] = "ret"; 
    char a [ MAXVAL ] = "a"; 
    char b [ MAXVAL ] = "b"; 
    char c [ MAXVAL ] = "c"; 
    char d [ MAXVAL ] = "d"; 

    int i = 0;
    printf ( "in recogn_string string_symb = %s;\n", string_symb );

    if ( strcmp ( string, a ) == 0 ) {
        str_symb_p = 0;
        return 1;
    }
    else {
        if ( strcmp ( string, b ) == 0 ) {
            str_symb_p = 0;
            return 2;
        }
        else {
            if ( strcmp ( string, c ) == 0 ) {
                str_symb_p = 0;
                return 3;
            }
            else {
                if ( strcmp ( string, d ) == 0 ) {
                    str_symb_p = 0;
                    return 4;
                }
                else {
                    if ( strcmp ( string, ph ) == 0 ) {
                        str_symb_p = 0;
                        return 5;
                    }
                    else {
                        if ( strcmp ( string, sw ) == 0 ) {
                            str_symb_p = 0;
                            return 6;
                        }
                        else {
                            if ( strcmp ( string, cs ) == 0 ) {
                                str_symb_p = 0;
                                return 7;
                            }
                            else {
                                if ( strcmp ( string, sin ) == 0 ) {
                                    str_symb_p = 0;
//                                    printf ( "in recogn_string in compare with sin string_symb = %s; str_symb_p = %d;\n", string_symb, str_symb_p );
                                    return 8;
                                }
                                else {
                                    if ( strcmp ( string, exp ) == 0 ) {
                                         str_symb_p = 0;
                                         return 9;
                                    }
                                    else {
                                        if ( strcmp ( string, pow ) == 0 ) {
                                            str_symb_p = 0;
                                            return 10;
                                        }
                                        else {
                                            if ( strcmp ( string, dbl ) == 0 ) {
                                                str_symb_p = 0;
                                                return 11;
                                            }
                                            else {
                                                if ( strcmp ( string, ret ) == 0 ) {
                                                    str_symb_p = 0;
                                                    return 12;
                                                }
                                                else 
                                                    return 0;
                                            }                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void put_digit_in_value ( void ) {

    if ( last_val == 1 ) {
        val_a = pop ();
        last_val = 0;
    }
    else {
        if ( last_val == 2 ) {
            val_b = pop ();
            last_val = 0;
        }    
        else {
            if ( last_val == 3 ) {
                val_c = pop ();
                last_val = 0;
            }
            else {
                if ( last_val == 4 ) {
                    val_d = pop ();
                    last_val = 0;
                }
            }
        }
    }
}



void push_last_and_prelast ( void ) {

    printf ( "Pushing last and pre_last values.\n" );
    if ( last_val > 0 ) {
        if ( pre_last_val > 0 ) {
            if ( pre_last_val == 1 ) {
                push_my ( val_a );
            };
            if ( pre_last_val == 2) {
                push_my ( val_b );
            };
            if ( pre_last_val == 3 ) {
                push_my ( val_c );
            };
            if ( pre_last_val == 4 ) {
                push_my ( val_d );
            };

            if ( last_val == 1 ) {
                push_my ( val_a );
            };
            if ( last_val == 2) {
                push_my ( val_b );
            };
            if ( last_val == 3 ) {
                push_my ( val_c );
            };
            if ( last_val == 4 ) {
                push_my ( val_d );
            };

            pre_last_val = 0;
            last_val = 0;
        }
        else {
            if ( last_val == 1 ) {
                push_my ( val_a );
            };
            if ( last_val == 2) {
                push_my ( val_b );
            };
            if ( last_val == 3 ) {
                push_my ( val_c );
            };
            if ( last_val == 4 ) {
                push_my ( val_d );
            };

            last_val = 0;
        }; 
    };

    printf ( "End of pushing.\n" );

}

unsigned short int convert_match_to_predefided ( unsigned short int match ) {

    if ( match == 1 ) {
        return NUMBER_1;
    }
    if ( match == 2 ) {
        return NUMBER_2;
    }
    if ( match == 3 ) {
        return NUMBER_3;
    }
    if ( match == 4 ) {
        return NUMBER_4;
    }
    if ( match == 5 ) {
        return NUMBER_5;
    }
    if ( match == 6 ) {
        return NUMBER_6;
    }
    if ( match == 7 ) {
        return NUMBER_7;
    }
    if ( match == 8 ) {
        return NUMBER_8;
    }
    if ( match == 9 ) {
        return NUMBER_9;
    }
    if ( match == 10 ) {
        return NUMBER_10;
    }
    if ( match == 11 ) {
        return NUMBER_11;
    }
    if ( match == 12 ) {
        return NUMBER_12;
    }
    if ( match == 13 ) {
        return NUMBER_13;
    }
    if ( match == 14 ) {
        return NUMBER_14;
    }
    if ( match == 15 ) {
        return NUMBER_15;
    }



}

void print_stack () {

    unsigned short int i = 0;

    if ( sp == 0 ) {
        printf ( "Stack is empty.\n" );
    }
    else {
        printf ( "Stack:\n" );
    };

    for ( i = 0; i < sp; i++ ) {
        printf ( "val [ %d ] = %lf.\n", i, val [ i ] );
    }

}

void print_unget_string () {

    int i = 0;

    while ( i <= str_unget_p ) {
        printf ( "str_unget [ %d ] = %c; and %d in digit.\n", i, string_unget [ i ], string_unget [ i ] );
        i++;
    };


}


void ungets ( char string [ MAXVAL ] ) {

    int i = 0;
    char exit = 0;

    while ( exit == 0 ) {

        printf ( "before check string [ %d ] = %c; exit = %d.\n", i, string [ i ], exit );
        if ( string [ i ] == 'r' && string [ i + 1 ] == 'e' && string [ i + 2 ] == 't' ) {
            exit = 1;
            i--;
        };
        if ( string [ i ] == EOF ) {
            exit = 1;
            i--;
        };
        if ( i > str_unget_p ) {
            exit = 1;
            i--;
        };
        if ( exit == 0 ) {
            i++;
        };
        printf ( "after check i = %d; exit = %d.\n", i, exit );
    }

    while ( i >= 0 ) {
        printf ( "ungetch ( string [ %d ] = '%c' ); \n", i, string [ i ] );
        ungetch ( string [ i ] );
        i--;
    }




}
