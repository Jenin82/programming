#include <stdio.h>
#include <string.h>

int i = 0, j = 0, k = 0, t = 1;
char str[50], final[10], temp1[5], temp2[5], operator;
char stack[50]; // Stack to handle operator precedence and parentheses
int top = -1;

void push(char op) {
    top++;
    stack[top] = op;
}

char pop() {
    if (top == -1) return '\0'; // Empty stack
    char op = stack[top];
    top--;
    return op;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // for '('
}

void generateIntermediateCode(char op) {
    char op2 = pop();
    char op1 = pop();
    printf("t%d = t%d %c t%d\n", t, t - 1, op2, t - 2);
    t++;
    push(op);
}

int main() {
    puts("Enter the string");
    gets(str);
    while (str[i] != '\0' && str[i] != '=')
    {
        final[i] = str[i];
        i++;
    }
    k = i + 1;
    i = 0;
    while (str[k] != '\0' && str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/')
    {
        temp1[i] = str[k];
        i++;
        k++;
    }
    push('='); // Push '=' onto the stack to ensure proper precedence handling
    operator = str[k];
    k++;
    i = 0;
    while (str[k] != '\0')
    {
        for (j = 0; j < 10; j++)
        {
            temp2[j] = '\0';
        }
        if (str[k] == '(')
        {
            push('('); // Push '(' onto the stack
            k++;
        }
        else if (str[k] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                generateIntermediateCode(pop());
            }
            if (top == -1) {
                printf("Invalid expression: Mismatched parentheses\n");
                break; // Terminate the loop
            }
            pop(); // Pop '(' from the stack
            k++;
        }
        else if (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/')
        {
            while (top != -1 && precedence(stack[top]) >= precedence(str[k]))
            {
                generateIntermediateCode(pop());
            }
            push(str[k]);
            k++;
        }
        else
        {
            i = 0;
            while (str[k] != '\0' && str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/' && str[k] != ')')
            {
                temp2[i] = str[k];
                i++;
                k++;
            }
            printf("t%d = %s\n", t, temp2);
            t++;
        }
    }
    while (top != -1)
    {
        if (stack[top] == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            break;
        }
        generateIntermediateCode(pop());
    }
    return 0;
}