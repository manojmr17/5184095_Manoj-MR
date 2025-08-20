#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Utility: check if n is a power of two
int is_power_of_two(long n) {
    return (n > 0 && (n & (n - 1)) == 0);
}

// Utility: find the largest power of two <= n
long highestPowerOfTwo(long n) {
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);
    return n - (n >> 1);
}

// Required function
char* counterGame(long n) {
    static char winner[10];
    int playerTurn = 0; // 0 -> Richard, 1 -> Louise

    while (n > 1) {
        if (is_power_of_two(n)) {
            n >>= 1; // divide by 2
        } else {
            n -= highestPowerOfTwo(n);
        }
        playerTurn ^= 1; // switch turn
    }

    if (playerTurn == 1)
        strcpy(winner, "Louise");
    else
        strcpy(winner, "Richard");

    return winner;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long n;
        scanf("%ld", &n);
        printf("%s\n", counterGame(n));
    }

    return 0;
}