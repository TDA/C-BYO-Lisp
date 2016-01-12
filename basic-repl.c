//
// Created by Sai Prashanth Chandramouli on 1/12/16.
//

#include <stdio.h>

static char input[2048];

int main(int argc, char *argv[]) {
    puts("LiSpy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    // infinite-loop
    while (1) {
        // o/p
        fputs('LiSpy>', stdout);

        // i/p
        fgets(input, 2048, stdin);

        printf("No you are a %s", input);
    }
    return 0;
}