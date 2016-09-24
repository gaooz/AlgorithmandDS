/**
date: 2012��09��
author: gaooz.com
*/

/**
ʮ������������ز���
*/
//---------------ʮ������-----------------
//����
typedef struct OLNode{
	int i,j;//�����±�
	int e;
	struct OLNode *right,*dowm;
}OLNode;
typedef struct ListMatrix{
	OLNode *rhead,*chead;
	int mu,nu,tu;//����������������Ԫ����
}ListMatrix;

//��������ʮ�������ʾ�ľ�����
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
	}//�ҵ�ָ��rpre��λ��
	while(1)
	{
		if(cpre->dowm==NULL||cpre->dowm->i>i)  break;
		cpre=cpre->dowm;
	}//�ҵ�cpre��λ��
	if(tag)//�жϸ�Ҫ����Ľ�����ڵ����Ƿ��Ѿ�����Ԫ��
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
//��ʮ������洢����
void CreatMatrix(ListMatrix &m)
{
	int m1,n,t,i;
	OLNode *p,*rpre,*cpre;
	printf("��������������������������Ԫ������");
	scanf("%d%d%d",&m1,&n,&t);
	m.mu=m1;m.nu=n;m.tu=t;
	m.rhead=(OLNode *)malloc((m1+1)*sizeof(OLNode));
	m.chead=(OLNode *)malloc((n+1)*sizeof(OLNode));
	for(i=1;i<m1+1;i++)
		m.rhead[i].right=NULL;
	for(i=1;i<n+1;i++)//��ʼ��ָ���ֵ
		m.chead[i].dowm=NULL;
	printf("��������%d������Ԫ��\n",m.tu);
	for(i=0;i<m.tu;i++)
	{
		p=(OLNode *)malloc(sizeof(OLNode));
		if(!p) exit(1);
		scanf("%d%d%d",&p->i,&p->j,&p->e);
		InsertMatrix(p,m);
	}
}