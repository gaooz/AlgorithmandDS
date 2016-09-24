/**
date: 2012年09月
author: gaooz.com
*/

/**
2012年9月28
静态查找表：顺序查找
当n很大时查找效率很低，但使用范围很广
*/

int Sequence_search(OrderList l,int num)
{//num为所要查找的元素的值，返回该值在顺序表中的位置
	int i;
	for(i=0;i<l.length;i++)
		if(l.a[i]==num)
			return i;
}