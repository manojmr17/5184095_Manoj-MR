#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

// helper: compute digit sum of a number
int sumOfDigits(long long val) {
    int total = 0;
    while (val > 0) {
        total += (int)(val % 10);
        val /= 10;
    }
    return total;
}

/*
 * The function returns the "super digit"
 * for a given number string n repeated k times.
 */
int superDigit(char* n, int k) {
    long long initialSum = 0;

    // sum digits of string n
    for (int idx = 0; n[idx] != '\0'; idx++) {
        initialSum += (n[idx] - '0');
    }

    // multiply by k (since string is repeated k times)
    initialSum *= k;

    // reduce until single digit
    while (initialSum >= 10) {
        initialSum = sumOfDigits(initialSum);
    }

    return (int)initialSum;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** tokens = split_string(rtrim(readline()));

    char* n = tokens[0];
    int k = parse_int(tokens[1]);

    int ans = superDigit(n, k);
    fprintf(fptr, "%d\n", ans);

    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_len = 1024;
    size_t data_len = 0;
    char* buf = malloc(alloc_len);

    while (true) {
        char* cursor = buf + data_len;
        char* line = fgets(cursor, alloc_len - data_len, stdin);
        if (!line) break;

        data_len += strlen(cursor);
        if (data_len < alloc_len - 1 || buf[data_len - 1] == '\n') break;

        alloc_len <<= 1;
        buf = realloc(buf, alloc_len);
        if (!buf) return NULL;
    }

    if (data_len > 0 && buf[data_len - 1] == '\n') {
        buf[data_len - 1] = '\0';
    } else {
        buf[data_len] = '\0';
    }
    return buf;
}

char* ltrim(char* str) {
    if (!str) return NULL;
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return NULL;
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** result = NULL;
    char* token = strtok(str, " ");
    int count = 0;

    while (token) {
        result = realloc(result, sizeof(char*) * ++count);
        result[count - 1] = token;
        token = strtok(NULL, " ");
    }
    return result;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
