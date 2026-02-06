#include <stdio.h>


int fibonacci(int n) {
 
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main() {
    int n, result;


    printf("Enter the nth number in the Fibonacci series: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci of a negative number is not possible.\\n");
    } else {
        
        result = fibonacci(n);
        printf("The %dth number in the Fibonacci series is %d\\n", n, result);
    }

    return 0;
}
