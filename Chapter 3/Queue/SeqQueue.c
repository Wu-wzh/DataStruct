#include <stdio.h>
#include <windows.h>
#define MaxSize 10
#define true 1
#define false 0
////
//
//ʹ��ѭ������洢���У����뾲̬���鲻ͬ���ǰ����˶�ͷ�Ͷ�βָ�� 
//���˳�������ʵ�ǻ�״�ģ���Ҫ����ȡģ������

//����������˳����е�����Ԫ�أ�����Ҫ��Queue�ṹ��Ӹ���������size����tag���������ж϶���Ϊ����ʱ�򣬾Ͳ�������һ���洢�ռ�
//ֻ��Ҫ�ж�size����tag��ֵ�����ж�ͷָ��=βָ��ʱ�����Ƕӿջ��Ƕ���
typedef struct Queue{
    int data[MaxSize];
    int front, tail;
}SqQueue;

int InitQueue(SqQueue *Q){
    Q->front = Q->tail = 0;
    return true;
}

//��βָ����ָ���β����һ��λ�ã��ھ�����Ŀ�п��ܻ�ı�Ϊָ���β����Ҫ��ϸ����
int EnQueue(SqQueue *Q, int e){
    if ((Q->tail + 1) % MaxSize == Q->front) return false;
    Q->data[Q->tail] = e;
    Q->tail = (Q->tail + 1) % MaxSize;
    return true;
}

int DeQueue(SqQueue *Q, int *x){
    if (Q->front == Q->tail) return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    return true;
}

int GetHead(SqQueue Q,int *x){
    if (Q.front == Q.tail) return false;
    *x = Q.data[Q.front];
    return true;
}
int isEmpty(SqQueue Q){ //����βָ����ڶ�ͷָ��ʱ������Ϊ��
    return Q.front == Q.tail;
}

int GetLength(SqQueue Q){
    return (Q.tail + MaxSize - Q.front) % MaxSize;
}

void printQueue(SqQueue Q){
    while (Q.front != Q.tail){
        printf("%d<-",Q.data[Q.front]);
        Q.front = (Q.front + 1) % MaxSize;
    }
    printf("end\n");
}
    
int main(){
    SqQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 4);
    printQueue(Q);
    int x;
    DeQueue(&Q, &x);
    printQueue(Q);
    printf("%d\n", GetLength(Q));
    system("pause");
    return 0;
}