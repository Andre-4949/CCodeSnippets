//
// Created by andre on 06.02.2024.
//

#include "readFromFile.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "../stringHelper.h"

char *readFile(char *filename) {
    FILE *file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err) {
        printf("%s", strerror(err));
        exit(0);
    }
    fseek(file, 0, SEEK_END);
    long lSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *readBuffer = calloc(lSize + 1, 1);

    char c;
    int index = 0;
    while (1) {
        c = fgetc(file);
        if (c == EOF) {
            break;
        }
        readBuffer[index++] = c;
    }
    fclose(file);
    return readBuffer;
}

char *readLine(char *filename, int linecount) {
    FILE *file1 = fopen(filename, "r");
    fseek(file1, 0, SEEK_SET); //file cursor auf index 0
    long lSize = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    char *content = calloc(lSize + 1, 1);
    fclose(file1);
    char *contentFull = readFile(filename);
    do {
        sscanf(contentFull, "%[^\n]*", content);
        contentFull += strlen(content) + 1;
        linecount--;
    } while (linecount > 0);
//    free(tmp);
    return content;

}