
/**
date: 2012年09月
author: gaooz.com
*/

/*-------------------------------------------------------------------------------
邻接多重表是无向图（无向网）的另一种链式存储结构、邻接多重表是邻接表的一种扩展，
在邻接表中一条边用两个边表结点表示，而在邻接多重表中则用一的边结点表示，则自然邻
接多重表中的链域比邻接多表，而出去mark标志域外，邻接多重表和邻接表占用的空间相同
----------------------2012/09/12*/
typedef struct EBox{
	int mark;//标记边是否已被访问
	int ivex,jvex;//顶点在图中的位置域
	struct EBox *ilink,*jlink;
	char *info;
}EBox;//边结点定义
typedef struct VexBox{
	int data;
	EBox *firstedge;//指向第一条依附于该顶点的边
}VexBox;
typedef struct{
	VexBox adjmulist[MAX_NUM];
	int vexnum,edgenum;
}AMLGraph;//图定义
void CreatAMLGraph(AMLGraph &G)
{//邻接多重表无向图的构造，过程类似于十字链表有向图的构造
	int i,j,sign1,sign2;EBox *p,*q,*k;VexBox v1,v2;
	printf("------------邻接多重表构造无向图------------\n");
	printf("请输入无向图的顶点数以及边数：");
	scanf("%d%d",&G.vexnum,&G.edgenum);
	if(G.vexnum==0)
		printf("该图为空图！\n");
	else
	{
		printf("请初始化这%d个顶点：",G.vexnum);
		for(i=0;i<G.vexnum;i++)
		{	scanf("%d",&G.adjmulist[i].data);
		G.adjmulist[i].firstedge=NULL;
		}
		if(G.edgenum==0)
			printf("该图为零图\n");
		else
		{
			printf("请初始化这%d条边：\n",G.edgenum);
			printf("格式：顶点1 顶点2（表示顶点1与顶点2共边）\n");
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
			if(p==NULL)//构造过程重点在于边链表的建立
				G.adjmulist[sign1].firstedge=q;
			else
			{
				while(p)
				{
					k=p;
					if(sign1==p->ivex)//判断路径
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