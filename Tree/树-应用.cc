/**
date: 2012��09��
author: gaooz.com
*/

//------------���������--------------
int TreeDepth(CSTree T)
{//���������
	int h1,h2;
	if(!T) return 0;
	else
	{
		h1=TreeDepth(T->firstchild);
		h2=TreeDepth(T->nextslibing);
		if(h1+1>h2) return h1+1;
		else        return h2;
	}
}
//-----------���ṹ���������Ҷ�ӽ�������·��-----------2012��08��27
void AllpathTree(CSTree &T)
{//�ҵ����������Ҷ�ӽ�������·��
	CSTree p;
	if(T)
	{
		PushStack(S,T);//�������Ϊ������ջ
		if(T->firstchild)//��������Ϊ�����������
			AllpathTree(T->firstchild);
		else
		{
			PrintStack(S);//������Ϊ����˵��ΪҶ�ӽ�㣬�����ǰջ�е�Ԫ��
           //���˴���count++;����������countΪҶ�ӽ����
			if(StackEmpty(S))
			{
				PopStack(S,p);//�˳���ǰջ��Ԫ�أ���������
				AllpathTree(p->nextslibing);
			}
		}
	}
	else
	{
		if(StackEmpty(S)) { PopStack(S,p); AllpathTree(p->nextslibing);}
	}
}