/**
date: 2012年09月
author: gaooz.com
*/

/*--------------------------------------------------------------------
邻接表存储表示，相对于邻接矩阵存储结构来说当为稀疏图时较为节省存储空间
但用邻接表存储有向图（有向网）时，不便于计算各结点的度
------------------------------------------------------2012年09月11*/
#define MAX_NUM 20//最大顶点数目
typedef enum {DG,DN,UDG,UDN} GraphKind;//图类型
typedef struct Acnode{
	int adjvex;//存放顶点在数组中的位置
	int value;//权值，这里定义为整型
	struct Acnode *next;
	char *info;//存放弧的信息
}Acnode;//弧的定义
typedef struct {
	int data;
	Acnode *firstarc;
}VertexNode;//顶点定义
typedef struct{
	VertexNode Vertex[MAX_NUM];
	int Vexnum,Arcnum;//当前顶点数目、弧数目
	GraphKind kind;//图的类型
}ALGraph;//图的定义
void CreatGraph_DN(ALGraph &G)
{//有向网的构造，利用邻接表实现
	Acnode *p,*q;int i,j,sign1,sign2,Value;
	VertexNode v1,v2;
	printf("利用邻接矩阵存储表示构造有向网\n");
	G.kind=DN;
	printf("请输入该有向网的顶点数目和弧的数目：");
	scanf("%d%d",&G.Vexnum,&G.Arcnum);
	printf("请初始化这%d个顶点：",G.Vexnum);
	for(i=0;i<G.Vexnum;i++)
	{
		scanf("%d",&G.Vertex[i].data);
		G.Vertex[i].firstarc=NULL;
	}
	printf("请初始化顶点之间的关系（%d条弧）：\n",G.Arcnum);
	printf("形式：顶点1 顶点2 权值（表示顶点1邻接到顶点2）\n");
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
			printf("信息输入有误！\n");
		else
		{
			p=(Acnode*)malloc(sizeof(Acnode));
		    p->next=NULL;
			p->adjvex=sign2;
			p->value=Value;//构造弧表结点
			q=G.Vertex[sign1].firstarc;
			if(q==NULL)//链入弧表结点至顶点链表中
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
{//计算各结点的度
	//邻接表存储的有向网，当计算顶点的度时，出度为顶点链表中弧表结点的数目
	//入度则需遍历整个邻接表求得相应的顶点的入度，然后与出度相加得到个顶点的度
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