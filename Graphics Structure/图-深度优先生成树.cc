/**
date: 2012��09��
author: gaooz.com
*/

//-------------------��������������Ĺ���-------------2012��09��15
void DFSTree(ALGraph &G,int v,Tree &T)
{//��ͼ�е�v�����㹹���������������T
	int w;Tree p,q;
	visted[v]=1;
	for(w=FirstAdjvex(G,v);w>=0;w=NextAdjvex(G,v,w))
		if(!visted[w])
		{
			p=(Tree)malloc(sizeof(TNode));
			p->Tdata=G.Vertex[w].Gdata;
			p->firstchild=NULL;p->nextsibling=NULL;
			if(T->firstchild==NULL)//First�����жϸý����Ƿ��Ѵ���������
			{ T->firstchild=p; }
			else q->nextsibling=p;
			q=p;
			DFSTree(G,w,q);//�ݹ����
		}
}
void DFSForest(ALGraph &G,Tree &T)
{//����ͼG���������������T
	int i;Tree p,q;
	T=NULL;
	for(i=0;i<G.Vexnum;i++)
		visted[i]=0;//��ʼʱ�ö���Ϊδ������״̬
	for(i=0;i<G.Vexnum;i++)
	if(!visted[i])
	{
		p=(Tree)malloc(sizeof(TNode));
		p->Tdata=G.Vertex[i].Gdata;
		p->firstchild=NULL;p->nextsibling=NULL;
		if(T==NULL) T=p;//�����Ϊ������pΪ�������
		else q->nextsibling=p;//��Ϊ��ͨͼ��else��䲻��ִ��,������������������Ҳֻ��������
		//��Ϊ����ͨͼ��ͨ��һ�����㲻�ܱ���ͼ�����ж��㣬����������������������������
		//�ɸ���һ���Ĺ�������������������ͼ����ͨ����
		q=p;
		DFSTree(G,i,p);//���ù���������������p���������������
	}
}