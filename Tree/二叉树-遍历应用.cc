/**
date: 2012��08��
author: gaooz.com
*/

//-----------�ñ���ʵ�ֶ������ļ��ּ򵥲���------------
void CountBinaryLeaf(BiTree T,int &count)
{//�����������Ҷ�ӽ����<�������>
	if(T)
	{
		if((T->lchild==NULL)&&(T->rchild==NULL))
			count++;//Ҷ�ӽ������1
		CountBinaryLeaf(T->lchild,count);
		CountBinaryLeaf(T->rchild,count);
	}
}
int BinaryTreeDepth(BiTree T)
{//��������������<�������>
	int depth,depthleft,depthright;
	if(T==NULL)
		depth=0;
	else
	{
		depthleft=BinaryTreeDepth(T->lchild);//�������������
		depthright=BinaryTreeDepth(T->rchild);//�������������
		depth=(depthleft>=depthright?depthleft:depthright)+1;
		//�������Ϊ������������Ƚϴ�ļ���1
	}
	return depth;
}
BiTree CopyBinaryTree(BiTree T)
{//���ƶ�����<�������>
	BiTree leftlink,rightlink,p;
	if(T==NULL)
		return NULL;
	if(T->lchild!=NULL)
	leftlink=CopyBinaryTree(T->lchild);
	else
		leftlink=NULL;//�õ�������ָ��
	if(T->rchild!=NULL)
	rightlink=CopyBinaryTree(T->rchild);
	else
		rightlink=NULL;//�õ�������ָ��
	p=(BiTree)malloc(sizeof(BiTNode));
	if(!p)
		exit(1);
	p->data=T->data;
	p->lchild=leftlink;
	p->rchild=rightlink;//���ƽ��
	return p;
}