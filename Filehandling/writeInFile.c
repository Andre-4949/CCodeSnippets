//
// Created by andre on 06.02.2024.
//

#include "writeInFile.h"

#include "stdlib.h"
#include "stdio.h"
#include "memory.h"
#include "inttypes.h"
#include "string.h"

char *writeWholeFile(char *filename, char *input) {
    FILE *file1 = fopen(filename, "w+");
    fprintf(file1, input);
    fflush(file1);
    fclose(file1);
}

char *addLineToFile(char *filename, char *input) {
    FILE *file1 = fopen(filename, "a");
    fprintf(file1, input);
//    fprintf(file1, "\n");
    fflush(file1);
    fclose(file1);
}

