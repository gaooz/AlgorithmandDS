
/**
date: 2012年09月
author: gaooz.com
*/


/**
AVL树：平衡二叉查找树
*/

//-----------------平衡二叉排序树的构建-------------2012年9月30
#define LH +1//左边高
#define EH 0//一样高
#define RH -1//右边高
typedef struct BSTNode{
	int data;
	int bf;//平衡因子
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;//平衡二叉排序树结构的定义
void R_Rotate(BSTree &p)
{//对以*p为根的二叉排序树做右旋处理，处理之后p指向新的树根结点
	BSTree lc;
	lc=p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;p=lc;
}
void L_Rotate(BSTree &p)
{//对以*p为根的二叉排序树做左旋处理，处理之后p指向新的树根结点
	BSTree rc;
	rc=p->rchild;
	p->rchild=rc->lchild;
	rc->lchild=p;p=rc;
}
void LeftBalance(BSTree &T)
{//对已*T为根的二叉排序树做左平衡旋转处理
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
{//对已*T为根的二叉排序树做右平衡旋转处理
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
{//若在平衡二叉排序树中不存在与关键字key相等的结点，则将关键字插入树中
	//布尔变量taller表示树是否“长高”
	if(T==NULL)
	{
		T=(BSTree)malloc(sizeof(BSTNode));
		T->data=key;T->bf=EH;//叶子结点其平衡因子肯定为0
		T->lchild=T->rchild=NULL;
		taller=1;//树长高了
	}
	else
	{
		if(key==T->data)
		{//如果树中已存放此关键字则不予插入
			taller=0;
			return 0;
		}
		if(key<T->data)
		{//关键字小于根结点则插入其左子树中
			if(!InsertAVL(T->lchild,key,taller))
				return 0;
			if(taller)
			{//如果树长高了，判断是否平衡
				switch(T->bf)
				{
				case LH:LeftBalance(T);//不平衡时调用左平衡函数，使左子树平衡
					taller=0; break;
				case EH:T->bf=LH;taller=1;
					break;
				case RH:T->bf=EH;taller=0;
					break;
				}
			}
		}
		else
		{//插入右子树中
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