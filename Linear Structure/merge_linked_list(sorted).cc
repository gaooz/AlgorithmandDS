/**
date: 2012年09月
author: gaooz.com
*/

//-----将两有序链表合并为一个链表------//
int mergeList(sqlist &head1,sqlist &head2,sqlist &head3)
{
	sqlist p,q;
	node e;
	p=head1->next;
	q=head2->next;
	while(p!=NULL&&q!=NULL)
	{
		if(p->data.exp<q->data.exp)
		{
			InsertList(head3,p->data);
			p=p->next;
		}
		else
		if(p->data.exp>q->data.exp)
		{
			InsertList(head3,q->data);
			q=q->next;
		}
		else
		if(p->data.exp==q->data.exp)
		{
			e.coefficient=p->data.coefficient+q->data.coefficient;
			e.exp=p->data.exp;//e.exp=q->data.exp;
			InsertList(head3,e);
			p=p->next;
			q=q->next;
		}
	}
	if(p!=NULL)
		while(p!=NULL)
		{
			InsertList(head3,p->data);
			p=p->next;
		}//如果p中有剩余，则直接将p中剩余元素插入head3中
	if(q!=NULL)
		while(q!=NULL)
		{
			InsertList(head3,q->data);
			q=q->next;
		}//如果q中有剩余，则直接将q中的剩余元素插入head3中
		return 0;
}