
/**
date: 2012��09��
author: gaooz.com
*/

/*-------------------------------------------------------------------------------
�ڽӶ��ر�������ͼ��������������һ����ʽ�洢�ṹ���ڽӶ��ر����ڽӱ��һ����չ��
���ڽӱ���һ�����������߱����ʾ�������ڽӶ��ر�������һ�ı߽���ʾ������Ȼ��
�Ӷ��ر��е�������ڽӶ������ȥmark��־���⣬�ڽӶ��ر���ڽӱ�ռ�õĿռ���ͬ
----------------------2012/09/12*/
typedef struct EBox{
	int mark;//��Ǳ��Ƿ��ѱ�����
	int ivex,jvex;//������ͼ�е�λ����
	struct EBox *ilink,*jlink;
	char *info;
}EBox;//�߽�㶨��
typedef struct VexBox{
	int data;
	EBox *firstedge;//ָ���һ�������ڸö���ı�
}VexBox;
typedef struct{
	VexBox adjmulist[MAX_NUM];
	int vexnum,edgenum;
}AMLGraph;//ͼ����
void CreatAMLGraph(AMLGraph &G)
{//�ڽӶ��ر�����ͼ�Ĺ��죬����������ʮ����������ͼ�Ĺ���
	int i,j,sign1,sign2;EBox *p,*q,*k;VexBox v1,v2;
	printf("------------�ڽӶ��ر�������ͼ------------\n");
	printf("����������ͼ�Ķ������Լ�������");
	scanf("%d%d",&G.vexnum,&G.edgenum);
	if(G.vexnum==0)
		printf("��ͼΪ��ͼ��\n");
	else
	{
		printf("���ʼ����%d�����㣺",G.vexnum);
		for(i=0;i<G.vexnum;i++)
		{	scanf("%d",&G.adjmulist[i].data);
		G.adjmulist[i].firstedge=NULL;
		}
		if(G.edgenum==0)
			printf("��ͼΪ��ͼ\n");
		else
		{
			printf("���ʼ����%d���ߣ�\n",G.edgenum);
			printf("��ʽ������1 ����2����ʾ����1�붥��2���ߣ�\n");
			for(i=0;i<G.edgenum;i++)
			{
				scanf("%d%d",&v1.data,&v2.data);
			    for(j=0;j<G.vexnum;j++)
				{	
				if(G.adjmulist[j].data==v1.data)
			      sign1=j;
			    if(G.adjmulist[j].data==v2.data)
				  sign2=j;
			    }
			q=(EBox*)malloc(sizeof(EBox));
			q->ivex=sign1;q->jvex=sign2;
			q->ilink=NULL;q->jlink=NULL;
			p=G.adjmulist[sign1].firstedge;
			if(p==NULL)//��������ص����ڱ�����Ľ���
				G.adjmulist[sign1].firstedge=q;
			else
			{
				while(p)
				{
					k=p;
					if(sign1==p->ivex)//�ж�·��
						p=p->ilink;
					else
						p=p->jlink;
				}
				if(sign1==k->ivex)
					k->ilink=q;
				else
					k->jlink=q;
			}
			p=G.adjmulist[sign2].firstedge;
			if(p==NULL)
				G.adjmulist[sign2].firstedge=q;
			else
			 {
				while(p)
				{
					k=p;
					if(sign2==p->ivex)
						p=p->ilink;
					else
						p=p->jlink;
				}
				if(sign2==k->ivex)
					k->ilink=q;
				else
					k->jlink=q;
			 }
			}
		}
	}
}