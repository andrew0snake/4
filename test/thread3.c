#include <stdio.h>


for (i = 0; i < 4; i++) {
    if (! call_in_child(some_function)) {
//        ... print error message and die...
        printf ( "Error(.\n" );
    }
}


int call_in_child(void (*function)(void))
{
    int pid = fork();
    if (pid < 0) {
        perror("fork");
        return 0;
    }
    if (pid == 0) {
        (*function)();
        exit(0);
    }
    return 1;
}

void 

