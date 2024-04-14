#include <stdio.h>
#include <stdlib.h>
#include "libconvert.h"

int main() {
    char text[100];
    printf("Enter text to convert to uppercase: ");
    fgets(text, sizeof(text), stdin);
    to_uppercase(text);
    printf("Uppercase: %s\n", text);
    return 0;
}
