/**
date: 2012年09月
author: gaooz.com
*/

//-----------------广度优先搜索-----------------2012、09、13
void BFS(ALGraph &G,int v)
{
	int w,sign,i;node e,e1;Queue q;VertexNode vv;
	InitQueue(q);
	visted[v]=1;//标志域更换表示已被访问
	e.data=G.Vertex[v].data;InsertQueue(q,e);
	while(!EmptyQueue(q))
	{
		for(i=0;i<G.Vexnum;i++)
			if(G.Vertex[i].data==q.base[q.front].data)
				sign=i;//找到表头结点在图中的位置
		for(w=FirstAdjvex(G,sign);w>=0;w=NextAdjvex(G,sign,w))
			if(!visted[w])//循环的作用是找到表中顶点所有邻接点依次插入队列
			{
				e.data=G.Vertex[w].data;InsertQueue(q,e);
				visted[w]=1;
			}
		DeleteQueue(q,e1);vv.data=e1.data;VistGraph(vv);
//找完顶点的所以邻接点后该顶点出队，然后访问输出
	}
}
void BFSTraverse(ALGraph &G)
{//广度优先搜索
	int i;
	for(i=0;i<G.Vexnum;i++) visted[i]=0;
	for(i=0;i<G.Vexnum;i++)
		if(!visted[i]) BFS(G,i);
}