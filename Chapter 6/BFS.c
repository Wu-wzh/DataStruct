#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0
#define MaxVertexNum 11
#define Infinte 10000;


//�������ݽṹ
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
    LinkNode *front, *tail;
}LinkQueue;

int InitQueue(LinkQueue *Q){
    Q->front = Q->tail = (LinkNode*)malloc(sizeof(LinkNode));
    Q->front->next = NULL;
    return true;
}

void EnQueue(LinkQueue *Q, int e){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next =NULL;
    Q->tail->next = p;
    Q->tail = p;
}

//���Ӳ�����ֻ��ͷ�ڵ���в���������Ҫע�⣬�����Ӻ���б�Ϊ�գ���ʱ��Ҫ�޸�tailβָ��ʹ����frontָ��ͬһλ��
int DeQueue(LinkQueue *Q, int *x){
    if (Q->front == Q->tail) return false;
    LinkNode *p = Q->front->next;
    *x = p->data;
    Q->front->next = p->next;
    if (p == Q->tail) Q->front = Q->tail;
    p = NULL;
    free(p);
    return true;
}

int isEmpty(LinkQueue Q){
    if (Q.front == Q.tail) return true;
    else return false;
}

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

void PrintGraph(MGraph G){
    for (int i = 0; i < G.vexnum; i++){
        for (int j = 0; j < G.vexnum; j++)
            printf("%d ", G.Edge[i][j] == 1 ? G.Edge[i][j]:0);
        printf("\n");
    }
}

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

//ͼ�ı����㷨
//�����ı�����ͬ�����������п��ܳ��ֶ�α���ͬһ�����㣬�����Ҫһ��visited����������Ƿ��Ѿ����ʹ��˶���


//BFS������ȱ���
int visited[MaxVertexNum];//ȫ�ֱ���visited visited���ܲ���ȫʹ��

void BFS_Min_Distance(MGraph G, int u, int e){
    int v = u;
    int d[G.vexnum], p[G.vexnum];
    for (int i = 0; i < G.vexnum; i++)
    {
        d[i] = Infinte; //d�洢v��������������̾��룬��ʼ��Ϊ�����
        p[i] = -1; //p�洢ÿ�������ֱ��ǰ���������ӡ���·��
    }
    d[v] = 0; //�Լ����Լ��ľ���Ϊ0��
    LinkQueue Q;
    InitQueue(&Q);
    //��ʼ�����������ı������ƣ�ֻ�����������visited�жϲ���

    visited[v] = 1; //�ڵ�v���ʹ���visitedֵ����Ϊ1
    EnQueue(&Q, v);//v��ӣ����к�������
    //��w�ĵ�һ���ڽӶ��㿪ʼ��

    //����whileѭ����ֱ��QΪ�գ�������Ϊ�����Ķ��㣬�򻹻������Ӳ��������Բ��õ��Ļ�û���������ǰ����
    while (!isEmpty(Q)){
        DeQueue(&Q, &v);//v���ӣ����ҽ�Ϊ���ʹ���v���ڽӽڵ�ȫ�����
        //�������v�ڵ���ڽӽڵ㣬δvisited�������

        //�����ж��㶼�������꣬����forѭ�����������ӣ��������е��������ռ�С��0������whileѭ��
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
            if (!visited[w]){
                d[w] = d[v] + 1; //w���ϸ�����Ϊv�����Ե�w�ľ�����ڵ�v�ľ����һ
                p[w] = v; //w���ϸ�����Ϊv
                visited[w] = 1;
                EnQueue(&Q, w);//��ȻҲ���Գ���ʱ���ʣ��������ڶ��е�FIFO�����Ծ����ģ����߶�����
            }
    }
    printf("����%d���ﶥ��%d����̾���Ϊ��%d\n", u, e, d[e]);
    printf("���·��Ϊ��");
    printf("%d", e);
    int temp = e;
    while (1){
        temp = p[temp];
        if (temp <= 0) break;
        printf("<- %d", temp);
    }
    // for (int i = 0; i < G.vexnum; i++)
    //     printf("%d ",d[i]);
    // for (int i = 0; i < G.vexnum; i++)
    //     printf("%d ",p[i]);
    
    
}
//�ڽӾ���BFS������Ψһ�ģ������ڽӱ��ǲ�Ψһ��


//�Ӷ���v�������й�����ȱ���
//�ռ临�Ӷȣ����д洢�������ΪO(|V|)
//ʱ�临�Ӷȣ��ڽӾ���O(|V|^2)
//�ڽӱ�O(|V| + |E|)

int main(){
    MGraph G;
    InitGraph(&G);
    CreateGraph(&G);
    PrintGraph(G);
    BFS_Min_Distance(G, 1, 7);
    system("pause");
    return 0;
}