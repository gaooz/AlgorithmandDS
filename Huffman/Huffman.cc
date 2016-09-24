/**
date: 2012��08��
author: gaooz.com
*/

//----------�����������������������Ĺ���������----------2012��08��29
typedef struct {
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;//�����������Ķ���
typedef char* *HuffmanCode;//�����ַ��Ͷ�ά��ַ
void CreatHuffmanTree(HuffmanTree &HT,int *w,int n)
{//�����������
	//w�д�ŵ���n��Ҷ�ӽ���Ȩֵ
	int i,j,min1,min2,minl,minr;
	HT=(HuffmanTree)malloc((2*n-1)*sizeof(HTNode));
	if(!HT)
		exit(1);
	for(i=0;i<n;i++)
		HT[i].weight=w[i];//HTǰn�����ΪҶ�ӽ��
	for(i=n;i<2*n-1;i++)
		HT[i].weight=0;//��ʼ��ʣ����
	for(i=0;i<2*n-1;i++)
	{//��ʼ��
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}
	for(i=n;i<2*n-1;i++)
	{
		min1=min2=MAX;
		for(j=0;j<i;j++)
		{
			if(HT[j].parent==-1)
			{
				if(HT[j].weight<min1) {min1=HT[j].weight;minl=j;}
			}
		}//�ҵ���һ����С����
		HT[minl].parent=i;
		for(j=0;j<i;j++)
		{
			if(HT[j].parent==-1)
			{
				if(HT[j].weight<min2)  { min2=HT[j].weight;  minr=j;}
			}
		}//�ҵ��ڶ�����С����
		HT[minr].parent=i;
		HT[i].weight=HT[minl].weight+HT[minr].weight;
		HT[i].lchild=minl;
		HT[i].rchild=minr;//��������ϵ
	}
}
void HuffmanTreeCode(HuffmanTree &HT,HuffmanCode &HC,int n)
{//��Ҷ�ӽ�㵽��������������������
	char *cd;int i,j,start,f;
	cd=(char *)malloc(MAXCHAR*sizeof(char));
	HC=(HuffmanCode)malloc(n*sizeof(char*));`
	cd[MAXCHAR-1]='\0';
	for(i=0;i<n;i++)
	{
		start=MAXCHAR-1;
		for(j=i,f=HT[j].parent;f!=-1;j=f,f=HT[f].parent)
		{	if(HT[f].lchild==j)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		HC[i]=(char *)malloc((MAXCHAR-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
}