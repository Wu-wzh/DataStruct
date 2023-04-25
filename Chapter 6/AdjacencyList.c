#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 10

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
    int isdir;
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
    printf("�����붥�����ͱ������ÿո��������");
    scanf("%d%d", &G->vexnum, &G->arcnum);
    // ����ÿ���������Ϣ
    printf("����������ÿ���������Ϣ��\n");
    for (int i = 0; i < G->vexnum; i++){
        printf("����[%d]Ϊ��", i);
        scanf("%s", &G->vertices[i].data);
    }

    //����ͼ��������ͼ
    printf("����ͼ������ͼ��0����ͼ��1����ͼ����\n");
    scanf("%d", &G->isdir);

    for (int j = 0; j < G->vexnum; j++){
        printf("��%d�����㹲�м����ߣ�", j);
        int len;
        scanf("%d", &len);
        int vex[len];
        printf("�����������%d�������ڽӵĶ��㣺\n");
        for (int k = 0; k < len; k++){
            scanf("%d", &vex[k]);
        }
        CreateList(&(G->vertices[j].first), vex, len);
    }
    
}

//�ж������ڵ��Ƿ����� x y Ϊ�ڵ�ı�ţ���0��ʼ(ֻʵ��������ͼ������ͼ��Ҫ�����������²���)
int Adjacent(ALGraph G, int x, int y){
    ArcNode* p = G.vertices[x].first;
    while(p != NULL){
        if (p->adjvex == y) return true;
        p = p->next;
    }
    return false;
}

//���һ���ڵ����еı�
//
void Neighbors(ALGraph G, int x){
    if (G.isdir == 0){ //����ͼ ֱ���ҵ��˽ڵ�������������
        ArcNode* p = G.vertices[x].first;
        while(p != NULL){
            printf("%d ",p->adjvex);
            p = p->next;
        }
    }

    //����ͼ ����Ҫ�ҵ��˽ڵ��������Ҫ�ҵ������ڵ���������Ƿ����Լ�
    //ʱ�临�ӶȽϸߣ�ȡ���ڱߵ������Ͷ���ĸ���������ϡ������к�����ͼ���첻��
    else{
        for (int i = 0; i < G.vexnum; i++){
            //��Ϊ�Լ��������������
            //��ifΪѰ�ҳ���
            if (i == x) {
                ArcNode* p = G.vertices[i].first;
                while(p != NULL){ 
                    printf("%d ",p->adjvex);
                    p = p->next;
                }
            }
            //��elseΪѰ����ߣ����Կ������ڽӱ��ȡʱ��Ѱ�������Ҫ����������ʱ�临�Ӷ�ΪO(|E|)
            else{
                ArcNode* p = G.vertices[i].first;
                while(p != NULL){ 
                    if (p->adjvex == x){
                        printf("%d ", i);
                        break;
                    }
                    p = p->next;
                }
            }
        }
    }
}//O(|V| + |E|)

//����һ���µĶ���(�ղ���ʱ�����κα�����)
void InsertVertex(ALGraph* G, char x){
    //��vexnum��һ�����ҽ�x��ֵ�����һ�����������
    (*G).vertices[(*G).vexnum++].data = x;
}//O(1)

//ɾ��һ������
//����Ҫ�����������е��б�ȫ��ɾ������Ҫ���������ڽӱ�ɾ�����й��ڴ˶������Ϣ
//�����������Ҫ������ȫ���ı�
void DeleteVertex(ALGraph* G,int x){}
//O(|E|)

//����Ѵ��ڶ���x��y֮��ı�
//ʹ��ͷ�巨���죬����ͼ������ͼ�������в�ͬ
void AddEdge(ALGraph* G, int x, int y){
    if (G->isdir){ //����ͼֻ��Ҫ��x���������ͷ��
        ArcNode* t = (ArcNode*)malloc(sizeof(ArcNode));
        t->adjvex = y;
        //ͷ�巨��firstΪͷ�ڵ�
        t->next = (*G).vertices[x].first->next;
        (*G).vertices[x].first->next = t;
    }
    else{//����ͼ������Ҫ��x����Ҫ�����y����������޸�
        ArcNode* t1 = (ArcNode*)malloc(sizeof(ArcNode));
        t1->adjvex = y;
        //ͷ�巨��firstΪͷ�ڵ�
        t1->next = (*G).vertices[x].first->next;
        (*G).vertices[x].first->next = t1;

        ArcNode* t2 = (ArcNode*)malloc(sizeof(ArcNode));
        t2->adjvex = x;
        //ͷ�巨��firstΪͷ�ڵ�
        t2->next = (*G).vertices[y].first->next;
        (*G).vertices[x].first->next = t2;
    }
}//O(1)


//����׿��ķ������
//�ҵ�����x�ĵ�һ���ڽӽڵ㣬���ڽӱ��п���Ψһ����Ϊ������û��˳���
//ɨ��x�������ҵ���һ���ڵ��return��û��return-1
int FirstNeighbor(ALGraph G, int x){
    if (G.vertices[x].first != NULL) return G.vertices[x].first->adjvex;
    else return -1;
}//O(1)
//����ͼѰ����߱Ƚϸ��ӣ�һ�㲻ʹ���ڽӱ�
//���ֻ��������ͼ������ͼ���ߵ����

//����y��x�ĵ�һ���ڽӵ㣬��x����һ���ڽӵ�
//��Ѱ�ҵ�һ���ڽӵ�����
int NextNeighbor(ALGraph G, int x, int y){
    if (G.vertices[x].first->next != NULL) return G.vertices[x].first->next->adjvex;
    else return -1;
}

//��Ȩͼ�еĸ�Ȩ��������Adjacent������ȫһ�£�ʵ�ּ�
int Get_edge_value(ALGraph G, int x, int y){}
int Set_edge_value(ALGraph G, int x, int y){}

void PrintAdjList(ALGraph G){
    for (int i = 0; i < G.vexnum; i++){
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
    // printf("%d\n", Adjacent(G, 0, 2));
    // printf("%d\n", Adjacent(G, 0, 4));
    Neighbors(G, 0);
    system("pause");
    return 0;
}