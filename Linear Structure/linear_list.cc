/**
date: 2012年09月
author: gaooz.com
*/

/**
线性表的定义及相关操作
*/
typedef struct
{
	char name[20];//注意如果应用指针的形式
	             //在初始化每个结点时一定要先为结点中的每个变量开辟内存空间
	char sex;
	char addr[100];
	unsigned int age;
	char phonenum[20];
}node;//结点描述
typedef struct
{
	node *p;
	int length;//当前顺序表长度
	int listsize;//当前分配的线性表长度
}list;//线性表描述
list L;//定义一个线性表
int initlist(list &l)//构造一个空的线性表
{
	l.p=(node*)malloc(LIST_INIT_SIZE*sizeof(node));
	if(!(l.p))
		exit(1);
	l.length=0;
	l.listsize=LIST_INIT_SIZE;
	return true;
}
void destroylist(list &l)//销毁线性表操作
{
	if(l.p!=NULL)
	{
		free(l.p);
		printf("销毁成功!\n");
	}
	else
		printf("线性表不存在！\n");
}
int clearlist(list &l)//将线性表置空操作
{
	if(l.p==NULL)
	{
		printf("线性表不存在！\n");
		return false;
	}
	else
		{
			free(l.p);
			l.p=(node*)malloc(l.listsize*sizeof(node));
			l.length=0;
	    }
	return true;
}
int listempty(list &l)//判断线性表是否为空表
{
	if(l.p==NULL)
		return true;
	else
		return false;
}
int getelem(list &l,int i,node &e)//用e返回表中第i个数据元素
{
	if(l.p==NULL)
		return false;
	else
		e=l.p[i-1];
	    return true;
}
int priorelem(list &l,int i,node &pre_e)//得到第i个元素的前驱元素
{
	if(i==0||l.p==NULL)
		return false;
	else
		pre_e=l.p[i-1];
		return true;
}
int nextelem(list &l,int i,node &next_e)//得到表中第i个元素的后继元素
{
	if(i>=l.length||l.p==NULL)
		return false;
	else
		next_e=l.p[i+1];
	return true;
}
int insertlist(list &l,int i,node &e)//将元素e插入到表l中第i个元素的后面
{
	node *q,*k;
	if(i<1||i>l.length+1)
		return false;
	if(l.length>=l.listsize)
	{
		l.p=(node *)realloc(l.p,(l.listsize+LISTINCREMENT)*sizeof(node));
		if(!l.p)
			exit(1);
		l.listsize+=LISTINCREMENT;
	}
	k=&l.p[i-1];
	for(q=&l.p[l.length-1];q>k;q--)
		*(q+1)=*q;
	*k=e;
	l.length++;
	return true;
}
int deletelist(list &l,int i,node &e)//删除表中第i个元素并用e返回其值
{
	node *q;
	int j=i-1;
	if(i<1||i>l.length)
		return false;
	e=l.p[i-1];
	for(q=&l.p[i-1];j<l.length-1;j++)
		*q=*(++q);
	l.length--;
	return true;
}
void mergerlist(list la,list lb,list &lc)//归并两个按非递减排列的线性表
{
	int la_len,lb_len,i=1,j=1,k=0;
	node ai,bj;
	la_len=la.length;
	lb_len=lb.length;
	while(i<=la_len&&j<=lb_len)
	{
		getelem(la,i,ai);
		getelem(lb,j,bj);
		if(ai.a<=bj.a)
		{
			insertlist(lc,++k,ai);
			i++;
		}
		else
		{
			insertlist(lc,++k,bj);
			j++;
		}
	}
	while(i<=la_len)
	{
		getelem(la,i,ai);
		insertlist(lc,++k,ai);
		i++;
	}
	while(j<=lb_len)
	{
		getelem(lb,j,bj);
		insertlist(lc,++k,bj);
		j++;
	}
}
int ListAscendingOrder(list &l)//按结点中某一元素的比较升序排列线性表中的结点
{
	node e;
	int i,j;
	if(l.p==NULL||l.length==1)
		return ERROR;
	for(i=0;i<l.length-1;i++)
		for(j=i+1;j<l.length;j++)
			if(l.p[i].num>=l.p[j].num)
			{
				e=l.p[i];
				l.p[i]=l.p[j];
				l.p[j]=e;
			}
			return OK;
}//省略降序排列
void MergerList(list la,list lb,list &lc)//将两线性表升序排列后再归并
{
	node *q,*k,e1;
	int i=0,j=0,m=0,n;
	ListAscendingOrder(la);
	ListAscendingOrder(lb);
	printf("表a升序排列后为：\n");
	for(i=0;i<la.length;i++)
		printf("%d ",la.p[i].num);
	printf("\n");
	printf("表b升序排列后为：\n");
	for(i=0;i<lb.length;i++)
		printf("%d ",lb.p[i].num);
	printf("\n");
	i=0;
	while(i<la.length&&j<lb.length)
	{
		if(la.p[i].num<=lb.p[j].num)
		{
			e1=la.p[i];
			i++;
		}
		else
		{
			e1=lb.p[j];
			j++;
		}
		if(e1.num!=lc.p[lc.length-1].num)
			InsertList(lc,++m,e1);
	}
	if(i<la.length)
		while(i<la.length)
		{
			if(la.p[i].num!=lc.p[lc.length-1].num)
				InsertList(lc,++m,la.p[i]);
			i++;
		}
	if(j<lb.length)
		while(j<lb.length)
		{
			if(lb.p[j].num!=lc.p[lc.length-1].num)
				InsertList(lc,++m,lb.p[j]);
			j++;
		}
		printf("按升序排列再归并两表为：\n");
		for(n=0;n<lc.length;n++)
			printf("%d ",lc.p[n].num);
		printf("\n");
}