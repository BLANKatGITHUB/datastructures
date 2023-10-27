#include<stdlib.h>
#include<stdio.h>

int fact();

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d",fact(n));
}

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}