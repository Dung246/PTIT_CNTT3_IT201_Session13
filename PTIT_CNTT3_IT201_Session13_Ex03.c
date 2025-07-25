#include<stdio.h>
#define MAX 100
//Khai báo stack
typedef struct Stack{
    int data[MAX];//Mảng chứa các phần tử của stack
    int top;   //chỉ số phần tử đỉnh

}Stack;

//Khởi tạo stack
void initialStack(Stack *s){
    s->top=-1; //ban đầu stack rỗng
}

//Tạo hàm kiểm tra Stack đã đâỳ hay chưa ?
int isFull(Stack *s){
    return s->top==MAX-1;
}

//Thêm phần tử vào stack
void push(Stack *s,int value){
    //Trước khi ush thì càn kiểm tra stack có đủ bộ nhớ hay không
    if(isFull(s)){
        printf("Stack da day");
        return ;
    }
    //Nếu stack còn bộ nhớ thì thêm vào
    s->data[++s->top]=value;
}

//Kiểm tra stack có bị rỗng khoong
int isEmpty(Stack *s) {
    return s->top==-1;
}

//Lấy và loại bỏ phần tử trên cùng
int pop(Stack *s) {
    //kiểm tra xem trong Stack có rỗng hay không
    if (isEmpty(s)) {
        printf("Stack rong");
        return -1;
    }
    return s->data[s->top--];
}

//Lấy và giữ nguyên phần tử ở đỉnh
int peeks(Stack *s) {
    //kiểm tra xem trong Stack có rỗng hay không
    if (isEmpty(s)) {
        printf("Stack rong\n");
        return -1;
    }
    return s->data[s->top];
}
void printStack(Stack *s) {
    printf("stack={");
    printf("element: [");
    for (int i=0;i<s->top;i++) {
        printf("%d",s->data[i]);
        if (i!=s->top-1) {
            printf(",");
        }
    }
    printf(" ]\n");
    printf("top: %d\n",s->top);
    printf("data: %d\n",s->top+1);
    printf("}");
}
int main(void){
    Stack s;
    initialStack(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);

    printStack(&s);

    while(!isEmpty(&s)) {
        int value=pop(&s);
        //Lấy phần tử
        printf("\nLay phan tu %d\n",pop(&s));
        printStack(&s);
    }
    // Thử lấy thêm 1 phần tử khi stack rỗng
    int value = pop(&s); // sẽ in ra thông báo lỗi
    if (value == -1) {
    }
    return 0;
}
