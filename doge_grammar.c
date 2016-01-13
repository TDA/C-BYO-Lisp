//
// Created by Sai Prashanth Chandramouli on 1/13/16.
//

#include <mpc.h>

int main(int argc, char *argv[]) {

    // Create an Adjective Parser
    mpc_parser_t* Adjective = mpc_new("adjective");
    // Create an Noun Parser
    mpc_parser_t* Noun      = mpc_new("noun");
    // Create a Phrase parser, Phrase = <Adjective> <Noun>
    mpc_parser_t* Phrase    = mpc_new("phrase");
    // Create Doge using the rest
    mpc_parser_t* Doge      = mpc_new("doge");


    // multi line string in C
    // Grammar description in a proper grammar style :P
    mpca_lang(MPCA_LANG_DEFAULT,
              "\
      adjective : \"wow\" | \"many\"            \
                |  \"so\" | \"such\" | \"much\";\
      noun      : \"lisp\" | \"language\"       \
                | \"book\" | \"build\" | \"c\"; \
      phrase    : <adjective> <noun>;           \
      doge      : <phrase>*;                    \
    ",
              Adjective, Noun, Phrase, Doge);

    // parsing can be done here :D

    mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

    return 0;
}