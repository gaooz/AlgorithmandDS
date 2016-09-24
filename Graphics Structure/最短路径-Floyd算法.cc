/**
date: 2012��09��
author: gaooz.com
*/

//---------------���·����Floyd�㷨------------------2012��9��25
//Floyd�㷨��������ͼ��һ�Զ��㼴�����붥��֮�����·�����㷨��

typedef int Path[MAX_NUM][MAX_NUM][MAX_NUM];//���·��
typedef int Dist[MAX_NUM][MAX_NUM];//������·������

void ShortPath_Floyd(MGraph G,Path &p,Dist &d)
{//Floyd�㷨����������ͼ��һ�Զ���֮������·��
	//·���������ά����p�У����·�����ȴ���ڶ�ά����d��
	int i,u,v,w;
	for(v=0;v<G.Vexnum;v++)//��ʼ��
		for(w=0;w<G.Vexnum;w++)
		{
			d[v][w]=G.arcs[v][w].Value;
			for(u=0;u<G.Vexnum;u++)
				p[v][w][u]=0;
				if(d[v][w]<MAX)
				{
					p[v][w][v]=1;//���
					p[v][w][w]=1;//�յ�
				}
		}
		for(u=0;u<G.Vexnum;u++)
			for(v=0;v<G.Vexnum;v++)
				for(w=0;w<G.Vexnum;w++)
					if(d[v][u]+d[u][w]<d[v][w])
					{
						d[v][w]=d[v][u]+d[u][w];
						for(i=0;i<G.Vexnum;i++)
							p[v][w][i]=p[v][u][i]||p[u][w][i];
					}
}