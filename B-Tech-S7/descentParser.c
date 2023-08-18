#include<stdio.h>

char input[100];

void main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    int result = parseExpression();
    printf("Result: %d\n", result);
}