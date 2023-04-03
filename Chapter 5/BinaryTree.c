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

int main(){
    BiTree T;
    InitTree(&T);
    CreateTree(&T);
    PreOrder(T);
    system("pause");
    return 0;
}