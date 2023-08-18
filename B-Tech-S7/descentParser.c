#include<stdio.h>
#include <ctype.h>

// Production rule
// E -> TE'
// E' -> +TE'|3
// T -> FT'
// T' -> *FT'|3
// F -> BF'
// F' -> /BF'|3
// B -> (E)|id

char input[100];
int i=0,error=0;

void E();
void EPrime();
void T();
void TPrime();
void F();
void FPrime();
void B();

void E() {
    T();
    EPrime();
}

void EPrime() {
    if(input[i] == '+' | input[i] == '-'){
        i++;
        T();
        EPrime();
    }
}

void T() {
    F();
    TPrime();
}

void TPrime(){
    if(input[i] == '*'){
        i++;
        F();
        TPrime();
    }
}

void FPrime(){
    if(input[i] == '/'){
        i++;
        B();
        FPrime();
    }
}

void F() {
    B();
    FPrime();
}

void B() {
    if(isalnum(input[i])){
        i++;
    }
    else if(input[i] == '(') {
        i++;
        E();
        if(input[i] == ')') {
            i++;
        }
        else{
            error++;
        }
    }
    else {
        error++;
    }
}

void main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    E();
    if(error == 0)
        printf("Approved...");
    else
        printf("Rejected...");
}