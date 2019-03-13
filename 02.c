#include <stdio.h>
#include <stdlib.h>

int count_char_in_file(char *filepath, char c) {
    FILE *f = fopen(filepath, "r");
    if (f == NULL) {
        return -1;
    }

    int counter = 0;
    int current_c;

    while( (current_c = fgetc(f)) != EOF ){
        if (current_c == c) {
            counter++;
        }
    }

    fclose(f);

    return counter;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter at least one file as a command line argument\n");
        exit(0);
    }

    char c;
    int count;

    printf("Give me a character: ");
    scanf("%c", &c);
    fflush(stdin);

    for(int i = 1; i < argc; i++) {
        count = count_char_in_file((char *)argv[i], c);
        if (count < 0) {
            fprintf(stderr, "error: %s\n", count, argv[i]);
            continue;
        }

        printf("%d %s\n", count, argv[i]);
    }

    return 0;
}
