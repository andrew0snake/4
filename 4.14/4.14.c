#include <stdio.h>

#define is_a(a,b) (a||b?a:b)
#define is_int(a,b) ()

//#define swap(t,A,B) ((t)(C);swap3((t)(C),(t)(A),(t)(B)))
#define swap(t,A,B) ((t)(C);printf("(t)(C),(t)(A),(t)(B"))
#define swap2(t,x,y) printf("%f,%f.\n",(t)(x),(t)(y))
#define swap3(z,x,y) (z=x,x=y,y=z)

#define def(T,V) T V
#define op1(A) ((A)=(A)+3)
#define op2(B) ((B)=(op1(B))-10)
#define print_def(T,A) (def(T,A);printf( " = %f;%d;\n", A))
#define inval(T,A) T B = 5; printf ( "external_value+internal_value=%f;\n", A+B );
#define swap(T,A,B) {T Z ; Z = A; A = B; B = Z;}

#define var_args(formatting,...) printf (formatting,__VA_ARGS__)


void main () {

    char string_int [] = "int";
    char string_dbl [] = "double";
    char rez [ 10 ] ;
    
    int x = 8;
    int y = 1;
    int z = 2;
    float f = 3.0;
    float g = 1.0;
    float h = 2.0;

    op1(x);
    printf ( "after op1 x = %d;\n", x );

    op2(x);
    printf ( "after op2 x = %d;\n", x );

//    print_def(float,x);

    inval(float,y);

    printf ( "before swap in float f = %f; g = %f;\n", f, g );
    swap(float,f,g)
    printf ( "after swap in float f = %f; g = %f;\n", f, g );

    printf ( "before swap in intf = %d; g = %d;\n", y, z );
    swap(int,y,z)
    printf ( "after swap in int f = %d; g = %d;\n", y, z );

    char *formatting = "\n%s%s\n\n";
    char *string1 = "string one ";
    char *string2 = "string two ";

    var_args(formatting,string1,string2);

}
