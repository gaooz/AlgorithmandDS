/**
date: 2012年09月
author: gaooz.com
*/

//-------------------深度优先生成树的构造-------------2012、09、15
void DFSTree(ALGraph &G,int v,Tree &T)
{//从图中第v个顶点构造深度优先生成树T
	int w;Tree p,q;
	visted[v]=1;
	for(w=FirstAdjvex(G,v);w>=0;w=NextAdjvex(G,v,w))
		if(!visted[w])
		{
			p=(Tree)malloc(sizeof(TNode));
			p->Tdata=G.Vertex[w].Gdata;
			p->firstchild=NULL;p->nextsibling=NULL;
			if(T->firstchild==NULL)//First用来判断该结点的是否已存在左子树
			{ T->firstchild=p; }
			else q->nextsibling=p;
			q=p;
			DFSTree(G,w,q);//递归调用
		}
}
void DFSForest(ALGraph &G,Tree &T)
{//构造图G的深度优先生成树T
	int i;Tree p,q;
	T=NULL;
	for(i=0;i<G.Vexnum;i++)
		visted[i]=0;//初始时置顶点为未被访问状态
	for(i=0;i<G.Vexnum;i++)
	if(!visted[i])
	{
		p=(Tree)malloc(sizeof(TNode));
		p->Tdata=G.Vertex[i].Gdata;
		p->firstchild=NULL;p->nextsibling=NULL;
		if(T==NULL) T=p;//如果树为空则令p为树根结点
		else q->nextsibling=p;//若为连通图则else语句不会执行,构造的深度优先生成树也只有左子树
		//若为非连通图即通过一个顶点不能遍历图中所有顶点，则构造的深度优先生成树会有右子树
		//可根据一定的规则遍历右子树求该无向图的连通分量
		q=p;
		DFSTree(G,i,p);//调用构造树函数，构造p的深度优先生成树
	}
}