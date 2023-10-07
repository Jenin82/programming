%{
    int v=0,c=0;
%}

%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%

void main() {
    printf("enter the string:\n");
    yylex();
    printf("Vowels: %d\n",v);
    printf("Consonents: %d\n",c);
}

int yywrap() {
    return 1;
}