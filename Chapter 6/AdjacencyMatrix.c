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

void PrintGraph(MGraph G){
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.Edge[i][j] == 1 ? G.Edge[i][j]:0);
        printf("\n");
    }
}
int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);
    Neighbors(G, 0);
    system("pause");
    return 0;
}