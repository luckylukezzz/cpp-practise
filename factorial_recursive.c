#include <stdio.h>

int factorial(int n) {
    if (n==0 || n==1){
        return 1;
    }
    return factorial(n-1)*n ;
}

int main() {
    int n;
    scanf("%d", &n);
    int x = factorial(n);
    printf("%d", x);

    return 0;
}