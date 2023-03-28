//�ַ����൱�ں����Ķ����򣬶���������൱�ں���ӳ��
#include <stdio.h>
#include <windows.h>

#define true 1
#define false 0
#define MaxSize 255


//�ճ���һ��Ԫ�أ�ʹ���±�ʹ��ַ�����Ŷ�Ӧ��
typedef struct {
    char ch[MaxSize];
    int length;
}SString;


//��ֵ����
int StrAssign(SString *S, char chars[]){
    int i;
    for (i = 0; chars[i] != '\0'; i++){
        if (i + 2 == MaxSize) return false;
        S->ch[i + 1] = chars[i];
    }
    S->length = i + 1;
    return true;
}

void StrCopy(SString *T, SString S){
    for (int i = 0; i < S.length; i++){
        T->ch[i] = S.ch[i];
    }
    T->length = S.length;
}

int StrLength(SString S){
    return S.length;
}

void ClearString(SString *S){
    S->length = 0;
}

void DestoryString(SString *S){
    free(S);
    S = NULL;
}

int Concat(SString *S, char S1[], char S2[]){
    int i, j;
    for (i = 0; S1[i] != '\0'; i++)
        S->ch[i + 1] = S1[i];
    S->length = i + 1;
    for (j = 0; S2[j] != '\0'; j++)
        S->ch[S->length + j] = S2[j];
    S->length += j;
    return true;
}

void printStr(SString S){
    for (int i = 1; i < S.length; i++){
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

int main(){
    SString S, T;

    // ��ֵ����
    char chars[] = "wuzihaoasdds";
    StrAssign(&S, chars);
    printf("S: ");
    printStr(S); // �����wuzihaoasdds

    // ���Ʋ���
    StrCopy(&T, S);
    printf("T: ");
    printStr(T); // �����wuzihaoasdds

    // �󴮳�����
    printf("S Length: %d\n", StrLength(S)); // �����13

    // ��ղ���
    ClearString(&S);
    printf("S: ");
    printStr(S); // �����

    // ���ٲ���
    DestoryString(&T);
    // printf("T: ");
    // printStr(T); // �˴������ѱ����ٵ� T�����ܻᵼ���쳣

    // ���Ӳ���
    Concat(&S, "wuzi", "haohaha");
    printf("S: ");
    printStr(S); // �����wuzihaohaha

    system("pause");
    return 0;
    
}