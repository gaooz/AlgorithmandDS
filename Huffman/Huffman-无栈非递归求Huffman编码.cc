/**
date: 2012年08月
author: gaooz.com
*/

//---------------无栈非递归遍历哈夫曼树求哈夫曼编码-------------
void BLHuffmanTreeCode(HuffmanTree &HT,HuffmanCode &HC,int n)
{//无栈非递归遍历哈夫曼树求哈夫曼编码
	char *cd;
	int cdlen=0,i,p=2*n-2;
	HC=(HuffmanCode)malloc(n*sizeof(char*));
	cd=(char*)malloc((MAXCHAR)*sizeof(char));
	for(i=0;i<=p;i++)
		HT[i].weight=0;//将其权值全部初始化为0，不影响哈夫曼编码的求取
	while(p!=-1)
	{
		if(HT[p].weight==0)
		{
			HT[p].weight=1;
			if(HT[p].lchild!=-1)
			{
				p=HT[p].lchild;//向左
				cd[cdlen++]='0';
			}
			else
				if(HT[p].rchild==-1)
				{//判断若为叶子结点则求得该结点的哈夫曼编码
					cd[cdlen]='\0';
					HC[p]=(char*)malloc((cdlen+1)*sizeof(char));
					strcpy(HC[p],cd);
				}
		}
		else
			if(HT[p].weight==1)
			{
				HT[p].weight=2;//第二次访问该结点时将其状态改为2
				if(HT[p].rchild!=-1)
				{
					p=HT[p].rchild;
					cd[cdlen++]='1';
				}
			}
			else
			{
				HT[p].weight=0;
				p=HT[p].parent;//退回父亲结点
				cdlen--;
			}
	}
}