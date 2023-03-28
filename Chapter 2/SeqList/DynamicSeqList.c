/*
����ȫ�Ϻ��淶��C���Դ��룬�ڽ��д���������ʱ��ʹ����c++�е�&���ã���û��ʹ��C�����еĵ�ַ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define InitSize 10
#define true 1
#define false 0

//SeqList�а��������ݱ���ͬʱ�������������MaxSize����������length
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;

//��ʼ�����Ա�,�������ʼԪ��ȫΪ0
void InitList(SeqList* L){
    L->data = (int*)malloc(InitSize * sizeof(int));
    for  (int i = 0; i < InitSize; i++)
        L->data[i] = 0;
    L->length = 0;
    L->MaxSize = InitSize;
}

//�������Ա����ݵĴ�СΪlen,ʱ�临�Ӷ�ΪO(n)
void IncreaseSize(SeqList *L, int len){
    int *p = L->data;
    L->data =(int *)malloc((L->MaxSize + len) * sizeof(int));
    for (int i = 0; i < L->length; i++)
        L->data[i] = p[i];
    L->MaxSize = L->MaxSize + len;
    free(p);
}
void InitList_Line(SeqList *L, int len){
    L->data = (int*)malloc(InitSize * sizeof(int));
    int temp = 1;
    for  (int i = 0; i < len; i++)
        L->data[i] = temp++;
    L->length = len;
    L->MaxSize = InitSize;
}
//���Ա�Ĳ���
/*
i��λ�򣬴�1��ʼ�����������±��0��ʼ
forѭ����ִ�еĲ���Ϊ����i���Ժ��Ԫ�ؽ��к���
��>= i�� :forѭ���ڵĲ����Ǻ�һ����ֵ��ǰһ����������һ�θ�ֵ�ǽ�λ��iҲ���Ƕ�Ӧ�����±�i-1��Ԫ�ظ��������±�i��Ԫ�أ����ѭ������j�Ľ�����Ҫ����i��
�����±�jӦ�õ���λ��i��

ʱ�临�Ӷȷ�����
i���д�1��length+1(��lengthΪn)n+1��ѡ����ÿ�γ��ֵĸ�����ͬ��ÿ���ƶ�������������ͨ��n+1-i��ʾ��
�㷨��ƽ�����Ӷ�Ϊ1/(n+1) * i��1��n+1 ͨ��n+1-i���
���Ϊ��1�ӵ�n����n(n+1)/2,����ÿ�γ��ֵĸ���֮��õ�ƽ���ƶ����� n/2, ��˴��㷨��ʱ�临�Ӷ���O(n)����ġ�

�ر�ģ�i=length+1ʱ��ʱ�临�Ӷ�Ϊo(1)
*/
int ListInsert(SeqList *L, int i, int e){
    if (i < 1 || i > L->length + 1) {
        printf("Invalid Number!!\n");
        return false;
    }
    if (L->length >= L->MaxSize){
        printf("Out of bound!!\n");
        return false;
    } 
    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

//���Ա�Ԫ��ɾ��
/*
for ѭ��������޸�Ϊ
for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
��Ϊ�α��ϵĴ��룬������ȫ��ͬ��
����������ڵ�����

ʱ�临�Ӷȷ�����
i���д�1��n n��ѡ�񣬼���ÿ������ĸ�����ͬ��ÿ���ƶ�Ԫ�ظ�����ͨ��Ϊn-i�����ƽ��ʱ�临�Ӷ�Ϊ
1/n * n��1��n ��ͣ�ͨ��Ϊn-i��������ƽ���ƶ������� (n-1)/2 ������㷨��ʱ�临�Ӷ���O(n)����ģ�
�ر�ģ�i=lengthʱ��ʱ�临�Ӷ�Ϊo(1)
*/
int ListDelete(SeqList *L, int i){
    if (i < 1 || i > L->length){
        printf("Invalid Number!!");
        return false;
    }
    int del = L->data[i - 1];
    for (int j = i - 1; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->data[L->length - 1] = 0;
    L->length--;
    return true;
}


//��λ����
int GetElement(SeqList L, int i){
    if (i < 1 || i > L.length + 1){
        printf("Invalid Number!!\n");
        return -1;
    } 
    return L.data[i-1];
}

//��ֵ���� ʱ�临�Ӷ�ΪO(n)
int LocateElement(SeqList L, int e){
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}
//�������Ա����Ԫ��
void printList(SeqList L){
    for (int i = 0; i < L.length; i++)
        printf("data[%d] = %d\n",i+1,L.data[i]);
}



//P17ҳ�α���Ŀ

//��һ�⣬˳�����ɾ����СֵԪ��(����Ψһ)������ɾ����ֵ�����ҿճ���λ�������һ��Ԫ�������˳���Ϊ���򷵻ش�����Ϣ
/*
ʱ�临�Ӷȷ���
��ؼ�����������Сֵ�ı���Ѱ�ң�������ζ���Ҫ�������������Ա������ʱ�临�Ӷ�ΪO(n)��
*/
int T1_Del_Min(SeqList *L){
    //˳���Ϊ���Ƿ��ش�����Ϣ
    if (L->length == 0){
        printf("˳���Ϊ�գ�");
        return -1;
    } 
    int index = 0;
    int min = L->data[0];
    for (int i = 1 ; i < L->length; i++)
        if (L->data[i] < min){
            min = L->data[i];
            index = i;
        }
    L->data[index] = L->data[L->length - 1];
    L->length--;       
    return min;
}

//�ڶ��⣬����Ԫ�أ�Ҫ��ռ临�Ӷ���O(1)
/*
���������ڴ�ռ���и�ֵ�Ĳ����ռ临�Ӷ�ΪO(n)�������Ҫʵ��ԭ�����򣬴��м俪ʼ���Գ�Ԫ�ؽ������ɡ�
���ÿ�������ż�������ż����ȫ��Ԫ�ؽ��жԵ�������ʱ���м��Ԫ�ز������ƶ�

ʱ�临�Ӷȷ���
�㷨�Ĳ�������ΪT(n/2)�������ʱ�临�Ӷ�ΪO(n);
*/
void T2_Reverse(SeqList *L){
    int temp = 0;
    for (int i = 0; i < L->length / 2; i++){
        temp = L->data[i];
        L->data[i] = L->data[L->length - 1 - i];
        L->data[L->length - 1 - i] = temp;
    }
}

//�����⣬ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1),ʵ��ɾ�����Ա�������ֵΪx��Ԫ�أ�

/*
Ϊ��ʹ�ռ临�Ӷ�ΪO(1),ֻ�ܲ���ԭ��ɾ���ķ�ʽ���Ȳ������������ڴ档

*/

/*
��һ�ַ��� ʹ��num��¼���Ա��в�����e��Ԫ�ظ�������Ԫ����ֵ��Ϊe�������Ԫ�ظ�ֵ��data[num]��ͬʱnum++,
����Ԫ����ֵΪe���򲻽��и�ֵ������ʹ�䱻����Ԫ�ظ��ǣ�ע��������ֵ֮�������Ա�����k��Ԫ��ֵΪe�������k��Ԫ����Ҫɾ����ֻ��Ҫ��L��length��ֵΪnum���ɣ������ݻ��Ǳ��������ڴ浱��
*/
void T3_Del_Value_1(SeqList *L, int e){
    int num = 0;
    for (int i = 0; i < L->length; i++){
        if (L->data[i] != e){
            L->data[num] = L->data[i];
            num++;
        }
    }
    L->length = num;
}

/*
�ڶ��ַ��� ʹ��num��¼���Ա��е���e��Ԫ�ظ�������Ԫ����ֵ��Ϊe����Ԫ��ǰ��num��λ�ã���Ԫ�ظ���Ϊe����num++��
����һ�����Ա���ʵ��ɾ��Ԫ�ز���,������Ա�����Ϊlength-num
*/
void T3_Del_Value_2(SeqList *L, int e){
    int num = 0;
    for (int i = 0; i < L->length; i++){
        if (L->data[i] != e){
            L->data[i - num] = L->data[i];
        }
        else num++;
    }
    L->length = L->length - num;
}

/*�������ַ�������ͨ����������num��¼Ϊe���߲�Ϊe�ĸ�����ͨ���������и��Ǹ�ֵ��
�����ַ��������Ա���ʹ��ָ���˼�룬һ��ͷָ��һ��βָ�룬���߷ֱ����м��ƶ���ֱ������,
�����ַ�ʽ���Ľ���ᵼ��˳��ı䣬�����ں����Ա�˳�򣬴˷����������ַ�����ʱ�临�Ӷ���͵��㷨
ע��while��������ҪС�ڵ��ڣ���ȱ�ٵ��ڣ����ܶ��Ԫ�أ���ȫ2���Ա�ɾ��2��tail��󵽴�0��������ȴ��Ϊ��1�����ǲ��Ե���Ϊ��ʱ��ȷ��Ӧ�����Ա�������Ӧ��ȫ��ɾ��
*/

void T3_Del_Value_3(SeqList *L, int e){
    int head = 0;
    int tail = L->length - 1;
    while (head <= tail){
        if (L->data[head] == e){
            if (L->data[tail] != e){
                // int temp = L->data[head];
                L->data[head] = L->data[tail];
                tail--;
                head++;
            }
            else{
                tail--;
            }
        }
        else head++;
    }
    L->length = tail + 1;
}


//�����⣬ �����ںܶ�̲���������ָ�ĵ�������˳�����ɾ��ֵ��s��t֮���Ԫ�أ�s<t�����Ұ���s��t����s��t��������գ����ض�Ӧ������Ϣ
/*
����˳����ǹؼ�����õ��㷨��ͬʱ��ͷ��β���бȽϣ�ֱ���ҵ��ٽ�ֵ��Ӧ�ı�ţ����м��Ԫ�ؽ��и��Ǽ���
�������ҵķ�����������ʱ�临�Ӷ�ΪO(n)����ģ�����������Ҫ����n�αȽϣ����ҽ���n�θ�ֵ����
���ֿα��������ҵĻ���һ�£����α��Ĵ�����Ӽ�ࡣ��Ҫѧϰһ�¡�
*/
void T4_Del_Range_1(SeqList *L, int s, int t){
    if (L->length == 0) printf("Empty List!!\n");
    else if (s > t) printf("Invalid s and t!!\n");
    else{
        int head = 0;
        int tail = L->length - 1;
        //�������
        while (L->data[head] < s){
            head++;
        }
        while (L->data[tail] > t){
            tail--;
        }
        for (int i = 0; i <= L->length - tail - 1; i++){
            L->data[head + i] = L->data[tail + i + 1];
        }
        L->length = L->length - (tail - head + 1);
        
    }
}

void T4_Del_Range_2(SeqList *L, int s, int t){
    //�����Ӧ�Ĵ�������
    // if (s > L->data[L->length]) printf("S too large!!\n");
    // else if (t < L->data[0]) printf("T too small!!\n");
    if (s > t) printf("Invalid S and T!!\n");
    else if (L->length == 0) printf("Empty List!!\n");

    else{
        int i, j;
        //�ɴ˿ɼ���forѭ������дһ�䵥���жϣ��������ٽ�ֵ

        //O(n)
        for (i = 0; i < L->length && L->data[i] <s; i++);  //Ѱ�ҵ�һ�����ڵ���s��Ԫ���±�i
        for (j = i; j < L->length && L->data[i] <= t; j++); //Ѱ�ҵ�һ������t���±�j
        //����������i��j-1��Ԫ�أ�ʹ��j��ʼ������Ԫ�ؽ����滻���ɣ�
        //��Ҳ��ΪʲôiҪ�ҵ����ڵ��ڣ���Ϊi����Ҫ�滻�ĵ�һ��Ԫ�أ�����Ҫ��֤i�ϸ���s��t�������ڣ�����ȡs����ȡ����s
        //i�ǵ�һ���滻��Ԫ�ر�����s��t֮��Ҳ�����ϸ����t

        //�����������滻����
        //ȡ����j�ĳ�ֵ
        for (; j < L->length; j++,i++)
            L->data[i] = L->data[j];
        //���L�ĳ��ȸ�Ϊi
        L->length = i;
    }

}

//������ ����������ƣ�����Ҫ��˳���������ģ���˲���ʹ��i��j�±��ҵ������ٽ����滻��
//�����з���������Ԫ�طŵ�˳����ǰ���֣�ʹ��num��¼��������Ԫ�ص����������num���Ԫ�ظ���ǰ��Ԫ�أ������ַ�����ʹ��ԭ�е�˳�����ı䡣

void T5_Del_Range_Unorder_1(SeqList *L, int s, int t){
    int num = 0;
    for (int i = 0; i < L->length; i++){
        //�����е��������ڵ�Ԫ��ȫ���ŵ�ǰ�档
        if (L->data[i] >= s && L->data[i] <= t){
            int temp = L->data[num];
            L->data[num] = L->data[i];
            L->data[i] = temp;
            num++;
        }
        // printList(*L);
        // printf("========\n");
        //ʹ�ú����Ԫ�ظ���ǰ���Ԫ�أ��������ԭ��ɾ��.
    }
    

    for (int j = 0; j + num < L->length; j++){
            int temp = L->data[j];
            L->data[j] = L->data[j + num];
            L->data[j + num] = temp;
    }
    L->length = L->length - num;
}

//�α��ϵķ����ǽ����в��������Ԫ��ǰ�ƣ����ҵķ����෴�����ǿ��Ա�֤���������ڵ�Ԫ��˳�򲻷����ı䡣

/*
���������㷨ͨ����¼����������Ԫ�صĸ���k������Ԫ����������ʱ��������һ��������ʱ��
��Ԫ��ǰ�Ƹ�����Ԫ�أ��Ᵽ֤�����κ�ʱ�䣬ǰi-k��һ���ǲ����������ڵ�Ԫ�ء�
*/
void T5_Del_Range_Unorder_2(SeqList *L,int s, int t){
    if (!L->length) printf("Empty List!!\n");
    if (s > t) printf("Invalid S and T!!\n");
    int k  = 0;
    for (int i = 0; i < L->length; i++){
        if (L->data[i] >= s && L->data[i] <= t) k++;
        else L->data[i - k] = L->data[i];
    }
    L->length -= k;
}

//������ ������˳�����ɾ�������ظ�Ԫ�أ�ʹ�����õ������Ա���Ԫ�ؾ���ͬ��


//�����漸��������ܽ�����ı�ѭ������i֮ǰ��Ԫ�أ�����Ӱ�����ɻ��ң���˿��Կ����ڵ�i��Ԫ��ʱ����αȽϣ���ζ�iǰ��Ԫ�ؽ��в������Ӷ�ʵ���㷨��
void T6_Del_Repeat_1(SeqList *L){
    int i, j ;
    for (i = 0,j = 1; j < L->length; j++)
        if (L->data[j] != L->data[i]) L->data[++i] = L->data[j];
    L->length = i + 1;
}
//���⣬��Ϊ˳���������ģ������ظ�Ԫ�ض���������һ�أ����ʵ��ɾ���㷨��Ϊ�򵥣����潫��������˳�����ɾ������������ʹ��ɢ�нṹ��
//ɢ�нṹ�ǲ��Ҳ��ֵ����ݣ����������������в��䡣
void T6_Del_Repeat_2(SeqList *L){
    int MaxSize = 100;
    int Hashtable[MaxSize];
    memset(Hashtable, 0, sizeof(Hashtable));  // ������Ԫ��ȫ����Ϊ0
    for (int i = 0; i < L->length; i++){
        Hashtable[L->data[i]] += 1;
    }
    int new_length = 0;
    for (int j = 0; j< L->MaxSize; j++){
        printf("%d: %d\n",j, Hashtable[j]);
        if (Hashtable[j] != 0){
            L->data[new_length] = j;
            new_length++;
        }
    }
    L->length = new_length;
}

//������ ���⽫��������Ψһ����ֻ���޸���ȵ�������ɣ���ϲ�������������ķ������ƣ�ֻ��������ʹ��ͷ�巨��
//ʹ������ָ�����i��j������¼L1��L2�Ĳ���λ�ã���һ������ȫ���Ƚ����ʱ������whileѭ����Ȼ��û�бȽ���İ�˳��ŵ�L����
//�������һ�����е�������ݶ�С����һ�����е���С���ݣ�ʱ�临�Ӷ�ΪOmin(L1.length,L2.length)
SeqList T7_Merge(SeqList L1, SeqList L2){
    SeqList L;
    L.data = (int*)malloc((L1.length + L2.length)* sizeof(int));
    int len = 0;
    int i = 0;
    int j = 0;
    while (i != L1.length && j != L2.length){
        if (L1.data[i] < L2.data[j]){
            L.data[len++] = L1.data[i++];
        }
        else if (L1.data[i] == L2.data[j])
        {
            L.data[len++] = L1.data[i++];
            j++;
        }
        else{
            L.data[len++] = L2.data[j++];
        }
    }
    if (i == L1.length)
        for (; j < L2.length; j++)
            L.data[len++] = L2.data[j];
    else if (j == L2.length)
        for (; i < L1.length; i++)
            L.data[len++] = L1.data[i];
    
    L.length = len;
    return L;
    
}

//�ڰ��⣬��һ��һά�����к�������˳���ʵ������˳����λ�û���
//�����������������ڴ��Ϊ��

SeqList T8_Inverse0(SeqList L, int s){ //sΪ��һ������ĳ���
    SeqList new_L;
    new_L.data = (int*) malloc(L.length * sizeof(int));
    int len = 0;
    //�����һ����
    for (int i = s; i < L.length; i++)
        new_L.data[len++] = L.data[i];
    //�����һ����
    for (int j = 0; j < s; j++){
        new_L.data[len++] = L.data[j];
    }
    new_L.length = len;
    return new_L;

}

//������ʹ�ÿռ临�Ӷ�ΪO(1)���㷨���Ƚ����е�Ԫ�ؽ������ã�Ȼ��ֱ��ǰ���Ӧ����������ֱ��������

//���ȱ�дһ�����ú�����ʵ�������ڵ�����
void Reverse(SeqList *L, int m, int n){

    int temp, mid = (m + n) / 2;
    for (int i = m - 1; i < mid; i++){
        temp = L->data[i];
        L->data[i] = L->data[--n];
        L->data[n] = temp;
    }

}

//֮�������ȶ������������ã�Ȼ��ֱ������Ԫ�ؽ�������,nΪ��һ������ĳ���
SeqList T8_Inverse(SeqList L, int n){
    Reverse(&L, 1, L.length);
    Reverse(&L, 1, L.length - n);
    Reverse(&L, L.length - n + 1, L.length);
    return L;
}
//�ھ���
//�����������в���Ԫ�أ�����ʹ������Ԫ�ؽ�����
//��������������ģ�����ʹ�ö��ַ��������ҵ�ʱ�临�ӶȽ��͵�logn����
int BinarySearch(SeqList L, int e){
    int left = 0;
    int right = L.length - 1;
    int mid;
    while (left <= right){ //ע�⣺����ѭ�������ĳ�!=���ڼ���������û��Ӱ��
        mid = (left + right) / 2;
        if (L.data[mid] == e)
            return mid;
        else if (L.data[mid] < e)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void T9_SearchOrInsert(SeqList *L, int e){
    int index = BinarySearch(*L, e);
    if (index != -1){
        if (index != L->length - 1){
            int temp = L->data[index];
            L->data[index] = L->data[index + 1];
            L->data[index + 1] = temp;
        }
    }
    else{
        int i = 0;
        while (true)
        {
            if (L->data[i++] > e){
                ListInsert(L, i, e);
                break;
            }
                
        }
        
    }
}

int main(){
    SeqList L;
    InitList(&L);
    // InitList(&L2);
    // InitList_Line(&L, 10);

    ListInsert(&L, 1, 0);
    ListInsert(&L, 2, 3);
    ListInsert(&L, 3, 5);
    ListInsert(&L, 4, 6);
    ListInsert(&L, 5, 9);
    IncreaseSize(&L, 2);
    printList(L);
    // printf("%d\n", L.length);
    printf("========\n"); 
    // printf("%d\n", BinarySearch(L, 0));
    // T9_SearchOrInsert(&L, 10);
    T9_SearchOrInsert(&L,10);
    printList(L);
    // Reverse(&L, 1, 9);
    // printList(T8_Inverse(L, 3));
    // printList(T8_Inverse(L, 3));
    // printList(T7_Merge(L1, L2));
    // printf("%d\n",T1_Del_Min(&L));
    // T2_Reverse(&L);
    // T3_Del_Value_3(&L, 2);
    // T4_Del_Range_2(&L, 5, 8);
    // T5_Del_Range_Unorder_1(&L, 1, 8);
    // T5_Del_Range_Unorder_2(&L, 1, 5);
    // T6_Del_Repeat_1(&L);
    // T6_Del_Repeat_2(&L);
    system("pause");
    return 0;

}
