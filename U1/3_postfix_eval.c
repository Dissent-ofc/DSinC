#include <stdio.h>
#include <ctype.h>   // For isdigit()
#include <stdlib.h>  // For atoi()
#include <math.h>    // For pow()

#define MAX 100

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int value) {          //Here recursion is happening as value is calling push function again and again
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// Pop element from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];    //first pops val2 then decrements and then pops val1
}

// Evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If character is a digit, push it to stack
        if (isdigit(ch)) {
            push(ch - '0'); // convert char digit to int
        }

        // If operator, pop two elements and apply operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
            case '+': result = val1 + val2; break;
            case '-': result = val1 - val2; break;
            case '*': result = val1 * val2; break;
            case '/': result = val1 / val2; break;
            case '%' : result = val1 % val2; break;
            case '^' : result = pow(val1, val2); break;
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a Postfix Expression (e.g., 231*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of Postfix Evaluation: %d\n", result);

    return 0;
}
