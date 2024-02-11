#include <stdio.h>
#include <stdlib.h>

#define  STACK_SIZE 100
int stack[STACK_SIZE];
size_t sp = 0;

void push(int x) {
    stack[sp++] = x;
}

void draw_ops(int *op1, int *op2) {
    if (sp < 2) {
        printf("Error: the expression is invalid.\n");
        return;
    }
    *op2 = stack[--sp];
    *op1 = stack[--sp];
}


int main(int argc, char *argv[]) {
    int op1, op2;

    for (int i = 1; i < argc; i++) {
        switch (*argv[i]) {
            case '+':
                draw_ops(&op1, &op2);
                push(op1 + op2);
                break;
            case '-':
                draw_ops(&op1, &op2);
                push(op1 - op2);
                break;
            case '*':
                draw_ops(&op1, &op2);
                push(op1 * op2);
                break;
            case '\\':
                draw_ops(&op1, &op2);
                if (op2 != 0) {
                    push(op1 / op2);
                } else {
                    printf("Error: division by zero.\n");
                }
                break;

            default:
                push(atoi(argv[i]));
                break;
        }
    }

    printf("Result of the expression: %d\n", stack[sp - 1]);
}
