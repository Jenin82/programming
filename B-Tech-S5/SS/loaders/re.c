#include<stdio.h>
#include<string.h>
int main() {
	char add[6],length[10],input[10],bitmask[10],relocbit;
	int start,len,i,address,opcode,addr,actualadd;
	FILE *f1,*f2;
	printf("Enter the actual starting address :");
	scanf("%d",&start);
	f1=fopen("reinput.txt","r");
	f2=fopen("reoutput.txt","w");
	fscanf(f1,"%s",input);
	while(strcmp(input,"E")!=0) {
		if(strcmp(input,"H")==0)
			fscanf(f1,"%s%s%s",add,length,input);
		if(strcmp(input,"T")==0) {
			fscanf(f1,"%d%s",&address,bitmask);
			address=address+start;
			len=strlen(bitmask);
			for(i=0;i<len;i++) {
				fscanf(f1,"%d%d",&opcode,&addr);
				relocbit=bitmask[i];
				if(relocbit=='0')
					actualadd=addr;
				else
					actualadd=addr+start;
				fprintf(f2,"%d %d%d\n",address,opcode,actualadd);
				address=address+3;
			}
			fscanf(f1,"%s",input);
		}
	}
	fclose(f1);
	fclose(f2);
}