/**
date: 2012年09月
author: gaooz.com
*/

//--------------------二叉排序树（二叉查找树）的构造-----------------2012年9月29
void BinarySortTree(BiTree &T,OrderList L)
{//以顺序表L中的结点构造二叉排序树
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
			{//p结点为左子树的结点
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
			{//p结点为右子树上的结点
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

//----------------------动态查找树在二叉排序树中进行插入操作--------------2012年9月29
int SearchBST(BiTree T,BiTree f,int key,BiTree &p)
{//查找二叉排序树T，f为T的根结点初始时为NULL
	//若查找成功，则p指向key所在的结点并返回TRUE
	//否则p指向该路径上最后一个结点并返回FALSE
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
{//当二叉排序树T中不存在关键字key则将key插入其中并返回TRUE
	//若存在关键字key则返回FALSE
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
//-------------二叉排序树中删除结点操作-------------2012年9月29
int Deletefun(BiTree &p)
{//从二叉排序树中删除指针p所指向的结点
	BiTree q,s;
	if(p->rchild==NULL)
	{//当右子树为空则只需要重接其左子树
		q=p;p=p->lchild;
		//函数形参为指针的引用因此p=p->lchild相当于f->lchild=p->lchild
		//其中f为指针p所指结点的父母
		free(q);
	}
	else
		if(p->lchild==NULL)
		{//左子树为空则只需要重接其右子树
			q=p;p=p->rchild;
			free(q);
		}
		else
		{//左右子树都不为空，详见笔记
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