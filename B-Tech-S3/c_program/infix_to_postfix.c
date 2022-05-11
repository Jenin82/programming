#include<stdio.h>
#include<string.h>

char stack[20],postfix[20];
int j=-1,top=0;

void pushtopostfix(char x);
void infixtopostfix(char x);
int priority(char x);

int main()
{
	int i=0;
	char a[20],x;
	printf("Enter the infix expression :\n");
	gets(a);
	stack[top] = '(';
	while(a[i] != '\0')
	{
		x=a[i];
		switch (x)
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
			case '(': {
				top++;
				stack[top] = '(';
			}
			break;
			case ')': {
				while(stack[top] != '(')
				{
					j++;
					postfix[j] = stack[top];
					top--;
				}
				top--;
			}
			break;
			default : pushtopostfix(x);
			break;
		}
		i++;
	}
	while(stack[top] != '(')
	{
		j++;
		postfix[j] = stack[top];
		top--;
	}
	top--;
	printf("Postfix expression is :\n");
	puts(postfix);
	return 0;
}

//Functions

void pushtopostfix(char x)
{
	j++;
	postfix[j] = x;
}

void infixtopostfix(char x)
{
	int a,b;
	a = priority(x);
	b = priority(stack[top]);
	if(a>b)
	{
		top++;
		stack[top] = x;
	}
	else 
	{
		j++;
		postfix[j] = stack[top];
		stack[top] = x;
	}
}

int priority(char x)
{
	if(x == '+')
		return 1;
	else if(x == '-')
		return 1;
	else if(x == '*')
		return 2;
	else if(x == '/')
		return 2;
	else if(x == '^')
		return 3;
	else 
		return 0;
}