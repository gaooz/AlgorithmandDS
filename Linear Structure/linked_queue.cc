/**
date: 2012��09��
author: gaooz.com
*/

/**
��ʽ���н����������������ʵ��
*/
//------�����е�����������-------//
typedef struct Node
{
	int a;
	struct Node *next;
}Qnode,*QueuePtr;
typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue &Q)
{
	Q.front=(Qnode *)malloc(sizeof(Qnode));
	if(!Q.front)
		exit(1);
	Q.rear=Q.front;
	Q.front->next=NULL;
}
void InsertQueue(LinkQueue &Q,Qnode e)
{
	QueuePtr p;
	p=(Qnode *)malloc(sizeof(Qnode));
	if(!p)
		exit(1);
	*p=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
void DeleteQueue(LinkQueue &Q,Qnode &e)
{
	Qnode *p;
	if(Q.front==Q.rear)
		printf("����Ϊ�գ�\n");
	else
	{
		p=Q.front->next;
		e=*p;
		Q.front->next=p->next;
		if(p==Q.rear)
			Q.rear=Q.front;
		free(p);
	}
}