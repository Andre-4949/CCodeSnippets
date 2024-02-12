//
// Created by andre on 07.02.2024.
//

#include "stringHelper.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int amountOfSplits(char *i_, char splitIndicator) {
    int countOfSplitChar = 0;
    for (int i = 0; i < strlen(i_); ++i) {
        if (i_[i] == splitIndicator && (i == 0 || i == strlen(i_) - 1)) {
            countOfSplitChar--;
        }
        countOfSplitChar += i_[i] == splitIndicator;
    }
    return countOfSplitChar >= 0 ? countOfSplitChar : 0;
}

char **splitString(char *i_, char splitIndicator) {
    char *input = calloc(strlen(i_) + 1, 1);
    memcpy(input, i_, strlen(i_));
    char *content = calloc(strlen(i_) + 1, 1);
    int countOfSplitChar = amountOfSplits(input, splitIndicator);

    char **out = calloc(countOfSplitChar + 1, 1);
    for (int i = 0; i < countOfSplitChar + 1; ++i) {
        out[i] = NULL;
    }
    char regexSplit[10] = {0};
    sprintf(regexSplit, "%%[^(%c)]*", splitIndicator);
    int indexOut = 0;
    int chars = 0;
    int contentLen = 0;
    do {
        sscanf(input, regexSplit, content);
        contentLen = strlen(content);
        input += contentLen + 1;
        chars += contentLen + 1;
        if (chars != 1) {
            out[indexOut] = calloc(contentLen + 1, 1);
            memcpy(out[indexOut], content, contentLen);
            indexOut++;
        }
    } while (chars < strlen(i_));
//    free(content);
    return out;
}