/**
date: 2012��09��
author: gaooz.com
*/

//------------------��������������ڽӱ�洢ͼ�ṹ��----------------------2012��09��13
int visted[MAX_NUM];//����Ϊȫ�ֱ�������Ÿ������Ƿ��ѱ����ʱ�־
void VistGraph(VertexNode V)
{//���ʶ������
	printf("%d ",V.data);
}
int FirstAdjvex(ALGraph &G,int v)
{//�õ�ͼG�е�v������ĵ�һ���ڽӶ�������λ��
	Acnode *p;p=G.Vertex[v].firstarc;
	if(p==NULL)
		return -1;
	return p->adjvex;
}
int NextAdjvex(ALGraph &G,int v,int w)
{//�õ�w������һ�ڽӵ��λ��
	Acnode *p;p=G.Vertex[v].firstarc;
	while(p->adjvex!=w&&p!=NULL)
		p=p->next;
	p=p->next;
	if(p==NULL)
		return -1;
	return p->adjvex;
}
void DFS(ALGraph &G,int v)
{//��������������Ĺ��̡�����v��ʾ��ͼ�е�v����㿪ʼ������ȱ���
	int w;
	VertexNode V;V=G.Vertex[v];
	visted[v]=1;VistGraph(V);//��ö������ڱ�־Ϊ1��ʾ�ѷ��ʣ�Ȼ����ʸö���
	for(w=FirstAdjvex(G,v);w>=0;w=NextAdjvex(G,v,w))
		if(!visted[w]) DFS(G,w);
}
void DFSTraverse(ALGraph &G)
{//�����������
	int i;
	for(i=0;i<G.Vexnum;i++) visted[i]=0;//���ȳ�ʼ�����ʱ�־
	for(i=0;i<G.Vexnum;i++)
		if(!visted[i]) DFS(G,i);
}