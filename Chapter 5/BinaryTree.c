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



//ջ�Ľṹ��
typedef struct LinkNode{
    struct BiNode* node;
    struct LinkNode* next;
}LinkNode, *LStatic;

//���нṹ��
typedef struct LinkQueue{
    LinkNode *front, *tail;
}LinkQueue;

//ջ��ʵ��
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
    l->node = (struct BiNode*)T;
    l->next = (*S)->next;
    (*S)->next = l;
    return true;
}

int Pop(LStatic* S, BiNode** p){
    if ((*S)->next == NULL) return false;
    LinkNode* n = (*S)->next;
    (*p) = (BiNode*)n->node;
    (*S)->next = n->next;
    free(n);
    return true;
}

int GetTop(LStatic S, BiNode** t){
    if (S->next == NULL) return false;
    (*t) = (BiNode*)S->next->node;
    return true;
}

int Empty_Stack(LStatic L){
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

//���е�ʵ��
int InitQueue(LinkQueue *Q){
    Q->front = Q->tail = (LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
    return true;
}
//��Ӳ���
void EnQueue(LinkQueue *Q, BiNode* t){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->node = (struct BiNode*)t;
    p->next = NULL;
    Q->tail->next = p;
    Q->tail = p;
}
//���Ӳ���
int DeQueue(LinkQueue *Q, BiNode** x){
    if (Q->front == Q->tail) return false;
    LinkNode *p = Q->front->next;
    (*x) = (BiNode*)p->node;
    Q->front->next = p->next;
    if (p == Q->tail) Q->front = Q->tail;
    p = NULL;
    free(p);
    return true;
}
int isEmpty_Queue(LinkQueue Q){
    if (Q.front == Q.tail) return true;
    else return false;
}
void printQueue(LinkQueue Q){
    LinkNode *p = Q.front;
    while (p->next != NULL){
        BiNode* t = (BiNode*)p->node;
        printf("%d<-", t->data);
        p = p->next;
    }
    printf("end\n");
}


//����һ�����ڵ�
void vist(BiNode* p){
    if (p == NULL) return;
    else printf("%d\n", p->data);
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

    BiNode *p = T;
    while (p || !Empty_Stack(L))
    {
        if (p)
        {
            Push(&L, p);
            vist(p);
            p = p->left;
        }
        else{
            Pop(&L, &p);
            p = p->right;
        }
        
    }
}
//�������
void InOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->left);
        printf("%d\n", T->data);
        PreOrder(T->right);
    }
}
//�ǵݹ�ʵ�ֵ��������
void InOrder_NoRecursion(BiTree T){
    LStatic L;
    InitStack(&L);

    if (T == NULL) return;

    BiNode *p = T;
    while (p || !Empty_Stack(L))
    {
        if (p)
        {
            Push(&L, p);
            p = p->left;
        }
        else{
            Pop(&L, &p);
            vist(p);
            p = p->right;
        }
        
    }

}
//�������
void PostOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->left);
        PreOrder(T->right);
        printf("%d\n", T->data);
    }
}
//�ǵݺ�������
void PostOrder_NoRecursion(BiTree T){
    LStatic L;
    InitStack(&L);
    BiNode *p = T; 
    BiNode *r = NULL;//�������Ϊ��ʼ��Ҷ�ӽڵ���ҽڵ�Ϊnull
    //pΪ�����ڵ�,rΪ��¼��ǰ�ڵ��Һ��ӵĸ����ڵ�
    while (p || !Empty_Stack(L))
    {
        if (p){ //�ߵ������
            Push(&L, p);
            p  = p->left;
        }
        else{
            //�Ȳ��ż���ջ����Ҫ�ж�ջ��Ԫ�ص��ҽڵ��Ƿ񱻷��ʹ������ʹ�֮��Ž��г�ջ
            GetTop(L, &p);
            if (p->right && p->right != r)  p = p->right; //��p���ҽڵ㲻Ϊ�ջ���δ�����ʹ����Ȳ����г�ջ����������Ѱ�ҿ��Գ�ջ��ֵ
            else{
                Pop(&L, &p);
                vist(p);
                r = p; //r��ֵΪp������p�ڵ���Ϣ���������ж��Ƿ��ջʱ���ϴα����rһ������p���Һ���
                p = NULL;//ֱ�ӽ����һ��else��֧
                //p����Ҫ���գ��������գ��ᵼ��ͬһ���ڵ�����ջ
                //��Ϊ��ǰ�����������У�else�ж�ִ����ȡ�Һ��Ӳ���������else��֧�е�else��֧����û�н���ȡ�ҽڵ����
            }
        }
    }
    
}

//�������(ʹ�ö���)
void LevelOrder(BiTree T){
    LinkQueue Q;

    InitQueue(&Q);
    BiNode* p = T;
    EnQueue(&Q, p);//���û����
    while (!isEmpty_Queue(Q))
    {
        DeQueue(&Q, &p);//����ûָ��null����
        vist(p);
        if (p->left != NULL){
            EnQueue(&Q, p->left);
        }
        if (p->right != NULL){
            EnQueue(&Q, p->right);
        } 
        // printQueue(Q);
    }
    
}

int main(){
    BiTree T;
    InitTree(&T);
    CreateTree(&T);
    printf("ǰ�������\n");
    // PreOrder(T);
    PreOrder_NoRecursion(T);
    printf("���������\n");
    // InOrder(T);
    InOrder_NoRecursion(T);
    printf("���������\n");
    // PostOrder(T);
    PostOrder_NoRecursion(T);
    printf("��α�����\n");
    LevelOrder(T);
    system("pause");
    return 0; 
}