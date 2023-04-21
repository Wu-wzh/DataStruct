#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 5
#define Infinte 10000;
typedef struct{
    char Vex[MaxVertexNum]; //�����洢������Ϣ
    int Edge[MaxVertexNum][MaxVertexNum]; //�����洢����Ϣ �ڴ洢��Ȩͼʱ���ɲ�ʹ��int������ռ���˷�
    int vexnum, arcnum;//�洢����ͱߵ�����
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
    char List[MaxVertexNum];
    List[0] = 'A';
    List[1] = 'B';
    List[2] = 'C';
    List[3] = 'D';
    List[4] = 'E';
    for (int i = 0; i < MaxVertexNum; i++){
        G->Vex[i] = List[i];
        G->Edge[0][1] = 1;
        G->Edge[1][0] = 1;
        G->Edge[1][2] = 1;
        G->Edge[2][1] = 1;
        G->Edge[2][3] = 1;
        G->Edge[3][2] = 1;
        G->Edge[3][4] = 1;
        G->Edge[4][3] = 1;
    }//����һ����
}
void PrintGraph(MGraph G){
    for (int i = 0; i < MaxVertexNum; i++){
        for (int j = 0; j < MaxVertexNum; j++)
            printf("%d ", G.Edge[i][j] == 1 ? G.Edge[i][j]:0);
        printf("\n");
    }
}
int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);
    system("pause");
    return 0;
}