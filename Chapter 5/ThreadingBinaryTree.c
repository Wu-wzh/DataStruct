#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0

//����������������ջ�洢�ṹ�����ÿ��򣬱��浱ǰ�ڵ��ǰ���ڵ�ͺ�̽ڵ�
//���Ը���ķ���ǰ���ͺ�̣��Լ�������һ���ڵ㿪ʼ����
//���������������Ĺ��챾�����Ƕ�������ȱ����㷨�ĸ��죬�������õĽ��в���
typedef struct node
{
    int data;
    struct node *left, *right;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

//��������ȫ�ֱ���������������
ThreadNode *p; //���������Ľڵ�
ThreadNode *pre = NULL; //Ѱ�ҹ����м�¼��ǰ���ڵ�
ThreadNode *final = NULL; //p�ڵ��ǰ���ڵ�

//ʹ�ö���ָ�뽨����
void CreateTree(ThreadTree *T){
    int data;
    scanf("%d", &data);
    if (data < 0) (*T) = NULL;
    //���еݹ����
    else{
        (*T) = (ThreadNode*)malloc(sizeof(ThreadNode));
        (*T)->data = data;
        (*T)->ltag =0;
        (*T)->rtag =0;
        CreateTree(&((*T)->left));
        CreateTree(&((*T)->right));
    }
}

void vist(ThreadNode* p){
    if (p == NULL) return;
    else printf("%d\n", p->data);
}

//�䱾���Ͼ���һ���������̣�����ͨ��������vist�����У���Ӽ�¼ǰ��̽ڵ㲢����tagֵ�Ĳ���
void InThread(ThreadTree *T, ThreadNode **pre){
    //�������������е���ʱ��pre��Ҫ���뺯��֮���ٴ���ʱ���иı䣬���ʹ�ö���ָ��
    ThreadNode *t = *T;
    if (t != NULL){
        InThread(&(t->left), pre); //�ݹ����������



        //һ�´���ζ�Ӧ���������е�vist���������ǲ����Ǵ�ӡ�ýڵ㣬���ǽ����������Ľ�����pre�ĸ��²���
        if (t->left == NULL){
            t->left = *pre;
            t->ltag = 1;
        } //�˴η��ʵ�����Ϊ�գ���˵���ҵ�����Ҫ������������Ԫ�أ�����Ԫ�ص�����ָ��ָ���ϴη��ʵĽڵ㣬��Ϊ����ǰ���ڵ�
        if ((*pre) != NULL && (*pre)->right == NULL){  //&&�����ʣ���ǰ�治���㣬�����жϺ��棬���Բ��õ���preΪnull���·������󣡣�
            (*pre)->right = t;
            (*pre)->rtag = 1;
        }//���ϴη��ʵ�pre�ڵ㲻�ǿգ�����pre���Һ����ǿգ�����η��ʵ�Ԫ��Ϊpre�ĺ�̽ڵ㣬���и�ֵ����
        //ִ��������Ĳ���֮��Ϊ��һ�β�����׼��
        //���ȶ�pre���и���
        *pre = t;



        InThread(&(t->right), pre);//�ݹ����������
    }
} //Ҫע��������̲��ǶԳƵģ�����ʵ�ֶ�һ���ڵ������������������ʵ�ֶ����һ���ڵ����������������������е��õ�ʱ����Ҫ�����һ���ڵ�������⴦��


void CreateInThread(ThreadTree *T){
    ThreadNode * pre = NULL;
    if (T != NULL){
        InThread(T, &pre);
        //�����һ���ڵ�����ر���
        /*Ҫע���ʱpreָ�����������������һ���ڵ㣬����ڵ�һ����Ҷ�ӽڵ㣬
        Ҳ����һ��û���Һ��ӣ����Բ���Ҫ�ж��Һ����Ƿ�Ϊ�գ�ֱ�ӽ��Һ��Ӹ�ֵΪnull�Ϳ���*/
        pre->right = NULL;
        pre->rtag = 1;
    }
}


//�䱾���Ͼ���һ���������̣�����ͨ��������vist�����У���Ӽ�¼ǰ��̽ڵ㲢����tagֵ�Ĳ���
void PreThread(ThreadTree *T, ThreadNode **pre){
    //�������������е���ʱ��pre��Ҫ���뺯��֮���ٴ���ʱ���иı䣬���ʹ�ö���ָ��
    ThreadNode *t = *T;
    if (t != NULL){
        
        //һ�´���ζ�Ӧ���������е�vist���������ǲ����Ǵ�ӡ�ýڵ㣬���ǽ����������Ľ�����pre�ĸ��²���
        if (t->left == NULL){
            t->left = *pre;
            t->ltag = 1;
        } //�˴η��ʵ�����Ϊ�գ���˵���ҵ�����Ҫ������������Ԫ�أ�����Ԫ�ص�����ָ��ָ���ϴη��ʵĽڵ㣬��Ϊ����ǰ���ڵ�
        if ((*pre) != NULL && (*pre)->right == NULL){  //&&�����ʣ���ǰ�治���㣬�����жϺ��棬���Բ��õ���preΪnull���·������󣡣�
            (*pre)->right = t;
            (*pre)->rtag = 1;
        }//���ϴη��ʵ�pre�ڵ㲻�ǿգ�����pre���Һ����ǿգ�����η��ʵ�Ԫ��Ϊpre�ĺ�̽ڵ㣬���и�ֵ����
        //ִ��������Ĳ���֮��Ϊ��һ�β�����׼��
        //���ȶ�pre���и���
        *pre = t;
        //����vist����ǰ�棬ǰ�����


        if (t->ltag == 0) PreThread(&(t->left), pre); 
        /*�ݹ����������,Ҫע���������������vist������˳�����⣬������ͺ���������ʱ�����ڷ���������ʼ����vist����ǰ
        ��˲����ܳ��ֶԽڵ����vist����֮����Ž��иýڵ��������������
        ��ǰ�������ͬ�������п��ܽ���vist����֮�󣬼��������Լ����������ģ��������ڽ���vist����֮�󣬴˽ڵ�������п���ָ�����Լ���ǰ���ڵ�
        ����������������ڵ�֮��һֱ�ظ����ʣ������Ҫ�õ�ltag��ʶ������������ڵ���������������������ӻ�������ǰ���ڵ㣬ֻ����������������ʱ�Ž����������ķ���*/
        PreThread(&(t->right), pre);//�ݹ����������
    }
} //Ҫע��������̲��ǶԳƵģ�����ʵ�ֶ�һ���ڵ������������������ʵ�ֶ����һ���ڵ����������������������е��õ�ʱ����Ҫ�����һ���ڵ�������⴦��


void CreatePreThread(ThreadTree *T){
    ThreadNode * pre = NULL;
    if (T != NULL){
        PreThread(T, &pre);
        //�����һ���ڵ�����ر���
        /*Ҫע���ʱpreָ�����ǰ����������һ���ڵ㣬����ڵ㲻һ����Ҷ�ӽڵ㣬
        ������Ҫ�ж����һ���ڵ���Һ����Ƿ�Ϊ�գ����Һ���Ϊ���Һ��Ӹ�ֵΪnull�Ϳ���*/
        if (pre->right == NULL){
            pre->right = NULL;//���Բ���������������Ϊ��Ϊ�˺����򱣳�ͳһ
            pre->rtag = 1;  
        }
        
    }
}



void PostThread(ThreadTree *T, ThreadNode **pre){
    //�������������е���ʱ��pre��Ҫ���뺯��֮���ٴ���ʱ���иı䣬���ʹ�ö���ָ��
    ThreadNode *t = *T;
    if (t != NULL){
        
        PostThread(&(t->left), pre); //�ݹ����������

        PostThread(&(t->right), pre);//�ݹ����������



        //һ�´���ζ�Ӧ���������е�vist���������ǲ����Ǵ�ӡ�ýڵ㣬���ǽ����������Ľ�����pre�ĸ��²���
        if (t->left == NULL){
            t->left = *pre;
            t->ltag = 1;
        } //�˴η��ʵ�����Ϊ�գ���˵���ҵ�����Ҫ������������Ԫ�أ�����Ԫ�ص�����ָ��ָ���ϴη��ʵĽڵ㣬��Ϊ����ǰ���ڵ�
        if ((*pre) != NULL && (*pre)->right == NULL){  //&&�����ʣ���ǰ�治���㣬�����жϺ��棬���Բ��õ���preΪnull���·������󣡣�
            (*pre)->right = t;
            (*pre)->rtag = 1;
        }//���ϴη��ʵ�pre�ڵ㲻�ǿգ�����pre���Һ����ǿգ�����η��ʵ�Ԫ��Ϊpre�ĺ�̽ڵ㣬���и�ֵ����

        //ִ��������Ĳ���֮��Ϊ��һ�β�����׼��
        //���ȶ�pre���и���
        *pre = t;
        //����vist��������棬�������
    }
} //Ҫע��������̲��ǶԳƵģ�����ʵ�ֶ�һ���ڵ������������������ʵ�ֶ����һ���ڵ����������������������е��õ�ʱ����Ҫ�����һ���ڵ�������⴦��


void CreatePostThread(ThreadTree *T){
    ThreadNode * pre = NULL;
    if (T != NULL){
        PostThread(T, &pre);
        //�����һ���ڵ�����ر���
        /*Ҫע���ʱpreָ����Ǻ�����������һ���ڵ㣬����ڵ㲻һ����Ҷ�ӽڵ㣬
        ������Ҫ�ж����һ���ڵ���Һ����Ƿ�Ϊ�գ����Һ���Ϊ���Һ��Ӹ�ֵΪnull�Ϳ���*/
        if (pre->right == NULL){
            pre->right = NULL;//���Բ���������������Ϊ��Ϊ�˺����򱣳�ͳһ
            pre->rtag = 1;  
        }
        
    }
}


//���������������ı���


//���ȷ�װ������Ҫ���������ض��ڵ��ǰ������ǰ�������ĵ�һ���ڵ㣬����������֮�󣬱㲻��ÿ�ν��б�����ô����Ѱ����
ThreadNode *FirstNode(ThreadNode *p){
    while (p->ltag == 0) p = p->left;
    return p;
}
//��ȡ��һ�������ڵ������ֱ�����ʽ�ж���һ��

ThreadNode *NextNode(ThreadNode *p){

    //���ҽڵ㲻�Ǻ�̽ڵ㣬��Ѱ���������е�һ�����ʵ�Ԫ�أ���Ϊ�˽ڵ�ĺ�̽ڵ�
    //��Ѱ����������һ�����ʵ�Ԫ�ر�ɵ��������FirstNode����
    if (p->rtag == 0) return FirstNode(p->right);

    //���ҽڵ���Ǻ�̽ڵ㣬ֱ�ӷ��ؼ���
    else return p->right;
}

//��װ��������������֮�󣬱����ͨ��һ��forѭ�����ӵ�һ�������ڵ㿪ʼ
//�����ϵ���nextnode������ֱ��pΪ��(��������Ԫ������ָ���Ϊ�գ������Ѿ����͹�Ϊʲô)��
void InOrder(ThreadNode *T){
    for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
        vist(p);
}

//������ͬ���߼�ʵ��������������������ı���
ThreadNode *LastNode(ThreadNode *p){
    while (p->rtag == 0) p = p->right;
    return p;
}
//��ȡ��һ�������ڵ������ֱ�����ʽ�ж���һ��

ThreadNode *PreNode(ThreadNode *p){

    //���ҽڵ㲻�Ǻ�̽ڵ㣬��Ѱ���������е�һ�����ʵ�Ԫ�أ���Ϊ�˽ڵ�ĺ�̽ڵ�
    //��Ѱ����������һ�����ʵ�Ԫ�ر�ɵ��������FirstNode����
    if (p->ltag == 0) return LastNode(p->left);

    //���ҽڵ���Ǻ�̽ڵ㣬ֱ�ӷ��ؼ���
    else return p->left;
}

//��װ��������������֮�󣬱����ͨ��һ��forѭ�����ӵ�һ�������ڵ㿪ʼ
//�����ϵ���nextnode������ֱ��pΪ��(��������Ԫ������ָ���Ϊ�գ������Ѿ����͹�Ϊʲô)��
void RevInOrder(ThreadNode *T){
    for (ThreadNode* p = LastNode(T); p != NULL; p = PreNode(p))
        vist(p);
}


int main(){
    ThreadTree T;
    CreateTree(&T);
    CreateInThread(&T);
    InOrder(T);
    printf("==============\n");
    RevInOrder(T);
    system("pause");
    return 0;
}