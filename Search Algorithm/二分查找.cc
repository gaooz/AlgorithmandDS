
/**
date: 2012年09月
author: gaooz.com
*/

/**
静态查找表：折半查找
只适用于有序的顺序查找表，效率明显高于顺序查找.
*/

int Binary_search(OrderList l,int num)
{//折半查找。查找num在顺序表l中的位置
	//只适用于有序的顺序表
	int i,low,high,mid;
	low=0;//顺序表中的元素位置是从0开始的
	high=l.length-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(l.a[mid]==num)
			return mid;
		else
			if(l.a[mid]>num)
				high=mid-1;
			else
				low=mid+1;
	}
	return 0;
}