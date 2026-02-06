#include <stdio.h>
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    // Move top n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    // Move remaining disk to destination
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3; 
    printf("Steps for Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}
