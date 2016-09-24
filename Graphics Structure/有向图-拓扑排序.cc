
/**
date: 2012年09月
author: gaooz.com
*/

//--------------------------------拓扑排序----------------------------------
/*AOV网拓扑排序
AOV网是有向无环网的一种，网中顶点表示活动，弧表示活动执行的优先顺序
拓扑排序输出AOV网中所有顶点----2012年9月21*/
void TopologicalSort(ALGraph G)
{//拓扑排序
	int indegree[MAX_NUM],count=0,k,i;Acnode *p;node e;
	stack s;
	CreatStack(s);
	for(i=0;i<G.Vexnum;i++)
		indegree[i]=0;//初始化顶点入度信息
	for(i=0;i<G.Vexnum;i++)
	{//遍历邻接表求得图中每个顶点的入度
		p=G.Vertex[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p=p->next;
		}
	}
	for(i=0;i<G.Vexnum;i++)//找到indegree数组中入度为0的顶点然后入栈
		if(!indegree[i]){ e.adjvex=i;	push(s,e);}
	while(!EmptyStack(s))
	{ 
		pop(s,e);printf("%d ",G.Vertex[e.adjvex]);
		count++;//对输出的顶点计数
		for(p=G.Vertex[e.adjvex].firstarc;p!=NULL;p=p->next)
		{
			k=p->adjvex;
			indegree[k]--;
			if(!indegree[k]) { e.adjvex=k;	push(s,e);}
			//删除下标为p->adjvex的顶点相关的边，并将度为0的顶点入栈
		}
	}
	if(count<G.Vexnum)
		printf("未能输出图中所有顶点，图中定存在环。\n");
}