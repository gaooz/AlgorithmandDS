/**
date: 2012年09月
author: gaooz.com
*/
void Merge(Sqlist L,Sqlist &T,int i,int m,int n)
{//将顺序表L中的[1....m-1]和[m...n]归并为顺序表T
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
{//2-路归并排序利用递归实现效率较低。时间复杂度为O(nlog2n)
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