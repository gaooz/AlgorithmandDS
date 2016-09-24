/**
date: 2012年09月
author: gaooz.com
*/

//-----------------------关节点的求取---------------------------2012年9月19
void DFSArticul(ALGraph G,int v)
{//从图中第v个顶点出发深度优先搜索求关结点
	int min,w;AcNode *p;
	visted[v]=min=++count;
	for(p=G.Vertex[v].firstarc;p;p=p->next)
	{
		w=p->adjvex;
		if(visted[w]==0) 
		{
			DFSArticul(G,w);
			if(low[w]<min) min=low[w];
			if(low[w]>=visted[v]&&!finash[v])//finash[]表示若该结点已经输出过则不再重复输出
			{
				printf("%d ",G.Vertex[v].Gdata.data);
				finash[v]=1;
			}
		}
		else
			if(visted[w]<min) min=visted[w];//w为其回边结点
	}
	low[v]=min;
}
void FindArticul(ALGraph G)
{//找图中所有的关节点并输出这些结点
	int i,v,v1=0;AcNode *p;
	count=1;
	visted[0]=1;low[0]=1;//假设从邻接表中第一个结点开始深度搜索，该结点为深度优先生成树的树根
	for(i=1;i<G.Vexnum;i++) { visted[i]=0;finash[i]=0;}//初始化其他还未访问的结点序列
	p=G.Vertex[0].firstarc;v=p->adjvex;
	DFSArticul(G,v);
	if(count<G.Vexnum)
	{ printf("%d ",G.Vertex[0].Gdata.data);
	//一次搜索未能遍历图中所以的顶点则说明树根结点至少存在两棵子树，说明树根为关节点
	 while(p->next)
	 {
		p=p->next;v=p->adjvex;
		if(visted[v]==0)
		DFSArticul(G,v);
	 }
	}
}//求取low[]的原则详见数据结构笔记。