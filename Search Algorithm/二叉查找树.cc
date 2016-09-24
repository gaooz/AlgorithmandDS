/**
date: 2012��09��
author: gaooz.com
*/

//--------------------������������������������Ĺ���-----------------2012��9��29
void BinarySortTree(BiTree &T,OrderList L)
{//��˳���L�еĽ�㹹�����������
	int i;BiTree p,q,k;T=NULL;
    for(i=0;i<L.length;i++)
	{
	   p=(BiTree)malloc(sizeof(BiTNode));
		p->data=L.l[i].num;
		p->lchild=NULL;p->rchild=NULL;
		if(T==NULL) T=p;
		else
		{
			if(p->data<T->data)
			{//p���Ϊ�������Ľ��
				q=T->lchild;
				if(q==NULL)	T->lchild=p;
				else
				{
					while(q!=NULL)
					{
						k=q;
						if(p->data<q->data) q=q->lchild;
						else  q=q->rchild;
					}
					if(p->data<k->data) k->lchild=p;
					else   k->rchild=p;
				}
			}
			else
			{//p���Ϊ�������ϵĽ��
				q=T->rchild;
				if(q==NULL)  T->rchild=p;
				else
				{
					while(q!=NULL)
					{
						k=q;
						if(p->data<q->data)	q=q->lchild;
						else	q=q->rchild;
					}
					if(p->data<k->data)	k->lchild=p;
					else	k->rchild=p;
				}
			}
		}
	}
}

//----------------------��̬�������ڶ����������н��в������--------------2012��9��29
int SearchBST(BiTree T,BiTree f,int key,BiTree &p)
{//���Ҷ���������T��fΪT�ĸ�����ʼʱΪNULL
	//�����ҳɹ�����pָ��key���ڵĽ�㲢����TRUE
	//����pָ���·�������һ����㲢����FALSE
	if(T==NULL) {p=f;return FALSE;}
	else
		if(key==T->data)
		{
			p=T;
			return TRUE;
		}
		else
			if(key<T->data)
				return SearchBST(T->lchild,T,key,p);
			else
				return SearchBST(T->rchild,T,key,p);
}
int InsertBST(BiTree &T,int key)
{//������������T�в����ڹؼ���key��key�������в�����TRUE
	//�����ڹؼ���key�򷵻�FALSE
	BiTree p,s;
	if(!SearchBST(T,NULL,key,p))
	{
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data=key;
		s->lchild=NULL;s->rchild=NULL;
		if(!p) T=s;
		else
			if(s->data<p->data)
				p->lchild=s;
			else
				p->rchild=s;
		return TRUE;
	}
	return FALSE;
}
//-------------������������ɾ��������-------------2012��9��29
int Deletefun(BiTree &p)
{//�Ӷ�����������ɾ��ָ��p��ָ��Ľ��
	BiTree q,s;
	if(p->rchild==NULL)
	{//��������Ϊ����ֻ��Ҫ�ؽ���������
		q=p;p=p->lchild;
		//�����β�Ϊָ����������p=p->lchild�൱��f->lchild=p->lchild
		//����fΪָ��p��ָ���ĸ�ĸ
		free(q);
	}
	else
		if(p->lchild==NULL)
		{//������Ϊ����ֻ��Ҫ�ؽ���������
			q=p;p=p->rchild;
			free(q);
		}
		else
		{//������������Ϊ�գ�����ʼ�
			q=p;s=p->lchild;
			while(s->rchild!=NULL)
			{
				q=s;
				s=s->rchild;
			}
			p->data=s->data;
			if(q!=p)
				q->rchild=s->lchild;
			else
				q->lchild=s->lchild;
			free(s);
		}
		return TRUE;
}
int DeleteBST(BiTree &T,int key)
{
	if(T==NULL)
		return FALSE;
	else
		if(key==T->data)
			return Deletefun(T);
		else
			if(key<T->data)
				return DeleteBST(T->lchild,key);
			else
				return DeleteBST(T->rchild,key);
}