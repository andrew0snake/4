#include <stdio.h>
    
int main( int argc, char **argv ) {
        unsigned int randval;
     FILE *f;
 
    f = fopen("/dev/random", "r");
    fread(&randval, sizeof(randval), 1, f);
    fclose(f);
 
    printf("%u\n", randval);

    while ( randval > 100 ) {
        randval /= 3;
        printf ( "randval = %d;\n", randval);
    };

    return 0;
 }

