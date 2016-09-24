/**
date: 2012��09��
author: gaooz.com
*/

//----------------���·����Dijkstra�㷨-------------------2012��9��25
//Dijkstra�㷨��������ͼ�е�һ��Դ����ͼ��������������·����
//ע�⣺���㷨ͼG���ڽӾ���������䲻����ʱ��MAX��ʾ��������-1��ʾ

typedef int Path[MAX_NUM][MAX_NUM];//���·��
typedef int Dist[MAX_NUM];//������·������

void ShortPath_Dijkstra(MGraph G,VertexNode v,Path &P,Dist &D)
{//���·��_�Ͻ�˹�����㷨
	//��ͼG�ж���vΪԴ����Դ�㵽������������·��,·������ڶ�ά����p��
	//Դ�㵽���������·�����ȴ����һά����D��
	int i,v0,j,w,k,n,Final[MAX_NUM],min;
	for(i=0;i<G.Vexnum;i++)
		if(v.data==G.Vertex[i].data) { v0=i; break; }
	for(i=0;i<G.Vexnum;i++)
	{//��ʼ��
		Final[i]=0;
		D[i]=G.arcs[v0][i].Value;
		for(j=0;j<G.Vexnum;j++)
			P[i][j]=0;//������·��Ϊ��
		if(D[i]<MAX)
		{
			P[i][v0]=1;//���
			P[i][i]=1;//�յ�
		}
	}
	D[v0]=0;Final[v0]=1;
	for(i=1;i<G.Vexnum;i++)
	{//������n-1����������·��
		min=MAX;
		for(j=0;j<G.Vexnum;j++)
			if(min>D[j]&&Final[j]==0)
			{ min=D[j];w=j;}
			Final[w]=1;//��ʾԴ�㵽�ö�������·���Ѿ��ҵ�
		for(k=0;k<G.Vexnum;k++)
			if(Final[k]==0&&D[k]>min+G.arcs[w][k].Value)
			{//�޸�D���������·�����ȵ�ֵ
				D[k]=min+G.arcs[w][k].Value;
				for(n=0;n<G.Vexnum;n++)
				P[k][n]=P[w][n];
				P[k][k]=1;//·��
			}
	}
}