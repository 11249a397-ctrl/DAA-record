 #include <stdio.h>
long long int factorial(int n);

int main() {
    int num;
   
    long long int result;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\\n");
    } else {
        result = factorial(num);
        printf("Factorial of %d is %lld\\n", num, result);
    }

    return 0;
}

long long int factorial(int n) {
   
    if (n == 0 || n == 1) {
        return 1;
    }
  
    else {
        return n * factorial(n - 1);
    }
}
