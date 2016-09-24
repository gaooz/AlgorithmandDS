/**
date: 2012年09月
author: gaooz.com
*/

/*
折半插入排序。相对直接插入排序来说改进了比较次数
记录移动次数并未改变、时间复杂度为O(n2)
*/
void BinarySort(Sqlist &L)
{//折半插入排序
	int low,high,i,m,j;
	for(i=2;i<=L.length;i++)
	{
		L.key[0]=L.key[i];
		low=1;high=i-1;
		while(low<=high)
		{//折半查找得到第i个结点在前面有序表中的插入位置
			m=(low+high)/2;
			if(L.key[i]<L.key[m]) high=m-1;
			else low=m+1;
		}
		for(j=i-1;j>=high+1;j--) L.key[j+1]=L.key[j];//记录向后移动
		L.key[high+1]=L.key[0];//插入结点
	}
}

//---------------------2-路插入排序----------------------
void TwoRoadSort(Sqlist &L)
{//2-路插入排序。相对直接插入排序来讲减少了记录移动的次数
	//时间复杂度仍是O(n2)
	int d[MAXSIZE],i,j,k,first,final;
	//first指针指向比d[1]小的最小的那个元素位置
	//final指向比d[1]大的最大的那个元素的位置
	//当所有关键字按非递减2-路插入有序排列至数组d中后first=final+1
	for(i=1;i<=L.length;i++)
		d[i]=0;//辅助数组的初始化
	first=1;final=2;d[1]=L.key[1];
	for(i=2;i<=L.length;i++)
	{
		if(L.key[i]<d[1])
		{//如果比第一个结点小则插入其前面，即从插入最"后面"
			for(j=L.length;j>=first;j--)
				if(d[j]!=0&&d[j]>L.key[i]);
				else break;
				if(d[j]==0)
				{ d[j]=L.key[i];first=j;}
				else
				{
					for(k=first-1;k<j;k++)
						d[k]=d[k-1];
					first=first-1;
					d[k]=L.key[i];
				}
		}
		else
		{//如果比第一个结点小则插入到该结点后面
			for(j=2;j<=final;j++)
				if(d[j]!=0&&d[j]<L.key[i]);
				else break;
				if(d[j]==0)
				{d[j]=L.key[i];final=j;}
				else
				{
					for(k=final+1;k>j;k--)
						d[k]=d[k-1];
					final=final+1;
					d[k]=L.key[i];
				}
		}
	}
	k=1;
	for(i=first;i<=L.length;i++)
		L.key[k++]=d[i];
	for(i=1;i<=final;i++)
		L.key[k++]=d[i];//把数组d中有序记录重新复制到顺序表L中
}