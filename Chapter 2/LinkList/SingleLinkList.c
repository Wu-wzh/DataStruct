//��������Ȼ�ڲ��롢ɾ���Ȳ�����˳���ʱ�临�Ӷȸ��ͣ������ڵ�����ֻ������ָ��ָ�룬����޷������������͵������ڱ�д�����ʱ����Ҫ���⿼�����һ���ڵ�����
#include <stdio.h>
#include <windows.h>
#define true 1;
#define false 0;
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode, *LinkList;

//��ʵ��ʹ���У���Ҫʹ��ָ��ȿ���ʹ��LNode*Ҳ����ʹ��LinkeList��
//���ߵȼۣ�����һ��Ҫ����ʵ�����ʹ�����ߣ�����������һ���б�ʹ��LinkList������������һ�������Ľڵ㣬��ʹ��LNode*

//��Ϊ��ͷ�ڵ����������ͷ�ڵ�ʱ��ʹ�ò������Ӽ�[
    

//��Ҫ���������������е�*�ͺ����ڲ���*����һ����˼
//���������д������LinkList���͵�ָ�룬����LinkList������Ǹ�ָ�룬���Ժ��������е�L��һ��ָ��ָ���ָ��
//���ں����ڲ�*��������ǽ����ò������Ȼ�ȡL��ָ�����ݣ���ΪL��һ��ָ���ָ�룬����*L���ǻ�ȡL�����ݣ����Ǹ�ָ�룬Ҳ�����Ǹ�LinkList��
//�ɴ�*L��ָ����LinkList��ͨ���޸�*L�����ݣ��Ϳ���ʵ��LinkList������
int InitList(LinkList* L){
    *L = (LNode*) malloc(sizeof(LNode));
    if (*L == NULL) return false;
    (*L)->next = NULL;
    return true;
}

int InitList_NoHead(LinkList* L){
    *L = (LNode*) malloc(sizeof(LNode));
    if (*L == NULL) return false;
    *L = NULL;
    return true;
}
//ʵ�飺����ʹ��LinkList�в���
// int InitList_Test(LinkList L){ //��ΪLinkList�Ǹ�ָ�룬����L��ʵ��ָ�룬ָ���������ڵ�
//     L = (LNode*) malloc(sizeof(LNode)); //��ΪL�Ǹ�ָ�룬����ֱ�Ӹ��������ڴ� Lֻ�Ǹ��������L�ĸ���Ʒ������ں����ڲ���L�޸Ĳ�����Ӱ�촫�����L������
//     if (*L == NULL) return false;
//     (*L)->next = NULL;
//     return true;
// } //���֮����L��ȻΪNULL���������������û�г�ʼ���ɹ�

int InitList_My(LinkList* L){
    //
    *L = (LNode*) malloc(sizeof(LNode));
    if (*L == NULL) return false;
    (*L)->data = 10;
    (*L)->next = NULL;
    return true;
}

//�����ǲ���ͷ��������������
int InitList_Nohead(LinkList* L){
    *L = NULL;
    return true;
}

//�ж������Ƿ�Ϊ��
int isEmpty(LinkList L){
    // if (L->next == NULL) return true;
    // else return false;
    return L->next == NULL;
}


//�������Ľڵ�ǰ��ͺ���װ�ɺ��������������������е��ã���ߴ���ɶ��ԣ������������

//����ָ���ڵ��������з�װ
int InsertNextNode(LNode* p, int e){ 
    if (p == NULL) return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
    // //����ѭ����Ŀ����Ϊ���ҵ���i - 1���ڵ㣬������в������
    // if (p == NULL) return false; //˵����ʱ����Ϊ�գ���ͷ�ڵ㶼û��
    // LNode* s = (LNode*)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next; //������˳���ܵߵ���s���Ӻ����ʱ����Ҫͨ��p��next���ӣ�
    // p->next = s; //����Ȱ�p��next��s���ӣ��ᵼ��s�Ҳ���ԭ��p֮���Ԫ�أ�����ԭ��p֮���Ԫ�ؾͱ���ʧ��
    // //�����������������Ѿ��ҵ�λ�õ�ǰ���£��������ݵĲ���
    // return true;
    //����һ�δ����ú���InsertNextNode���з�װ��
}

//ǰ���ڵ����
/*
�����պ�̽ڵ�����˼�룬��Ҫ���ҵ�����ڵ��ǰһ���ڵ㣬�����������ڸ����Ĳ�����һ�������Ľڵ�
�������������������Ѱ��ǰ���ڵ�������鷳��һ�����еķ�������ͨ�����������������ҵ�������ڵ��ǰ���ڵ�

����һ�ּ򵥷���������������Ϊ���ڵ㣬���ǲ���ʱ���������򣬼���ʵ��ǰ�������
���ַ���ʵ���ϲ�û�����������ڵ�ǰ����һ���µĽڵ㣬�����ڽڵ������롣

����ʵ��ʹ�ò���ǰ���ڵ�Ĳ���ʱ�临�ӶȽ�ΪO(1)����װ��֮����ֱ�������������е���
*/
int InsertPriorNode(LNode* p, int e){
    if (p == NULL) return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = p->data;
    p->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//�˴�������bug�ģ����ַ�����Ҫ�õ���һ���ڵ㣬�����˽ڵ���������е����һ���ڵ�ʱ���ٽ�next�ڵ��data�����Լ��ͻ���ֿ�ָ�����
//��Ҳ���ֳ��˵������ȱ�㣬�ڴ��뿪ͷ����
int DeleteNode(LNode* p){
    if (p == NULL) return false;
    p->data = p->next->data;
    p->next = p->next->next;
    return true;
}

LNode* GetElement(LinkList L, int i){
    if (i < 0) return NULL;
    int j = 0; //��j���ڵ�
    LNode* p = L; 

    //����������Ԫ�أ�j��Ҫ��i��ͬ��λ�ã�����while��ʱj<i����j=iʱ�㲻��ִ�С�
    while (p != NULL && j < i)
    {  
        p = p->next;
        j++;
    }
    return p;
    // int j = 0; //��ǰpָ����ǵڼ����ڵ� ��Ϊp��ʼ��ָ��ͷ���ģ���ͷ�ڵ�������Ϊ��0���ڵ㣬���������������Ľڵ㣬ֻ��һ������������������ڵ㣬û��data��
    // p = *L; //��ʼʱָ��ͷ�ڵ� �����*ͬ���ǽ����ò������Ȼ��L�����ݣ����Ǵ���Ĳ����ĵ�ַ���ɴ˱����ͨ���޸�p�����ݣ��޸�L�е�����
    // while (p != NULL && j < i - 1){
    //     p = p->next;
    //     j++;
    // }
}

//��λ�����
//j���������ҵ���i���ڵ�
int ListInsert(LinkList* L, int i, int e){
    if (i < 1) return false;

    LNode* p = GetElement(*L, i - 1); //p�ǵ�i���ڵ��ǰ���ڵ�

    return InsertNextNode(p, e); //p����ľ��Ǹ�ָ�룬����Ҫȡ���ַ
}

//����ͷ��㣬�����ã�����ڴ�ͷ�����ӷ���
//���ͷ��㲻ͬ���ǣ��ڵ�һ��λ�ò����Ϊ����,��Ҫ����ָ����һ��Ԫ�أ�����Ԫ��һ�£�����j��Ҫ��1��ʼ��
int ListInsert_Nohead(LinkList* L, int i, int e){
    if (i < 1) return false;
    if (i == 1){
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = *L; //s���ͷ
        *L = s; //��L����ָ��s��������ʵ���˵�һ��Ԫ�صĲ��롣
        return true;
    }
    LNode *p; //pָ��ǰɨ�赽�Ľڵ�
    int j = 1; //��ǰpָ����ǵڼ����ڵ�
    p = *L; //��ʼʱָ��ͷ�ڵ� �����*ͬ���ǽ����ò������Ȼ��L�����ݣ����Ǵ���Ĳ����ĵ�ַ���ɴ˱����ͨ���޸�p�����ݣ��޸�L�е�����
    while (p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    //����ѭ����Ŀ����Ϊ���ҵ���i���ڵ��ǰ���ڵ㣬������в������
    if (p == NULL) return false; //˵����ʱ����Ϊ�գ���ͷ�ڵ㶼û��
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next; //������˳���ܵߵ���s���Ӻ����ʱ����Ҫͨ��p��next���ӣ�
    p->next = s; //����Ȱ�p��next��s���ӣ��ᵼ��s�Ҳ���ԭ��p֮���Ԫ�أ�����ԭ��p֮���Ԫ�ؾͱ���ʧ��
    //�����������������Ѿ��ҵ�λ�õ�ǰ���£��������ݵĲ���
    return true;
}

//��λ��ɾ��
int ListDelete(LinkList* L, int i, int *e){
    if (i < 1) return false;
    LNode* p;
    int j = 0;
    p = *L; //*�ǽ��������ã�����L�Ƕ���ָ�룬����*����֮�����LinkList��ͷ���ĵ�ַ��������p�����޸�ʱ���ֱ�������ں����ⲿ�Ĳ���

    //��Ҫ�ҵ���ɾ���ڵ��ǰ���ڵ�
    //���ǵ������ȱ�㣬����һ���ڵ��ǰ���ڵ�ֻ��ͨ�������ķ�ʽ
    //˫������ֱ�ӿ���ʹ��pirorָ������ʣ�ѭ����������Ҳ���Դ�����ڵ��Ժ���б���
    while (p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    *e = p->next->data;
    p->next = p->next->next;
    return true;
}

int ListDelete_Nohead(LinkList* L, int i, int *e){
    if (i < 1) return false;
    if (i == 1){
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s = (*L)->next;
        *L = s;
        return true;    
    }
    LNode* p;
    int j = 1;
    p = *L; //*�ǽ��������ã�����L�Ƕ���ָ�룬����*����֮�����LinkList�ĵ�ַ��������p�����޸�ʱ���ֱ�������ں����ⲿ�Ĳ���

    //�ҵ���ɾ���ڵ��ǰ���ڵ�
    while (p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    *e = p->next->data;
    p->next = p->next->next;
    return true;
}

//��ֵ���ң��ҵ�������Ϊe�Ľڵ�
LNode* LoacteElement(LinkList L, int e){
    LNode* p = L->next; //�ӵ�һ���ڵ㿪ʼ(����ͷ�ڵ�)
    while (p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

int GetLength(LinkList L){
    LNode* p = L;
    int len = 0;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
    
}


//β�巨����������
/*
����ÿ���������ֵ���ǲ���β�ڵ��ߵģ����Բ����Ԫ�ذ�ԭ�����У�������Ҫʵ�ֵ�ͷ�巨����ÿ�������Ԫ�ز��뵽ͷ�ڵ㣬��˿���ʵ����������
����㷨�Ĺؼ�����tʱ��׷��L��β�ڵ㣬��ΪҪ��¼ÿ��ѭ����L��β�ڵ㣬��˱��㷨��û�и���ָ���ڵ�����ķ���
*/
LinkList List_TailInsert(LinkList* L){
    int x;
    // *L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *t = *L; //tΪβָ�룬sΪÿ�κ������Ĳ���ڵ� �˸�ֵ����ֻ��L������t
    scanf("%d",&x);
    while (x != 666)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x; //�����������ֵx����s��data��
        t->next = s; //��s���뵽L���档����Ϊt��ʾ����L��βָ�룩
        t = s; //�ٴν�tָ��β�ڵ�
        scanf("%d",&x);
    }
    t->next = NULL; //�����β�ڵ��ָ�գ���ֹ����δ֪����
    return *L;
}

//ͷ�巨����������
/*
�����Ѿ�ʵ���˶Ե����ڵ�ĺ�����������ֻ��Ҫʹ��ѭ�����ú�������
ͷ�巨����ʵ�ֶ�һ�����е��������У�������Ŀ�о�������
*/
LinkList List_HeadInsert(LinkList* L){
    LNode* Head = *L;
    int x;
    scanf("%d", &x);
    while (x != 666)
    {
        InsertNextNode(Head, x);
        scanf("%d", &x);
    }
    return *L;
}


//���������
/*
ͨ������ͷ�巨��ʵ�����������
*/
LinkList List_Reverse(LinkList *L){
    if (!(*L) || !(*L)->next) return *L;
    LNode* Head = (LNode*)malloc(sizeof(LNode));
    Head->next = NULL; //��ֹ���ִ���
    LNode* p = (*L)->next; //ע���ʱp���Ǵ�ͷ�ڵ㿪ʼ�ģ����Ǵӵ�һ���ڵ㿪ʼ����Ϊwhileѭ������Ҫֱ�ӽ��в���
    while (p != NULL)
    {
        InsertNextNode(Head, p->data);
        p = p->next;
    }
    return Head;
    
}
void printList(LinkList L, int signal){
    LNode *p;
    p = L;
    if (signal) p = p->next;
    while (p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    
}

//��һ�⣬�ݹ�ɾ������ֵΪx�Ľڵ�(����ͷ�ڵ�)
void T1_Delete_Recursion(LinkList *L, int e){
    LNode *p = *L;
    if (p == NULL) return;
    if (p->data == e){
        *L = p->next;
        free(p);
        T1_Delete_Recursion(L, e);
    }
    else
        T1_Delete_Recursion(&((*L)->next), e);
}

int main(){
    int Del_1;
    LinkList L = NULL;
    InitList_NoHead(&L);
    ListInsert_Nohead(&L, 1, 2);
    ListInsert_Nohead(&L, 2, 3);
    ListInsert_Nohead(&L, 3, 2);
    ListInsert_Nohead(&L, 4, 10);
    ListInsert_Nohead(&L, 5, 2);
    ListInsert_Nohead(&L, 6, 6);
    // ListDelete(&L, 1, &Del_1);
    // printList(List_TailInsert(&L), 1);
    printList(L, 0);
    printf("==========\n");
    T1_Delete_Recursion(&L, 2);
    printList(L, 0);
    // printList(List_Reverse(&L), 1);
    // printf("%d\n",GetElement(L, 3)->data);
    // printf("%d\n",LoacteElement(L, 3)->data);
    // printf("%d\n",GetLength(L));
    system("pause");
    return 0;
}

