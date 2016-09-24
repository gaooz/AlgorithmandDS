/**
date: 2012年09月
author: gaooz.com
*/

void HeapAdjust(Sqlist &L,int s,int m)
{//调整（筛选）L.data[s]使L.data[s....m]成为一个大顶堆
	int rc,j;rc=L.data[s];
	for(j=2;j<=m;j=j*2)
	{
		if(j<m&&L.data[j]>L.data[j+1]) j++;
		if(rc<L.data[j]) break;
		L.data[s]=L.data[j];s=j;
	}
	L.data[s]=rc;
}
void HeapSort(Sqlist &L)
{//堆排序。时间复杂度为O(nlog2n)
	int i,change;
	for(i=L.length/2;i>=0;i--)
		HeapAdjust(L,i,L.length);//将L.data[1...L.length]建成大顶堆
	for(i=L.length;i>1;i--)
	{
		change=L.data[1];
		L.data[1]=L.data[i];
		L.data[i]=change;//最后一个记录相互交换
		HeapAdjust(L,1,i-1);//将L.data[1...i-1]重新调整为大顶堆
	}
}