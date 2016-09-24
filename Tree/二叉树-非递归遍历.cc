/**
date: 2012��08��
author: gaooz.com
*/

/**
����ջ�ṹʵ�ֶ������ķǵݹ����
*/
void PreOrderTraverse(BiTree &T)
{//��������ǵݹ�ʵ��
	stack S;BiTree p;
	InitStack(S);p=T;
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			VistTree(p);
			PushStack(S,p);
			p=p->lchild;
		}
		else
		{ PopStack(S,p);p=p->rchild; }
	}
}
void MiddleTree(BiTree &T)
{//��������������ǵݹ�ʵ��
	stack S;BiTree p;
	InitStack(S);p=T;
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			PushStack(S,p);
			p=p->lchild;
		}
		else
		{
			PopStack(S,p);
			VistTree(p);
			p=p->rchild;
		}
	}
}
void LastOrderTraverse(BiTree &T)
{//�ǵݹ�������
	//��tag�����Ƕ�Ӧ�Ľ���Ƿ񱻷��ʹ�
	int sign=-1,tag[MAXSIZE];
	stack S;
	BiTree p,p1;
	p=T;
	InitStack(S);
	while(p!=NULL||StackEmpty(S))
	{
		if(p!=NULL)
		{
			PushStack(S,p);
			tag[++sign]=0;
			p=p->lchild;
		}
		else
		{
			if(tag[sign]==0)
			{//������δ��������ȡ��ջ��Ԫ�أ�����ջ������������
				Gettop(S,p);
				tag[sign]=1;
				p=p->rchild;
			}
			else
			{//����ý�㱻���ʹ���Ԫ�س�ջ���
				PopStack(S,p1);
				sign--;
				VistTree(p1);
			}
		}
	}
}