//
// Created by 43459 on 12/3/2020.
//

#ifndef C_PROJECT_GRAPH_H
#define C_PROJECT_GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#define N  6
//邻接矩阵数据结构
typedef  struct{
    int vcount;//顶点数
    int type ;//0 无向图，1 有向图
    char  vexs[N]  ;     // 顶点信息
    int  arcs[N][N]; //关系矩阵
} GraphMatrix;

//邻接表数据结构
struct EdgeNode { //边表中的结点
    int  endvex;     //相邻顶点在顶点表中下标
    int  weight;  //边的权
    struct EdgeNode  * nextedge;   //链字段
};
typedef struct EdgeNode * EdgeList;

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
    for(i=0;i<G->vcount;i++)
    {
//  printf("%c ",G->vexs[i]);
        for( j=0;j<G->vcount;j++)
            printf("%d ",G->arcs[i][j]);
        printf("\n");
    }
}

/*第一关 完成图初始化-邻接矩阵
*/
GraphMatrix *initGraphMatrix( )
{
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接矩阵，不需要考虑输入的数字非法情况，不输入顶点的信息*/


}
/*第二关 完成图初始化-邻接表,并完成输出图的邻接表函数
*/
GraphList *initGraphList( )
{
    /*第一行输入图的类型、图的顶点数和边数，第二行输入各条边的两顶点的编号，按顶点编号从小到大的顺序输入。
  输出邻接表。不需考虑输入的数字非法情况，输入顶点的信息*/

}



void printGraphLit( GraphList *G)
{
    /*输出邻接表，输出格式：顶点->邻接顶点编号->...*/


}


/*第三关 完成图的广度遍历（周游），可根据需要添加自定义函数
*/
void BFS_list(GraphList *G)
{


}

/*第四关 完成图的深度遍历（周游），可根据需要添加自定义函数
*/
void DFS_list(GraphList *G)
{


}

/*第五关 生成图的拓扑排序，可根据需要添加自定义函数
*/

void Top_list(GraphList *G)
{


}

/*第六关 prim算法生成最小生成树
*/

void Prim_list(GraphList *G)
{


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
