/**
date: 2012��09��
author: gaooz.com
*/

/**
KMP�㷨
*/
//----------------KMP�㷨----------------
int index_kmp(string T,string S,int pos)
{
	int i=pos,j=1;
	while(i<=S.length&&j<=T.length)
	{
		if(S.ch[i]==T.ch[j])
		{
			i++;
			j++;
		}
		else
			j=next[j+1];
	}
	if(j>T.length)
		return i-T.length;
	else
		return 0;
}
void get_next(string T)
{
	int i=1,j=0;
	next[1]=0;
	while(i<=T.length)
	{
		if(j-1==0||T.ch[i]==T.ch[j])
		{
			i++;
			j++;
			if(T.ch[i]!=T.ch[j])
				next[i]=j;
			else
				next[i]=next[j];
		}
		else
			j=next[j];
	}
}
