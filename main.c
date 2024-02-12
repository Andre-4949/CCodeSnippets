#include <stdio.h>
#include "Filehandling/readFromFile.h"
#include "stdlib.h"
#include "string.h"
#include "stringHelper.h"

int main() {
    printf("%s", readLine("test.txt", 1));

    return 0;
}
