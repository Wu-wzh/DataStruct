//������������ȫ����������Ƶ���㣩��ƽ��������Ƕ���״��Ҫ���������ȫ��������ʵ�������������Ӽ�
//������������һ�ֽڵ���Ҫ�������������������Խ�ӽ�ƽ���������������Ч��Խ��

#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0

typedef struct node
{
    int data;
    struct node *left, *right;
}BiNode, *BiTree;

void InitTree(BiTree *T){
    (*T) = NULL;
}

//ջ��ʵ��

typedef struct LinkNode{
    struct BiNode* node;
    struct LinkNode* next;
}LinkNode, *LStatic;

//��ͷ���
int InitStack(LStatic* S){
    *S = (LinkNode*) malloc(sizeof(LinkNode));
    if (*S == NULL) return false;
    (*S)->next = NULL;
    return true;
}

int Push(LStatic* S, BiNode* T){ 
    if (*S == NULL) return false;
    LinkNode* l = (LinkNode*)malloc(sizeof(LinkNode));
    l->node = (BiNode*)T;
    l->next = (*S)->next;
    (*S)->next = l;
    return true;
}

BiNode* Pop(LStatic* S){
    if ((*S)->next == NULL) return false;
    BiNode *t;
    LinkNode* p = (*S)->next;
    t = (BiNode*)p->node;
    (*S)->next = p->next;
    free(p);
    return t;
}

BiNode* GetTop(LStatic S){
    BiNode* t;
    if (S->next == NULL) return false;
    t = (BiNode*)S->next->node;
    return t;
}

int Empty(LStatic L){
    return L->next == NULL;
}
void printStack(LStatic S){
    LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
    t = S->next;
    while (t != NULL)
    {
        //��Ҫ��ʼ��������ֱ����t->node->data
        BiNode* x = (BiNode*)t->node;
        printf("%d\n",x->data);
        t = t->next;
    }
    
}

//ʹ�ö���ָ�뽨����
void CreateTree(BiTree *T){
    int data;
    scanf("%d", &data);
    if (data < 0) (*T) = NULL;
    //���еݹ����
    else{
        (*T) = (BiTree)malloc(sizeof(BiNode));
        (*T)->data = data;
        CreateTree(&((*T)->left));
        CreateTree(&((*T)->right));
    }
}

//��ʹ�ö���ָ�룬ʹ�÷���ֵ�ķ�ʽ����
BiTree CreateTree_1(BiTree T){
    int data;
    scanf("%d", &data);
    if (data < 0) return NULL;
    //���еݹ����
    else{
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = data;
        T->left = CreateTree_1(T->left);
        T->right = CreateTree_1(T->right);
    }
    return T;
}


//ǰ�����
void PreOrder(BiTree T){
    if (T != NULL){
        printf("%d\n", T->data);
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

//�ǵݹ�ʵ�ֵ�ǰ�����
void PreOrder_NoRecursion(BiTree T){
    LStatic L;
    InitStack(&L);

    if (T == NULL) return;

    BiNode *s = T;
    //�����е���������ջ
    while (s != NULL)
    {
        printf("%d\n",s->data);
        Push(&L, s);
        s = s->left;
    }

    //������������ͬ���Ĳ��ԣ�ֱ����ջΪ��
    while (!Empty(L))
    {
        BiNode* top = GetTop(L);
        BiNode* t = top->right;
        Pop(&L);
        while (t != NULL)
        {
            printf("%d\n",t->data);
            Push(&L, t);
            t = t->left;
        }
    }
    

    // printStack(L);

}

//�������
void InOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->left);
        printf("%d\n", T->data);
        PreOrder(T->right);
    }
}
//�ǵݹ�ʵ�ֵ�ǰ�����
void InOrder_NoRecursion(BiTree T){
    LStatic L;
    InitStack(&L);

    if (T == NULL) return;

    BiNode *s = T;
    //�����е���������ջ
    while (s != NULL)
    {
        Push(&L, s);
        s = s->left;
    }

    //������������ͬ���Ĳ��ԣ�ֱ����ջΪ��
    while (!Empty(L))
    {
        BiNode* top = GetTop(L);
        BiNode* t = top->right;
        BiNode* x = Pop(&L);
        printf("%d\n",x->data);
        while (t != NULL)
        {
            Push(&L, t);
            t = t->left;
        }
    }
    

    // printStack(L);

}
//�������
void PostOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->left);
        PreOrder(T->right);
        printf("%d\n", T->data);
    }
}



int main(){
    BiTree T;
    InitTree(&T);
    CreateTree(&T);
    // printf("ǰ�������\n");
    InOrder_NoRecursion(T);
    // printf("���������\n");
    // InOrder(T);
    // printf("���������\n");
    // PostOrder(T);
    system("pause");
    return 0;
}