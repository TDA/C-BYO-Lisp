//
// Created by Sai Prashanth Chandramouli on 1/13/16.
//

#include "mpc.h"

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

    // parsing can be done here :D

    mpc_cleanup(4, Number, Operator, Expr, LiSpy);

    return 0;
}