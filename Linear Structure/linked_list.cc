/**
date: 2012��09��
author: gaooz.com
*/

/**
����Ķ����봴��
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
int CreatList(slist &head)//�˴�ӦΪֻ��Ե�����
{
	head=(list *)malloc(sizeof(list));
	if(!head)
	return ERROR;
	head->next=NULL;
	return OK;
}