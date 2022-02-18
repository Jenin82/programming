#include<stdio.h>
#include<string.h>

char stack[50],infix[50],postfix[50];
int top=-1,i=-1,j=-1;

void infixtopostfix(char x);
int priority(char x);
void push(char x);
void pushtopostfix(char x);
int pop();

void main()
{
	char x;
	printf("Enter the infix expression\n");
	gets(infix);
	for(i=0;infix[i] != '\0';i++)
	{
		x=infix[i];
		switch(x)
		{
			case '+': infixtopostfix(x);
			break;
			case '-': infixtopostfix(x);
			break;
			case '*': infixtopostfix(x);
			break;
			case '/': infixtopostfix(x);
			break;
			case '^': infixtopostfix(x);
			break;
			case '(': push(x);
			break;
			case ')': infixtopostfix(x);
			break;
			default : pushtopostfix(x);
			break;
		}
	}
	puts(postfix);
}

//Functions

void infixtopostfix(char x)
{
	int a = priority(x);
	int b = priority(stack[top]);
	if(a>b)
	{
		top++;
		stack[top] = a;
	}
	else
	{
		j++;
		postfix[j] = pop();
		top++;
		stack[top] = a;
	}
}

void push(char x)
{
	top++;
	stack[top] = x;
}

void pushtopostfix(char x)
{
	j++;
	postfix[j] = x;
	puts(x);
}

int pop()
{
	top--;
	return stack[top+1];
}

int priority(char x)
{
	if(x=='+')
		return 1;
	else if(x=='-')
		return 1;
	else if(x=='*')
		return 2;
	else if(x=='/')
		return 2;
	else if(x=='^')
		return 3;
	else
		return 0;
}