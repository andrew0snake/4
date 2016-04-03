#include <stdio.h>
#if PARAM == 1
#define MYDEF "one.h"
#elif PARAM == 2
#define MYDEF "two.h"
#elif PARAM == 3
#define MYDEF "three.h"
#elif PARAM == 4
#define MYDEF "four.h"
#endif
#include MYDEF

void main () {

    printf ( "MYDEF = %s;\n", MYDEF );

    printf ( "value = %d;\n", VAL );

}
