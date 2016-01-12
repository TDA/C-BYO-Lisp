//
// Created by Sai Prashanth Chandramouli on 1/12/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>

static char input[2048];

int main(int argc, char *argv[]) {
    puts("LiSpy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    // infinite-loop
    while (1) {
        // o/p
        // changing fputs + fgets into readline, lets you hold memory as well
        // fputs("LiSpy> ", stdout);

        // automatically strips the \n, so we might have to add it before printing
        input = readline("LiSpy> ");
        // i/p
        // fgets(input, 2048, stdin);

        printf("No you are a %s", input);
    }
}