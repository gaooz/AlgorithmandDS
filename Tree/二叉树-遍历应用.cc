/**
date: 2012年08月
author: gaooz.com
*/

//-----------用遍历实现二叉树的几种简单操作------------
void CountBinaryLeaf(BiTree T,int &count)
{//计算二叉树的叶子结点数<先序遍历>
	if(T)
	{
		if((T->lchild==NULL)&&(T->rchild==NULL))
			count++;//叶子结点数加1
		CountBinaryLeaf(T->lchild,count);
		CountBinaryLeaf(T->rchild,count);
	}
}
int BinaryTreeDepth(BiTree T)
{//计算二叉树的深度<后序遍历>
	int depth,depthleft,depthright;
	if(T==NULL)
		depth=0;
	else
	{
		depthleft=BinaryTreeDepth(T->lchild);//计算左子树深度
		depthright=BinaryTreeDepth(T->rchild);//计算右子树深度
		depth=(depthleft>=depthright?depthleft:depthright)+1;
		//树的深度为左右子树中深度较大的加上1
	}
	return depth;
}
BiTree CopyBinaryTree(BiTree T)
{//复制二叉树<后序遍历>
	BiTree leftlink,rightlink,p;
	if(T==NULL)
		return NULL;
	if(T->lchild!=NULL)
	leftlink=CopyBinaryTree(T->lchild);
	else
		leftlink=NULL;//得到左子树指针
	if(T->rchild!=NULL)
	rightlink=CopyBinaryTree(T->rchild);
	else
		rightlink=NULL;//得到右子树指针
	p=(BiTree)malloc(sizeof(BiTNode));
	if(!p)
		exit(1);
	p->data=T->data;
	p->lchild=leftlink;
	p->rchild=rightlink;//复制结点
	return p;
}