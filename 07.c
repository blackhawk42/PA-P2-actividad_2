#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_streams(FILE *dst, FILE *src) {
    char c;
    while( (c = fgetc(src)) != EOF ){
        fputc(c, dst);
    }
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: 07.exe OUTPUT_FILE [INPUT_FILE..]\n");
        fprintf(stderr, "If no input file is given, stdin will be used\n");
        exit(0);
    }
    
    FILE *f_out = fopen(argv[1], "w");

    if (argc == 2) {
        copy_streams(f_out, stdin);
    }
    else {
        FILE *f_in;
        for(int i = 2; i < argc; i++) {
            f_in = fopen(argv[i], "r");
            
            copy_streams(f_out, f_in);

            fclose(f_in);
        }
    }

    fclose(f_out);

    return 0;
}
