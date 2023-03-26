/*
ջ�����Ʋ����ɾ�����������Ա�
n����ͬԪ�ؽ�ջ����սԪ�ز�ͬ���и���Ϊ1/(n+1)*C(2/2n)(������)���ֽ�����������
*/
#include <stdio.h>
#include <windows.h>
#define MaxSize 10
#define true 1;
#define false 0;

typedef struct{
    int data[MaxSize];
    int top; //ջ��
} SeqStack;

void InitStack(SeqStack* S){
    S->top = -1;
    // else *S->top = 0;
}

//��ջ
int Push(SeqStack* S, int x){
    if (S->top == MaxSize - 1) return false;
    // S->top += 1; //��ִ��ջ����һ����
    // S->data[S->top] = 1; //�ٽ��и�ֵ
    //������ȼ�������
    S->data[++S->top] = x;
    return true;
}
// int Push0(SeqStack* S, int x){
//     if (S->top == MaxSize) return false;
//     // S->top += 1; //��ִ��ջ����һ����
//     // S->data[S->top] = 1; //�ٽ��и�ֵ
//     //������ȼ�������
//     S->data[S->top++] = x;
//     return true;
// }
//��ջ(����)
int Pop(SeqStack* S, int *x){
    if (S->top == -1) return false;
    *x = S->data[S->top--];
    return true;
}
// int Pop0(SeqStack* S, int &x){
//     if (S->top == -1) return false;
//     x = S->data[--S->top];
//     return false;
// }
//��ȡջ��Ԫ��(������)
int GetTop(SeqStack* S, int* x){
    if (S->top == -1) return false;
    *x = S->data[S->top];
    return false;
}
// int GetTop0(SeqStack* S, int &x){
//     if (S->top == -1) return false;
//     x = S->data[S->top - 1];
//     return false;
// }

void printStack(SeqStack S){
    while (S.top != -1)
    {
       printf("%d\n", S.data[S.top--]); 
    }
}

int main(){
    SeqStack S;
    int x;

    // ��ʼ��һ����ջ
    InitStack(&S);

    // ��Ԫ������ѹ��ջ��
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 5);
    Push(&S, 6);
    Push(&S, 7);
    Push(&S, 9);

    // ��ӡջ��Ԫ��
    printf("ջ��Ԫ�أ�\n");
    printStack(S);
    printf("\n");

    // ���ν�Ԫ�ص�������ӡ
    printf("����Ԫ�أ�\n");
    int a = 1;
    while (Pop(&S, &x))
    {
        printf("��%d�ε�����Ԫ��Ϊ��%d\n", a++, x);
    }
    printf("\n");
    system("pause");
    return 0;
}



