/**
date: 2012年09月
author: gaooz.com
*/


/**
利用行逻辑连接顺序表实现矩阵相乘
*/
int MultMatrix(RLSMatrix m,RLSMatrix n,RLSMatrix &q)
{//矩阵相乘函数、核心算法
	int arow,ctemp[MAXRC],i,tp,p,brow,t,ql,ccol;
	if(m.nu!=n.mu)
		return ERROR;
	q.mu=m.mu;q.nu=n.nu;q.tu=0;
	if(m.tu*n.tu!=0)
	{
		for(arow=1;arow<=m.mu;arow++)
		{//按m矩阵中每行进行处理
			for(i=1;i<=n.nu;i++)
				ctemp[i]=0;//每行处理开始，使得ctemp[]置零
			q.rpos[arow]=q.tu+1;//求矩阵q中rpos的值
			if(arow<m.mu)
				tp=m.rpos[arow+1];
			else
				tp=m.tu+1;//求得arow下一行第一个非零所在的位置
			for(p=m.rpos[arow];p<tp;p++)//依次处理矩阵m中每行上所有的非零元
			{
				brow=m.data[p].j;
				if(brow<n.mu)
					t=n.rpos[brow+1];
				else
					t=n.tu+1;
				for(ql=n.rpos[brow];ql<t;ql++)
				{
					ccol=n.data[ql].j;
					ctemp[ccol]+=m.data[p].num*n.data[ql].num;
				}

			}
			for(ccol=1;ccol<=n.nu;ccol++)
			{
				if(ctemp[ccol])
				{
					if(++q.tu>MAXSIZE) return ERROR;
					q.data[q.tu].i=arow;
					q.data[q.tu].j=ccol;
					q.data[q.tu].num=ctemp[ccol];
				}
			}
		}
	}
	return OK;
}
void getrpos(RLSMatrix &m)
{
	int i,num[MAXRC],j;
	for(i=1;i<=m.mu;i++)
		num[i]=0;//先使每行上元素的个数为0
	for(i=1;i<=m.tu;i++)
		num[m.data[i].i]++;//遍历三元组求得每行上元素的个数
	for(j=1;j<=m.mu;j++)
	{
		if(num[j]!=0)
			break;
	}
	m.rpos[j]=1;//j代表第一个非零元数不为零的行的下标
	for(i=j+1;i<=m.mu;i++)
		m.rpos[i]=m.rpos[i-1]+num[i-1]; //求得每列上第一个元素在转置矩阵三元组中的存储序号

}