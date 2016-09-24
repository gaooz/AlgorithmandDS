/**
date: 2012��09��
author: gaooz.com
*/

/**
�����Ķ��弰��ز���
*/
//--------------------�����----------------2012/09/01
//------------�����Ĺ��켰�ݹ����-----------
//�����Ķ����õ�����һЩ�������������д��Ķ����ڴ˲���������
typedef enum{ATOM,LIST}ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union{
		char atom;
		struct{struct GLNode *hp,*tp;}ptr;
	};//��atomռ���ڴ������Ϊԭ�ӽ�㣬����ptrռ���ڴ�Ϊ����
}*Glist;//�������ṹ�Ķ���
void SubString(Sstring &A,Sstring &B,int i,int n)
{//ȡ�Ӵ�����
	//��B���дӵ�i���ַ��𳤶�Ϊn���ַ������Ƶ�A��
	int j=0,m=0;
		for(j=i;j<i+n;j++)
			A.ch[m++]=B.ch[j];
		A.ch[m]='\0';
		A.length=m;
}
void SeverGlist(Sstring &str,Sstring &hstr)
{//���ǿմ����������ʽ�Ĵ���str�е�һ������֮ǰ��
	//�ַ��ø�hstr��ʣ����ַ�����ȥ�ö��ţ�����str��
	Sstring Ch;int i=0,k=0,n=str.length;
	InitString(Ch);
	do
	{
		i++;
		ClearString(Ch);InitString(Ch);
		SubString(Ch,str,i-1,1);//ÿ��ȡһ���ַ���Ch����
		if(Ch.ch[0]=='(')
			k++;
		else
			if(Ch.ch[0]==')')
				k--;
	}while(i<n&&(Ch.ch[0]!=','||k!=0));
		if(i<n)
		{
			SubString(hstr,str,0,i-1);
			SubString(str,str,i,n-i);
		}
		else
		{
			strcpy(hstr.ch,str.ch);
			hstr.length=str.length;
			ClearString(str);
		}
}
void CreatGlist(Glist &L,Sstring &S)
{//�����Ĺ���
	//����ͷβ����洢�ṹ,�ɹ������д��ʽ��S��������
	Glist p,q;Sstring sub,hsub;
	InitString(sub);InitString(hsub);
	if(strcmp(S.ch,"()")==0) L=NULL;
	else
	{
		if(!(L=(Glist)malloc(sizeof(GLNode))))
			exit(1);
		if(S.length==1)
		{//��Ϊ�����ַ���ԭ��
			L->tag=ATOM;
			L->atom=S.ch[0];
		}
		else
		{
			L->tag=LIST;p=L;//LΪ��ͷ
			SubString(sub,S,1,S.length-2);//��ȥ�������
			do
			{
				SeverGlist(sub,hsub);//��sub�з������ͷ��hsub
				CreatGlist(p->ptr.hp,hsub);q=p;
				if(!StringEmpty(sub))
				{
					p=(Glist)malloc(sizeof(GLNode));
					p->tag=LIST;q->ptr.tp=p;
				}
			}while(!StringEmpty(sub));
			q->ptr.tp=NULL;
		}
	}
	printf("�������ɹ���\n");
}
void TraverseGlist(Glist &L)
{//�ݹ���������
	Glist p;
	if(L)
	{
		p=L;
		if(p->tag==ATOM)
			printf("%c ",p->atom);
		else
		{
			while(p)
			{
				TraverseGlist(p->ptr.hp);
				p=p->ptr.tp;
			}
		}
	}
}
//---------------���������ȡ����õݹ�-------------2012/09/02
int GlistDepth(Glist &L)
{//�ݹ�����������
	Glist p;int depth,max=0;
	if(!L) return 1;//�ձ�����Ϊ1
	if(L->tag==ATOM) return 0;//ԭ�ӵ����Ϊ0
	for(p=L;p;p=p->ptr.tp)
	{
		depth=GlistDepth(p->ptr.hp);
		if(max<depth)
			max=depth;//�ҳ����ӱ�����ȵ����ֵ
	}
	return max+1;//���������Ϊ���ӱ���������ļ�1
}
//-------------�����ĸ���--------------2012��09��02
void CopyGlist(Glist &T,Glist L)
{//�����ĸ��ƣ�����L���Ƶ���T��/���õݹ�ʵ��
	if(!L) T=NULL;//��Ϊ��
	else
	{
		T=(Glist)malloc(sizeof(GLNode));
		T->tag=L->tag;
		if(L->tag==ATOM)
		{//��Ϊԭ�ӽ��
			T->atom=L->atom;
		}
		else
			if(L->tag==LIST)
			{//��Ϊ����
				CopyGlist(T->ptr.hp,L->ptr.hp);
				CopyGlist(T->ptr.tp,L->ptr.tp);
			}
	}
}