#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define InitSize 11
#define true 1
#define false 0
#define TableLength 5


//������ṹ��
typedef struct{
    int maxvalue;
    int low, high;
} Index, IndexTable[TableLength];

void InitTable(IndexTable **T){  //�޸ĺ�����������Ϊ IndexTable**
    int k = 10;
    for (int i = 0; i < TableLength; i++){
        (*T)[i]->maxvalue = k;   //ͨ��ָ���޸� IndexTable �е�Ԫ��
        (*T)[i]->low = 0;
        (*T)[i]->high = 0;
        k+=10;
    }
}


int CreateTable(IndexTable *T){
    int List[14] = {7,10,13,19,16,20,27,22,30,40,36,43,50,48};
    T[0]->low = 0;
    T[0]->high = 1;

    T[1]->low = 2;
    T[1]->high = 5;

    T[2]->low = 6;
    T[2]->high = 8;

    T[3]->low = 9;
    T[3]->high = 10;
    
    T[4]->low = 11;
    T[4]->high = 13;
} 
//�������򣬵��ǿ�����������ַֿ�ķ��������õõ������������У�
//�Ӷ�ʹ��ʱ�临�Ӷȵ͵��㷨�ȶԿ����в��ң����ҵ����ϵĿ��������ڽ���˳�����

int Search_Block_Binary(IndexTable *T, int key){
    int List[14] = {7,10,13,19,16,20,27,22,30,40,36,43,50,48};

    int low = 0, high = 4, mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (key == T[mid]->maxvalue) //���ҵ���key��λ��
            for (int i = T[mid]->low; i <= T[mid]->high; i++)
                if (key == List[i]) return i;

        else if (key < T[mid]->maxvalue) //���������м�Ԫ�صĺ��棬�����highֵΪmid - 1
            high = mid - 1;
    
        else low = mid + 1; //���������м�Ԫ�ص�ǰ�棬�����lowֵΪmid + 1
    }

    //����֮�󲢲��ǽ�����������֤�����Բ��ҵ������ڽ���ѭ����low���ڵ��������Ӧ��Ԫ����
    for (int i = T[i]->low; i <= T[i]->high; i++)
                if (key == List[i]) return i;
    return -1;    
}

int main(){
    IndexTable *T;
    T = (IndexTable*)malloc(sizeof(Index) * 5);
    InitTable(&T);
    CreateTable(&T); //����Ϊ������Ϊʵ������˳�����������
    printf("%d\n", Search_Block_Binary(T, 19));
    system("pause");
    return 0;
}