#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return '\0';

    return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';

    return stack[top];
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (ch == ' ' || ch == '\t')
            continue;

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();

            if (top == -1) {
                printf("Invalid expression!\n");
                return;
            }

            pop();
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' ||
                 ch == '%' || ch == '^') {

            while (top != -1 && peek() != '(' &&
                  (precedence(peek()) > precedence(ch) ||
                  (precedence(peek()) == precedence(ch) &&
                   ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
        else {
            printf("Invalid character: %c\n", ch);
            return;
        }
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Invalid expression!\n");
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    if (fgets(infix, sizeof(infix), stdin) == NULL)
        return 1;

    infixToPostfix(infix);

    return 0;
}
