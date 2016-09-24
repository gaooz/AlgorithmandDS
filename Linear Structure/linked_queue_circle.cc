/**
date: 2012��09��
author: gaooz.com
*/

/**
��ʽѭ������
*/
//-------------ѭ������---------------//
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct queue
{
	node *base;
	int front;
	int rear;
}Queue;
int tag;
void InitQueue(Queue &Q)
{
	Q.base=(node *)malloc(MAX*sizeof(node));
	if(!Q.base)
		exit(1);
	Q.front=Q.rear=0;
	tag=0;
}
void InsertQueue(Queue &Q,node e)
{
	if(tag==1&&Q.front==Q.rear)
		printf("ѭ������������\n");
	else
	{
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAX;
		if(Q.rear==Q.front)
			tag=1;
	}
}
void DeleteQueue(Queue &Q,node &e)
{
	if(tag==0&&Q.front==Q.rear)
		printf("����Ϊ�գ�\n");
	else
	{
		e=Q.base[Q.front];
		Q.front=(Q.front+1)%MAX;
		if(Q.front==Q.rear)
			tag=0;
	}
}
int EmptyQueue(Queue &Q)
{
	if(Q.front==Q.rear&&tag==0)
		return 1;
	else
		return 0;
}