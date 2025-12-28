/*Infix to postfix
204 Shivam */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int prec(char c) {
    return (c == '^') ? 3 : (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix: ");
    scanf("%s", infix);

    int i, j = 0;
    for (i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) postfix[j++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && prec(stack[top]) >= prec(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1) postfix[j++] = pop();
    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}
