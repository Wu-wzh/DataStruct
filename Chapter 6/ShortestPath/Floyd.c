/*��̬�滮��˼�룺
��ʼ����Ȩ��������ǰ���ڵ����
��������v0��ת�����·Ϊ
��������v0��v1��ת�����·Ϊ
��������v0��v1��v2��ת�����·Ϊ
......
��������v0��v1��...��vn-1��ת�����·Ϊ

���Ҵ��㷨���Խ�����ڸ�Ȩ��ͼ
���޷�������и�Ȩ��·��ͼ
*/
#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 20
#define Infinte 10000
typedef struct{
    char Vex[MaxVertexNum]; //�����洢������Ϣ
    int Edge[MaxVertexNum][MaxVertexNum]; //�����洢����Ϣ �ڴ洢��Ȩͼʱ���ɲ�ʹ��int������ռ���˷�
    int vexnum, arcnum;//�洢����ͱߵ�����
    int isdir; //�Ƿ�������ͼ
} MGraph;
/*�˴洢�ṹ��ʱ�临�Ӷȣ�
�洢����ṹO(n),�洢�߽ṹO(n^2),������ʱ�临�Ӷ�ΪO(n^2)
�����ڽӾ������洢ϡ�����ʱ������ɺܶ�洢�ռ���˷ѣ�ʹ����ʽ�洢�ṹ����һ��

�����ڽӾ���A��n�η���A^n[i][j]���ִ�����ǴӶ���i������j����Ϊn�ĳ��ȵ�·����������
*/

void InitGraph(MGraph *G){
    for (int i = 0; i < MaxVertexNum; i++){
        // G->Vex[i] = NULL;
        for (int j = 0; j < MaxVertexNum; j++)
        {
            if (i == j) G->Edge[i][j] = 0;
            else G->Edge[i][j] = Infinte;
        }
    }
}
void CreateGraph(MGraph *G){
    // ��ʼ��ͼ�ı�
    InitGraph(G);

    printf("�����붥�����ͱ������ÿո��������");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    // ����ÿ���������Ϣ
    printf("����������ÿ���������Ϣ��\n");
    for (int i = 0; i < G->vexnum; i++){
        printf("Vex[%d] = ", i);
        scanf("%s", &G->Vex[i]);
    }
    //����ͼ��������ͼ
    printf("����ͼ������ͼ��0����ͼ��1����ͼ����\n");
    scanf("%d", &G->isdir);

    // ����ÿ���ߵ������յ�
    printf("����������ÿ���ߵ������յ㣨�ÿո����,��Ŵ�0��ʼ����\n");
    for (int i = 0; i < G->arcnum; i++){
        int v1, v2, w;
        printf("������ڱߵ���������(����ͼֻ��Ҫ����һ��)", i);
        scanf("%d%d%d", &v1, &v2, &w);
        G->Edge[v1][v2] = w;
        if (G->isdir == 0) G->Edge[v2][v1] = w;
    }
}

void CreateGraph_My(MGraph *G)
{
    // ��ʼ��ͼ�ı�
    InitGraph(G);

    (*G).vexnum = 5;
    (*G).arcnum = 10;
    (*G).isdir = 1;
    
    int c = 48;
    for (int i = 0; i < G->vexnum; i++){
        (*G).Vex[i] = c++;
    }
    

    int arr[10][3] = {{0,1,10},{0,4,5},{1,4,2},{4,1,3},{1,2,1},{4,3,2},{2,3,4},{3,2,6},{3,0,7},{4,2,9}};
    // int arr[5][3] = {{0,1,6},{1,0,10},{0,2,13},{2,0,5},{1,2,4}};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 3; j++){
            (*G).Edge[arr[i][0]][arr[i][1]] = arr[i][2];
            // (*G).Edge[arr[i][1]][arr[i][0]] = arr[i][2];
        }
    }
}

void PrintGraph(MGraph G){
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.Edge[i][j] >= 1 && G.Edge[i][j] < Infinte ? G.Edge[i][j] : 0);
        printf("\n");
    }
}

//Dijkstra�㷨
void Floyd(MGraph G){
    //��ʼ��A(-1)��p(-1)����
    int A[G.vexnum][G.vexnum];
    int p[G.vexnum][G.vexnum];
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++){
            A[i][j] = G.Edge[i][j];//��ʼ��AΪ�������κζ���ľ��룬����ʼ·������
            p[i][j] = -1; 
            //p�����ʼ��Ϊȫ-1����ʾ���ڲ������κνڵ㣬���û��ǰ���ڵ�
        }
    }
    
    //ѭ������
    for (int k = 0; k < G.vexnum; k++) //�Զ���v<=kΪ��ת
        for (int i = 0; i < G.vexnum; i++) //����A����ı���
            for (int j = 0; j < G.vexnum; j++)
                //������k�ڵ�Ϊ�м̣����õ���·��С�ڵ�ǰ��·����������滻
                if (A[i][k] + A[k][j] < A[i][j]){
                    A[i][j] = A[i][k] + A[k][j];
                    p[i][j] = k; //���Ҹ���ǰ������p����Ϣ
                }

    //��ӡ���
    printf("A����\n");
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("p����\n");
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    int temp;
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++){
            if (i == j) continue;
            if (A[i][j] != Infinte){
                printf("����%d�붥��%d�����·������Ϊ��%d��",i, j, A[i][j]);
                printf("���·��Ϊ��%d", i);
                temp = j;
                while (p[i][temp] > 0){
                    temp = p[i][temp];
                    printf("-->%d", temp);
                }
                printf("-->%d", j);
                printf("\n");
            }
            else{
                printf("����%d�붥��%d�����·�����Ȳ�����\n",i, j);
            }
        }
        
    }
    
}

int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph_My(&G);
    PrintGraph(G);
    //����forѭ����ʱ�临�Ӷ�ΪO(n^3)
    Floyd(G);
    system("pause");
    return 0;
}
