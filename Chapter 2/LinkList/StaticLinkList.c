#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data;
    int cur;  // ָ����һ��Ԫ�ص��±�
} SLNode, *SList;

void InitSpace(SLNode *space) {
    // ��ʼ����̬����ռ�
    for (int i = 0; i < MAXSIZE - 1; i++) {
        space[i].cur = i + 1;  // ��ÿ���ڵ��curָ����һ�����ÿռ�
    }
    space[MAXSIZE - 1].cur = 0;  // ���һ���ڵ��curָ��0����ʾ��̬����Ϊ��
}

int Malloc(SLNode *space) {
    // �Ӿ�̬�����з���һ���ռ䣬���ظÿռ���±ꡣ
    int i = space[0].cur;
    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

void Free(SLNode *space, int k) {
    // �ͷ��±�Ϊk�Ŀռ䣬������뾲̬����Ŀ���������
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void InitList(SList S) {
    // ��ʼ����̬����
    for (int i = 0; i < MAXSIZE - 2; i++) {
        S[i].cur = i + 1;  // ��ÿ���ڵ��curָ����һ���ڵ�
    }
    S[MAXSIZE - 2].cur = 0;  // ���һ���ڵ��curָ��0����ʾ��̬����Ϊ��
}

void Insert(SList S, int i, int e, SLNode *space) {
    // ���±�Ϊi�Ľڵ�֮�����һ��ֵΪe�Ľڵ�
    int j = Malloc(space);
    space[j].data = e;
    space[j].cur = S[i].cur;
    S[i].cur = j;
}

void Delete(SList S, int i, SLNode *space) {
    // ɾ���±�Ϊi�Ľڵ�
    int j = S[i].cur;
    S[i].cur = space[j].cur;
    Free(space, j);
}

int Locate(SList S, int e, SLNode *space) {
    // ����ֵΪe�Ľڵ���±꣬�����±�ֵ
    int i = S[MAXSIZE - 2].cur;
    while (i && space[i].data != e) {
        i = space[i].cur;
    }
    return i;
}

void DestroyList(SList S, SLNode *space) {
    // ���پ�̬����
    int i = S[MAXSIZE - 2].cur;
    while (i) {
        int j = S[i].cur;
        Free(space, i);
        i = j;
    }
    S[MAXSIZE - 2].cur = 0;  // ��̬�����ٴ��ÿ�
}

int GetLength(SLNode *space) {
    // ��ȡ��̬����ĳ���
    int i = space[MAXSIZE - 1].cur;
    int length = 0;
    while (i) {
        length++;
        i = space[i].cur;
    }
    return length;
}

void PrintList(SLNode *space) {
    // �����̬���������Ԫ��
    int i = space[MAXSIZE - 1].cur;
    while (i) {
        printf("%d ", space[i].data);
        i = space[i].cur;
    }
    printf("\n");
}

int main() {
    SLNode space[MAXSIZE];
    SList S = space;
    InitSpace(space);
    InitList(S);
    printf("��̬�����ʼ״̬��\n");
    PrintList(space);
    int k = Malloc(space);
    space[k].data = 10;
    Insert(S, 0, k, space);
    k = Malloc(space);
    space[k].data = 20;
    Insert(S, 1, k, space);
    k = Malloc(space);
    space[k].data = 30;
    Insert(S, 2, k, space);
    printf("��������Ԫ�غ�ľ�̬����״̬��\n");
    PrintList(space);
    Delete(S, 1, space);
    printf("ɾ���ڶ���Ԫ�غ�ľ�̬����״̬��\n");
    PrintList(space);
    printf("Ԫ��20��λ�ã�%d\n", Locate(S, 20, space));
    printf("Ԫ��50��λ�ã�%d\n", Locate(S, 50, space));
    DestroyList(S, space);
    printf("���پ�̬�����Ŀռ�״̬��\n");
    for (int i = 0; i < MAXSIZE; i++)
        printf("%d ", space[i].cur);
    printf("\n");
    system("pause");
    return 0;
}

