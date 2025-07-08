#include <stdio.h>
#define MAX 100

// Khai báo stack
typedef struct Stack {
    int data[MAX]; // Mảng chứa các phần tử của stack
    int top;       // Chỉ số phần tử đỉnh
} Stack;

// Khởi tạo stack
void initialStack(Stack *s) {
    s->top = -1; // ban đầu stack rỗng
}

// Kiểm tra stack đầy
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Kiểm tra stack rỗng
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Thêm phần tử vào stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("stack da day\n");
        return;
    }
    s->data[++s->top] = value;
}

// Lấy phần tử ra khỏi stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("stack rong\n");
        return -1;
    }
    return s->data[s->top--];
}

// Xem phần tử đỉnh stack
int peeks(Stack *s) {
    if (isEmpty(s)) {
        printf("stack rong\n");
        return -1;
    }
    return s->data[s->top];
}

// In ra toàn bộ phần tử trong stack
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rong\n");
        return;
    }
    printf("\nstack = {\n");
    printf("elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i != s->top) printf(", ");
    }
    printf("],\n");
    printf("top: %d,\n", s->top);
    printf("cap: %d\n", s->top + 1);
    printf("}\n");
}

// Hàm main
int main(void) {
    Stack s;
    initialStack(&s);

    int value;
    printf("Nhap phan tu:\n");
    for (int i = 0; i < 5; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }
    // In thông tin stack sau khi thêm
    printStack(&s);

    return 0;
}
