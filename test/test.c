#include <stdio.h>

int q[100],n,f=-1,r=-1,item;

void enqueue(){
	if(f==0&&r=n-1 || r+1==f){
		printf("Overflow\n");
	}
	else if(f==-1&&r==-1){
		f=r=0;
		q[r] = item;
	}
	else if(r==n-1){
		r=0;
		q[r]=item;
	}
	else {
		r=r+1;
		q[r]= item;
	}
}

void dequeue(){
	if(f==-1 && r==-1){
		printf("Underflow");
	}
	else if(f==r){
		f=r=-1;
	}
	else if(f==n-1){
		f=0;
	}
	else {
		f=f+1;
	}
}

void enqueuef(){
	if(f==0 && r=n-1 || r+1==f){
		printf("Overflow\n");
	}
	else if(f==-1 && r==-1){
		f=r=0;
		q[r] = item;
	}
	else if(f==0){
		f=n-1;
		q[f]=item;
	}
	else {
		f=f-1;
		q[f]=item;
	}
}

void deleter(){
	if(f==-1 && r==-1){
		printf("Underflow");
	}
	else if(f==r){
		f=r=-1;
	}
	else if(r==0){
		r=n-1;
	}
	else {
		r--;
	}
}