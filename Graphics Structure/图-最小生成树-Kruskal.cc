/**
date: 2012��09��
author: gaooz.com
*/

//----------------Kruskal�㷨---------------------2012��9��22
int pfun(ALGraph &G,int i,int j)
{//�ж�ͼG�е�i������͵�j�������Ƿ���ͬһ����ͨ������
	int k;
	for(k=0;k<G.Vexnum;k++)
		visted[k]=0;
	DFS(G,i);
	if(visted[j]==1)
		return 1;
	return 0;
}
void Kruskal(ALGraph G,ALGraph &T)
{//��³˹�����㷨������С������
	closedge Edge;int i,j=0,flag=1,k,sign,lowcost;AcNode *p,*q;
	Edge.length=0;
	for(i=0;i<G.Vexnum;i++)
	{//��ʼ��T(��С�������а���ͼ�����ж���)	
		T.Vertex[i].Gdata=G.Vertex[i].Gdata;
		T.Vertex[i].firstarc=NULL;
	}
	T.Vexnum=G.Vexnum;T.Arcnum=0;
	for(i=0;i<G.Vexnum;i++)
	{//��ͼ�е����еı߼���Edge��
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
	printf("�ҵ���С��Ϊ��<%d,%d,%d>  ",Edge.edge[sign].i,Edge.edge[sign].j,Edge.edge[sign].value);
	if(!pfun(T,Edge.edge[sign].i,Edge.edge[sign].j))
		{//����ñ����������������㲻��ͬһ����ͨ��������Ѹñ߼�����С��������
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
			Edge.edge[sign].value=0;//��ʾ�ñ��Ѳ�����С������
			printf("�ɹ�����<%d,%d,%d>������С������\n",Edge.edge[sign].i,Edge.edge[sign].j,lowcost);
	}
	}
}