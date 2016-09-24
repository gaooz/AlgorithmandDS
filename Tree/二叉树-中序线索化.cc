/**
date: 2012��08��
author: gaooz.com
*/


//----------------����������������������-----------
//�������������Ķ���
typedef enum pointtag{link,thread};//link=0��ʾָ�룬thread=1��ʾ����
typedef struct BTree{
	int data;
	struct BTree *lchild,*rchild;
	pointtag ltag,rtag;
}BiTNode,*BiTree;//�����������Ķ���
BiTree pre;//������Ϊȫ�ֱ���

//�������������Ĺ���
void InThreading(BiTree &p)
{
	if(p!=NULL)
	{
		InThreading(p->lchild);
		if(p->lchild==NULL) { p->lchild=pre;p->ltag=thread;}
		if(pre->rchild==NULL) { pre->rchild=p;pre->rtag=thread;}
		pre=p;
		InThreading(p->rchild);
	}
}

//������������
void InOrderThreading(BiTree &Thr,BiTree &T)
{
	Thr=(BiTree)malloc(sizeof(BiTNode));//����ͷ���
	if(!Thr)
		exit(1);
	Thr->ltag=link;
	Thr->rchild=Thr;
	Thr->rtag=thread;
	if(T==NULL) { Thr->lchild=Thr;}
	else
	{
		Thr->lchild=T;//��ͷ������ָ��ָ��ǿյĸ����
		pre=Thr;
		InThreading(T);
		pre->rchild=Thr;
		pre->rtag=thread;
		Thr->rchild=pre;
	}

}

//������������������
void InOrderTraverse(BiTree &T)
{
	BiTree p;
	p=T->lchild;//pָ���
	while(p!=T)//��p��Ϊͷ���ʱ
	{//�������Ķ���������һ��˫��ѭ������
		while(p->ltag==link)
			p=p->lchild;//���󵽵�
		VistTree(p);
		while(p->rtag==thread&&p->rchild!=T)
		{	p=p->rchild; VistTree(p); }
		//��p����ָ��Ϊ������p->rchildΪp�ĺ��
		//��˿���ֱ����p=p->rchildȻ�����
		p=p->rchild;
		//��̷�����������������
	}
}