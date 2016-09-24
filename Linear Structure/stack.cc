/**
date: 2012年09月
author: gaooz.com
*/

/**
栈的定义与基本操作
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
}stack;//顺序栈结构定义
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
{//进栈操作
	if(s.top-s.base>=s.stacksize)
	{	s.base=(node *)realloc(s.base,(s.stacksize+INCRESTACKMENT)*sizeof(node));
	if(!s.base)
		exit(OVERFLOW);
	s.top=s.base+s.stacksize;//可以不写此语句；
	s.stacksize+=INCRESTACKMENT;
	}
	*(s.top++)=e;//*s.top++=e;
}
void pop(stack &s,node &e)
{//出栈操作
	if(s.top==s.base||s.base==NULL)
		printf("信息有误！\n");
	else
		e=*--s.top;
}
//-------取栈顶元素函数------//
void gettop(stack &s,node &e)
{
	if(s.base==s.top)
		printf("栈为空，无法取得栈顶元素！\n");
	else
	{
		e=*(s.top-1);
	}
}