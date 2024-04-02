#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;


int is_empty(Stack *stack) {
    return stack->top == -1;
}


int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}


void make_empty(Stack *stack) {
    stack->top = -1;
}


void push(Stack *stack, char item) {
    if (!is_full(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack penuh%c\n", item);
    }
}

char pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack kosong\n");
        return '\0';
    }
}

int match(char a, char b) {
    return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}

int is_balanced(char *str) {
    Stack stack;
    make_empty(&stack);
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (is_empty(&stack) || !match(pop(&stack), str[i])) {
                return 0;
            }
        }
    }
    return is_empty(&stack);
}

int main() {
    char str[MAX_SIZE];
    printf("Masukan Tanda kurung yang akan dicocokan : ");
    scanf("%s", str);
    if (is_balanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}