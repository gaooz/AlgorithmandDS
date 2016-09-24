/**
date: 2012年09月
author: gaooz.com
*/

/*-----------------------------------------------------
十字链表存储结构是有向图（有向网）的另一种链式存储结构、
可以把十字链表看成是邻接矩阵的链式存储形式
-------------------------------------------2012年9月12*/
typedef struct ArcBox{
	int tailvex,headvex;
	struct ArcBox *hlink,*tlink;
	char *info;
}ArcBox;//弧表结点的定义
typedef struct VexNode{
	int data;
	ArcBox *firstin,*firstout;//指向第一个入结点和第一个出结点
}VexNode;//顶点结点的定义
typedef struct {
	VexNode xlist[MAX_NUM];
	int vexnum,arcnum;
}OLGraph;//图的定义
void CreatOLGraph_DN(OLGraph &G)
{//构造十字链表形式的有向图
	int i,j,sign1,sign2;VexNode v1,v2;ArcBox *p,*q;
	printf("--------------有向图十字链表-------------\n");
	printf("请输入该有向图顶点的数目和弧的数目：");
	scanf("%d%d",&G.vexnum,&G.arcnum);
	if(G.vexnum==0)
		printf("图为空图！\n");
	else
	{
		printf("请初始化这%d个顶点：",G.vexnum);
			for(i=0;i<G.vexnum;i++)
			{
				scanf("%d",&G.xlist[i].data);
				G.xlist[i].firstin=NULL;
				G.xlist[i].firstout=NULL;//初始化指针
			}
		if(G.arcnum==0)
			printf("图为零图！\n");
		else
		{
			printf("请初始化这%d条弧：",G.arcnum);
			printf("\n格式：顶点1 顶点2（表示顶点1邻接到顶点2）\n");
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
				q->hlink=NULL;q->tlink=NULL;//初始化
				p=G.xlist[sign1].firstout;
				if(p==NULL)
					G.xlist[sign1].firstout=q;//注意不能写成p=q
				else
				{
					while(p->tlink!=NULL)
						p=p->tlink;
					p->tlink=q;
				}//链接firstout指向的链表
				p=G.xlist[sign2].firstin;
				if(p==NULL)
					G.xlist[sign2].firstin=q;//注意不能写成p=q
				else
				{
					while(p->hlink!=NULL)
						p=p->hlink;
					p->hlink=q;
				}//链接顶点中firstin指向的链表
			}
		}
	}
}
void TaverseOLGraph(OLGraph &G)
{//输出十字链表形式的有向图
	int i,sign;ArcBox *p;
	printf("\n输出有向图中结点间的关系：\n");
	for(i=0;i<G.vexnum;i++)
	{
		p=G.xlist[i].firstout;
		while(p)
		{
			sign=p->headvex;
			printf("顶点%d邻接到顶点%d\n",G.xlist[i].data,G.xlist[sign].data);
			p=p->tlink;
		}
	}
}