/**
date: 2012年08月
author: gaooz.com
*/


/**
用队列结构实现二叉树的层次遍历
*/
void FloorTraverse(BiTree &T)
{//层序遍历
	Queue q;BiTree p;
	InitQueue(q);p=T;
	if(p)
	{
		EnterQueue(q,p);//入队
		while(q.front!=q.rear)
		{
			QuitQueue(q,p);//出队并输出
			printf("%d ",p->data);
			if(p->lchild)
			EnterQueue(q,p->lchild);
			if(p->rchild)
			EnterQueue(q,p->rchild);//左右子树分别入队
		}
	}
}