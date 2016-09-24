/**
date: 2012年09月
author: gaooz.com
*/

/**
快速排序是对起泡排序的一种改进。如果单看平均排序时间那快速排序是最好的排序方法，
一般取第一个元素为枢轴记录，但当顺序表有序或基本有序时取第一个记录为枢轴会使得快速排序退化为起泡排序（时间复杂度为O(n2)）。
因此为避免快速排序退化为起泡排序通常在表中记录有序或基本有序时采用"三者取中"法来取得枢轴结点。
*/

int Partition(Sqlist &L,int low,int high)
{//枢轴是随机选取的，通常选择第一个记录为枢轴
	//使序列位置从low到high位置的记录做以下排列：
	//比枢轴结点大的记录排列的枢轴之后，否则排列在其前面
	//返回排列后枢轴记录在顺序表中位置
	int pivotkey;
	L.key[0]=L.key[low];//选第一个元素为枢轴记录存储在0单元位置
	pivotkey=L.key[low];//取得枢轴记录关键字
	while(low<high)
	{
		while(low<high&&L.key[high]>=pivotkey) high--;
		L.key[low]=L.key[high];
		while(low<high&&L.key[low]<=pivotkey) low++;
		L.key[high]=L.key[low];
	}
	L.key[low]=L.key[0];//将枢轴记录存入排序后的枢轴所在的新位置
	return low;//返回枢轴结点所在的新位置
}
void QSort(Sqlist &L,int low,int high)
{//对顺序表L中从low到high的序列做快速排序
	int p;
	if(low<high)
	{
		p=Partition(L,low,high);
		QSort(L,low,p-1);//对低子表快速排序，p是枢轴位置
		QSort(L,p+1,high);//对高子表快速排序
	}
}
void QuickSort(Sqlist &L)
{//快速排序
	QSort(L,1,L.length);
}