#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
  FILE *f1,*f2,*f3,*f4;
  int flag,flag1,locctr,location,loc;
  char symbol[10],add[10],opcode[10],obj[10],code[10],character,label[10],mne[10],operand[20];
  f1=fopen("out.txt","r");
  f2=fopen("output.txt","w");
  f3=fopen("optab.txt","r");
  f4=fopen("symtab.txt","r");
  fscanf(f1,"%s%s",opcode,operand);
  if(strcmp(opcode,"START")==0) {
    fprintf(f2,"%s %s",opcode,operand);
    fscanf(f1,"%d%s%s",&locctr,opcode,operand);
  }
  while(strcmp(opcode,"END")!=0) {
    flag=0;
    fscanf(f3,"%s%s",code,mne);
    while(strcmp(code,"END")!=0) {
      if(strcmp(opcode,code)==0) {
        flag=1;
        break;
      }
      fscanf(f3,"%s%s",code,mne);
    }
    if(flag==1) {
      flag1=0;
      rewind(f4);
      while(!feof(f4)){
        fscanf(f4,"%d%s",&loc,symbol);
        if(strcmp(symbol,operand)==0){
          flag1=1;
          break;
        }
      }
      if(flag1==1) {
        sprintf(add,"%d",loc);
        strcpy(obj,strcat(mne,add));
      }
    }
    else if(strcmp(opcode,"BYTE")==0||strcmp(opcode,"WORD")==0){
      if((operand[0]=='C') || (operand[0]=='X')) {
        character=operand[2];
        sprintf(add,"%d",character);
        strcpy(obj,add);
      }
      else {
        strcpy(obj,add);
      }
    }
    else
      strcpy(obj,"\0");
    fprintf(f2,"\n%s %s %d %s",opcode,operand,locctr,obj);
    fscanf(f1,"%d%s%s",&locctr,opcode,operand);
  }
  fprintf(f2,"\n%s %s %d",opcode,operand,locctr);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
}

