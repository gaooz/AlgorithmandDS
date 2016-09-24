/**
date: 2012年09月
author: gaooz.com
*/

//------------求树的深度--------------
int TreeDepth(CSTree T)
{//求树的深度
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
//-----------树结构中输出根到叶子结点的所有路径-----------2012、08、27
void AllpathTree(CSTree &T)
{//找到并输出根到叶子结点的所有路径
	CSTree p;
	if(T)
	{
		PushStack(S,T);//结点若不为空则入栈
		if(T->firstchild)//左链若不为空则遍历左链
			AllpathTree(T->firstchild);
		else
		{
			PrintStack(S);//左链若为空则说明为叶子结点，输出当前栈中的元素
           //若此处有count++;语句则输出的count为叶子结点数
			if(StackEmpty(S))
			{
				PopStack(S,p);//退出当前栈顶元素，遍历右链
				AllpathTree(p->nextslibing);
			}
		}
	}
	else
	{
		if(StackEmpty(S)) { PopStack(S,p); AllpathTree(p->nextslibing);}
	}
}