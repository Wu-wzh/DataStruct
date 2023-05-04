#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 10
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

    (*G).vexnum = 6;
    (*G).arcnum = 10;
    (*G).isdir = 0;
    
    int c = 48;
    for (int i = 0; i < G->vexnum; i++){
        (*G).Vex[i] = c++;
    }
    

    int arr[10][3] = {{0,1,6},{0,2,5},{0,3,1},{1,3,5},{1,4,3},{2,3,4},{2,5,2},{3,4,6},{3,5,4},{4,5,6}};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 3; j++){
            (*G).Edge[arr[i][0]][arr[i][1]] = arr[i][2];
            (*G).Edge[arr[i][1]][arr[i][0]] = arr[i][2];
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

//Prim�㷨
void Prim(MGraph G, int start){
    int val = 0;//��СȨֵ
    int lowCast[G.vexnum]; //��¼��ǰ���ڽӽڵ��Ȩֵ
    int isJoin[G.vexnum]; //��Ǹ��ڵ��Ƿ�����
    char prime[G.vexnum]; //��С�������������
    int index = 0; //��С������������

    //��ʼ��lowCast��isJoin����
    for (int i = 0; i < G.vexnum; i++){
        lowCast[i] = G.Edge[start][i];
        isJoin[i] = 0;
    }

    prime[index++] = G.Vex[start]; //��һ����������prime����
    lowCast[start] = 0;//����start�����Ѿ�����prime���飬����lowCast��Ϊ0;
    isJoin[start] = 1;//start�����Ѿ����

    //����forѭ������
    for (int i = 0; i < G.vexnum; i++){
        if (i == start) continue; //start�ڵ��Ѿ������

        int j = 0;
        int k; //�洢��Сֵ������
        //Ѱ��lowCast��Сֵ����
        int min = Infinte; //��ʼ��Ϊһ���������
        while (j < G.vexnum){
            if (!isJoin[j] && lowCast[j] < min){ //ֻѰ��δ����prime�������Сֵ
                min = lowCast[j];
                k = j;
            }
            j++;
        }
        val += min;
        prime[index++] = G.Vex[k]; //�������prime����
        lowCast[k] = 0;//����k�����Ѿ�����prime���飬����lowCast��Ϊ0;
        isJoin[k] = 1;//k�����Ѿ����

        //����lowCast��ֵ
        for (int z = 0; z < G.vexnum; z++)
            if (!isJoin[z] && G.Edge[k][z] < lowCast[z]) 
            //δ��prime������lowCastֵ������prime����k������j����˵����ʱ�����߾���prime������ɵĸ���
                lowCast[z] = G.Edge[k][z];
        
    }
    
    // ��ӡ��С������
    printf("Prim�㷨������С������Ϊ��\n");
    for (int i = 0; i < index; i++)
        printf("%c ", prime[i]);
    printf("\n");
    printf("��СȨֵΪ��%d\n", val);

}
int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);

    //Prim�㷨��һ�ֶ����̰���㷨��ͨ�����Ͻ�����̾���Ķ��㲢��prime���飬���ҵ���С����������
    //������Kruskal�㷨��һ�ֱߵ�̰���㷨��ͨ�����Ͻ���̱ߵ��������㲢�������飬�õ��˼���֮��ĺϲ������������Ҫʹ�ò��鼯��
    //���鼯��ʵ��һ�ּ������ݽṹ�����ǽ���ʵ�ֺϲ����ж��Ƿ���һ�����ϵĲ�������֮Ϊ���Ͳ顣
    Prim(G, 0);
    system("pause");
    return 0;
}