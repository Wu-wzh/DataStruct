#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 10
#define MaxSize 20
#define Infinte 10000
typedef struct
{
    char Vex[MaxVertexNum];               // �����洢������Ϣ
    int Edge[MaxVertexNum][MaxVertexNum]; // �����洢����Ϣ �ڴ洢��Ȩͼʱ���ɲ�ʹ��int������ռ���˷�
    int vexnum, arcnum;                   // �洢����ͱߵ�����
    int isdir;                            // �Ƿ�������ͼ
} MGraph;
/*�˴洢�ṹ��ʱ�临�Ӷȣ�
�洢����ṹO(n),�洢�߽ṹO(n^2),������ʱ�临�Ӷ�ΪO(n^2)
�����ڽӾ������洢ϡ�����ʱ������ɺܶ�洢�ռ���˷ѣ�ʹ����ʽ�洢�ṹ����һ��

�����ڽӾ���A��n�η���A^n[i][j]���ִ�����ǴӶ���i������j����Ϊn�ĳ��ȵ�·����������
*/

void InitGraph(MGraph *G)
{
    for (int i = 0; i < MaxVertexNum; i++)
    {
        // G->Vex[i] = NULL;
        for (int j = 0; j < MaxVertexNum; j++)
        {
            if (i == j)
                G->Edge[i][j] = 0;
            else
                G->Edge[i][j] = Infinte;
        }
    }
}
void CreateGraph(MGraph *G)
{
    // ��ʼ��ͼ�ı�
    InitGraph(G);

    printf("�����붥�����ͱ������ÿո��������");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    // ����ÿ���������Ϣ
    printf("����������ÿ���������Ϣ��\n");
    for (int i = 0; i < G->vexnum; i++)
    {
        printf("Vex[%d] = ", i);
        scanf("%s", &G->Vex[i]);
    }
    // ����ͼ��������ͼ
    printf("����ͼ������ͼ��0����ͼ��1����ͼ����\n");
    scanf("%d", &G->isdir);

    // ����ÿ���ߵ������յ�
    printf("����������ÿ���ߵ������յ㣨�ÿո����,��Ŵ�0��ʼ����\n");
    for (int i = 0; i < G->arcnum; i++)
    {
        int v1, v2, w;
        printf("������ڱߵ���������(����ͼֻ��Ҫ����һ��)", i);
        scanf("%d%d%d", &v1, &v2, &w);
        G->Edge[v1][v2] = w;
        if (G->isdir == 0)
            G->Edge[v2][v1] = w;
    }
}

void CreateGraph_My(MGraph *G)
{
    // ��ʼ��ͼ�ı�
    InitGraph(G);

    (*G).vexnum = 6;
    (*G).arcnum = 10;
    (*G).isdir = 0;;

    int arr[10][3] = {{0,1,6},{0,2,5},{0,3,1},{1,3,5},{1,4,3},{2,3,4},{2,5,2},{3,4,6},{3,5,4},{4,5,6}};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 3; j++){
            (*G).Edge[arr[i][0]][arr[i][1]] = arr[i][2];
            (*G).Edge[arr[i][1]][arr[i][0]] = arr[i][2];
        }
    }
}


void PrintGraph(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.Edge[i][j] >= 1 && G.Edge[i][j] < Infinte ? G.Edge[i][j] : 0);
        printf("\n");
    }
}
// ���鼯��ʾ��Ϊ���Ϲ�ϵ��ֻʵ�ּ��ϵĲ�ѯ�Ͳ��Ĳ���
// ������Ͳ����������Ż������������Ż���Ϊ�˽��Ͳ������ʱ�临�Ӷ�
// ��������Ż�Ч�ʺܸߣ������ﵽ�˳�������
// ��n��������Ԫ�غϲ�Ϊһ�����ϣ����ڲ�������Ҫ���ҵ����ϲ�Ԫ�صĸ��ڵ㣬�����ʱ�临�Ӷ�Ϊ�������˲������ʱ�临�Ӷ�

// ȫ����ʼ��Ϊ-1
void Initial_DSU(int S[])
{
    for (int i = 0; i < MaxSize; i++)
        S[i] = -1;
}

// ����� �ҵ������������������ 
int Find(int S[], int x){
    // ʱ�临�Ӷ�ΪO(n)��nΪ�߶�
    while (S[x] >= 0)
        x = S[x];
    return x;
}

// ���������ֱ�Ӻϲ������ܻᵼ�ºϲ���������ߣ�Ӱ�����ٶ�
void Union(int S[], int root1, int root2)
{
    if (root1 == root2)
        return;
    S[root2] = root1;
}

//�Զ���qsort�����Ƚ���
int comp(const void *a,const void *b){
    if (((int*)a)[0]<((int*)b)[0]) return -1;
    else return 1;
}

void Sort(MGraph G, int (*SortEdge)[3]){
    int index = 0;//SortEdge����

    for (int i = 0; i < G.vexnum; i++){
        for (int j = i + 1; j < G.vexnum; j++){
            if (G.Edge[i][j] > 0 && G.Edge[i][j] < Infinte){
                SortEdge[index][0] = G.Edge[i][j];
                SortEdge[index][1] = i;
                SortEdge[index][2] = j;
                index++;
            }
                
        }
    } 
    //ʹ��C�����Դ��Ŀ�������
    //store��ά������ count�г���  sizeof(int)*2 �ܹ����� comp1�Զ��庯�� 
    qsort(SortEdge, G.arcnum, sizeof(int) * 3, comp);
}

// Kusral�㷨
void Kusral(MGraph G){
    int val = 0;//Ȩ�ش�С
    int SortEdge[G.arcnum][3]; //�����������飬�����߳��Ⱥ����߶�������

    Sort(G, SortEdge);//Sort�����õ������ı�Ȩ��ά����
    for (int i = 0; i < G.arcnum; i++)
        printf("%d %d %d\n", SortEdge[i][0], SortEdge[i][1], SortEdge[i][2]);
    int S[MaxSize]; //SΪ���鼯��ʹ�����е�˫�ױ�ʾ��
    Initial_DSU(S); //��ʼ�����鼯��ÿ���ڵ����
    for (int i = 0; i < G.arcnum; i++){
        //�ж������ߵ����������Ƿ�����ͬһ������
        if (Find(S, SortEdge[i][1]) != Find(S, SortEdge[i][2])){
            val += SortEdge[i][0];
            Union(S, Find(S, SortEdge[i][1]), Find(S, SortEdge[i][2]));//��������ͬһ�����ϣ�������кϲ�
            //�ϲ�ʱҪ��Ҫ����Ҫ��������кϲ����������ֶ�ʧ�ڵ㡣
            printf("��%d�͵�%d����\n", SortEdge[i][1], SortEdge[i][2]);
        }
    }
    printf("��Ȩֵ��СΪ��%d\n", val);

}
int main()
{
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);

    // Prim�㷨��һ�ֶ����̰���㷨��ͨ�����Ͻ�����̾���Ķ��㲢��prime���飬���ҵ���С����������
    // ������Kruskal�㷨��һ�ֱߵ�̰���㷨��ͨ�����Ͻ���̱ߵ��������㲢�������飬�õ��˼���֮��ĺϲ������������Ҫʹ�ò��鼯��
    // ���鼯��ʵ��һ�ּ������ݽṹ�����ǽ���ʵ�ֺϲ����ж��Ƿ���һ�����ϵĲ�������֮Ϊ���Ͳ顣
    Kusral(G);
    system("pause");
    return 0;
}