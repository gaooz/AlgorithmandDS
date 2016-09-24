
/**
date: 2012��08��
author: gaooz.com
*/

/**
�������ı���-�ݹ�ʵ��
*/
void VistTree(BiTree &T)
{//������
	if(T!=NULL)
		printf("%d ",T->data);
}
void PreOrderTraverse(BiTree &T)
{//�ݹ�ʵ���������
	if(T!=NULL)
		VistTree(T);
	if(T->lchild)
	PreOrderTraverse(T->lchild);
	if(T->rchild)
	PreOrderTraverse(T->rchild);
}
void MiddleOrderTraverse(BiTree &T)
{//�ݹ�ʵ���������
	if(T->lchild!=NULL)
		MiddleOrderTraverse(T->lchild);
	VistTree(T);
	if(T->rchild!=NULL)
		MiddleOrderTraverse(T->rchild);
}
void LastOrderTraverse(BiTree &T)
{//�ݹ�ʵ�ֺ������
	if(T->lchild!=NULL)
		LastOrderTraverse(T->lchild);
	if(T->rchild!=NULL)
		LastOrderTraverse(T->rchild);
	VistTree(T);
}