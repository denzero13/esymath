#include "header.h"
#include <stdio.h>

int plus(int num1, int num2) {
    return num1 + num2;
}

int minus(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    
    if (num2 == 0) {
        printf("Error: Cannot divide by zero.\n");
	return -1; // Indicate an error
    }

    return num1 / num2;
}
