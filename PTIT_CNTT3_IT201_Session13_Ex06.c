#include <stdio.h>
#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

void initialStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->data[++s->top] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int isPalindrome(char str[]) {
    Stack s;
    initialStack(&s);

    int len = stringLength(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX];

    printf("Nhap chuoi g: ");
    scanf("%s", str); // chỉ đọc đến khoảng trắng

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
