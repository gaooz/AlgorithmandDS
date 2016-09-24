/**
date: 2012年09月
author: gaooz.com
*/

//----------------最短路径：Dijkstra算法-------------------2012年9月25
//Dijkstra算法适用于求图中的一个源点至图中其他顶点的最短路径。
//注意：此算法图G中邻接矩阵当两顶点间不共边时用MAX表示，而不用-1表示

typedef int Path[MAX_NUM][MAX_NUM];//存放路径
typedef int Dist[MAX_NUM];//存放最短路径长度

void ShortPath_Dijkstra(MGraph G,VertexNode v,Path &P,Dist &D)
{//最短路径_迪杰斯特拉算法
	//以图G中顶点v为源点求源点到其他顶点的最短路径,路径存放在二维数组p中
	//源点到各顶点最短路径长度存放在一维数组D中
	int i,v0,j,w,k,n,Final[MAX_NUM],min;
	for(i=0;i<G.Vexnum;i++)
		if(v.data==G.Vertex[i].data) { v0=i; break; }
	for(i=0;i<G.Vexnum;i++)
	{//初始化
		Final[i]=0;
		D[i]=G.arcs[v0][i].Value;
		for(j=0;j<G.Vexnum;j++)
			P[i][j]=0;//首先置路径为空
		if(D[i]<MAX)
		{
			P[i][v0]=1;//起点
			P[i][i]=1;//终点
		}
	}
	D[v0]=0;Final[v0]=1;
	for(i=1;i<G.Vexnum;i++)
	{//求其他n-1个顶点的最短路径
		min=MAX;
		for(j=0;j<G.Vexnum;j++)
			if(min>D[j]&&Final[j]==0)
			{ min=D[j];w=j;}
			Final[w]=1;//表示源点到该顶点的最短路径已经找到
		for(k=0;k<G.Vexnum;k++)
			if(Final[k]==0&&D[k]>min+G.arcs[w][k].Value)
			{//修改D数组中最短路径长度的值
				D[k]=min+G.arcs[w][k].Value;
				for(n=0;n<G.Vexnum;n++)
				P[k][n]=P[w][n];
				P[k][k]=1;//路径
			}
	}
}