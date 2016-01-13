//
// Created by Sai Prashanth Chandramouli on 1/13/16.
//

// "" searches current dir first, while <> searches
// system first :D wow!
#include "mpc.h"

int main(int argc, char *argv[]) {

    // Build an Adjective Parser
    mpc_parser_t* Adjective = mpc_or( 5, // no of arguments
            mpc_sym("Such"), // each symbol is wrapped in mpc_sym
            mpc_sym("So"), // each symbol is wrapped in mpc_sym
            mpc_sym("Much"),
            mpc_sym("Many"),
            mpc_sym("Wow")
    );

    // Build an Noun Parser
    mpc_parser_t* Noun = mpc_or( 5, // no of arguments
            mpc_sym("lisp"), mpc_sym("language"),
            mpc_sym("book"), mpc_sym("build"),
            mpc_sym("c")
    );

    // Build a Phrase parser, Phrase = <Adjective> <Noun>
    mpc_parser_t* Phrase = mpc_and( 2, // no of arguments
                                 mpcf_strfold, // how to add up the individual tokens
                                 Adjective,
                                 Noun,
                                 free
    );

    mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

    // parsing can be done here :D


    mpc_delete(Doge);
    return 0;
}