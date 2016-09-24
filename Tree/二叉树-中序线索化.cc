/**
date: 2012年08月
author: gaooz.com
*/


//----------------二叉树中序线索化及遍历-----------
//线索化二叉树的定义
typedef enum pointtag{link,thread};//link=0表示指针，thread=1表示线索
typedef struct BTree{
	int data;
	struct BTree *lchild,*rchild;
	pointtag ltag,rtag;
}BiTNode,*BiTree;//线索二叉树的定义
BiTree pre;//定义其为全局变量

//中序线索化核心过程
void InThreading(BiTree &p)
{
	if(p!=NULL)
	{
		InThreading(p->lchild);
		if(p->lchild==NULL) { p->lchild=pre;p->ltag=thread;}
		if(pre->rchild==NULL) { pre->rchild=p;pre->rtag=thread;}
		pre=p;
		InThreading(p->rchild);
	}
}

//线索化二叉树
void InOrderThreading(BiTree &Thr,BiTree &T)
{
	Thr=(BiTree)malloc(sizeof(BiTNode));//建立头结点
	if(!Thr)
		exit(1);
	Thr->ltag=link;
	Thr->rchild=Thr;
	Thr->rtag=thread;
	if(T==NULL) { Thr->lchild=Thr;}
	else
	{
		Thr->lchild=T;//令头结点的左指针指向非空的根结点
		pre=Thr;
		InThreading(T);
		pre->rchild=Thr;
		pre->rtag=thread;
		Thr->rchild=pre;
	}

}

//遍历中序线索二叉树
void InOrderTraverse(BiTree &T)
{
	BiTree p;
	p=T->lchild;//p指向根
	while(p!=T)//当p不为头结点时
	{//线索化的二叉树就像一个双向循环链表
		while(p->ltag==link)
			p=p->lchild;//向左到底
		VistTree(p);
		while(p->rtag==thread&&p->rchild!=T)
		{	p=p->rchild; VistTree(p); }
		//若p的右指针为线索则p->rchild为p的后继
		//因此可以直接令p=p->rchild然后访问
		p=p->rchild;
		//后继访问完毕则遍历右子树
	}
}