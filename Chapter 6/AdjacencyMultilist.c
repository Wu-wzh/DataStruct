#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 4

typedef struct EdgeNode {
    int vertex1;            // �ߵ������˵�
    int vertex2;
    struct EdgeNode* next1; // ָ��ͬһ���˵����һ����
    struct EdgeNode* next2; // ָ����һ���˵����һ����
} EdgeNode;

//��ʮ���������Ĳ�ͬ���ǰ����������ڽӱ�����ڽӱ�����˺ϲ���
//���Բ����ֱߵķ�������ڽӶ��ر�ֻ�ܴ洢����ͼ
typedef struct VertexNode {
    char data;              // ��������
    EdgeNode* firstedge;    // ָ���һ�������ö���ı�
} VertexNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;       // ��������
    int vexnum;             // ������
    int edgenum;            // ����
} AMGraph;

void CreateEdgeNode(EdgeNode** edge, int v1, int v2) {
    *edge = (EdgeNode*)malloc(sizeof(EdgeNode));
    (*edge)->vertex1 = v1;
    (*edge)->vertex2 = v2;
    (*edge)->next1 = NULL;
    (*edge)->next2 = NULL;
}

void CreateList(AMGraph* G, int v1, int v2) {
    EdgeNode* edge;
    CreateEdgeNode(&edge, v1, v2);

    // Ϊv1���һ���µı�
    if (G->vertices[v1].firstedge == NULL) {
        G->vertices[v1].firstedge = edge;
    } else {
        EdgeNode* p = G->vertices[v1].firstedge;
        while (p->next1 != NULL) {
            p = p->next1;
        }
        p->next1 = edge;
    }

    // Ϊv2���һ���µı�
    if (G->vertices[v2].firstedge == NULL) {
        G->vertices[v2].firstedge = edge;
    } else {
        EdgeNode* p = G->vertices[v2].firstedge;
        while (p->next2 != NULL) {
            p = p->next2;
        }
        p->next2 = edge;
    }
}

void InitGraph(AMGraph* G) {
    G->vexnum = MaxVertexNum;
    G->edgenum = 0;
    for (int i = 0; i < G->vexnum; i++) {
        G->vertices[i].data = 'A' + i;
        G->vertices[i].firstedge = NULL;
    }
}

void PrintGraph(AMGraph* G) {
    printf("ͼ���ڽӶ��ر����£�\n");
    for (int i = 0; i < G->vexnum; i++) {
        printf("%c: ", G->vertices[i].data);
        EdgeNode* p = G->vertices[i].firstedge;
        while (p != NULL) {
            if (p->vertex1 == i) {
                printf("%c ", G->vertices[p->vertex2].data);
                p = p->next1;
            } else {
                printf("%c ", G->vertices[p->vertex1].data);
                p = p->next2;
            }
        }
        printf("\n");
    }
}

int main() {
    AMGraph G;
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
