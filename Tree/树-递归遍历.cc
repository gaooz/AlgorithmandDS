/**
date: 2012��09��
author: gaooz.com
*/

/***
�������ֱ�����ʽ

*/

void PreOrderTraverse(CSTree &T)
{//�ݹ�ʵ�ֶ���������������������ȸ�����
	if(T!=NULL)
		VistTree(T);
	if(T->firstchild)
	PreOrderTraverse(T->firstchild);
	if(T->nextslibing)
	PreOrderTraverse(T->nextslibing);
}
void MiddleOrderTraverse(CSTree &T)
{//�ݹ�ʵ�ֶ�������������������ĺ������
	if(T->firstchild!=NULL)
		MiddleOrderTraverse(T->firstchild);
	VistTree(T);
	if(T->nextslibing!=NULL)
		MiddleOrderTraverse(T->nextslibing);
}
//���Ĳ�α���ֻ�������������������Ԫ�ؼ���