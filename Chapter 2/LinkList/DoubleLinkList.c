#include <stdio.h>
#include <windows.h>
#define true 1;
#define false 0;

//˫��������ڵ��������ָ����һ��ָ��ǰ���ڵ㣨�����ڣ�����һ��ָ���̽ڵ㣨�����ڣ�
//ÿһ���ڵ�֮�䶼�൱�ڽ������������ӣ�������ɾ������ӵȲ���ʱҪ����ȥ��.

typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
} DNode, *LinkList;

//ͬ������Ĳ���L��һ��ָ�룬�����ڲ�ʹ��*����������* L�ͱ�ʾ��������ĵ�ַ��ͨ���޸������ַ�е����ݣ��Ӷ�ʵ�ֶ�L���޸�
//����singal��ʾ�Ƿ���ͷ�ڵ�
int InitList(LinkList *L, int sinal){
    *L = (DNode*)malloc(sizeof(DNode));
    if (*L == NULL) return false;
    if (sinal){
        (*L)->prior = NULL;
        (*L)->next = NULL;
    }
    else *L = NULL;
    return true;
}

//���²�����ǰ��ͺ�������װ��������ߴ���Ŀɶ��ԡ�

//������
int InsertNextDNode(DNode *p, DNode *s){
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//ǰ�����
//������priorָ����ǰ������ͱ����Լ���
int InsertPriorDNode(DNode *p, DNode *s){
    if (p == NULL || s == NULL) return false;
    s->prior = p->prior;
    if (p == NULL)
        p->prior->next = s;
    p->prior = s;
    s->next = p;
}

//˫�����ɾ������
//��Ҫ��˫�����prior��nextָ����ͬʱ�޸�
//ɾ��p�ĺ�̽ڵ�
int DeleteNextNode(DNode* p){
    if (p == NULL) return false;
    DNode* q = p->next;
    if (q == NULL) return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);

    return true;
}

//ͷ�巨
/*ͷ�巨������ʵ�ַ���
��һ����ͨ�����ϵ���ͷ�ڵ�������
�����ٱ�֤��һ���ڵ����ʱ�����ϵ����һ���ڵ�ǰ�����
�����ʵ���˵�һ�ַ���
*/
LinkList List_HeadInsert(LinkList* L){
    DNode* Head = *L;
    int x;
    scanf("%d", &x);
    while (x != 666)
    {
        DNode* p = (DNode*)malloc(sizeof(DNode));
        p->data = x;
        InsertNextDNode(Head, p);
        scanf("%d", &x);
    }
    return *L;
}

//β�巨
LinkList List_TailInsert(LinkList* L){
    int x;
    DNode *s, *t = *L;
    scanf("%d",&x);
    while (x != 666)
    {
        s = (DNode*)malloc(sizeof(DNode));
        s->data = x;
        t->next = s;
        t = s; //�ؼ���tβָ��ʼ��ָ��s���һ���ڵ�
        scanf("%d",&x);
    }
    t->next = NULL;
    return *L;
}




//��������˫����
void DestoryList(LinkList* L){
    while ((*L)->next != NULL)
        DeleteNextNode(*L);
    free(*L);
    L=NULL;
}

int isEmpty(LinkList L, int signal){
    if (signal) return L->next == NULL;
    else return L == NULL;
}

DNode *LocateElement(LinkList L, int e) {
    DNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

int GetLength(LinkList L) {
    DNode *p = L;
    int len = 0;
    while (p->next != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

void printList(LinkList L, int signal){
    DNode *p = L;
    if (signal == 1) p = p->next;
    while (p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}


int main() {
    LinkList L = NULL;
    InitList(&L, 1);

    // ʹ��β�巨����˫����
    printf("ʹ��β�巨����˫����\n");
    List_TailInsert(&L);
    printf("˫�������ݣ�\n");
    printList(L, 1);

    printf("==========\n");

    // ʹ��ͷ�巨����˫����
    printf("ʹ��ͷ�巨����˫����\n");
    LinkList L2 = NULL;
    InitList(&L2, 1);
    List_HeadInsert(&L2);
    printf("˫�������ݣ�\n");
    printList(L2, 1);

    printf("==========\n");

    // ��ֵ����Ԫ��
    printf("��ֵ����Ԫ�أ�\n");
    int target = 3;
    DNode *foundNode = LocateElement(L, target);
    if (foundNode) {
        printf("�ҵ�Ԫ�أ�%d\n", foundNode->data);
    } else {
        printf("δ�ҵ�Ԫ��\n");
    }

    printf("==========\n");

    // ����������
    printf("���������ȣ�\n");
    int len = GetLength(L);
    printf("�����ȣ�%d\n", len);

    printf("==========\n");

    // ��ָ��λ�ò���ڵ�
    printf("��ָ��λ�ò���ڵ㣺\n");
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = 99;
    DNode *posNode = LocateElement(L, 2);
    if (posNode) {
        InsertNextDNode(posNode, newNode);
    }
    printf("�����½ڵ����������ݣ�\n");
    printList(L, 1);

    printf("==========\n");


    // ��������
    printf("��������\n");
    DestoryList(&L);
    printf("����������\n");

    system("pause");
    return 0;
}