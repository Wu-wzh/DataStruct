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
    S->length = i;
    return true;
}

void StrCopy(SString *T, SString S){
    for (int i = 0; i < S.length + 1; i++){
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
    S = NULL;
    free(S);
    
}

int Concat(SString *S, char S1[], char S2[]){
    int i, j;
    for (i = 0; S1[i] != '\0'; i++)
        S->ch[i + 1] = S1[i];
    S->length = i;
    for (j = 0; S2[j] != '\0'; j++)
        S->ch[S->length + 1 + j] = S2[j];
    S->length += j;
    return true;
}

int SubString(SString *Sub, SString S, int pos, int len){
    if (pos + len - 1 > S.length) return false;
    for (int i = pos; i < pos + len; i++){
        Sub->ch[i - pos + 1] = S.ch[i];
    }
    Sub->length = len;
    return true;
}

int StrCompare(SString S, SString T){
    for (int i = 0; i <= S.length && i <= T.length; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.length - T.length;
}


//����
int Index(SString S, SString T){
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i < n - m + 1)
    {
        SubString(&sub, S, i, m);
        if (StrCompare(S,sub) != 0) i++;
        else return i;
    }
    return 0;
}

//���������ʺ�С�ַ���ƥ�䣬���Ľϴ�Ŀռ�
int NaviePatternMatching(SString S, SString T){
    int i, j = 1; //i��j�ֱ�Ϊ����S��ģʽ��T��ָ��
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j]){
            i++; j++;
        }
        else{
            i = i - j + 2; //��ƥ��ʧ�ܣ���i����Ϊ�����е���һ����Ҫ��ģʽ��ƥ��Ĵ��ĳ�ʼλ��
            j = 1; //j����Ϊ1
        }
    }
    if (j > T.length) return i - T.length; //wihleѭ��������������jԽ�磬�ȳɹ�ƥ�䣬����iԽ�磬j<T.length��û��ƥ��ɹ�
    else return 0;
    
}

//KMP�㷨Ϊ����ģʽƥ��ĸĽ�����ƥ������У�j����ʱ�����ƹ���Ԫ��˵���Ѿ��ɹ�ƥ�䣬���i��ֵ����Ҫһ��һ�����ƶ�
//KMP�㷨���������ģʽ����Ϣ����Сƥ����� ������ģʽƥ����ȣ�iָ�벻��Ҫ���ݣ����Ǻ���Ҫ��
//ģʽ������Ϣ������һ������next���洢�������㷨�Ĺؼ�����ģʽ����next�������Ϣ
int KMP(SString S, SString T){

    //��next����
    int next[T.length + 1];
    next[1] = 0; 
    //�����κ�ģʽ������next[1]����0���ȵ�һ��Ԫ�ؾͲ�ƥ��ʱ��ֱ�ӽ�j��Ϊ0��Ȼ��i��jͬʱ��һ���������ĺô����ô����ø����
    next[2] = 1;
    //�����κ�ģʽ������next[2]����1



    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 | S.ch[i] == T.ch[j]){ //next�����е�j=0�������Ϊ���⣬Ϊ�˴������ʽͳһ����j��Ϊ0��Ȼ��ijͬʱ��һ
            i++; j++;
        }
        else
            j = next[i]; //�˲��ǹؼ���Ҳ��������ģʽƥ�����Ĳ�ͬ�����������Ż���ı���
    }
    if (j > T.length) return i - T.length;
    else return 0;  
}
//ʱ�临�Ӷȴﵽ��O(m+n)

void printStr(SString S){
    for (int i = 1; i < S.length + 1; i++){
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

int main(){
    SString S, T;

    // ��ֵ����
    char s1[] = "wuzihaoasdds";
    StrAssign(&S, s1);
    char sub[] = "uzi"; 
    StrAssign(&T, sub);
    // printf("S: ");
    // printStr(S); // �����wuzihaoasdds

    // // ���Ʋ���
    // StrCopy(&T, S);
    // printf("T: ");
    // printStr(T); // �����wuzihaoasdds

    // // �󴮳�����
    // printf("S Length: %d\n", StrLength(S)); // �����13

    // // ��ղ���
    // ClearString(&S);
    // printf("S: ");
    // printStr(S); // �����

    // // ���ٲ���
    // DestoryString(&T);
    // // printf("T: ");
    // // printStr(T); // �˴������ѱ����ٵ� T�����ܻᵼ���쳣

    // // ���Ӳ���
    // Concat(&S, "wuzi", "haohaha");
    // printf("S: ");
    // printStr(S); // �����wuzihaohaha
    // SString Sub;
    // SubString(&Sub, S, 3, 2);
    // printStr(Sub);
    // printf("%d\n",StrCompare(S, T));
    printf("%d\n", NaviePatternMatching(S, T));
    system("pause");
    return 0;
    
}
