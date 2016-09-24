
/**
date: 2012年08月
author: gaooz.com
*/

/**
二叉树的遍历-递归实现
*/
void VistTree(BiTree &T)
{//输出结点
	if(T!=NULL)
		printf("%d ",T->data);
}
void PreOrderTraverse(BiTree &T)
{//递归实现先序遍历
	if(T!=NULL)
		VistTree(T);
	if(T->lchild)
	PreOrderTraverse(T->lchild);
	if(T->rchild)
	PreOrderTraverse(T->rchild);
}
void MiddleOrderTraverse(BiTree &T)
{//递归实现中序遍历
	if(T->lchild!=NULL)
		MiddleOrderTraverse(T->lchild);
	VistTree(T);
	if(T->rchild!=NULL)
		MiddleOrderTraverse(T->rchild);
}
void LastOrderTraverse(BiTree &T)
{//递归实现后序遍历
	if(T->lchild!=NULL)
		LastOrderTraverse(T->lchild);
	if(T->rchild!=NULL)
		LastOrderTraverse(T->rchild);
	VistTree(T);
}