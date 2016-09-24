/**
date: 2012年09月
author: gaooz.com
*/

/***
树的两种遍历方式

*/

void PreOrderTraverse(CSTree &T)
{//递归实现二叉树先序遍历、即树的先根遍历
	if(T!=NULL)
		VistTree(T);
	if(T->firstchild)
	PreOrderTraverse(T->firstchild);
	if(T->nextslibing)
	PreOrderTraverse(T->nextslibing);
}
void MiddleOrderTraverse(CSTree &T)
{//递归实现二叉树中序遍历、即树的后根遍历
	if(T->firstchild!=NULL)
		MiddleOrderTraverse(T->firstchild);
	VistTree(T);
	if(T->nextslibing!=NULL)
		MiddleOrderTraverse(T->nextslibing);
}
//树的层次遍历只需依次输出上述队列中元素即可