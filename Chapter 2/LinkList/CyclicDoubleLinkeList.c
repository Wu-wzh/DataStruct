#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//ѭ��˫����,��ڵ��������ָ����һ��ָ��ǰ���ڵ㣨�����ڣ�����һ��ָ���̽ڵ㣨�����ڣ�
//ÿһ���ڵ�֮�䶼�൱�ڽ������������ӣ�������ɾ������ӵȲ���ʱҪ����ȥ��
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkedList;

int InitList(DLinkedList *L)
{
    *L = (DNode *)malloc(sizeof(DNode));
    if (*L == NULL)
        return false;
    (*L)->prior = *L;
    (*L)->next = *L;
    return true;
}

int InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

int InsertPriorDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    return InsertNextDNode(p->prior, s);
}

int DeleteNextNode(DNode *p)
{
    if (p == NULL || p->next == p)
        return false;
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

DLinkedList List_HeadInsert(DLinkedList *L)
{
    DNode *Head = *L;
    int x;
    scanf("%d", &x);
    while (x != 666)
    {
        DNode *s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = Head->next;
        s->prior = Head;
        Head->next->prior = s;
        Head->next = s;
        scanf("%d", &x);
    }
    //����ѭ������
    Head->prior = (*L)->prior;
    (*L)->prior->next = Head;
    return *L;
}


DLinkedList List_TailInsert(DLinkedList *L)
{
    int x;
    DNode *s, *t = *L;
    scanf("%d", &x);
    while (x != 666)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = t->next;
        s->prior = t;
        t->next->prior = s;
        t->next = s;
        t = s;
        scanf("%d", &x);
    }
    //����ѭ������
    t->next = *L;
    (*L)->prior = t;
    return *L;
}


void DestroyList(DLinkedList *L)
{
    DNode *p = (*L)->next;
    DNode *q;
    while (p != *L)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
}

int isEmpty(DLinkedList L)
{
    return L->next == L;
}

DNode *LocateElement(DLinkedList L, int e)
{
    DNode *p = L->next;
    while (p != L && p->data != e)
    {
        p = p->next;
    }
    if (p == L)
        return NULL;
    return p;
}

int GetLength(DLinkedList L)
{
    DNode *p = L->next;
    int len = 0;
    while (p != L)
    {
        len++;
        p = p->next;
    }
    return len;
}

void printList(DLinkedList L)
{
    DNode *p = L->next;
    while (p != L)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    DLinkedList L = NULL;
    InitList(&L);

    printf("ʹ��β�巨����ѭ��˫����\n");
    List_TailInsert(&L);
    printf("ѭ��˫�������ݣ�\n");
    printList(L);

    printf("==========\n");

    printf("ʹ��ͷ�巨����ѭ��˫����\n");
    DLinkedList L2 = NULL;
    InitList(&L2);
    List_HeadInsert(&L2);
    printf("ѭ��˫�������ݣ�\n");
    printList(L2);

    DestroyList(&L);
    DestroyList(&L2);

    system("pause");
    return 0;
}
