/**
date: 2012年08月
author: gaooz.com
*/

/**
利用栈结构实现二叉树的非递归遍历
*/
void PreOrderTraverse(BiTree &T)
{//先序遍历非递归实现
	stack S;BiTree p;
	InitStack(S);p=T;
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			VistTree(p);
			PushStack(S,p);
			p=p->lchild;
		}
		else
		{ PopStack(S,p);p=p->rchild; }
	}
}
void MiddleTree(BiTree &T)
{//中序遍历二叉树非递归实现
	stack S;BiTree p;
	InitStack(S);p=T;
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			PushStack(S,p);
			p=p->lchild;
		}
		else
		{
			PopStack(S,p);
			VistTree(p);
			p=p->rchild;
		}
	}
}
void LastOrderTraverse(BiTree &T)
{//非递归后序遍历
	//用tag数组标记对应的结点是否被访问过
	int sign=-1,tag[MAXSIZE];
	stack S;
	BiTree p,p1;
	p=T;
	InitStack(S);
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			PushStack(S,p);
			tag[++sign]=0;
			p=p->lchild;
		}
		else
		{
			if(tag[sign]==0)
			{//如果结点未被访问则取出栈顶元素，访问栈顶结点的右子树
				Gettop(S,p);
				tag[sign]=1;
				p=p->rchild;
			}
			else
			{//如果该结点被访问过则元素出栈输出
				PopStack(S,p1);
				sign--;
				VistTree(p1);
			}
		}
	}
}