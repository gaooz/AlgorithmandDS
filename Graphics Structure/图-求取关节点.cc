/**
date: 2012��09��
author: gaooz.com
*/

//-----------------------�ؽڵ����ȡ---------------------------2012��9��19
void DFSArticul(ALGraph G,int v)
{//��ͼ�е�v����������������������ؽ��
	int min,w;AcNode *p;
	visted[v]=min=++count;
	for(p=G.Vertex[v].firstarc;p;p=p->next)
	{
		w=p->adjvex;
		if(visted[w]==0) 
		{
			DFSArticul(G,w);
			if(low[w]<min) min=low[w];
			if(low[w]>=visted[v]&&!finash[v])//finash[]��ʾ���ý���Ѿ�����������ظ����
			{
				printf("%d ",G.Vertex[v].Gdata.data);
				finash[v]=1;
			}
		}
		else
			if(visted[w]<min) min=visted[w];//wΪ��ر߽��
	}
	low[v]=min;
}
void FindArticul(ALGraph G)
{//��ͼ�����еĹؽڵ㲢�����Щ���
	int i,v,v1=0;AcNode *p;
	count=1;
	visted[0]=1;low[0]=1;//������ڽӱ��е�һ����㿪ʼ����������ý��Ϊ�������������������
	for(i=1;i<G.Vexnum;i++) { visted[i]=0;finash[i]=0;}//��ʼ��������δ���ʵĽ������
	p=G.Vertex[0].firstarc;v=p->adjvex;
	DFSArticul(G,v);
	if(count<G.Vexnum)
	{ printf("%d ",G.Vertex[0].Gdata.data);
	//һ������δ�ܱ���ͼ�����ԵĶ�����˵������������ٴ�������������˵������Ϊ�ؽڵ�
	 while(p->next)
	 {
		p=p->next;v=p->adjvex;
		if(visted[v]==0)
		DFSArticul(G,v);
	 }
	}
}//��ȡlow[]��ԭ��������ݽṹ�ʼǡ�