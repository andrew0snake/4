#include <stdio.h>



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
