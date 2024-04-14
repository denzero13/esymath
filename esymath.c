#include <stdio.h>
#include "libcalc.h"

int main() {
    int firstNumber;
    int secondNumber;
    char operation;
    int res;

    printf("Choice posible operation [+, -, *, /, f, s]: \n");
    scanf(" %c", &operation);
    
    printf("Type first number: \n");
    if (scanf("%d", &firstNumber) != 1) {
        printf("First number must be integer\n");
	return -1;
    }

    if (operation != 'f' && operation != 's') {
        printf("Type second number: \n");
        
	if (scanf("%d", &secondNumber) != 1) {
            printf("Second number must by integer\n");
	    return -1;
        }    
    }

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
	    if (secondNumber == 0) {
                printf("Error: Cannot divide by zero.\n");
		return -1;
	    }
	    res = divide(firstNumber, secondNumber);
	    break;
	case 'f':
	    res = factorial(firstNumber);
	    break;    
	case 's':
	    res = square_root(firstNumber);
            break;   
	default:
	    printf("Operation %c not found \n", operation);
	    return -1;
	}
	    
    printf("Result of operation %c is %d \n", operation, res);
    return 0;
}
