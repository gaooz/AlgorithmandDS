/**
date: 2012年09月
author: gaooz.com
*/

//---------------最短路径：Floyd算法------------------2012年9月25
//Floyd算法适用于求图中一对顶点即顶点与顶点之间最短路径的算法。

typedef int Path[MAX_NUM][MAX_NUM][MAX_NUM];//存放路径
typedef int Dist[MAX_NUM][MAX_NUM];//存放最短路径长度

void ShortPath_Floyd(MGraph G,Path &p,Dist &d)
{//Floyd算法，适用于求图中一对顶点之间的最短路径
	//路径存放在三维数组p中，最短路径长度存放在二维数组d中
	int i,u,v,w;
	for(v=0;v<G.Vexnum;v++)//初始化
		for(w=0;w<G.Vexnum;w++)
		{
			d[v][w]=G.arcs[v][w].Value;
			for(u=0;u<G.Vexnum;u++)
				p[v][w][u]=0;
				if(d[v][w]<MAX)
				{
					p[v][w][v]=1;//起点
					p[v][w][w]=1;//终点
				}
		}
		for(u=0;u<G.Vexnum;u++)
			for(v=0;v<G.Vexnum;v++)
				for(w=0;w<G.Vexnum;w++)
					if(d[v][u]+d[u][w]<d[v][w])
					{
						d[v][w]=d[v][u]+d[u][w];
						for(i=0;i<G.Vexnum;i++)
							p[v][w][i]=p[v][u][i]||p[u][w][i];
					}
}