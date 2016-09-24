/**
date: 2012��09��
author: gaooz.com
*/

/*--------------------------------------------------------------------
�ڽӱ�洢��ʾ��������ڽӾ���洢�ṹ��˵��Ϊϡ��ͼʱ��Ϊ��ʡ�洢�ռ�
�����ڽӱ�洢����ͼ����������ʱ�������ڼ�������Ķ�
------------------------------------------------------2012��09��11*/
#define MAX_NUM 20//��󶥵���Ŀ
typedef enum {DG,DN,UDG,UDN} GraphKind;//ͼ����
typedef struct Acnode{
	int adjvex;//��Ŷ����������е�λ��
	int value;//Ȩֵ�����ﶨ��Ϊ����
	struct Acnode *next;
	char *info;//��Ż�����Ϣ
}Acnode;//���Ķ���
typedef struct {
	int data;
	Acnode *firstarc;
}VertexNode;//���㶨��
typedef struct{
	VertexNode Vertex[MAX_NUM];
	int Vexnum,Arcnum;//��ǰ������Ŀ������Ŀ
	GraphKind kind;//ͼ������
}ALGraph;//ͼ�Ķ���
void CreatGraph_DN(ALGraph &G)
{//�������Ĺ��죬�����ڽӱ�ʵ��
	Acnode *p,*q;int i,j,sign1,sign2,Value;
	VertexNode v1,v2;
	printf("�����ڽӾ���洢��ʾ����������\n");
	G.kind=DN;
	printf("��������������Ķ�����Ŀ�ͻ�����Ŀ��");
	scanf("%d%d",&G.Vexnum,&G.Arcnum);
	printf("���ʼ����%d�����㣺",G.Vexnum);
	for(i=0;i<G.Vexnum;i++)
	{
		scanf("%d",&G.Vertex[i].data);
		G.Vertex[i].firstarc=NULL;
	}
	printf("���ʼ������֮��Ĺ�ϵ��%d��������\n",G.Arcnum);
	printf("��ʽ������1 ����2 Ȩֵ����ʾ����1�ڽӵ�����2��\n");
	for(i=0;i<G.Arcnum;i++)
	{
		sign1=-1;sign2=-1;
		scanf("%d%d%d",&v1.data,&v2.data,&Value);
		for(j=0;j<G.Vexnum;j++)
		{
			if(G.Vertex[j].data==v1.data)
				sign1=j;
			if(G.Vertex[j].data==v2.data)
				sign2=j;
		}
		if(sign1==-1||sign2==-1)
			printf("��Ϣ��������\n");
		else
		{
			p=(Acnode*)malloc(sizeof(Acnode));
		    p->next=NULL;
			p->adjvex=sign2;
			p->value=Value;//���컡����
			q=G.Vertex[sign1].firstarc;
			if(q==NULL)//���뻡����������������
				G.Vertex[sign1].firstarc=p;
			else
			{
				while(q->next!=NULL)
				q=q->next;
			    q->next=p;
			}
		}
	}
}
int *CountVerNum_DN(ALGraph G)
{//��������Ķ�
	//�ڽӱ�洢���������������㶥��Ķ�ʱ������Ϊ���������л��������Ŀ
	//���������������ڽӱ������Ӧ�Ķ������ȣ�Ȼ���������ӵõ�������Ķ�
	int D[MAX_NUM],ID[MAX_NUM],OD[MAX_NUM];int i;
	Acnode *p;
	for(i=0;i<G.Vexnum;i++)
	{
		D[i]=0;ID[i]=0;OD[i]=0;
	}
	for(i=0;i<G.Vexnum;i++)
	{
		p=G.Vertex[i].firstarc;
		if(p==NULL)
			OD[i]=0;
		else
			while(p!=NULL)
			{
				OD[i]++;
				ID[p->adjvex]++;
				p=p->next;
			}
	}
	for(i=0;i<G.Vexnum;i++)
		D[i]=ID[i]+OD[i];
	return D;
}