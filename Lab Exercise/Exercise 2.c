#include<stdio.h>
int div(int divisor, int dividend);
int relativePrime(int A, int B);
int search(int x, int arr[x], int i, int N);
int main(){
    printf("Choice input 1: Division without multiplication, division and modulo\n");
    printf("Choice input 2: Relative Prime Check\n");
    printf("Choice input 3: Search Integer\n");
    int choice;
    printf("Input choice of operation: ");
    scanf("%i", &choice);

    if(choice==1){
        int divisor, dividend, quotient;
                printf("Enter divisor and dividend: ");
                scanf("%i %i", &divisor, &dividend);

                quotient = div(divisor, dividend);
                printf("Output: %i\n", quotient);
    }
    if(choice==2){
        int A,B,ans;
                printf("Enter value for integer A and B: ");
                scanf("%i %i", &A, &B);
                ans = relativePrime(A,B);

                if(ans==1)
                    printf("Output: 1\n");
                else 
                    printf("Output: 0\n");
    }
    if(choice==3){
        int x=0, i, N;
            printf("Enter size of array: ");
            scanf("%i", &x);
            int arr[x];
            for(i=0; i<x; i++){
                printf("Enter value for pos %i: ", i+1);
                scanf("%i", &arr[i]);
                if(i == x-1){
                    printf("Enter value of N: ");
                    scanf("%i", &N); 
                }
            }
        search(x, arr, 0, N);
    }   
}

// Function Recursion for Division
int div(int divisor, int dividend){
    if(divisor==dividend)
        return 1;
    else if(divisor-dividend <= 0)
        return 0;
    else
        return 1 + div(divisor-dividend, dividend);
}

// Function Recursion for Checking Relative Prime Integers
int relativePrime(int A, int B){
    if(B != 0)
        return relativePrime(B, A%B);
    else 
        return A;
}

//Function Recursion for Search Algorithm
int search(int x, int arr[x], int i, int N){
    if(i>x)
        return printf("Output: 0");
    if(arr[i] == N)
        return printf("Output: 1");
    search(x, arr, i+1, N);
}

