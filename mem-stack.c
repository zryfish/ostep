#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

int
main(int argc, char *argv[])
{
    if(argc != 2) {
        fprintf(stderr, "usage: mem <value>\n");
        exit(1);
    }

    printf("(pid:%d) addr of main: %llx\n", (int)getpid(), (unsigned long long) main);
    //printf("(pid:%d) addr of p : %llx\n", (int)getpid(), (unsigned long long) &p);
    int p = atoi(argv[1]);
    while(1) {
        Spin(1);
        p = p + 1;
        printf("(pid:%d) addr: %x -- value of p: %d\n" , getpid(), (unsigned) &p, p);
    }

    return 0;
}
