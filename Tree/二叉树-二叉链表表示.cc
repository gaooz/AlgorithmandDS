/**
date: 2012年08月16
author: gaooz.com
*/

/**
二叉树的二叉链表描述
*/
//用二叉链表描述二叉树、并用递归实现二叉树的三种遍历操作
typedef struct BTree{
	int data;
	struct BTree *lchild,*rchild;
}BiTNode,*BiTree;

//创建二叉树
void CreatBinaryTree(BiTree &T)
{//构造一个二叉树（递归定义）
	int ch;//以0表示空树
	printf("输入结点：");
	scanf("%d",&ch);
	if(ch==0) T=NULL;//约定值为零的结点为空
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		if(!T) exit(1);
		T->data=ch;
		CreatBinaryTree(T->lchild);//递归
		CreatBinaryTree(T->rchild);
	}
}