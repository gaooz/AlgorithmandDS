/**
date: 2012年09月
author: gaooz.com
*/

/**
链表的定义与创建
*/
typedef struct 
{
	int num;
}node;
typedef struct LIST
{
	node data;
	struct LIST *next;
}list,*slist;
int CreatList(slist &head)//此处应为只针对的引用
{
	head=(list *)malloc(sizeof(list));
	if(!head)
	return ERROR;
	head->next=NULL;
	return OK;
}