/**
date: 2012��09��
author: gaooz.com
*/

//-----------------�����������-----------------2012��09��13
void BFS(ALGraph &G,int v)
{
	int w,sign,i;node e,e1;Queue q;VertexNode vv;
	InitQueue(q);
	visted[v]=1;//��־�������ʾ�ѱ�����
	e.data=G.Vertex[v].data;InsertQueue(q,e);
	while(!EmptyQueue(q))
	{
		for(i=0;i<G.Vexnum;i++)
			if(G.Vertex[i].data==q.base[q.front].data)
				sign=i;//�ҵ���ͷ�����ͼ�е�λ��
		for(w=FirstAdjvex(G,sign);w>=0;w=NextAdjvex(G,sign,w))
			if(!visted[w])//ѭ�����������ҵ����ж��������ڽӵ����β������
			{
				e.data=G.Vertex[w].data;InsertQueue(q,e);
				visted[w]=1;
			}
		DeleteQueue(q,e1);vv.data=e1.data;VistGraph(vv);
//���궥��������ڽӵ��ö�����ӣ�Ȼ��������
	}
}
void BFSTraverse(ALGraph &G)
{//�����������
	int i;
	for(i=0;i<G.Vexnum;i++) visted[i]=0;
	for(i=0;i<G.Vexnum;i++)
		if(!visted[i]) BFS(G,i);
}