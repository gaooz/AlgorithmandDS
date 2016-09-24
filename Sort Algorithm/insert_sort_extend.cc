/**
date: 2012��09��
author: gaooz.com
*/

/*
�۰�����������ֱ�Ӳ���������˵�Ľ��˱Ƚϴ���
��¼�ƶ�������δ�ı䡢ʱ�临�Ӷ�ΪO(n2)
*/
void BinarySort(Sqlist &L)
{//�۰��������
	int low,high,i,m,j;
	for(i=2;i<=L.length;i++)
	{
		L.key[0]=L.key[i];
		low=1;high=i-1;
		while(low<=high)
		{//�۰���ҵõ���i�������ǰ��������еĲ���λ��
			m=(low+high)/2;
			if(L.key[i]<L.key[m]) high=m-1;
			else low=m+1;
		}
		for(j=i-1;j>=high+1;j--) L.key[j+1]=L.key[j];//��¼����ƶ�
		L.key[high+1]=L.key[0];//������
	}
}

//---------------------2-·��������----------------------
void TwoRoadSort(Sqlist &L)
{//2-·�����������ֱ�Ӳ����������������˼�¼�ƶ��Ĵ���
	//ʱ�临�Ӷ�����O(n2)
	int d[MAXSIZE],i,j,k,first,final;
	//firstָ��ָ���d[1]С����С���Ǹ�Ԫ��λ��
	//finalָ���d[1]��������Ǹ�Ԫ�ص�λ��
	//�����йؼ��ְ��ǵݼ�2-·������������������d�к�first=final+1
	for(i=1;i<=L.length;i++)
		d[i]=0;//��������ĳ�ʼ��
	first=1;final=2;d[1]=L.key[1];
	for(i=2;i<=L.length;i++)
	{
		if(L.key[i]<d[1])
		{//����ȵ�һ�����С�������ǰ�棬���Ӳ�����"����"
			for(j=L.length;j>=first;j--)
				if(d[j]!=0&&d[j]>L.key[i]);
				else break;
				if(d[j]==0)
				{ d[j]=L.key[i];first=j;}
				else
				{
					for(k=first-1;k<j;k++)
						d[k]=d[k-1];
					first=first-1;
					d[k]=L.key[i];
				}
		}
		else
		{//����ȵ�һ�����С����뵽�ý�����
			for(j=2;j<=final;j++)
				if(d[j]!=0&&d[j]<L.key[i]);
				else break;
				if(d[j]==0)
				{d[j]=L.key[i];final=j;}
				else
				{
					for(k=final+1;k>j;k--)
						d[k]=d[k-1];
					final=final+1;
					d[k]=L.key[i];
				}
		}
	}
	k=1;
	for(i=first;i<=L.length;i++)
		L.key[k++]=d[i];
	for(i=1;i<=final;i++)
		L.key[k++]=d[i];//������d�������¼���¸��Ƶ�˳���L��
}