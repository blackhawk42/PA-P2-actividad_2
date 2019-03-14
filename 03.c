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

    fclose(f);

    // If the last char was not a newline, but neither was it an immediate EOF, count
    // it as a line
    if(last_char != EOF && last_char != '\n') {
        count++;
    }

    return count;
    
}

int line_length(FILE *f) {
    int count = 0;
    char c;

    long initial_position = ftell(f);

    while( (c = fgetc(f)) != EOF ){
        if (c == '\n') {
            break;
        }

        count++;
    }

    fseek(f, initial_position, SEEK_SET);

    return count;
}

char *store_line(FILE *f, int line_size) {
    char *destination = (char *)malloc( (sizeof(char)*line_size) + 1 );
    if (destination == NULL) {
        return NULL;
    }

    char c;
    int i = 0;

    long initial_position = ftell(f);

    while( (c = fgetc(f)) != EOF ){
        if (c == '\n') {
            break;
        }

        destination[i] = c;
        i++;
    }

    fseek(f, initial_position, SEEK_SET);

    destination[i] = '\0';

    return destination;
}

void print_array_of_lines(char **array, int lines) {
    printf("{\n");
    for(int i = 0; i < lines; i++) {
        printf("\t\"%s\"\n", array[i]);
    }
    printf("}\n");
}

void destroy_array_of_lines(char **array, int lines) {
    for(int i = 0; i < lines; i++) {
        free(array[i]);
    }

    free(array);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter at least one file as a command line argument\n");
        exit(0);
    }

    int lines;
    int line_size;

    for(int i = 1; i < argc; i++) {
        lines = count_lines((char *)argv[i]);
        
        char **array_of_lines = (char **)malloc( sizeof(char *)*lines );

        FILE *f = fopen(argv[i], "r");

        for(int j = 0; j < lines; j++) {
            line_size = line_length(f);
            array_of_lines[j] = store_line(f, line_size);
            fseek(f, line_size+1, SEEK_CUR);
        }

        fclose(f);

        print_array_of_lines(array_of_lines, lines);
        destroy_array_of_lines(array_of_lines, lines);
    }
    return 0;
}
