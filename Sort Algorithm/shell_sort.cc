/**
date: 2012年09月
author: gaooz.com
*/

//希尔排序也是插入排序的一种，它是这几种插入排序中时间复杂度唯一比前几种插入排序时间复杂（O(n2)）度小的排序方法。
//只是增量序列应选的适当。
void ShellInsert(Sqlist &L,int dk)
{//按dk增量对顺序表做一趟希尔排序
	int i,j;
	for(i=dk+1;i<=L.length;i++)
		if(L.key[i]<L.key[i-dk])
		{
			L.key[0]=L.key[i];
			for(j=i-dk;j>0&&L.key[0]<L.key[j];j=j-dk)
				L.key[j+dk]=L.key[j];
			L.key[j+dk]=L.key[0];
		}
}
void ShellSort(Sqlist &L,int dlta[],int t)
{//按增量序列dlta做希尔排序
	int k;
	for(k=0;k<t;k++)
		ShellInsert(L,dlta[k]);
}