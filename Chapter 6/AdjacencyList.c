#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 5

typedef struct ArcNode{ //���Ǹ�����
    int adjvex; //�������ڵ�ָ���Ǹ�����
    struct ArcNode *next;
} ArcNode;

typedef struct VEle{ //��Ԫ�غ�һ�㣬����������Ӱ��
    char data; //�洢������Ϣ
    ArcNode *first;//�����Ӧһ��������ʾ����������˳��Ψһ
} VEle, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices; //AdjList��һ��VNode��˳���
    int vexnum, arcnum;
} ALGraph;

void CreateList(ArcNode** first, int vex[], int len){ //lenΪvex�ĳ���
    if (len == 0) return; //���ڽӣ�ֱ�ӷ���
    //��ʼfitstΪ�գ��Ƚ����׽ڵ㴴��������ᱨ��
    ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = vex[0];
    p->next = NULL;
    *first = p;

    //p����¼���һ���ڵ�
    for (int i = 1; i < len; i++){
        ArcNode* t = (ArcNode*)malloc(sizeof(ArcNode));
        t->adjvex = vex[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
}

// void AddNode(ArcNode** p, ArcNode* q){
//     (*p)->next = q;
// }

void InitGraph(ALGraph *G){
    for (int i = 0; i < MaxVertexNum; i++){
        // G->vertices[i].data = ;
        G->vertices[i].first = NULL;
    }        
}

void CreateGraph(ALGraph *G){
    G->vertices[0].data = 'A';
    G->vertices[1].data = 'B';
    G->vertices[2].data = 'C';
    G->vertices[3].data = 'D';
    G->vertices[4].data = 'E'; //����

    int x1[3] = {1,2,3};
    CreateList(&(G->vertices[0].first), x1, 3);
    int x2[2] = {0,4};
    CreateList(&(G->vertices[1].first), x2, 2);
    int x3[4] = {0,1,2,3};
    CreateList(&(G->vertices[2].first), x3, 4);
    int x4[1] = {2};
    CreateList(&(G->vertices[3].first), x4, 1);
    int x5[3] = {0,3,4};
    CreateList(&(G->vertices[4].first), x5, 3);
    
}

void PrintAdjList(ALGraph G){
    for (int i = 0; i < MaxVertexNum; i++){
        printf("%c : ",G.vertices[i].data);
        ArcNode* p = G.vertices[i].first;
        while (p != NULL)
        {
            printf("%d->", p->adjvex);
            p = p->next;
        }
        printf("end\n");
    }
}

int main(){
    ALGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintAdjList(G);
    system("pause");
    return 0;
}