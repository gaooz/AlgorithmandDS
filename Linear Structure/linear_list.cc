/**
date: 2012��09��
author: gaooz.com
*/

/**
���Ա�Ķ��弰��ز���
*/
typedef struct
{
	char name[20];//ע�����Ӧ��ָ�����ʽ
	             //�ڳ�ʼ��ÿ�����ʱһ��Ҫ��Ϊ����е�ÿ�����������ڴ�ռ�
	char sex;
	char addr[100];
	unsigned int age;
	char phonenum[20];
}node;//�������
typedef struct
{
	node *p;
	int length;//��ǰ˳�����
	int listsize;//��ǰ��������Ա���
}list;//���Ա�����
list L;//����һ�����Ա�
int initlist(list &l)//����һ���յ����Ա�
{
	l.p=(node*)malloc(LIST_INIT_SIZE*sizeof(node));
	if(!(l.p))
		exit(1);
	l.length=0;
	l.listsize=LIST_INIT_SIZE;
	return true;
}
void destroylist(list &l)//�������Ա����
{
	if(l.p!=NULL)
	{
		free(l.p);
		printf("���ٳɹ�!\n");
	}
	else
		printf("���Ա����ڣ�\n");
}
int clearlist(list &l)//�����Ա��ÿղ���
{
	if(l.p==NULL)
	{
		printf("���Ա����ڣ�\n");
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
int listempty(list &l)//�ж����Ա��Ƿ�Ϊ�ձ�
{
	if(l.p==NULL)
		return true;
	else
		return false;
}
int getelem(list &l,int i,node &e)//��e���ر��е�i������Ԫ��
{
	if(l.p==NULL)
		return false;
	else
		e=l.p[i-1];
	    return true;
}
int priorelem(list &l,int i,node &pre_e)//�õ���i��Ԫ�ص�ǰ��Ԫ��
{
	if(i==0||l.p==NULL)
		return false;
	else
		pre_e=l.p[i-1];
		return true;
}
int nextelem(list &l,int i,node &next_e)//�õ����е�i��Ԫ�صĺ��Ԫ��
{
	if(i>=l.length||l.p==NULL)
		return false;
	else
		next_e=l.p[i+1];
	return true;
}
int insertlist(list &l,int i,node &e)//��Ԫ��e���뵽��l�е�i��Ԫ�صĺ���
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
int deletelist(list &l,int i,node &e)//ɾ�����е�i��Ԫ�ز���e������ֵ
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
void mergerlist(list la,list lb,list &lc)//�鲢�������ǵݼ����е����Ա�
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
int ListAscendingOrder(list &l)//�������ĳһԪ�صıȽ������������Ա��еĽ��
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
}//ʡ�Խ�������
void MergerList(list la,list lb,list &lc)//�������Ա��������к��ٹ鲢
{
	node *q,*k,e1;
	int i=0,j=0,m=0,n;
	ListAscendingOrder(la);
	ListAscendingOrder(lb);
	printf("��a�������к�Ϊ��\n");
	for(i=0;i<la.length;i++)
		printf("%d ",la.p[i].num);
	printf("\n");
	printf("��b�������к�Ϊ��\n");
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
		printf("�����������ٹ鲢����Ϊ��\n");
		for(n=0;n<lc.length;n++)
			printf("%d ",lc.p[n].num);
		printf("\n");
}