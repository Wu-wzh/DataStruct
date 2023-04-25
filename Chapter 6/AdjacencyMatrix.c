#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 10
#define Infinte 10000;
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
        int v1, v2;
        printf("������ڱߵ���������(����ͼֻ��Ҫ����һ��)", i);
        scanf("%d%d", &v1, &v2);
        G->Edge[v1][v2] = 1;
        if (G->isdir == 0) G->Edge[v2][v1] = 1;
    }
}


//�ж������ڵ��Ƿ����� x y Ϊ�ڵ�ı�ţ���0��ʼ 
//��ʹ�ýڵ����ƣ���Ҫ��һ�����Ƶ���ŵ�ת�ƹ��̣���Ҫ���ĸ����ʱ�临�Ӷ�
int Adjacent(MGraph G, int x, int y){
    return G.Edge[x][y];
}//O(1)

//���һ���ڵ����еı�
void Neighbors(MGraph G, int x){
    //����ͼ������ͼ�Ĵ���ʽ��һ��
    if (G.isdir == 0){
        for (int i = 0; i < G.vexnum; i++)
        if (G.Edge[x][i] == 1) printf("%d ", i);
        printf("\n");
    }
    else{
        for (int i = 0; i < G.vexnum; i++){ //����ͼ��Ҫ�к���ͬʱ����
            if (G.Edge[x][i] == 1) printf("%d ", i);
            if (G.Edge[i][x] == 1) printf("%d ", i);
        }
        printf("\n");
    }
}//O(|V|)

//����һ���µĶ���(�ղ���ʱ�����κα�����)
void InsertVertex(MGraph* G, char x){
    //��vexnum��һ�����ҽ�x��ֵ�����һ�����������
    (*G).Vex[(*G).vexnum++] = x;
}//O(1)

//ɾ��һ������
//һ�ַ����ǰɴ��кʹ���ɾ���󣬽���Ԫ���ƶ������������ƶ����������ֿ����
//����ʱ�临�ӶȽϸߣ���˲������һ����־λ��ɾ��ʱ�����д���ȫ����ֵΪ0�����ұ�־λ��Ϊ0����
void DeleteVertex(MGraph* G,int x){}
//O(|V|)

//����Ѵ��ڶ���x��y֮��ı�
//���������ȡ�����ԣ������
void AddEdge(MGraph* G, int x, int y){
    (*G).Edge[x][y] = 1;
}//O(1)


//����׿��ķ������
//�ҵ�����x�ĵ�һ���ڽӽڵ㣬���ڽӾ�����Ψһ
//ɨ��x���ڵ��У��ҵ���һ���ڵ��return��û��return-1
int FirstNeighbor(MGraph G, int x){
    for (int i = 0; i < G.vexnum; i++){
        if (G.Edge[x][i] == 1) return i;
    }
    return -1;
}//O(1)~O(|V|)

//����y��x�ĵ�һ���ڽӵ㣬��x����һ���ڽӵ�
//��Ѱ�ҵ�һ���ڽӵ�����
int NextNeighbor(MGraph G, int x, int y){
    for (int i = y + 1; i < G.vexnum; i++){
        if (G.Edge[x][i] == 1) return i;
    }
    return -1;
}

//��Ȩͼ�еĸ�Ȩ��������Adjacent������ȫһ�£�ʵ�ּ�
int Get_edge_value(MGraph G, int x, int y){}
int Set_edge_value(MGraph G, int x, int y){}

void PrintGraph(MGraph G){
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.Edge[i][j] == 1 ? G.Edge[i][j]:0);
        printf("\n");
    }
}

//=======================================//
//=======================================//
//=======================================//
//=======================================//

void visit(MGraph G, int x){
    printf("%s ", G.Vex[x]);
}
//ͼ�ı����㷨
//�����ı�����ͬ�����������п��ܳ��ֶ�α���ͬһ�����㣬�����Ҫһ��visited����������Ƿ��Ѿ����ʹ��˶���


//BFS������ȱ���

//�Ӷ���v�������й�����ȱ���
void BFS(MGraph G, int v){

    //��ʼ��visited����
    int visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++){
        visited[i] = 0;
    }

    //��ʼ����
    visited[v] = 1;

    
}

int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);
    // Neighbors(G, 0);
    printf("%d\n", FirstNeighbor(G, 1));
    printf("%d\n", NextNeighbor(G, 1, 0));
    system("pause");
    return 0;
}