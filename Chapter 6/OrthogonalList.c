#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 4

typedef struct ArcNode {
    int inversename;  // ������� ���ڽӱ�
    int positivename;  // �����յ� �ڽӱ�
    struct ArcNode* inverselink;  // ָ��ͬ�յ����һ���� ���߽������ڽӱ�ָ��
    struct ArcNode* positivelink;  // ָ��ͬ������һ���� ���߽������ڽӱ�ָ��
} ArcNode;

typedef struct VEle {
    char data;  // ��������
    ArcNode* firstout;  // ָ���һ������
    ArcNode* firstin;   // ָ���һ���뻡
} VEle, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;  // ��������
    int vexnum;        // ������
    int arcnum;        // ����
} ALGraph;

void CreateArcNode(ArcNode** arc, int tail, int head) {
    *arc = (ArcNode*)malloc(sizeof(ArcNode));
    (*arc)->inversename = tail;
    (*arc)->positivename = head;
    (*arc)->inverselink = NULL;
    (*arc)->positivelink = NULL;
}

void CreateList(ALGraph* G, int node_pre, int node_later) {  //�������򴴽�ʮ������
    ArcNode* arc;
    CreateArcNode(&arc, node_pre, node_later);

    //���ڽӱ��ʵ��
    if (G->vertices[node_pre].firstout == NULL) { //���˽ڵ㵱���ڽӱ��ͷ�ڵ�
        G->vertices[node_pre].firstout = arc;
    } else {  //ͷ�巨
        arc->positivelink = G->vertices[node_pre].firstout;
        G->vertices[node_pre].firstout = arc;
    }

    //�ڽӱ��ʵ��
    if (G->vertices[node_later].firstin == NULL) { //���˽ڵ㵱�����ڽӱ��ͷ�ڵ�
        G->vertices[node_later].firstin = arc;
    } else { //ͷ�巨
        arc->inverselink = G->vertices[node_later].firstin;
        G->vertices[node_later].firstin = arc;
    }

    //ʮ������ʵ�����ǰ��ڽӱ�����ڽӱ������ͬһ���ṹ���У��Ӷ�ʹ�ü�����Ⱥ���ȶ��ܼ�
    //���ʮ������ֻ�ܴ洢����ͼ����Ϊֻ������ͼ������Ⱥͳ���
}

void InitGraph(ALGraph* G) {
    G->vexnum = MaxVertexNum;
    G->arcnum = 0;
    for (int i = 0; i < G->vexnum; i++) {
        G->vertices[i].data = 'A' + i;  // �����㸳ֵ
        G->vertices[i].firstout = NULL;
        G->vertices[i].firstin = NULL;
    }
}

void PrintGraph(ALGraph* G) {
    printf("ͼ��ʮ���������£�\n");
    for (int i = 0; i < G->vexnum; i++) {
        printf("%c: ", G->vertices[i].data);
        ArcNode* out = G->vertices[i].firstout;
        ArcNode* in = G->vertices[i].firstin;
        printf("���߽ڵ� : ");
        while (out != NULL) {
            printf("%c, ", G->vertices[out->positivename].data);
            out = out->positivelink;
        }
        printf(" || ");
        printf("��߽ڵ� : ");
        while (in != NULL) {
            printf("%c, ", G->vertices[in->inversename].data);
            in = in->inverselink;
        }
        printf("\n");
    }
}

int main() {
    ALGraph G;
    InitGraph(&G);
    CreateList(&G, 0, 1);
    CreateList(&G, 0, 2);
    CreateList(&G, 2, 0);
    CreateList(&G, 2, 3);
    CreateList(&G, 3, 0);
    CreateList(&G, 3, 1);
    CreateList(&G, 3, 2);
    PrintGraph(&G);

    system("pause");
    return 0;
}