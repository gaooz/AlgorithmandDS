/**
date: 2012��09��
author: gaooz.com
*/

/*-----------------------------------------------------
ʮ������洢�ṹ������ͼ��������������һ����ʽ�洢�ṹ��
���԰�ʮ�����������ڽӾ������ʽ�洢��ʽ
-------------------------------------------2012��9��12*/
typedef struct ArcBox{
	int tailvex,headvex;
	struct ArcBox *hlink,*tlink;
	char *info;
}ArcBox;//������Ķ���
typedef struct VexNode{
	int data;
	ArcBox *firstin,*firstout;//ָ���һ������͵�һ�������
}VexNode;//������Ķ���
typedef struct {
	VexNode xlist[MAX_NUM];
	int vexnum,arcnum;
}OLGraph;//ͼ�Ķ���
void CreatOLGraph_DN(OLGraph &G)
{//����ʮ��������ʽ������ͼ
	int i,j,sign1,sign2;VexNode v1,v2;ArcBox *p,*q;
	printf("--------------����ͼʮ������-------------\n");
	printf("�����������ͼ�������Ŀ�ͻ�����Ŀ��");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	if(G.vexnum==0)
		printf("ͼΪ��ͼ��\n");
	else
	{
		printf("���ʼ����%d�����㣺",G.vexnum);
			for(i=0;i<G.vexnum;i++)
			{
				scanf("%d",&G.xlist[i].data);
				G.xlist[i].firstin=NULL;
				G.xlist[i].firstout=NULL;//��ʼ��ָ��
			}
		if(G.arcnum==0)
			printf("ͼΪ��ͼ��\n");
		else
		{
			printf("���ʼ����%d������",G.arcnum);
			printf("\n��ʽ������1 ����2����ʾ����1�ڽӵ�����2��\n");
			for(i=0;i<G.arcnum;i++)
			{
				scanf("%d%d",&v1.data,&v2.data);
				for(j=0;j<G.vexnum;j++)
				{	if(G.xlist[j].data==v1.data)
						sign1=j;
				if(G.xlist[j].data==v2.data)
					sign2=j;
				}
				q=(ArcBox*)malloc(sizeof(ArcBox));
				q->tailvex=sign1;q->headvex=sign2;
				q->hlink=NULL;q->tlink=NULL;//��ʼ��
				p=G.xlist[sign1].firstout;
				if(p==NULL)
					G.xlist[sign1].firstout=q;//ע�ⲻ��д��p=q
				else
				{
					while(p->tlink!=NULL)
						p=p->tlink;
					p->tlink=q;
				}//����firstoutָ�������
				p=G.xlist[sign2].firstin;
				if(p==NULL)
					G.xlist[sign2].firstin=q;//ע�ⲻ��д��p=q
				else
				{
					while(p->hlink!=NULL)
						p=p->hlink;
					p->hlink=q;
				}//���Ӷ�����firstinָ�������
			}
		}
	}
}
void TaverseOLGraph(OLGraph &G)
{//���ʮ��������ʽ������ͼ
	int i,sign;ArcBox *p;
	printf("\n�������ͼ�н���Ĺ�ϵ��\n");
	for(i=0;i<G.vexnum;i++)
	{
		p=G.xlist[i].firstout;
		while(p)
		{
			sign=p->headvex;
			printf("����%d�ڽӵ�����%d\n",G.xlist[i].data,G.xlist[sign].data);
			p=p->tlink;
		}
	}
}