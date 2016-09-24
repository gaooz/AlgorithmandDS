/**
date: 2012年09月
author: gaooz.com
*/

//------------------深度优先搜索（邻接表存储图结构）----------------------2012、09、13
int visted[MAX_NUM];//定义为全局变量，存放各顶点是否已被访问标志
void VistGraph(VertexNode V)
{//访问顶点操作
	printf("%d ",V.data);
}
int FirstAdjvex(ALGraph &G,int v)
{//得到图G中第v个顶点的第一个邻接顶点所在位置
	Acnode *p;p=G.Vertex[v].firstarc;
	if(p==NULL)
		return -1;
	return p->adjvex;
}
int NextAdjvex(ALGraph &G,int v,int w)
{//得到w顶点下一邻接点的位置
	Acnode *p;p=G.Vertex[v].firstarc;
	while(p->adjvex!=w&&p!=NULL)
		p=p->next;
	p=p->next;
	if(p==NULL)
		return -1;
	return p->adjvex;
}
void DFS(ALGraph &G,int v)
{//深度优先搜索核心过程。参数v表示从图中第v个结点开始深度优先遍历
	int w;
	VertexNode V;V=G.Vertex[v];
	visted[v]=1;VistGraph(V);//令该顶点所在标志为1表示已访问，然后访问该顶点
	for(w=FirstAdjvex(G,v);w>=0;w=NextAdjvex(G,v,w))
		if(!visted[w]) DFS(G,w);
}
void DFSTraverse(ALGraph &G)
{//深度优先搜索
	int i;
	for(i=0;i<G.Vexnum;i++) visted[i]=0;//首先初始化访问标志
	for(i=0;i<G.Vexnum;i++)
		if(!visted[i]) DFS(G,i);
}