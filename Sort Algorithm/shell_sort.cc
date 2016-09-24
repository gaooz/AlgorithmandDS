/**
date: 2012��09��
author: gaooz.com
*/

//ϣ������Ҳ�ǲ��������һ�֣������⼸�ֲ���������ʱ�临�Ӷ�Ψһ��ǰ���ֲ�������ʱ�临�ӣ�O(n2)����С�����򷽷���
//ֻ����������Ӧѡ���ʵ���
void ShellInsert(Sqlist &L,int dk)
{//��dk������˳�����һ��ϣ������
	int i,j;
	for(i=dk+1;i<=L.length;i++)
		if(L.key[i]<L.key[i-dk])
		{
			L.key[0]=L.key[i];
			for(j=i-dk;j>0&&L.key[0]<L.key[j];j=j-dk)
				L.key[j+dk]=L.key[j];
			L.key[j+dk]=L.key[0];
		}
}
void ShellSort(Sqlist &L,int dlta[],int t)
{//����������dlta��ϣ������
	int k;
	for(k=0;k<t;k++)
		ShellInsert(L,dlta[k]);
}