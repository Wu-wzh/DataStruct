#include <stdio.h>
#include <windows.h>
#define true 1;
#define false 0;

//�������ֵļӼ��˳�����
typedef struct LinkNode_C{
    char str;
    struct LinkNode_C* next;
}LinkNode_C, *LStatic_C;

typedef struct LinkNode_N{
    float num;
    struct LinkNode_N* next;
}LinkNode_N, *LStatic_N;

int InitStack_C(LStatic_C* S){
    *S = (LinkNode_C*) malloc(sizeof(LinkNode_C));
    if (*S == NULL) return false;
    (*S)->next = NULL;
    return true;
}
int InitStack_N(LStatic_N* S){
    *S = (LinkNode_N*) malloc(sizeof(LinkNode_N));
    if (*S == NULL) return false;
    (*S)->next = NULL;
    return true;
}

int Push_C(LStatic_C* S, char x){ 
    if (*S == NULL) return false;
    LinkNode_C* t = (LinkNode_C*)malloc(sizeof(LinkNode_C));
    t->str = x;
    t->next = (*S)->next;
    (*S)->next = t;
    return true;
}
int Push_N(LStatic_N* S, float x){ 
    if (*S == NULL) return false;
    LinkNode_N* t = (LinkNode_N*)malloc(sizeof(LinkNode_N));
    t->num = x;
    t->next = (*S)->next;
    (*S)->next = t;
    return true;
}
char Pop_C(LStatic_C* S){
    char x;
    if ((*S)->next == NULL) return 'f';

    LinkNode_C* p = (*S)->next;
    x = p->str;
    (*S)->next = p->next;
    free(p);
    return x;
}
float Pop_N(LStatic_N* S){
    float x;
    if ((*S)->next == NULL) return 666;

    LinkNode_N* p = (*S)->next;
    x = p->num;
    (*S)->next = p->next;
    free(p);
    return x;
}

char GetTop_C(LStatic_C S){
    char x;
    if (S->next == NULL) return 'f';
    x = S->next->str;
    return x;
}
float GetTop_N(LStatic_N S){
    float x;
    if (S->next == NULL) return 666;
    x = S->next->num;
    return x;
}

void printStatic_C(LStatic_C S){
    LinkNode_C* t = (LinkNode_C*)malloc(sizeof(LinkNode_C));
    t = S->next;
    while (t != NULL)
    {
        printf("%c\n",t->str);
        t = t->next;
    }
    
}

void printStatic_N(LStatic_N S){
    LinkNode_N* t = (LinkNode_N*)malloc(sizeof(LinkNode_N));
    t = S->next;
    while (t != NULL)
    {
        printf("%f\n",t->num);
        t = t->next;
    }
    
}
int isEmpty_C(LStatic_C S){
    return S->next == NULL;
}
int isEmpty_N(LStatic_N S){
    return S->next == NULL;
}

float Two_Number(LStatic_N *SI, char operator){
    if (operator == '+'){
        float back = Pop_N(SI);
        float front = Pop_N(SI);
        Push_N(SI, back + front);
        return true;
    }
    if (operator == '-'){
        float back = Pop_N(SI);
        float front = Pop_N(SI);
        Push_N(SI, front - back);
        return true;
    }
    if (operator == '*'){
        float back = Pop_N(SI);
        float front = Pop_N(SI);
        Push_N(SI, front * back);
        return true;
    }
    if (operator == '/'){
        float back = Pop_N(SI);
        float front = Pop_N(SI);
        Push_N(SI, front / back);
        return true;
    }
    
}

int Calculate(char str[]){
    LStatic_C SC;
    LStatic_N SI;
    InitStack_C(&SC);
    InitStack_N(&SI);
    for (int i = 0; i<strlen(str); i++){

        //������ѹ�������ջ
        if (str[i] == '(')
            Push_C(&SC, str[i]);
        if (str[i] == ')'){
            while (GetTop_C(SC) != '(')
                Two_Number(&SI, Pop_C(&SC));
            Pop_C(&SC);
        }
        //����ѹ�������ջ
        if (str[i] >=48 && str[i] <= 57)
        {
            Push_N(&SI, (int)str[i] - 48);
        }
        //��ǰ�����Ϊ�Ӽ������ʱ
        if (str[i] == '-' || str[i] == '+'){
            //��������ջΪ�գ���ֱ�ӽ��������ѹ��ջ
            if (GetTop_C(SC) == 'f')
                Push_C(&SC, str[i]);
            
            //����Ϊ�գ��鿴ջ�ڵ�������Ƿ�ȵ�ǰ������ȼ��߻�����ͬ(�ԼӼ��������˵��+��-��*��/)��
            //�����з������������γ�ջ���Ҷ�Ӧ�ڲ�����ջ���в��� Ҫע�⵽������֮�󣬱㲻�ܼ�����ջ
            else{
                while (GetTop_C(SC) != 'f' && GetTop_C(SC) != '(')
                    Two_Number(&SI, Pop_C(&SC));
                Push_C(&SC, str[i]);
            }
        }
        if (str[i] == '*' || str[i] == '/'){
            //��������ջΪ�գ���ֱ�ӽ��˲�����ѹ��ջ
            if (GetTop_C(SC) == 'f')
                Push_C(&SC, str[i]);
            //����Ϊ�գ��鿴ջ�ڵ�������Ƿ�ȵ�ǰ������ȼ��ͻ�����ͬ ���ڳ˳����������Ҫ���в����Ľ��˳�������˲��ÿ������ŵ�����
            else{     
                while (GetTop_C(SC) == '*' || GetTop_C(SC) == '/')
                    Two_Number(&SI, Pop_C(&SC));
                Push_C(&SC, str[i]);
            }
        }
        printf("��%d��ջ�����\n", i);
        printf("�����ջ��\n");
        printStatic_C(SC);
        printf("������ջ��\n");
        printStatic_N(SI);
        printf("==============\n");
    }
    //ѭ����ɺ󣬽����������ջ�е�ȫ��Ԫ�س�ջ�������ڲ�����ջ�н��в���
    while (GetTop_C(SC) != 'f')
    {
        Two_Number(&SI, Pop_C(&SC));
        Two_Number(&SI, Pop_C(&SC));
    }
    printf("%f\n", GetTop_N(SI));
    // printStatic_C(SC);
    // printStatic_N(SI);
}

int main(){
    char str[] = "3/6*(1+2)*3";
    Calculate(str);

    system("pause");
    return 0;
}
