#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int board[MAX], count = 0;
int n;


int isSafe(int k) {
    for(int i = 1; i < k; i++) {
        if(board[i] == board[k] || abs(board[i] - board[k]) == abs(i - k))
            return 0;
    }
    return 1;
}

void nQueen(int k) {
    for(int i = 1; i <= n; i++) {
        board[k] = i;
        if(isSafe(k)) {
            if(k == n) {
                count++;
                printf("\nSolution %d:\n", count);
                for(int i = 1; i <= n; i++)
                    printf("%d ", board[i]);
                printf("\n");
            }
            else {
                nQueen(k + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueen(1);

    if(count == 0)
        printf("No solution exists\n");

    return 0;
}