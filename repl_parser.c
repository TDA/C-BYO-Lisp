//
// Created by Sai Prashanth Chandramouli on 1/12/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

static const int MAX_LENGTH = 2048;
static char buffer[MAX_LENGTH];

// cross platform repl, with preprocessor statements
#ifdef _WIN32
#include <string.h>
    // here we need to stub both readline and history, as windows doesnt have editline
    char* readline(char* prompt) {
        fputs(prompt, stdout);
        fgets(buffer, MAX_LENGTH, stdin);
        char* input = malloc(strlen(buffer) + 1);
        // we need to manually append the \0 or null termination wont occur :(
        strncpy(input, buffer, MAX_LENGTH);
        input[strlen(input) - 1] = '\0';
        return input;
    }

    void add_history(char* state) {
        // do nothing, as windows has this behavior by default
    }
#else
#include <editline/readline.h>
#endif

int main(int argc, char *argv[]) {
    // Create an Number Parser
    mpc_parser_t* Number = mpc_new("number");
    // Create an Operator Parser
    mpc_parser_t* Operator = mpc_new("operator");
    // Create a Expr parser, Expr = <number> | '(' <operator> <expr>+ ')'
    mpc_parser_t* Expr = mpc_new("expr");
    // Create LiSpy using the rest
    mpc_parser_t* LiSpy = mpc_new("lispy");


    // multi line string in C
    // Grammar description in a proper grammar style :P
    mpca_lang(MPCA_LANG_DEFAULT,
              "                                                     \
    number   : /-?[0-9]+/ ;                             \
    operator : '+' | '-' | '*' | '/' ;                  \
    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
    lispy    : /^/ <operator> <expr>+ /$/ ;             \
  ", Number, Operator, Expr, LiSpy);


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

        // Attempt to Parse the user Input
        mpc_result_t result;

        if (mpc_parse("<stdin>", // input stream
                      input, // where to store it
                      Lispy, // which grammar to use for parsing
                      &result) // store result in this
            // mpc_parse returns 1 on success, 0 on failure, so can use as a conditional
                ) {
            // On Success Print the AST that was parsed
            mpc_ast_print(result.output);
            mpc_ast_delete(result.output);
        } else {
            // Otherwise Print the Error
            mpc_err_print(result.error);
            mpc_err_delete(result.error);
            break;
        }

        // lets free the memory used
        free(input);
    }

    mpc_cleanup(4, Number, Operator, Expr, LiSpy);
    return 0;
}