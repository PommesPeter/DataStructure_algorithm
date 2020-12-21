#ifndef C_PROJECT_GRAPH_H
#define C_PROJECT_GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#define N  6
//邻接矩阵数据结构
typedef struct {
    int vcount;//顶点数
    int type;//0 无向图，1 有向图
    char vexs[N];     // 顶点信息
    int arcs[N][N]; //关系矩阵
} GraphMatrix;

//邻接表数据结构
struct EdgeNode { //边表中的结点
    int endvex;     //相邻顶点在顶点表中下标
    int weight;  //边的权
    struct EdgeNode *nextedge;   //链字段
};
typedef struct EdgeNode *EdgeList;

typedef struct
{
    char  vertex;  //记录顶点信息
    int degree;//用于记录顶点的入度，在拓扑排序时需使用
    EdgeList  edgelist;  //指向边表的指针
} VexNode;
typedef struct{
    VexNode  vexs[N];  //N个顶点
    int type ;//0 无向图，1 有向图
    int vcount;//顶点数
} GraphList;



/*第一关 完成图初始化
*/
void printGraph(GraphMatrix *G)
{//本函数输出图的邻接矩阵
    int i,j;
    for (i = 0; i < G->vcount; i++) {
//  printf("%c ",G->vexs[i]);
        for (j = 0; j < G->vcount; j++)
            printf("%d ", G->arcs[i][j]);
        printf("\n");
    }
}

/*第一关 完成图初始化-邻接矩阵
*/
GraphMatrix *initGraphMatrix() {
    //0 5 6 0 1 0 3 1 2 1 4 2 3 2 4
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接矩阵，不需要考虑输入的数字非法情况，不输入顶点的信息*/
    GraphMatrix *g = (GraphMatrix *) malloc(sizeof(GraphMatrix));
    int e_num;
    scanf("%d%d%d", &g->type, &g->vcount, &e_num);
    for (int i = 0; i < g->vcount; i++) {
        for (int j = 0; j < g->vcount; j++) {
            g->arcs[i][j] = 0;
        }
    }

    for (int i = 0; i < e_num; i++) {
        int begin, end;
        scanf("%d%d", &begin, &end);
//        g->vexs[i] = (char)(begin + '0');
        g->arcs[begin][end] = 1;
        if (g->type == 0) {
            g->arcs[end][begin] = 1;
        }
        return g;
    }
}

/*第二关 完成图初始化-邻接表,并完成输出图的邻接表函数
*/
GraphList *initGraphList() {
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接表。不需考虑输入的数字非法情况，输入顶点的信息*/
    //0 4 5 0123 0 1 0 2 0 3 1 2 1 3
    GraphList *G = (GraphList *) malloc(sizeof(GraphList));
    int edgecount, i, begin, end, weight;
    scanf("%d%d%d", &G->type, &G->vcount, &edgecount);
    getchar();
    for (i = 0; i < G->vcount; i++) {
        G->vexs[i].edgelist = NULL;
        scanf("%c", &G->vexs[i].vertex);
    }

    for (i = 0; i < edgecount; i++) {
        scanf("%d%d", &begin, &end);
        struct EdgeNode *p;
        p = (struct EdgeNode *) malloc(sizeof(struct EdgeNode));
        p->endvex = end;
        p->weight = weight;
        p->nextedge = G->vexs[begin].edgelist;
        G->vexs[begin].edgelist = p;
        G->vexs[end].degree++;
        if (G->type == 0) {
            p = (struct EdgeNode *) malloc(sizeof(struct EdgeNode));
            p->endvex = begin;
            p->weight = weight;
            p->nextedge = G->vexs[end].edgelist;
            G->vexs[end].edgelist = p;
        }
    }
    return G;
}


void printGraphLit(GraphList *G) {
    /*输出邻接表，输出格式：顶点->邻接顶点编号->...*/
    for (int i = 0; i < G->vcount; i++) {
        printf("%c", G->vexs[i].vertex);
        for (struct EdgeNode *p = G->vexs[i].edgelist; p != NULL; p = p->nextedge) {
            printf("->%d", p->endvex);
        }
        printf("\n");
    }
}


/*第三关 完成图的广度遍历（周游），可根据需要添加自定义函数*/

int queue_isEmpty(int* front, int* rear) {
    if (*front == *rear) {
        return 1;
    }
    return 0;
}

int queue_isFull(int* front, int* rear) {
    if ((*rear + 1) % N == *front) {
        return 1;
    }
    else {
        return 0;
    }
}

void deQueue(int* queue, int* front, int* rear, int* i) {
    if (!queue_isEmpty(front, rear)) {
        *i = queue[*front];
        *front = (*front + 1) % N;
    }
}

void enQueue(int* queue, int* front, int* rear, int i) {
    if (!queue_isFull(front, rear)) {
        queue[*rear] = i;
        *rear = (*rear + 1) % N;
    }
}

void BFS_list(GraphList *G) {
    //0 6 7 012345 0 1 0 2 0 3 1 5 2 4 3 4 4 5
    int queue[N] = {0}, visited[N] = {0}, front = 0, rear = 0;
    for (int i = 0; i < G->vcount; i++) {
        visited[i] = 1;
        printf("%d ", i);
        enQueue(queue, &front, &rear, i);
        while (!queue_isEmpty(&front, &rear)) {
            deQueue(queue, &front, &rear, &i);
            EdgeList e = G->vexs[i].edgelist;
            while (e) {
                if (!visited[e->endvex]) {
                    visited[e->endvex] = 1;
                    printf("%d ", e->endvex);
                    enQueue(queue, &front, &rear, e->endvex);
                }
                e = e->nextedge;
            }
        }
    }
}

/*第四关 完成图的深度遍历（周游），可根据需要添加自定义函数
*/
void DFS_list(GraphList *G) {
    //0 5 6 01234 0 1 0 3 1 2 1 4 2 3 2 4
    int visit[N] = {0};
    struct EdgeNode *p;
    for (int i = 0; i < G->vcount; i++) {
        if (visit[i] == 0) {
            printf("%d ", i);
            visit[i] = 1;
            p = G->vexs[i].edgelist;
            do {
                while (p) {

                    if (visit[p->endvex] == 0) {
                        visit[p->endvex] = 1;
                        printf("%d ", p->endvex);
                        break;
                    }
                    p = p->nextedge;
                }
                if (p == NULL) break;
                p = G->vexs[p->endvex].edgelist;
            } while (1);
        }
    }
}

/*第五关 生成图的拓扑排序，可根据需要添加自定义函数
*/

void Top_list(GraphList *G) {
    int visit[N] = {0};
    int flag = 0;
    for (int i = 0; i < G->vcount; i++) {
        if (G->vexs[i].degree == 0 && visit[i] == 0) {
            flag = 1;
            visit[i] = 1;
            printf("%d ", i);
            struct EdgeNode *p = G->vexs[i].edgelist;
            while (p) {
                G->vexs[p->endvex].degree--;
                p = p->nextedge;
            }
        }
        if (flag == 1) {
            i = 0;
            flag = 0;
        }
    }

}

/*第六关 prim算法生成最小生成树
*/

void Prim_list(GraphList *G) {
    int vex[N];
    int i, j, k;
    int curnum = 0;
    int visit[N];
    int start = 0;
    struct EdgeNode *p;
    int minvalue, minvex;

    for (i = 0; i < G->vcount; i++)
        visit[i] = 0;

    vex[0] = start;
    visit[start] = 1;

    while (curnum < G->vcount - 1) {
        minvalue = 8888;
        minvex = -1;
        k = -1;
        for (i = 0; i <= curnum; i++) {
            p = G->vexs[vex[i]].edgelist;
            if (p && minvex == -1) {
                minvex = p->endvex;
                if (k == -1) k = vex[i];
            }
            while (p) {
                if (p->weight < minvalue && visit[p->endvex] == 0) {
                    minvalue = p->weight;
                    minvex = p->endvex;
                    k = vex[i];
                }
                p = p->nextedge;
            }
        }
        curnum++;
        vex[curnum] = minvex;
        visit[minvex] = 1;
        printf("%d %d\n", k, minvex);

    }

}
/*第七关 Kruskal算法生成最小生成树
*/

void Kruskal_list(GraphList *G)
{


}

/*第八关 Dijistra算法求最短路径
*/

void Dijkstra_list(GraphList *G)
{


}




#endif //C_PROJECT_GRAPH_H
/*最短路径代码void ShortestPath(int start)
{
    int dist[N]; //用于存放顶点0到其余各顶点的最短路径
	int i ;
	int visit[N] ;//用于表示该顶点加入到最短集合


	visit[0] = 1; //初始化顶点0加入集合
	dist[0] = 0; //初始化顶点0到自身距离0
	for(i=1;i<N;i++)
	{
	   visit[i] = 0;
	   dist[i] = 8888;
	   	}//初始化 其余各顶点未加入最短集合以及初始化初始路径为最大值

	PrintDist(dist) ;   //输出当前路径情况，便于调试

	//	本段代码用于初始化顶点0到能到达顶点的距离的赋值

	struct node *p ,*q;

	p = Ndata[0].next;
	minvalue = 8888;
	while(p)
	{
	   dist[p->data] = p->value ;
	   p = p->next;
	}

	int count = 0; //用于记录集合中顶点数
	int minvalue,minvex ;

	while(count<N)
	 {
	   PrintDist(dist) ;
	   cout<<endl;

       minvalue = 8888;
	   for(i=1;i<N;i++)
	   	if(minvalue > dist[i] && visit[i] == 0)
	   	  {
	   	  	minvalue = dist[i]  ;
	   	  	minvex = i  ;
		 }//获取本轮dist中最小的路径及顶点


    	visit[minvex] = 1 ;

    	q = Ndata[minvex].next ;
    	while(q)
    	{
    		if(dist[q->data] > dist[minvex]+q->value )
    		  dist[q->data] = dist[minvex]+q->value ;
    		 q = q->next;
		}
		count++;
	}


}*/