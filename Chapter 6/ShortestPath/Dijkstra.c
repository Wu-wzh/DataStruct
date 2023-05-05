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
void Dijkstra(MGraph G, int start){
    int min_dis, index;//dist�е����·���Ͷ�Ӧ�Ľڵ�
    int dist[G.vexnum]; //��¼��ǰѭ�����·������
    int path[G.vexnum]; //��¼��ǰѭ���������ǰ������
    char vex[G.vexnum]; //��¼�������Ƿ��ҵ����·��

    //��ʼ��vex��dist��path����
    dist[start] = 0; //��ʼ�ڵ㵽�Լ������·��Ϊ0
    path[start] = -1; //��ʼ�ڵ���ǰ��
    vex[start] = 1;
    for (int i = 0; i < G.vexnum; i++){
        if (i == start) continue;
        vex[i] = 0; //vex��ʼֻ�п�ʼ�ڵ�Ϊ1�����඼Ϊ0
        dist[i] = G.Edge[start][i];
        path[i] = G.Edge[start][i] == Infinte ? -1 : start;
    }

    //����n-1�α���
    for (int i = 0; i < G.vexnum - 1; i++){
        //�ҵ�dist����С��ֵ�Ͷ�Ӧ�Ķ���
        min_dis = Infinte; //��ʼ��Ϊ�����
        index = -1;//�����ʼ��Ϊ-1
        for (int i = 0; i < G.vexnum; i++){
            if (!vex[i] && dist[i] < min_dis){
                min_dis = dist[i];
                index = i;
            }
        }
        //�ҵ������dist��Сֵ���ǵ���index��������·��
        //����index�������·�����ҵ��ˣ�����vex����Ϊ1
        vex[index] = 1;
        //����dist
        for (int j = 0; j < G.vexnum; j++){
            //����j������δ�ҵ����·������index���㵽j����ľ���������͸���dist��ֵ
            //���ҽ���j�������ǰ���ڵ��Ϊindex
            if (!vex[j] && G.Edge[index][j] + min_dis < dist[j]){
                dist[j] = G.Edge[index][j] + min_dis;
                path[j] = index;
            } //�����˲���֮��dist�е�����Ҳ�����滻
        }    
    }

    printf("dist��");
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
    printf("path��");
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
    for (int i = 0; i < G.vexnum; i++){
        if (i == start) continue;
        printf("����%d������%d�����·������Ϊ��%d�����·��Ϊ��", start, i, dist[i]);
        printf("%d", i);
        int temp = path[i];
        while (temp > 0){
            printf("<--%d", temp);
            temp  = path[temp];
        }
        printf("<--%d", start);
        printf("\n");
    }
    
        
    
    
}
int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph_My(&G);
    PrintGraph(G);
    //Dijkstra��Prime�㷨����
    //���ߵ�ʱ�临�Ӷȶ���O(n^2)
    Dijkstra(G, 0);   
    system("pause");
    return 0;
}