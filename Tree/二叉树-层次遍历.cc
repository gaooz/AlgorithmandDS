/**
date: 2012��08��
author: gaooz.com
*/


/**
�ö��нṹʵ�ֶ������Ĳ�α���
*/
void FloorTraverse(BiTree &T)
{//�������
	Queue q;BiTree p;
	InitQueue(q);p=T;
	if(p)
	{
		EnterQueue(q,p);//���
		while(q.front!=q.rear)
		{
			QuitQueue(q,p);//���Ӳ����
			printf("%d ",p->data);
			if(p->lchild)
			EnterQueue(q,p->lchild);
			if(p->rchild)
			EnterQueue(q,p->rchild);//���������ֱ����
		}
	}
}