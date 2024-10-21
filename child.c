#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    printf("\nThis is a exec run process.(pid:%d)\n",(int) getpid());
    sleep(3);
    printf("Three seconds have passed.\n");

    return 0;
}