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

/*
 * Complete the 'balancedSums' function below.
 * Returns "YES" if an index exists such that
 * the sum of elements on the left equals the sum on the right,
 * otherwise returns "NO".
 */
char* balancedSums(int n, int* arr) {
    long sumAll = 0;
    long leftSum = 0;

    for (int i = 0; i < n; i++) {
        sumAll += arr[i];
    }

    for (int i = 0; i < n; i++) {
        long rightSum = sumAll - leftSum - arr[i];
        if (leftSum == rightSum) {
            return "YES";
        }
        leftSum += arr[i];
    }

    return "NO";
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int T = parse_int(ltrim(rtrim(readline())));

    for (int t = 0; t < T; t++) {
        int size = parse_int(ltrim(rtrim(readline())));
        char** temp = split_string(rtrim(readline()));

        int* arr = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            arr[i] = parse_int(*(temp + i));
        }

        char* ans = balancedSums(size, arr);
        fprintf(fptr, "%s\n", ans);

        free(arr);
    }

    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_len = 1024;
    size_t len = 0;
    char* data = malloc(alloc_len);

    while (true) {
        char* cursor = data + len;
        char* line = fgets(cursor, alloc_len - len, stdin);
        if (!line) break;

        len += strlen(cursor);
        if (len < alloc_len - 1 || data[len - 1] == '\n') break;

        alloc_len <<= 1;
        data = realloc(data, alloc_len);
        if (!data) return NULL;
    }

    if (len > 0 && data[len - 1] == '\n') {
        data[len - 1] = '\0';
    } else {
        data[len] = '\0';
    }

    return data;
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
    char** tokens = NULL;
    char* token = strtok(str, " ");
    int count = 0;

    while (token) {
        tokens = realloc(tokens, sizeof(char*) * ++count);
        tokens[count - 1] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

int parse_int(char* str) {
    char* endptr;
    int val = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return val;
}