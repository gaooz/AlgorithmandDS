/**
date: 2012��08��16
author: gaooz.com
*/

/**
�������Ķ�����������
*/
//�ö����������������������õݹ�ʵ�ֶ����������ֱ�������
typedef struct BTree{
	int data;
	struct BTree *lchild,*rchild;
}BiTNode,*BiTree;

//����������
void CreatBinaryTree(BiTree &T)
{//����һ�����������ݹ鶨�壩
	int ch;//��0��ʾ����
	printf("�����㣺");
	scanf("%d",&ch);
	if(ch==0) T=NULL;//Լ��ֵΪ��Ľ��Ϊ��
	else
	{
		T=(BiTNode *)malloc(sizeof(BiTNode));
		if(!T) exit(1);
		T->data=ch;
		CreatBinaryTree(T->lchild);//�ݹ�
		CreatBinaryTree(T->rchild);
	}
}