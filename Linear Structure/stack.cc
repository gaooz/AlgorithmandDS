/**
date: 2012��09��
author: gaooz.com
*/

/**
ջ�Ķ������������
*/
typedef struct
{
	int num;
}node;
typedef struct 
{
	node *base;
	node *top;
	int stacksize;
}stack;//˳��ջ�ṹ����
int CreatStack(stack &stackll)
{
	stackll.base=(node *)malloc(INITSTACKSIZE*sizeof(node));
	if(!stackll.base)
		exit(OVERFLOW);
	stackll.top=stackll.base;
	stackll.stacksize=INITSTACKSIZE;
	return OK;
}
void push(stack &s,node e)
{//��ջ����
	if(s.top-s.base>=s.stacksize)
	{	s.base=(node *)realloc(s.base,(s.stacksize+INCRESTACKMENT)*sizeof(node));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base+s.stacksize;//���Բ�д����䣻
	s.stacksize+=INCRESTACKMENT;
	}
	*(s.top++)=e;//*s.top++=e;
}
void pop(stack &s,node &e)
{//��ջ����
	if(s.top==s.base||s.base==NULL)
		printf("��Ϣ����\n");
	else
		e=*--s.top;
}
//-------ȡջ��Ԫ�غ���------//
void gettop(stack &s,node &e)
{
	if(s.base==s.top)
		printf("ջΪ�գ��޷�ȡ��ջ��Ԫ�أ�\n");
	else
	{
		e=*(s.top-1);
	}
}