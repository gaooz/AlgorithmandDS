
/**
date: 2012��09��
author: gaooz.com
*/


/**
AVL����ƽ����������
*/

//-----------------ƽ������������Ĺ���-------------2012��9��30
#define LH +1//��߸�
#define EH 0//һ����
#define RH -1//�ұ߸�
typedef struct BSTNode{
	int data;
	int bf;//ƽ������
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;//ƽ������������ṹ�Ķ���
void R_Rotate(BSTree &p)
{//����*pΪ���Ķ�����������������������֮��pָ���µ��������
	BSTree lc;
	lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;p=lc;
}
void L_Rotate(BSTree &p)
{//����*pΪ���Ķ�����������������������֮��pָ���µ��������
	BSTree rc;
	rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;p=rc;
}
void LeftBalance(BSTree &T)
{//����*TΪ���Ķ�������������ƽ����ת����
	BSTree lc,rd;
	lc=T->lchild;
	switch(lc->bf)
	{
	case LH:T->bf=lc->bf=EH;
		R_Rotate(T);
		break;
	case RH:rd=lc->rchild;
		switch(rd->bf)
		{
		case LH:T->bf=RH;lc->bf=EH;
			break;
		case EH:T->bf=lc->bf=EH;
			break;
		case RH:T->bf=EH;lc->bf=RH;
			break;
		}
		rd->bf=EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}
}
void RightBalance(BSTree &T)
{//����*TΪ���Ķ�������������ƽ����ת����
	BSTree lc,rd;
	lc=T->rchild;
	switch(lc->bf)
	{
	case RH:T->bf=lc->bf=EH;
		L_Rotate(T);
		break;
	case LH:rd=lc->lchild;
		switch(rd->bf)
		{
		case RH:T->bf=LH;lc->bf=EH;
			break;
		case LH:T->bf=EH;lc->bf=RH;
			break;
		case EH:T->bf=lc->bf=EH;
			break;
		}
		rd->bf=EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
}
int InsertAVL(BSTree &T,int key,bool &taller)
{//����ƽ������������в�������ؼ���key��ȵĽ�㣬�򽫹ؼ��ֲ�������
	//��������taller��ʾ���Ƿ񡰳��ߡ�
	if(T==NULL)
	{
		T=(BSTree)malloc(sizeof(BSTNode));
		T->data=key;T->bf=EH;//Ҷ�ӽ����ƽ�����ӿ϶�Ϊ0
		T->lchild=T->rchild=NULL;
		taller=1;//��������
	}
	else
	{
		if(key==T->data)
		{//��������Ѵ�Ŵ˹ؼ����������
			taller=0;
			return 0;
		}
		if(key<T->data)
		{//�ؼ���С�ڸ�������������������
			if(!InsertAVL(T->lchild,key,taller))
				return 0;
			if(taller)
			{//����������ˣ��ж��Ƿ�ƽ��
				switch(T->bf)
				{
				case LH:LeftBalance(T);//��ƽ��ʱ������ƽ�⺯����ʹ������ƽ��
					taller=0; break;
				case EH:T->bf=LH;taller=1;
					break;
				case RH:T->bf=EH;taller=0;
					break;
				}
			}
		}
		else
		{//������������
			if(!InsertAVL(T->rchild,key,taller))
				return 0;
			if(taller)
			{
				switch(T->bf)
				{
				case LH:T->bf=EH; taller=0;
					break;
				case EH:T->bf=RH;taller=1;
					break;
				case RH:RightBalance(T);taller=0;
					break;
				}
			}
		}
	}
	return 1;
}