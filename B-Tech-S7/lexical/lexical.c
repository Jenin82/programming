#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
char keyword[20][10] = {"int", "char", "main", "for"};
char operator[20][3] = {"==", "++", "-", "+", "="};
char symbol[20][2] = {";", ",", ":", "(" ,")", "{", "}"};
char constant[20][3] = {"10", "1", "2"};

int j;

int key(char *text) {
    for(j=0;j<4;j++){
        if(strcmp(text,keyword[j]) == 0)
            return 1;
    }        
}

int op(char *text) {
    for(j=0;j<6;j++){
        if(strcmp(text,operator[j]) == 0)
            return 1;
    }        
}

int sym(char *text) {
    for(j=0;j<8;j++){
        if(strcmp(text,symbol[j]) == 0)
            return 1;
    }  
    char* s;
    s = (char*)malloc(20);
    strcpy(s, text);
    s[strlen(s)-1] = '\0';
    for(j=0;j<8;j++){
        if(strcmp(s,symbol[j]) == 0)
            return 2;
    }        
}

int con(char *text) {
    for(j=0;j<3;j++){
        if(strcmp(text,constant[j]) == 0)
            return 1;
    }        
}

int main()
{
    int i;
    FILE *fp;
    char line[MAX];

    fp = fopen("file.txt", "r");
    if (fp == NULL)
        return 1;

    while (fgets(line, MAX, fp))
    {
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            // printf(" %s\n", token);
            char a[4] = "int";
            if (i = (key(token)) == 1)
                printf("%s - keyword\n", token);
            else if (i = (op(token)) == 1)
                printf("%s - operator\n", token);
            else if (i = (con(token)) == 1)
                printf("%s - constant\n", token);
            else if (i = (sym(token)) == 1)
                printf("%s - symbol\n", token);
            else if (i = (sym(token)) == 2)
                printf("%s - symbol\n", token);
            else
                printf("%s - identifier\n", token);
            token = strtok(NULL, " ");
        }
    }
    fclose(fp);
}