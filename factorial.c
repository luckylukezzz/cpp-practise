#include <stdio.h>

int factorial(int n) {
    int sum = 1;
    for(int i = 2 ; i<= n ; i++){
        sum *= i;   
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int x = factorial(n);
    printf("%d", x);
    return 0;
}
