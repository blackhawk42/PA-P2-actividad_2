#include <stdio.h>
#include <stdlib.h>

int count_lines(char *path) {
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return -1;
    }

    int count = 0;

    char last_char = EOF;
    char c;

    while( (c = fgetc(f)) != EOF ){
        if (c == '\n') {
            count++;
        }

        last_char = c;
    }

    // If the last char was not a newline, but neither was it an immediate EOF, count
    // it as a line
    if(last_char != EOF && last_char != '\n') {
        count++;
    }

    return count;
    
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter at least one file as a command line argument\n");
        exit(0);
    }

    int lines;

    for(int i = 1; i < argc; i++) {
        lines = count_lines((char *)argv[i]);
        if (lines < 0) {
            fprintf(stderr, "error: %s\n", argv[i]);
        }

        printf("%d %s\n", lines, argv[i]);
    }

    return 0;
}