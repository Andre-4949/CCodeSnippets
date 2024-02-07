//
// Created by andre on 06.02.2024.
//

#include "readFromFile.h"

#include "stdlib.h"
#include "stdio.h"
#include "memory.h"
#include "inttypes.h"
#include "string.h"

void switchCases(char *in);

char* readFile(char* filename){
    FILE *file1 = fopen(filename, "r+");
    fseek(file1, 0, SEEK_SET); //file cursor auf index 0
    long lSize = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    char *readBuffer = calloc(lSize + 1, 1);

    char c;
    int index = 0;
    while (1) {
        char s[100];
        fscanf_s(file1, "%[^\n]*", &s);
        printf("%s", s);
        fclose(file1);
        c = fgetc(file1);
        if (c == EOF) {
            break;
        }
        readBuffer[index++] = c;
    }
    fclose(file1);
    return readBuffer;
}

char* readLine(char* filename, int linecount){
    FILE *file1 = fopen(filename, "r+");
    fseek(file1, 0, SEEK_SET); //file cursor auf index 0
    long lSize = ftell(file1);
    fseek(file1, 0, SEEK_SET);
    char *content = calloc(lSize + 1, 1);

    fscanf_s(file1, "%[^\n]*", &content);
    printf("%s", content);
    fclose(file1);
    return content;
}