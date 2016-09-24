/**
date: 2012��09��
author: gaooz.com
*/


/**
�������߼�����˳���ʵ�־������
*/
int MultMatrix(RLSMatrix m,RLSMatrix n,RLSMatrix &q)
{//������˺����������㷨
	int arow,ctemp[MAXRC],i,tp,p,brow,t,ql,ccol;
	if(m.nu!=n.mu)
		return ERROR;
	q.mu=m.mu;q.nu=n.nu;q.tu=0;
	if(m.tu*n.tu!=0)
	{
		for(arow=1;arow<=m.mu;arow++)
		{//��m������ÿ�н��д���
			for(i=1;i<=n.nu;i++)
				ctemp[i]=0;//ÿ�д���ʼ��ʹ��ctemp[]����
			q.rpos[arow]=q.tu+1;//�����q��rpos��ֵ
			if(arow<m.mu)
				tp=m.rpos[arow+1];
			else
				tp=m.tu+1;//���arow��һ�е�һ���������ڵ�λ��
			for(p=m.rpos[arow];p<tp;p++)//���δ������m��ÿ�������еķ���Ԫ
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
		num[i]=0;//��ʹÿ����Ԫ�صĸ���Ϊ0
	for(i=1;i<=m.tu;i++)
		num[m.data[i].i]++;//������Ԫ�����ÿ����Ԫ�صĸ���
	for(j=1;j<=m.mu;j++)
	{
		if(num[j]!=0)
			break;
	}
	m.rpos[j]=1;//j�����һ������Ԫ����Ϊ����е��±�
	for(i=j+1;i<=m.mu;i++)
		m.rpos[i]=m.rpos[i-1]+num[i-1]; //���ÿ���ϵ�һ��Ԫ����ת�þ�����Ԫ���еĴ洢���

}