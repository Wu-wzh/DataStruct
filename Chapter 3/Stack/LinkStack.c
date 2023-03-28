#include <stdio.h>
#include <windows.h>
#define true 1;
#define false 0;

//��Ҫ���ڶ���ṹ��ʱ��struct�����LinkNode����ʡ�ԣ����򽫻ᵼ�±������޷�ʶ��LinkNode���ͣ���˲���ʹ��LStatic������LinkNode��ָ��
//������ִ��S->next����һ������ʱ��ϵͳ���ܰ�������LinkNode*���ͣ����Ծͻᱨ��
typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}LinkNode, *LStatic;

//��ͷ���
int InitStack(LStatic* S){
    *S = (LinkNode*) malloc(sizeof(LinkNode));
    if (*S == NULL) return false;
    (*S)->next = NULL;
    return true;
}
int InitStack_NoHead(LStatic* S){
    *S = (LinkNode*) malloc(sizeof(LinkNode));
    if (*S == NULL) return false;
    (*S) = NULL;
    return true;
}

int Push(LStatic* S, int x){ 
    if (*S == NULL) return false;
    LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
    t->data = x;
    t->next = (*S)->next;
    (*S)->next = t;
    return true;
}
int Push_NoHead(LStatic* S, int x){ 
    LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
    t->data = x;
    // if ((*S)->next = NULL) {
    //     t->next = NULL;
    //     *S = t;   
    // }
    // else{
    //     t->next = *S;
    //     *S = t;
    //     return true;
    // }
    t->next = *S;
    *S = t;
    return true;

    
}

int Pop(LStatic* S, int *x){
    if ((*S)->next == NULL) return false;

    LinkNode* p = (*S)->next;
    *x = p->data;
    (*S)->next = p->next;
    free(p);
    return true;
}
int Pop_NoHead(LStatic* S, int *x){
    if ((*S) == NULL) return false; //��ջΪ��
    LinkNode* p = *S;
    *x = p->data;
    // if (p->next == NULL){
    //     (*S) = NULL;
    //     return true;
    // }
    *S = p->next;
    free(p);
    return true;
}

int GetTop(LStatic S, int *x){
    if (S->next == NULL) return false;
    *x = S->next->data;
    return true;
}
int GetTop_NoHead(LStatic S, int *x){
    if (S == NULL) return false;
    *x = S->data;
    return false;
}

void printList(LStatic S){
    LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
    t = S->next;
    while (t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    
}
void printList_NoHead(LStatic S){
    LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
    t = S;
    while (t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
    
}

int main(){
    LStatic S;
    int x;

    // ��ʼ��һ����ջ
    InitStack_NoHead(&S);

    // ѹ���һ��Ԫ�ز���ӡջ��Ԫ��
    Push_NoHead(&S, 1);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ѹ��ڶ���Ԫ�ز���ӡջ��Ԫ��
    Push_NoHead(&S, 2);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ����һ��Ԫ�ز���ӡջ��Ԫ�غ͵�����Ԫ��
    Pop_NoHead(&S, &x);
    printf("������Ԫ�أ�%d\n", x);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ѹ�������Ԫ�ز���ӡջ��Ԫ��
    Push_NoHead(&S, 3);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ����һ��Ԫ�ز���ӡջ��Ԫ�غ͵�����Ԫ��
    Pop_NoHead(&S, &x);
    printf("������Ԫ�أ�%d\n", x);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ѹ����ĸ�Ԫ�ز���ӡջ��Ԫ��
    Push_NoHead(&S, 4);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ����һ��Ԫ�ز���ӡջ��Ԫ�غ͵�����Ԫ��
    Pop_NoHead(&S, &x);
    printf("������Ԫ�أ�%d\n", x);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ѹ������Ԫ�ز���ӡջ��Ԫ��
    Push_NoHead(&S, 5);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ���ε�������Ԫ�ز���ӡջ��Ԫ�غ͵�����Ԫ��
    Pop_NoHead(&S, &x);
    printf("������Ԫ�أ�%d\n", x);
    Pop_NoHead(&S, &x);
    printf("������Ԫ�أ�%d\n", x);
    printf("ջ��Ԫ�أ�\n");
    printList_NoHead(S);
    printf("-----------\n");

    // ���Ե���ջΪ��ʱ�޷���������Ԫ�ص����
    if (!Pop_NoHead(&S, &x))
    {
        printf("��ջΪ�գ��޷���������Ԫ��\n");
    }

    system("pause");
    return 0;
}


