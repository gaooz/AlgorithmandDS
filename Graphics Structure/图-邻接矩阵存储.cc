/**
date: 2012年09月
author: gaooz.com
*/

//----邻接矩阵存储表示，实现有向网的构造及各顶点度的计算----2012年09月11
/*邻接矩阵存储表示既是数组存储表示，即可用于有向图（有向网），也可用于无向图（无向网）
优点：便于存储，便于计算图结构中各顶点的度；
缺点：当图中顶点数目较多切顶点之间的联系较少时采用这种存储结构比较浪费存储空间。*/
#include<stdio.h>
#define MAX_NUM 20//最大顶点数目为20
typedef enum {DG,DN,UDG,UDN} GraphKind;//图类型标志，有向图、有向网、无向图、无向网。
typedef enum {Border,UnBorder} Graph_Border;
typedef struct {
	int data;
}VertexNode;//图中顶点结构定义
typedef struct {
	union {
		Graph_Border adj;//适用于图，表示是否相邻
		int Value;//网，权值(这里定义权值类型为int型)
	}Graph_Net;
	char *info;//存储边或者弧的相关信息
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//边或弧结构的定义
typedef struct {
	VertexNode Vertex[MAX_NUM];//存储顶点数组
	AdjMatrix arcs;//存储顶点之间的关系，即边或弧(邻接矩阵)
	int Vexnum,Arcnum;//当前途中顶点数目、边或弧数目
	GraphKind kind;//图的类型
}MGraph;//图结构的定义
void CreatGraph_DN(MGraph &G)
{//构造有向网结构
	int i,j,isign,jsign;
	VertexNode v1,v2;ArcCell arc;
	printf("构造有向网：\n");
	G.kind=DN;//说明图的结构
	printf("请输入网中顶点数目和弧的数目：");
	scanf("%d%d",&G.Vexnum,&G.Arcnum);
	printf("请初始化这些顶点：");
	for(i=0;i<G.Vexnum;i++)
		scanf("%d",&G.Vertex[i].data);
	for(i=0;i<G.Vexnum;i++)
		for(j=0;j<G.Vexnum;j++)
			G.arcs[i][j].Graph_Net.Value=-1;//先初始化邻接矩阵
	printf("请初始化顶点之间的联系（即弧的信息）：\n");
	printf("格式：顶点1 顶点2 权值（表示顶点1邻接到顶点2）\n");
	for(i=0;i<G.Arcnum;i++)
	{
		scanf("%d%d%d",&v1.data,&v2.data,&arc.Graph_Net.Value);
		isign=-1;jsign=-1;
		for(j=0;j<G.Vexnum;j++)
		{
			if(G.Vertex[j].data==v1.data)
				isign=j;
			if(G.Vertex[j].data==v2.data)
				jsign=j;//找到两顶点之间的关系即弧所在的邻接矩阵中的位置
		}
		if(isign==-1||jsign==-1)
			printf("顶点输入有误！\n");
		else
		{
			G.arcs[isign][jsign].Graph_Net.Value=arc.Graph_Net.Value;
			//初始化邻接矩阵中该位置弧权值的信息
		}
	}

}
int *CountVexNum_DN(MGraph G)
{//有向网各顶点度的计算
	int D[MAX_NUM],ID[MAX_NUM],OD[MAX_NUM];//分别存放顶点的度、入度、出度
	int i,j,k;
	for(i=0;i<G.Vexnum;i++)
	{//初始化
		D[i]=0;
		ID[i]=0;
		OD[i]=0;
	}
	for(i=0;i<G.Vexnum;i++)
	{
		for(j=0;j<G.Vexnum;j++)
			if(G.arcs[i][j].Graph_Net.Value!=-1)
				OD[i]++;//计算顶点出度
		for(k=0;k<G.Vexnum;k++)
			if(G.arcs[k][i].Graph_Net.Value!=-1)
				ID[i]++;//计算顶点入度
		D[i]=ID[i]+OD[i];//有向图（有向网）中顶点的度为入度加出度
	}
	return D;
}