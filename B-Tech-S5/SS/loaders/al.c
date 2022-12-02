#include<stdio.h>
#include<string.h>
void main() {
	char input[10];
	int start,length,address;
	FILE *f1,*f2;
	f1=fopen("inabl.txt","r");
	f2=fopen("outabl.txt","w");
	fscanf(f1,"%s",input);
	while(strcmp(input,"E")!=0) {
		if(strcmp(input,"H")==0) 
			fscanf(f1,"%d%d%s",&start,&length,input);
		else if(strcmp(input,"T")==0) {
			fscanf(f1,"%d%s",&address,input);
			fprintf(f2,"%d %c%c\n",address,input[0],input[1]);
			fprintf(f2,"%d %c%c\n",(address+1),input[2],input[3]);
			fprintf(f2,"%d %c%c\n",(address+2),input[4],input[5]);
			address=address+3;
			fscanf(f1,"%s",input);
		}
		else {
			fprintf(f2,"%d %c%c\n",address,input[0],input[1]);
			fprintf(f2,"%d %c%c\n",(address+1),input[2],input[3]);
			fprintf(f2,"%d %c%c\n",(address+2),input[4],input[5]);
			address=address+3;
			fscanf(f1,"%s",input);
		}
	}
	fclose(f1);
	fclose(f2);
}