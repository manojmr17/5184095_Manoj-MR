#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* read_line();
int to_int(char*);
char** split_tokens(char*);

int* icecreamParlor(int money, int arr_size, int* costs, int* result_size) {
    *result_size = 2;
    int *ans = malloc(2 * sizeof(int));

    for (int p = 0; p < arr_size; p++) {
        for (int q = p + 1; q < arr_size; q++) {
            if (costs[p] + costs[q] == money) {
                ans[0] = p + 1;   
                ans[1] = q + 1;
                return ans;
            }
        }
    }

    ans[0] = ans[1] = -1;
    return ans;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int t = to_int(read_line());

    for (int tc = 0; tc < t; tc++) {
        int m = to_int(read_line());
        int n = to_int(read_line());

        char** tokens = split_tokens(read_line());
        int* arr = malloc(n * sizeof(int));

        for (int k = 0; k < n; k++) {
            arr[k] = to_int(tokens[k]);
        }

        int res_size;
        int* res = icecreamParlor(m, n, arr, &res_size);

        for (int idx = 0; idx < res_size; idx++) {
            fprintf(fptr, "%d", res[idx]);
            if (idx < res_size - 1) fprintf(fptr, " ");
        }
        fprintf(fptr, "\n");

        free(arr);
        free(res);
        free(tokens);
    }

    fclose(fptr);
    return 0;
}

char* read_line() {
    size_t cap = 1024, len = 0;
    char* buf = malloc(cap);
    if (!buf) exit(1);

    while (fgets(buf + len, cap - len, stdin)) {
        len += strlen(buf + len);
        if (len == 0 || buf[len - 1] == '\n') break;
        cap *= 2;
        buf = realloc(buf, cap);
        if (!buf) exit(1);
    }

    if (len && buf[len - 1] == '\n') buf[len - 1] = '\0';
    return buf;
}

int to_int(char* s) {
    return (int)strtol(s, NULL, 10);
}

char** split_tokens(char* line) {
    char** arr = NULL;
    int count = 0;
    char* tok = strtok(line, " ");
    while (tok) {
        arr = realloc(arr, sizeof(char*) * (count + 1));
        arr[count++] = tok;
        tok = strtok(NULL, " ");
    }
    return arr;
}
