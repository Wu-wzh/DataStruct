//���ֲ��ң�ֻ����������˳���Ĳ��� ������ָ�벻�Ͻ�����С��ÿ����СΪԭ���Ķ���֮һ
//�����ж���ASL(ƽ�����ҳ���)���� ���ж�����һ��ƽ�����������

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define InitSize 11
#define true 1
#define false 0

typedef struct{
    int *data;
    int length;
}SSTable;

void InitList(SSTable* L){
    L->data = (int*)malloc(InitSize * sizeof(int));
    for  (int i = 0; i < InitSize; i++)
        L->data[i] = 0;
    L->length = 0;
}

int ListInsert(SSTable *L, int i, int e){
    if (i < 1 || i > L->length + 1) {
        printf("Invalid Number!!\n");
        return false;
    }
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

int CreateTable(SSTable *S){
    printf("����˳����ұ�����(�����,��666Ϊ����)��\n");
    int x, i = 0;
    scanf("%d", &x);
    while (x != 666){
        S->data[i++] = x;
        S->length++;
        scanf("%d", &x);
    }
}

int Search_Binary(SSTable L, int key){
    //��ʼ������ָ��ֱ�Ϊ��һ�������һ��Ԫ�أ���������low��high���м�ָ��
    int low = 0, high = L.length - 1, mid;
    while (low <= high){
        mid = (high + low) / 2; //int�ͽ���������
        if (key == L.data[mid]) return mid; //���ҵ���key��λ�ã�ֱ�ӷ���midֵ
        else if (key < L.data[mid]) //���������м�Ԫ�صĺ��棬�����highֵΪmid - 1
            high = mid - 1;
        else low = mid + 1; //���������м�Ԫ�ص�ǰ�棬�����lowֵΪmid + 1
    }
    //������ɺ�û���ҵ�����������midֵ��˵��û�ҵ�������-1
    return -1;
} //Ҫע����ֲ��ұ�����˳�����Ϊ�������У���ʱ�临�Ӷ�ΪO(log2n),���Կ������㷨��ʱ�临�ӶȺܺ�

int main(){
    SSTable S;
    InitList(&S);
    CreateTable(&S);
    printf("%d\n", Search_Binary(S, 44));
    system("pause");
    return 0;
}