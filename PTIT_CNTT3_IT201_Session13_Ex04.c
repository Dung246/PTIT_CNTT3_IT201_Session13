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

//Tạo hàm kiểm tra Stack đã đâ hay chưa ?
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
        printf("Stack rong");
        return -1;
    }
    return s->data[s->top];
}
//Hàm in danh sách
// void printElements(int element,int totalElement) {
//     if (totalElement==0) {
//         printf("Stack rong");
//         return;
//     }
//     // duyệt các phàn tử trong stack
//     printf("Danh sach cac phan tu trong Stack:");
//     for (int i=totalElement-1;i>=0;i--) {
//         printf("%d \n",element[i]);
//     }
// }

//Hàm in ra danh sách các phần tử Stack theo thứ tự đảo nguọc
void printElements(Stack *s) {
    if (s->top==-1) {
        printf("Stack rong");
        return;
    }
    printf("Danh sach cac phan tu co trong stack:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n",s->data[i]);
    }
}
int main(void){
    Stack s;
    initialStack(&s);

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);

    //Hàm in danh sách
    printElements(&s);

    //Lấy phần tử
    printf("Lay phan tu %d\n",pop(&s));

    printf("Phan tu o dinh %d\n",peeks(&s));
    return 0;
}