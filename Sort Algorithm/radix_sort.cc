
/*
# date 2012年09月
# gaooz.com
# radix sort
***/

void Distribute(SLList l,int i,ArrType &f,ArrType &e)
{//按LSD分配算法。
	int p,j;
	for(j=0;j<RADIX;j++) f[j]=0;//指针初始化
	for(p=l.r[0].next;p!=0;p=l.r[p].next)
	{
		j=ord(l.r[p].key,i);//取得低位关键字在记录中的下标
		if(f[j]==0) f[j]=p;//若第j个静态链表为空则头指针直接指向即可
		else l.r[e[j]].next=p;//若第j个静态链表不为空则从后面插入
		e[j]=p;//更改尾指针的指向
	}
}
void Collect(SLList &r,int i,ArrType f,ArrType e)
{//收集算法。与分配算法相对
	int j,t;
	for(j=0;!f[j];j++);//找到第一个非空子表
	r.r[0].next=f[j];t=e[j];//r.r[0]指向第一个非空子表的第一个结点
	while(j<RADIX)
	{
		for(j++;j<RADIX-1&&!f[j];j++);//找到下一个非空子表
		if(f[j]) {r.r[t].next=f[j];t=e[j];}
	}
	r.r[t].next=0;//收集完成后最后一个结点的next指针指向0
}
void RadixSort(SLList &L)
{//基数排序.时间复杂度为O(d(n+rd)),其中d为记录中关键字的个数
	//rd为基数的取值范围,n为记录的个数
	int i;ArrType f,e;
	for(i=0;i<L.recnum;i++) L.r[i].next=i+1;
	L.r[L.recnum].next=0;//最后一个记录的next指针指向0
	for(i=0;i<L.keynum;i++)
	{
		Distribute(L,i,f,e);
		Collect(L,i,f,e);
	}
}