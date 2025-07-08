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
    //Trước khi push thì càn kiểm tra stack có đủ bộ nhớ hay không
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
void reverseStack(int arr[],int n) {
    Stack s;
    initialStack(&s);

    for (int i =0; i <n; i++){
        push(&s,arr[i]);

    }
    for (int i =0; i <n; i++) {
        arr[i]=pop(&s);
    }
}
void printArr(int arr[],int n) {
    printf("[");
    for (int i =0; i <n; i++) {
        printf("%d",arr[i]);
        if (i!=n-1) {
            printf(",");
        }
    }
    printf("]");
}
int main(void){
    Stack s;
    initialStack(&s);
    int n,arr[MAX];

    //Nhập số lượng phần tử
    printf("Nhap n:");
    scanf("%d",&n);

    //Nhập giá trị cho từng phần tử
    printf("Nhap cac phan tu:\n");
    for (int i =0; i <n; i++) {
        printf("Phan tu %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printArr(arr,n);

    //Hàm đảo ngược
    reverseStack(arr,n);
    printf("\nMang sau khi dao nguoc la:");
    printArr(arr,n);

    return 0;
}