#include <stdio.h>

long long int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    long long int a = 0; 
    long long int b = 1;
    long long int next_term;

    for (int i = 2; i <= n; i++) {
        next_term = a + b; 
        a = b;             
        b = next_term;     
    }

   
    return b;
}

int main() {
    int n;

    printf("Enter the nth term number (n >= 0): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    long long int result = fibonacci_iterative(n);
    printf("The %dth Fibonacci term is: %lld\n", n, result);

    return 0;
}
