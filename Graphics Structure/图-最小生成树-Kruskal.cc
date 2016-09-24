/**
date: 2012年09月
author: gaooz.com
*/

//----------------Kruskal算法---------------------2012年9月22
int pfun(ALGraph &G,int i,int j)
{//判断图G中第i个顶点和第j个顶点是否在同一个连通分量上
	int k;
	for(k=0;k<G.Vexnum;k++)
		visted[k]=0;
	DFS(G,i);
	if(visted[j]==1)
		return 1;
	return 0;
}
void Kruskal(ALGraph G,ALGraph &T)
{//克鲁斯卡尔算法构造最小生成树
	closedge Edge;int i,j=0,flag=1,k,sign,lowcost;AcNode *p,*q;
	Edge.length=0;
	for(i=0;i<G.Vexnum;i++)
	{//初始化T(最小生成树中包含图中所有顶点)	
		T.Vertex[i].Gdata=G.Vertex[i].Gdata;
		T.Vertex[i].firstarc=NULL;
	}
	T.Vexnum=G.Vexnum;T.Arcnum=0;
	for(i=0;i<G.Vexnum;i++)
	{//将图中的所有的边加入Edge中
		p=G.Vertex[i].firstarc;
		while(p)
		{
			for(k=0;k<Edge.length;k++)
			{
				flag=1;		if((Edge.edge[k].i==i&&Edge.edge[k].j==p->adjvex)||(Edge.edge[k].i==p->adjvex&&Edge.edge[k].j==i))
				{ 	flag=0;break;  }
			}
			if(flag)
			{
				Edge.edge[j].i=i;Edge.edge[j].j=p->adjvex;
				Edge.edge[j].value=p->value;j++;Edge.length++;
			}
			p=p->next;
		}
	}
	while(T.Arcnum!=T.Vexnum-1)
	{
	lowcost=MAX;
	for(j=0;j<Edge.length;j++)
	{
		if(lowcost>Edge.edge[j].value&&Edge.edge[j].value!=0)
		{sign=j;lowcost=Edge.edge[j].value;}
	}
	printf("找到最小边为：<%d,%d,%d>  ",Edge.edge[sign].i,Edge.edge[sign].j,Edge.edge[sign].value);
	if(!pfun(T,Edge.edge[sign].i,Edge.edge[sign].j))
		{//如果该边所依附的两个顶点不在同一个连通分量上则把该边加入最小生成树中
			q=(AcNode *)malloc(sizeof(AcNode));
			q->adjvex=Edge.edge[sign].j;
			q->value=Edge.edge[sign].value;
			q->next=NULL;
			p=T.Vertex[Edge.edge[sign].i].firstarc;
			if(p==NULL)
				T.Vertex[Edge.edge[sign].i].firstarc=q;
			else
			{
				while(p->next!=NULL)
					p=p->next;
				p->next=q;
			}
			q=(AcNode *)malloc(sizeof(AcNode));
			q->adjvex=Edge.edge[sign].i;
			q->value=Edge.edge[sign].value;
			q->next=NULL;
			p=T.Vertex[Edge.edge[sign].j].firstarc;
			if(p==NULL)
				T.Vertex[Edge.edge[sign].j].firstarc=q;
			else
			{
				while(p->next!=NULL)
					p=p->next;
				p->next=q;
			}
			T.Arcnum++;
			Edge.edge[sign].value=0;//表示该边已并入最小生成树
			printf("成功将边<%d,%d,%d>并入最小生成树\n",Edge.edge[sign].i,Edge.edge[sign].j,lowcost);
	}
	}
}