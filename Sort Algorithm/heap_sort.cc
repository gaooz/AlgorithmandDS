/**
date: 2012��09��
author: gaooz.com
*/

void HeapAdjust(Sqlist &L,int s,int m)
{//������ɸѡ��L.data[s]ʹL.data[s....m]��Ϊһ���󶥶�
	int rc,j;rc=L.data[s];
	for(j=2;j<=m;j=j*2)
	{
		if(j<m&&L.data[j]>L.data[j+1]) j++;
		if(rc<L.data[j]) break;
		L.data[s]=L.data[j];s=j;
	}
	L.data[s]=rc;
}
void HeapSort(Sqlist &L)
{//������ʱ�临�Ӷ�ΪO(nlog2n)
	int i,change;
	for(i=L.length/2;i>=0;i--)
		HeapAdjust(L,i,L.length);//��L.data[1...L.length]���ɴ󶥶�
	for(i=L.length;i>1;i--)
	{
		change=L.data[1];
		L.data[1]=L.data[i];
		L.data[i]=change;//���һ����¼�໥����
		HeapAdjust(L,1,i-1);//��L.data[1...i-1]���µ���Ϊ�󶥶�
	}
}