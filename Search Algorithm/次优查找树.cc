/**
date: 2012��09��
author: gaooz.com
*/


//---------------------���Ų������Ĺ���------------------2012��9��28
//���㷨ʱ�临�Ӷ�ΪO(nlog2n),�������Ե������Ų����������������Ų�������ʱ�临�ӶȽϴ�

int sw[MAXLENGTH];//ȫ�ֱ�������ż�¼���ۼ�Ȩֵ
void NearlyOptimal(BiTree &T,OrderList &L,int low,int high)
{//���Ų������Ĺ���,����sw�д�ű�L��¼���ۼ�Ȩֵ��swΪȫ�ֱ���
	int i,j=0, min,dw;
	min=sw[high];dw=sw[high];
	for(i=low;i<=high;i++)
	 if(abs(dw-sw[i]-sw[i-1])<min)
	 {//abs(dw-sw[i]-sw[i-1])�൱��P(����⣩
		 j=i;
		 min=abs(dw-sw[i]-sw[i-1]);
	 }
	 T=(BiTree)malloc(sizeof(BiTNode));
	 T->data=L.l[j].num;
	 if(j==low)
		 T->lchild=NULL;
	 else//����������
		 NearlyOptimal(T->lchild,L,low,j-1);
	 if(j==high)
		 T->rchild=NULL;
	 else//����������
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
		{//���sw
			sw[i]=sw[i-1]+L.l[i].weight;//Ȩֵ�ۼ�
		}
		NearlyOptimal(T,L,0,L.length-1);
	}
}