#include <stdio.h>
#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

// Khởi tạo ngăn xếp
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char ch) {
    if (!isFull(s)) {
        s->data[++s->top] = ch;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Kiểm tra dấu ngoặc hợp lệ
int isValidExpression(char expr[]) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) return 0;
            char top = pop(&s);
            if (!isMatchingPair(top, ch)) return 0;
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Nhap expr : ");
    scanf("%s", expr);  // Không dùng fgets, chỉ dùng scanf

    if (isValidExpression(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
