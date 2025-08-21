#include <stdio.h>
#include <stdlib.h>


int s1[100000], s2[100000];
int top1 = -1, top2 = -1;

void push_s1(int val) { s1[++top1] = val; }
int pop_s1() { return s1[top1--]; }
int empty_s1() { return top1 == -1; }

void push_s2(int val) { s2[++top2] = val; }
int pop_s2() { return s2[top2--]; }
int empty_s2() { return top2 == -1; }

void add_q(int val) { push_s1(val); }

void shift_stacks() {
    while (!empty_s1()) {
        push_s2(pop_s1());
    }
}

void remove_q() {
    if (empty_s2()) shift_stacks();
    if (!empty_s2()) pop_s2();
}

void front_q() {
    if (empty_s2()) shift_stacks();
    if (!empty_s2()) {
        printf("%d\n", s2[top2]);
    }
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int val;
            scanf("%d", &val);
            add_q(val);
        } else if (type == 2) {
            remove_q();
        } else if (type == 3) {
            front_q();
        }
    }
    return 0;
}
