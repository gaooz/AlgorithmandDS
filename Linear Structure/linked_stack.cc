/**
date: 2012��09��
author: gaooz.com
*/

/**
��ջʵ��
*/
typedef struct Node
{
	int num;
	struct Node *next;
}node;
typedef struct 
{
	Node *top;
	Node *base;
}stack;
void InitStack(stack &s)
{
	s.base=(Node *)malloc(sizeof(node));
	if(!s.base)
		exit(1);
	else
	{
		s.base->next=NULL;
		s.top=s.base;
	}
}
void InsertStack(stack &s,node e)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(!p)
		exit(1);
	else
	{
		*p=e;
		p->next=s.top;
		s.top=p;
	}
}
void DeleteStack(stack &s,node &e)
{
	node *p;
	if(s.top==s.base)
		printf("ջΪ�գ�\n");
	else
	{
		p=s.top;
		s.top=s.top->next;
		e=*p;
		free(p);
	}
}