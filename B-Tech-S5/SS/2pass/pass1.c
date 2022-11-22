#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char label[30],opcode[30],operand[30],opcode1[30],operand1[30];
int locctr,x;
void main() {
  FILE *f1,*f2,*f3,*f4;
  f1=fopen("input.txt","r");
  f2=fopen("optab.txt","r");
  f3=fopen("symtab.txt","w");
  f4=fopen("out.txt","w");
  void function() {
    fprintf(f4,"%d %s %s\n",locctr,opcode,operand);
    fprintf(f3,"%d %s\n",locctr,label);
  }
  while(fscanf(f1,"%s%s%s",label,opcode,operand)!=EOF) {
    if(strcmp(label,"**")==0) {
      if(strcmp(opcode,"START")==0) {
        fprintf(f4,"%s %s\n",opcode,operand);
        locctr=atoi(operand);
      }
      else {  
        rewind(f2);
        x=0;
        while(fscanf(f2,"%s%s",opcode1,operand1)!=EOF) 
          if(strcmp(opcode,opcode1)==0)
            x=1;
        if(x==1){
          fprintf(f4,"%d %s %s\n",locctr,opcode,operand);
          locctr+=3;
        }
      }
    }
    else {
      if(strcmp(opcode,"RESW")==0) {
        function();
        locctr+=3*(atoi(operand));
      }
      else if(strcmp(opcode,"RESB")==0) {
        function();
        locctr+=(atoi(operand));
      }
      else if(strcmp(opcode,"WORD")==0) {
        function();
        locctr+=3;
      }
      else if(strcmp(opcode,"BYTE")==0) {
        function();
        locctr+=1;
      }
      else {
        function();
        locctr+=3;
      }
    }
  }
}
