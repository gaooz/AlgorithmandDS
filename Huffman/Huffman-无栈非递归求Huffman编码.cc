/**
date: 2012��08��
author: gaooz.com
*/

//---------------��ջ�ǵݹ�����������������������-------------
void BLHuffmanTreeCode(HuffmanTree &HT,HuffmanCode &HC,int n)
{//��ջ�ǵݹ�����������������������
	char *cd;
	int cdlen=0,i,p=2*n-2;
	HC=(HuffmanCode)malloc(n*sizeof(char*));
	cd=(char*)malloc((MAXCHAR)*sizeof(char));
	for(i=0;i<=p;i++)
		HT[i].weight=0;//����Ȩֵȫ����ʼ��Ϊ0����Ӱ��������������ȡ
	while(p!=-1)
	{
		if(HT[p].weight==0)
		{
			HT[p].weight=1;
			if(HT[p].lchild!=-1)
			{
				p=HT[p].lchild;//����
				cd[cdlen++]='0';
			}
			else
				if(HT[p].rchild==-1)
				{//�ж���ΪҶ�ӽ������øý��Ĺ���������
					cd[cdlen]='\0';
					HC[p]=(char*)malloc((cdlen+1)*sizeof(char));
					strcpy(HC[p],cd);
				}
		}
		else
			if(HT[p].weight==1)
			{
				HT[p].weight=2;//�ڶ��η��ʸý��ʱ����״̬��Ϊ2
				if(HT[p].rchild!=-1)
				{
					p=HT[p].rchild;
					cd[cdlen++]='1';
				}
			}
			else
			{
				HT[p].weight=0;
				p=HT[p].parent;//�˻ظ��׽��
				cdlen--;
			}
	}
}