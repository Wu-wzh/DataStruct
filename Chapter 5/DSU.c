#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxSize 100
//���鼯��ʾ��Ϊ���Ϲ�ϵ��ֻʵ�ּ��ϵĲ�ѯ�Ͳ��Ĳ���
//������Ͳ����������Ż������������Ż���Ϊ�˽��Ͳ������ʱ�临�Ӷ�
//��������Ż�Ч�ʺܸߣ������ﵽ�˳�������
//��n��������Ԫ�غϲ�Ϊһ�����ϣ����ڲ�������Ҫ���ҵ����ϲ�Ԫ�صĸ��ڵ㣬�����ʱ�临�Ӷ�Ϊ�������˲������ʱ�临�Ӷ�
int UFSets[MaxSize];

//ȫ����ʼ��Ϊ-1
void Initial(int S[]){
    for (int i = 0; i < MaxSize; i++)
        S[i] = -1;
}

//���ڵ�ľ���ֵΪ�˼������ĸ߶�
void CreateDSU(int S[]){
    S[0] = -3;
    S[1] = 0;
    S[2] = 0;
    S[3] = 1;
    S[4] = -2;
    S[5] = 4;
    S[6] = 4;
    S[7] = -2;
    S[8] = 7;
}

//����� �ҵ������������������
int Find_Bad(int S[], int x){
    //ʱ�临�Ӷ�ΪO(n)��nΪ�߶�
    while(S[x] >= 0)
        x = S[x];
    return x;
}

//��������Ż���ѹ��·�� ��Ϊ���������
int Find(int S[], int x){
    int root = x;
    while(S[root] >= 0)
        root = S[root];

    //ѹ��·��
    while (x != root){
        int t = S[x]; //�ҵ�x�ĸ��ڵ�
        S[x] = root; //�����ڵ�ֱ�ӹ��ص����ڵ���
        x = t; //�Ҹ��ڵ㣬��������ѹ��
    }
    //����while��ʵ���˽�x��root�ڵ��ϵ����нڵ����ѹ���������˲���������ߺ���ʱ�临�Ӷ�
}
//�Ż�֮���ʱ�临�Ӷ��������͵���������;

//�������ʱ�临�Ӷ��뵥�����������ɵ����ĸ߶��й�
//���Ҫ����п��ٵĲ�ѯ����Ҫ�ڲ�����ʱʹ�ϲ������߶Ⱦ�������

//���������ֱ�Ӻϲ������ܻᵼ�ºϲ���������ߣ�Ӱ�����ٶ�
void Union_Bad(int S[], int root1, int root2){
    if (root1 == root2) return;
    S[root2] = root1;
}

//С���������
//�Բ����������Ż�֮�����ĸ߶Ȳ�����O(logn),���Բ������ʱ�临�Ӷ�Ҳ����logn�������Ĳ�������O(1)
void Union(int S[], int root1, int root2){
    if (root1 == root2) return;

    //���ڹ涨�ڸ��ڵ��ֵΪ��ֵ�����ֵԽ����ԽС
    if (S[root1] > S[root2]){ //root1ΪС��
        S[root2] += S[root1];
        S[root1] = root2;
    } else{ //root2ΪС��
        S[root1] += S[root2];
        S[root2] = root1;
    }
}

int main(){

    system("pause");
    return 0;
}