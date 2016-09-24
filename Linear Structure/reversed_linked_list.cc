/**
date: 2012年09月
author: gaooz.com
*/

void InvertedList(sqlist &head)
{//-------不构造新表逆置单链表函数---------//
	list *p,*q,*k;
	p=head->next;
	q=p->next;
	k=q->next;
	p->next=NULL;
	while(k!=NULL)
	{
		q->next=p;
		p=q;
		q=k;
		k=k->next;
	}
	q->next=p;
	head->next=q;
}