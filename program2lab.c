
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = -1;
int max = 100;
void push(char ch, char arr[]);
char pop(char arr[]);
void infixtopostfix(char source[], char target[]);
int preced(char op);

int main() {
    char infix[100], postfix[100];

    printf("enter the expression\n");
    gets(infix);

    infixtopostfix(infix, postfix);

    return 0;
}

void infixtopostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char arr[100];
    top = -1;

    push('(', arr);
    strcat(source, ")");
    while (source[i] != '\0') {
        char ch = source[i];

        if (ch == '(') {
            push(ch, arr);
        }
        else if (ch == ')') {
            char temp = pop(arr);
            while (temp != '(') {
                target[j++] = temp;
                temp = pop(arr);
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && preced(arr[top]) >= preced(ch)) {
                char rem = pop(arr);
                target[j++] = rem;
            }
            push(ch, arr);
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            target[j++] = ch;
        }

        else {
            printf("Invalid character %c\n", ch);
            exit(1);
        }

        i++;
    }
    target[j] = '\0';

    printf("Postfix expression: %s\n", target);
}

void push(char ch, char arr[]) {
    if (top == max - 1) {
        printf("overflow\n");
        exit(1);
    }
    arr[++top] = ch;
}

char pop(char arr[]) {
    if (top == -1) {
        printf("underflow\n");
        exit(1);
    }
    return arr[top--];
}

int preced(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
