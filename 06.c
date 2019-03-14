#include <stdio.h>
#include <stdlib.h>

void print_usage() {
    fprintf(stderr, "use: 06.exe INPUT_FILE OUTPUT_FILE [INPUT_FILE OUTPUT_FILE ...]\n\n");
    fprintf(stderr, "Command line arguments are in pairs: an input filename followed by its output filename.\n\n");
    fprintf(stderr, "The line to delete will be asked at execution time. If the file has fewer lines than the one given, the file will be written unchanged to the output.\n");
}

void delete_line(FILE *dst, FILE *src, int line) {
    int current_line = 1;
    char c;

    while( (c = fgetc(src)) != EOF ) {
        if (current_line != line) {
            fprintf(dst, "%c", c);
        }

        if (c == '\n') {
            current_line++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        exit(0);
    }

    if ( (argc-1) % 2 != 0) {
        fprintf(stderr, "error: odd number of command line arguments given\n");
        print_usage();
        exit(2);
    }

    int line;
    printf("Give me a line to delete: ");
    scanf("%d", &line);
    fflush(stdin);

    if (line < 1) {
        fprintf(stderr, "Line number should be 1 or greater");
        exit(1);
    }

    FILE *input;
    FILE *output;

    for(int i = 1; i < argc; i += 2) {
        input = fopen(argv[i], "r");
        if (input == NULL) {
            fprintf(stderr, "error while opening for reading: %s\n", argv[i]);
            continue;
        }

        output = fopen(argv[i+1], "w");
        if (output == NULL) {
            fprintf(stderr, "error while opening for writing: %s\n", argv[i+1]);
            fclose(input);
            continue;
        }

        delete_line(output, input, line);

        fclose(input);
        fclose(output);
    }

    return 0;
}
