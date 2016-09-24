/**
date: 2012年09月
author: gaooz.com
*/

/**
广义表的定义及相关操作
*/
//--------------------广义表----------------2012/09/01
//------------广义表的构造及递归遍历-----------
//广义表的定义用到串的一些操作，上述已有串的定义在此不再叙述。
typedef enum{ATOM,LIST}ElemTag;
typedef struct GLNode{
	ElemTag tag;
	union{
		char atom;
		struct{struct GLNode *hp,*tp;}ptr;
	};//若atom占用内存则表明为原子结点，否则ptr占用内存为表结点
}*Glist;//广义表结点结构的定义
void SubString(Sstring &A,Sstring &B,int i,int n)
{//取子串操作
	//将B串中从第i个字符起长度为n的字符串复制到A中
	int j=0,m=0;
		for(j=i;j<i+n;j++)
			A.ch[m++]=B.ch[j];
		A.ch[m]='\0';
		A.length=m;
}
void SeverGlist(Sstring &str,Sstring &hstr)
{//将非空串（广义表形式的串）str中第一个逗号之前的
	//字符置给hstr，剩余的字符（除去该逗号）留在str中
	Sstring Ch;int i=0,k=0,n=str.length;
	InitString(Ch);
	do
	{
		i++;
		ClearString(Ch);InitString(Ch);
		SubString(Ch,str,i-1,1);//每次取一个字符至Ch串中
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
{//广义表的构造
	//采用头尾链表存储结构,由广义表书写形式串S定义广义表
	Glist p,q;Sstring sub,hsub;
	InitString(sub);InitString(hsub);
	if(strcmp(S.ch,"()")==0) L=NULL;
	else
	{
		if(!(L=(Glist)malloc(sizeof(GLNode))))
			exit(1);
		if(S.length==1)
		{//若为单个字符即原子
			L->tag=ATOM;
			L->atom=S.ch[0];
		}
		else
		{
			L->tag=LIST;p=L;//L为表头
			SubString(sub,S,1,S.length-2);//脱去外层括号
			do
			{
				SeverGlist(sub,hsub);//从sub中分离出表头串hsub
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
	printf("广义表构造成功！\n");
}
void TraverseGlist(Glist &L)
{//递归遍历广义表
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
//---------------求广义表的深度、利用递归-------------2012/09/02
int GlistDepth(Glist &L)
{//递归求广义表的深度
	Glist p;int depth,max=0;
	if(!L) return 1;//空表的深度为1
	if(L->tag==ATOM) return 0;//原子的深度为0
	for(p=L;p;p=p->ptr.tp)
	{
		depth=GlistDepth(p->ptr.hp);
		if(max<depth)
			max=depth;//找出各子表中深度的最大值
	}
	return max+1;//广义表的深度为各子表中深度最大的加1
}
//-------------广义表的复制--------------2012、09、02
void CopyGlist(Glist &T,Glist L)
{//广义表的复制，将表L复制到表T中/利用递归实现
	if(!L) T=NULL;//若为空
	else
	{
		T=(Glist)malloc(sizeof(GLNode));
		T->tag=L->tag;
		if(L->tag==ATOM)
		{//若为原子结点
			T->atom=L->atom;
		}
		else
			if(L->tag==LIST)
			{//若为表结点
				CopyGlist(T->ptr.hp,L->ptr.hp);
				CopyGlist(T->ptr.tp,L->ptr.tp);
			}
	}
}