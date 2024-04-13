#include <stdio.h>
#include "header.h"

int main() {
    int firstNumber;
    int secondNumber;
    char operation;


    printf("Type first number: \n");
    scanf("%d", &firstNumber);

    printf("Type second number: \n");
    scanf("%d", &secondNumber);
    
    printf("Choice posible operation [+, -, *, /]: \n");
    scanf(" %c", &operation);
    
    int res;

    switch (operation) {
        case '+':
	    res = plus(firstNumber, secondNumber);
	    break;
	case '-':
	    res = minus(firstNumber, secondNumber);
	    break;
	case '*':
	    res = multiply(firstNumber, secondNumber);
	    break;
	case '/':
	    res = divide(firstNumber, secondNumber);
	    break;
	default:
	    printf("Operation %c not found", operation);
	    return -1;
	}
	    
    printf("Result of operation %c is %d \n", operation, res);
    return 0;
}
