/**
date: 2012年09月
author: gaooz.com
*/

/**
十字链表定义与相关操作
*/
//---------------十字链表-----------------
//定义
typedef struct OLNode{
	int i,j;//行列下标
	int e;
	struct OLNode *right,*dowm;
}OLNode;
typedef struct ListMatrix{
	OLNode *rhead,*chead;
	int mu,nu,tu;//行数、列数、非零元个数
}ListMatrix;

//将结点插入十字链表表示的矩阵中
void InsertMatrix(OLNode *t,ListMatrix &q)
{
	OLNode *rpre,*cpre,*p;
	int i,tag;
	p=(OLNode *)malloc(sizeof(OLNode));
	p->i=t->i;p->j=t->j;p->e=t->e;
	rpre=&q.rhead[p->i];cpre=&q.chead[p->j];
	for(i=1;i<q.nu+1;i++)
	{
		tag=1;
		if(rpre->right==NULL||rpre->right->j>p->j)  break;
		if(rpre->right->j==p->j) {tag=0;break;}
		rpre=rpre->right;
	}//找到指针rpre的位置
	while(1)
	{
		if(cpre->dowm==NULL||cpre->dowm->i>i)  break;
		cpre=cpre->dowm;
	}//找到cpre的位置
	if(tag)//判断该要出入的结点所在的行是否已经存在元素
	{
		p->right=rpre->right;rpre->right=p;
		p->dowm=cpre->dowm;cpre->dowm=p;
	}
	else
	{
		if(rpre->right->e+p->e==0)
		{
			if(rpre->right!=NULL)
			rpre->right=rpre->right->right;
			if(cpre->dowm!=NULL)
			cpre->dowm=cpre->dowm->dowm;
		}
		if(rpre->right->e+p->e!=0)
			rpre->right->e+=p->e;
	}
}
//用十字链表存储矩阵
void CreatMatrix(ListMatrix &m)
{
	int m1,n,t,i;
	OLNode *p,*rpre,*cpre;
	printf("请输入矩阵的行数、列数、非零元个数：");
	scanf("%d%d%d",&m1,&n,&t);
	m.mu=m1;m.nu=n;m.tu=t;
	m.rhead=(OLNode *)malloc((m1+1)*sizeof(OLNode));
	m.chead=(OLNode *)malloc((n+1)*sizeof(OLNode));
	for(i=1;i<m1+1;i++)
		m.rhead[i].right=NULL;
	for(i=1;i<n+1;i++)//初始化指针的值
		m.chead[i].dowm=NULL;
	printf("请输入这%d个非零元：\n",m.tu);
	for(i=0;i<m.tu;i++)
	{
		p=(OLNode *)malloc(sizeof(OLNode));
		if(!p) exit(1);
		scanf("%d%d%d",&p->i,&p->j,&p->e);
		InsertMatrix(p,m);
	}
}