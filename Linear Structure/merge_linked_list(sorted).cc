/**
date: 2012��09��
author: gaooz.com
*/

//-----������������ϲ�Ϊһ������------//
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
		}//���p����ʣ�࣬��ֱ�ӽ�p��ʣ��Ԫ�ز���head3��
	if(q!=NULL)
		while(q!=NULL)
		{
			InsertList(head3,q->data);
			q=q->next;
		}//���q����ʣ�࣬��ֱ�ӽ�q�е�ʣ��Ԫ�ز���head3��
		return 0;
}