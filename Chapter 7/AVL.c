#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0

typedef struct AVLNode
{
    int data;
    int balance; //ƽ���������ƽ������
    struct AVLNode *left, *right;
}AVLNode, *AVLTree;

//�������
void InOrder(AVLTree T){
    if (T != NULL){
        InOrder(T->left);
        printf("%d\n", T->data);
        InOrder(T->right);
    }
}
//����������ʵ�֣�����BSTNode��ָ��
//�ǵݹ���ҿռ临�Ӷ�ΪO(1)
AVLNode *BST_Search(AVLTree T, int key){
    AVLNode *p = T;
    while (p != NULL && key != p->data){
        if (key < p->data) p = p->left; //���˽ڵ�С��key���ɶ����������Ķ��壬��˽ڵ������Ѱ��
        else p = p->right; //����������Ѱ��
    }
    return T;
}

//�ݹ���� �ռ临�Ӷ�ΪO(h)
AVLNode *BST_Search_R(AVLTree T, int key){}

//ƽ�ܶ������Ĳ��������������ͨ�����������Ĳ���֮�󣬻�ʹ�ö���������ƽ�⣬�����Ҫ�ٽ�һ������ƽ�⻯

//�ݹ�ʵ��
int BST_Insert(AVLTree *T, int key){
    if ((*T) == NULL){
        (*T) = (AVLTree)malloc(sizeof(AVLNode));
        (*T)->data = key;
        (*T)->left = (*T)->right = NULL;
        return 1;
    }
    else if ((*T)->data == key) return 0; //�������������Ѿ������˴˽ڵ�
    else if (key < (*T)->data) return BST_Insert(&((*T)->left), key); //keyС�ڴ˽ڵ㣬Ӧ���ڴ˽ڵ�����Ӳ���
    else if (key > (*T)->data) return BST_Insert(&((*T)->right), key); //key���ڴ˽ڵ㣬Ӧ���ڴ˽ڵ���Һ��Ӳ���
}

//��������ɾ�����̣�����ڲ��������Ϊ���ӣ���Ҫ���ֶ�����
/*
1.��ɾ�������Ҷ�ӽڵ㣬ֱ��ɾ������
2.��ɾ�����ֻ��һ������������������ɾ���˽ڵ�֮�����������ĸ��ڵ�����Լ�
3.��ɾ����㼴����������������������ӣ��ж��ֲ��ԣ�����ѧϰƽ�������֮�󣬻�����õĲ��ԡ�
���ҵ��˽ڵ�����������С�Ľڵ㣨����ߣ�
���ҵ��˽ڵ������������Ľڵ㣨���ұߣ�
*/

//�����������Ľ������̣���str��������һ���в������
void Create_BST(AVLTree *T, int str[], int n){
    (*T) = NULL;
    int i = 0;
    while (i < n){
        BST_Insert(T, str[i]);
        i++;
    }
}
//�����ϵĶ����������Ľ������̿��Կ�������ѯ������ʱ�临�Ӷ�ȡ���ڶ����������ĸ߶ȣ��������ö����������Ĳ����ٶȸ��죬
//��������ø���"ƽ��"���ɴ�����ƽ��������ĸ��
int main(){
    AVLTree T;
    int str[8] = {50, 66, 60, 26, 21, 30, 70, 68};
    Create_BST(&T, str, 8);
    InOrder(T);
    system("pause");
    return 0; 
}