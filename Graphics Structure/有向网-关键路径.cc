/**
date: 2012年09月
author: gaooz.com
*/

//----------------关键路径---------------2012年9月24
int TopologicalSort(ALGraph G,stack &T)
{//拓扑排序、求得各顶点的最早发生时间，并把逆拓扑排序顺序的顶点存入栈T中
	////省略部分内容，省略内容与上述拓扑排序相同
	for(i=0;i<G.Vexnum;i++)//找到indegree数组中入度为0的顶点然后入栈
	{E[i]=0;//初始化最早发生时间}
	while(!EmptyStack(s))
	{ 
		pop(s,e);push(T,e);                   
		count++;//对输出的顶点计数
		for(p=G.Vertex[e.adjvex].firstarc;p!=NULL;p=p->next)
		{
			k=p->adjvex;
			indegree[k]--;
			if(!indegree[k]) { e1.adjvex=k;	push(s,e1);}
			if((E[e.adjvex]+p->value)>E[k]){ E[k]=(E[e.adjvex]+p->value);}
			//拓扑排序求得每个顶点的最早发生时间
		}
	}
	return count;
}
void CriticalPath(ALGraph G)
{//关键路径的求取、适用于图中关键路径唯一
	stack T;int i,j,min;node e;Acnode *p;
	CreatStack(T);
	if(TopologicalSort(G,T)<G.Vexnum)
		printf("图G中存在环，无法求取关键路径！\n");
	else
	{
		for(i=0;i<G.Vexnum;i++)
		{	L[i]=E[i];//初始化每个顶点的最迟发生时间  }
		while(!EmptyStack(T))
		{
			pop(T,e);
			if(G.Vertex[e.adjvex].firstarc!=NULL)
			{
				p=G.Vertex[e.adjvex].firstarc;
				min=L[p->adjvex]-p->value;
			 for(p=G.Vertex[e.adjvex].firstarc;p!=NULL;p=p->next)
			 {
				 if(min>L[p->adjvex]-p->value)
					 min=L[p->adjvex]-p->value;
			 }
			 L[e.adjvex]=min;//求得各顶点的最迟发生时间
	//最迟发生时间为该顶点邻接点的最迟发生时间减去该顶点到其邻接点的活动所用时间的最小值
			}
		}
		printf("关键路径上的顶点为：");
		for(j=0;j<G.Vexnum;j++)
			if(visted[j]==0)
			DFS(G,j);
//DFS经过改进输出图G中的关键路径上的顶点.若E[i]==L[i]则i是关键路径上的顶点
		printf("\n");
	}
}