#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct Node {
    int kind;           
    char *value;        
    struct Node *prev;
} Node;

char text[MAX_SIZE + 1] = "";   
int textLen = 0;                
Node* stackHead = NULL;

void push(int kind, const char *val) {
    Node* elem = (Node*)malloc(sizeof(Node));
    elem->kind = kind;
    elem->value = strdup(val);  
    elem->prev = stackHead;
    stackHead = elem;
}

Node* pop() {
    if (!stackHead) return NULL;
    Node* out = stackHead;
    stackHead = stackHead->prev;
    return out;
}

void append(const char *w) {
    push(1, w);  
    strcat(text, w);
    textLen = strlen(text);
}

void delete(int k) {
    int idx = textLen - k;
    char* cut = (char*)malloc(k + 1);
    strncpy(cut, text + idx, k);
    cut[k] = '\0';
    push(2, cut);
    text[idx] = '\0';
    textLen = strlen(text);
    free(cut);
}

void undo() {
    Node* action = pop();
    if (!action) return;

    if (action->kind == 1) {
        int sz = strlen(action->value);
        text[textLen - sz] = '\0';
        textLen -= sz;
    } else if (action->kind == 2) {
        strcat(text, action->value);
        textLen = strlen(text);
    }
    free(action->value);
    free(action);
}

int main() {
    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char buff[MAX_SIZE + 1];
            scanf(" %[^\n]", buff);  
            append(buff);

        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            delete(k);

        } else if (type == 3) {
            int pos;
            scanf("%d", &pos);
            printf("%c\n", text[pos - 1]);

        } else if (type == 4) {
            undo();
        }
    }

    return 0;
}
