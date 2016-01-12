//
// Created by Sai Prashanth Chandramouli on 1/12/16.
//

#include <stdio.h>
#include <stdlib.h>
// cross platform repl, with preprocessor statements
#ifdef _WIN32
    #include <string.h>
    // here we need to stub both readline and history, as windows doesnt have editline

    void add_history(char* state) {
    // do nothing, as windows has this behavior by default
    }
#else
    #include <editline/readline.h>
#endif

int main(int argc, char *argv[]) {
    puts("LiSpy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    // infinite-loop
    while (1) {
        // o/p
        // changing fputs + fgets into readline, lets you hold memory as well
        // fputs("LiSpy> ", stdout);

        // automatically strips the \n, so we might have to add it before printing
        char* input = readline("LiSpy> ");
        // i/p
        // fgets(input, 2048, stdin);

        // lets add to memory, so it can be a proper repl
        add_history(input);

        printf("No you are a %s\n", input);

        // lets free the memory used
        free(input);
    }
}