/**
date: 2012��09��
author: gaooz.com
*/

void InvertedList(sqlist &head)
{//-------�������±����õ�������---------//
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