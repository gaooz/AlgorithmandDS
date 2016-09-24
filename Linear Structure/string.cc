
/**
date: 2012��09��
author: gaooz.com
*/

/**
�ַ����ṹ��������ز���ʵ��
*/
//-----------�����ѷ���洢��ʽ��һЩ����------------------//
typedef struct string
{
	char *ch;
	int length;
}sstring;
void CreatString(sstring &T)
{
	T.ch=(char*)malloc(sizeof(char));
	T.length=0;
}
void StringAssign(sstring &T,char *s)
{//����s��ֵ��ֵ����T
	if(T.ch)
		free(T.ch);
	T.ch=(char*)malloc(strlen(s)*sizeof(char));//����T.ch=(char*)malloc(sizeof(char));
	//��̬���ٿռ䲻ͬ�ھ�̬�ڴ濪��֮��
	if(!T.ch)
	{
		printf("ERROR");
		exit(1);
	}
	strcpy(T.ch,s);
	T.length=strlen(s);
}
void ClearString(sstring &T)
{
	if(T.ch)
		free(T.ch);
	T.length=0;
}
void ConcatString(sstring &T,sstring s1,sstring s2)
{//������
	if(T.ch)
		free(T.ch);
	T.ch=(char*)malloc((strlen(s1.ch)+strlen(s2.ch))*sizeof(char));
	if(!T.ch)
	{
		printf("ERROR\n");
		exit(1);
	}
	strcpy(T.ch,s1.ch);
	strcat(T.ch,s2.ch);
	T.length=strlen(s1.ch)+strlen(s2.ch);
}
void SubString(sstring &sub,sstring s,int pos,int len)
{//ȡ�Ӵ�������ȡ��s��λ�ô�pos��len�����Ӵ���sub��
	int i,j=0;
	if(sub.ch)
		free(sub.ch);
	sub.ch=(char *)malloc((len-pos+1+1)*sizeof(char));
	if(!sub.ch)
	{
		printf("ERROR\n");
		exit(1);
	}
	for(i=pos-1;i<len;i++)
		sub.ch[j++]=s.ch[i];
	sub.ch[j]='\0';
	sub.length=strlen(sub.ch);
}
int CountString(sstring s1,sstring s2)
{//�ж��Ӵ�s2��ĸ��s1�г��ֵĴ���
	int i,j,k,count=0;
	if(s1.length==0||s2.length==0||s2.length>s1.length)
	{
		printf("ERROR\n");
		return 0;
	}
	else
	{
		for(i=0;i<s1.length;i++)
		{
			k=1;
			for(j=0;j<s2.length;j++)
			{
				if(s2.ch[j]!=s1.ch[i+j])
				{
					k=0;
					break;
				}
			}
			if(k)
				count++;
		}
	}
	return count;
}
void Deletestring(sstring &s,int pos,int len)
{//ɾ��s����λ�ô�pos��len����Ԫ��
	int i,j,k;
	if(s.length==0)
		printf("ERROR\n");
	else
	{
		for(i=pos-1,j=len;j<s.length;i++,j++)
			s.ch[i]=s.ch[j];
		s.ch[i]='\0';
		s.length-=(len-pos)+1;
	}
}
void DeleteSub(sstring &s1,sstring s2)
{//ɾ��ĸ��s1�е��Ӵ�s2
	int i,j,k,tag=0;
	for(i=0;i<s1.length;i++)
	{
		k=1;
		if(tag)
		i--;
		for(j=0;j<s2.length;j++)
			if(s2.ch[j]!=s1.ch[i+j])
			{
				k=0;
				break;
			}
			if(k)
			{
				Deletestring(s1,i+1,i+s2.length);
				tag=1;
			}
	}

}