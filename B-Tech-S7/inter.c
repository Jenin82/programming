#include <stdio.h>
#include <string.h>

int i = 0, j = 0, k, t = 1;
char str[50], final[10], temp1[5], temp2[5], operator;

void main()
{
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
    operator= str[k];
    k++;
    i = 0;
    while (str[k] != '\0' && str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/')
    {
        temp2[i] = str[k];
        i++;
        k++;
    }
    printf("t1 = %s %c %s\n", temp1, operator, temp2);

    while (str[k] != '\0')
    {
        for (j = 0; j < 10; j++)
        {
            temp2[j] = '\0';
        }
        operator= str[k];
        k++;
        i = 0;
        while (str[k] != '\0' && str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/')
        {
            temp2[i] = str[k];
            i++;
            k++;
        }
        printf("t%d = t%d %c %s\n", t + 1, t, operator, temp2);
        t++;
    }
}