/**
date: 2012年09月
author: gaooz.com
*/


//---------------------次优查找树的构造------------------2012年9月28
//本算法时间复杂度为O(nlog2n),其性能略低于最优查找树，但构造最优查找树的时间复杂度较大。

int sw[MAXLENGTH];//全局变量，存放记录的累加权值
void NearlyOptimal(BiTree &T,OrderList &L,int low,int high)
{//次优查找树的构造,数组sw中存放表L记录的累加权值，sw为全局变量
	int i,j=0, min,dw;
	min=sw[high];dw=sw[high];
	for(i=low;i<=high;i++)
	 if(abs(dw-sw[i]-sw[i-1])<min)
	 {//abs(dw-sw[i]-sw[i-1])相当于P(见详解）
		 j=i;
		 min=abs(dw-sw[i]-sw[i-1]);
	 }
	 T=(BiTree)malloc(sizeof(BiTNode));
	 T->data=L.l[j].num;
	 if(j==low)
		 T->lchild=NULL;
	 else//构造左子树
		 NearlyOptimal(T->lchild,L,low,j-1);
	 if(j==high)
		 T->rchild=NULL;
	 else//构造右子树
		 NearlyOptimal(T->rchild,L,j+1,high);
}
void CreatOptimalTree(BiTree &T,OrderList &L)
{
	int i;
	if(L.length==0)
		T=NULL;
	else
	{
		sw[0]=L.l[0].weight;
		for(i=1;i<L.length;i++)
		{//求得sw
			sw[i]=sw[i-1]+L.l[i].weight;//权值累加
		}
		NearlyOptimal(T,L,0,L.length-1);
	}
}