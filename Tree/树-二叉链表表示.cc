/**
date: 2012年09月
author: gaooz.com
*/

typedef struct CSNode{//树的二叉链表定义
	int data;
	struct CSNode *firstchild,*nextslibing;
}CSNode,*CSTree;

typedef struct {
	CSTree *base;
	int front,rear;
}Queue;//队列定义

//构造树结构
void CreatTree(CSTree &T)
{
	T=NULL;
	Queue Q;
	CSTree p,s,r;
	InitQueue(Q);
	int fa,ch;//我们约定0代表空树,-1为根结点的根结点
	for(scanf("%d%d",&fa,&ch);ch!=0;scanf("%d%d",&fa,&ch))
	{
		p=(CSTree)malloc(sizeof(CSNode));
		p->data=ch;
		p->firstchild=NULL;
		p->nextslibing=NULL;
		EnterQueue(Q,p);
		if(fa==-1)
			T=p;
		else
		{
			GetQueueHead(Q,s);
			while(s->data!=fa)
          {DeleteQueue(Q);GetQueueHead(Q,s);}
			if(!s->firstchild)
			{s->firstchild=p;r=p;}
			else
			{r->nextslibing=p;r=p;}
		}
	}
}