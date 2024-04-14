#include <ctype.h>
#include "libconvert.h"

void to_uppercase(char *text) {
    while (*text) {
        *text = toupper(*text);
	text++;
    }
}

void to_lowercase(char *text) {
    while (*text) {
        *text = tolower(*text);
	text++;
    }
}
