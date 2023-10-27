#include<stdio.h>
#include<stdlib.h>

int fabocci(int n);

int main(){
    int n;
    printf("Enter the term: ");
    scanf("%d", &n);
    printf("%d", fabocci(n));
}

int fabocci(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fabocci(n-1)+fabocci(n-2);
    }
}