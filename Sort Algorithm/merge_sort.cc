/**
date: 2012��09��
author: gaooz.com
*/
void Merge(Sqlist L,Sqlist &T,int i,int m,int n)
{//��˳���L�е�[1....m-1]��[m...n]�鲢Ϊ˳���T
	int j,k;
	for(j=m+1,k=i;i<=m&&j<=n;k++)
	{
		if(L.data[i]<L.data[j]) T.data[k]=L.data[i++];
		else T.data[k]=L.data[j++];
	}
	if(i<=m) 
		for(;i<=m;)
			T.data[k++]=L.data[i++];
	if(j<=n)
		for(;j<=n;)
			T.data[k++]=L.data[j++];
}
void MSort(Sqlist L,Sqlist &T,int s,int t)
{//2-·�鲢�������õݹ�ʵ��Ч�ʽϵ͡�ʱ�临�Ӷ�ΪO(nlog2n)
	int m;Sqlist S;S.length=0;
	if(s==t) T.data[s]=L.data[s];
	else
	{
		m=(s+t)/2;
		MSort(L,S,s,m);
		MSort(L,S,m+1,t);
		Merge(S,T,s,m,t);
	}
}
void MergeSort(Sqlist &L)
{
	MSort(L,L,1,L.length);
}