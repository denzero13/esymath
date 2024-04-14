#include <stdio.h>
#include <stdlib.h>
#include "libconvert.h"

int main() {
    char text[100];
    printf("Enter text to convert to lowercase: ");
    fgets(text, sizeof(text), stdin);
    to_lowercase(text);
    printf("Lowercase: %s\n", text);
    return 0;
}
