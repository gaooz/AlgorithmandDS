/**
date: 2012��09��
author: gaooz.com
*/

typedef struct CSNode{//���Ķ���������
	int data;
	struct CSNode *firstchild,*nextslibing;
}CSNode,*CSTree;

typedef struct {
	CSTree *base;
	int front,rear;
}Queue;//���ж���

//�������ṹ
void CreatTree(CSTree &T)
{
	T=NULL;
	Queue Q;
	CSTree p,s,r;
	InitQueue(Q);
	int fa,ch;//����Լ��0�������,-1Ϊ�����ĸ����
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