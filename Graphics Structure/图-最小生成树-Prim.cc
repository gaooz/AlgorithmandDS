/**
date: 2012��09��
author: gaooz.com
*/

//----------------Prim�㷨------------------2012��09��20
typedef struct {
	int adjvex;
	int lowcost;
}close[MAX_NUM];//��������Ķ���
void MinispanTree_PRIM(MGraph G,MGraph &T)
{//Prim�㷨��С�������Ĺ���
	int k=0,i,j,m,lowcost;//�涨�ӵ�0�����㿪ʼ
	close closedge;length=G.Vexnum;//�������������
	T.Vexnum=G.Vexnum;
	for(i=0;i<G.Vexnum;i++)
		T.Vertex[i].data=G.Vertex[i].data;
	for(i=0;i<G.Vexnum;i++)
		for(j=0;j<G.Vexnum;j++)
			T.arcs[i][j].Graph_Net.Value=-1;
	for(i=0;i<G.Vexnum;i++)
	{	
		closedge[i].adjvex=k;
		closedge[i].lowcost=G.arcs[k][i].Graph_Net.Value;
	}
	closedge[k].lowcost=0;//�ѵ�0����㲢����С������
	for(m=1;m<G.Vexnum;m++)
 {
	 lowcost=MAX;
	for(i=1;i<G.Vexnum;i++)
	{
		if(lowcost>closedge[i].lowcost&&closedge[i].lowcost!=0&&closedge[i].lowcost!=-1)
		{
			lowcost=closedge[i].lowcost;
			k=i;
		}
	}
	T.arcs[closedge[k].adjvex][k].Graph_Net.Value=lowcost;
	T.arcs[k][closedge[k].adjvex].Graph_Net.Value=lowcost;
	closedge[k].lowcost=0;//�൱�ڰѵ�k����㲢����С������
	for(i=1;i<G.Vexnum;i++)
	{
	if((G.arcs[k][i].Graph_Net.Value<closedge[i].lowcost&&G.arcs[k][i].Graph_Net.Value!=-1)||closedge[i].lowcost==-1)
		{
			closedge[i].lowcost=G.arcs[k][i].Graph_Net.Value;
			closedge[i].adjvex=k;
		}
	}
 }
}