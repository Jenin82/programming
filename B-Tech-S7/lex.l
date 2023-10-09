%{
#include<stdio.h>
%}
keyword int|void|while|do|for
id ([a-zA-Z])([a-zA-Z0-9])*
rop <|<=|>=|==
pun [;,{}()]
con ([0-9])([0-9])*
aop [+]
aop1 [-]
aop2 [*]
aop3 [/]
assign =
%%
{keyword} {printf("%s is a keyword \n",yytext);}
{id} {printf("%s is a identifier \n",yytext);}
{rop} {printf("%s is a relational operator \n",yytext);}
{pun} {printf("%s is a punctuation \n",yytext);}
{con} {printf("%s is a constant \n",yytext);}
{aop} {printf("%s is a arithmetic operator \n",yytext);}
{aop1} {printf("%s is a arithmetic operator \n",yytext);}
{aop2} {printf("%s is a arithmetic operator \n",yytext);}
{aop3} {printf("%s is a arithmetic operator \n",yytext);}
{assign} {printf("%s is a assignment operator \n",yytext);}
%%
int yywrap(void){}
int main()
{
printf("Enter a string");
yylex();
return 1;
}
