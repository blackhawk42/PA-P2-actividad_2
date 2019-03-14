#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

typedef struct {
    int words;
    int chars;
} WcReport_s, *WcReport;


WcReport pseudo_wc(char *path) {
    WcReport report = (WcReport)malloc(sizeof(WcReport_s));
    report->chars = 0;
    report->words = 0;

    FILE *f = fopen(path, "r");
    if (f == NULL) {
        return NULL;
    }

    char c;
    char last_char = EOF;

    while( (c = fgetc(f)) != EOF ){
        report->chars++;

        if (isspace(c) && !isspace(last_char)) {
            report->words++;
        }

        //printf("c = %c, isspace = %d, lastchar = %c, !isspace = %d\n", c, isspace(c), last_char, !isspace(last_char));

        last_char = c;

    }

    if (report->chars > 0 && !isspace(last_char)) {
        report->words++;
    }

    fclose(f);

    return report;
    
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Please enter at least one file as a command line argument\n");
        exit(0);
    }

    WcReport report;

    for(int i = 1; i < argc; i++) {
        report = pseudo_wc((char *)argv[i]);
        if (report == NULL) {
            fprintf(stderr, "error: %s\n", argv[i]);
            continue;
        }

        printf("%d %d %s\n", report->words, report->chars, argv[i]);
    }

    return 0;
}