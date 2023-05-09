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
    
    printf("����˳����ұ�����(��666Ϊ����)��\n");
    int x, i = 1;
    scanf("%d", &x);
    while (x != 666){
        S->data[i++] = x;
        scanf("%d", &x);
    }

}

int Search_Seq(SSTable *L, int key){
    L->data[0] = key;
    int i;
    for (i = L->length; L->data[i] != key; --i) //�޲���ѭ���������ҵ�i
    return i;
}
/*�����Ż� ��
1��������п����Ż����Ҳ��ԣ����ٲ��ҳɹ���ʱ�临�Ӷ�
2���������Ԫ�صĸ��ʲ�ͬ�������ʸߵķ��ڲ���ǰ�棬���ٲ���ʧ�ܵ�ʱ�临�Ӷ�
�����Ż�����Ҫ���������в��ҳɹ�������໹�ǲ���ʧ�ܵ������
*/
int main(){
    SSTable L;
    InitList(&L);
    CreateTable(&L);
    printf("%d\n", Search_Seq(&L, 66));
    system("pause");
    return 0;
}