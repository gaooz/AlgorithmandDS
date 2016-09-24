/**
date: 2012��09��
author: gaooz.com
*/

/**
���������Ƕ����������һ�ָĽ����������ƽ������ʱ���ǿ�����������õ����򷽷���
һ��ȡ��һ��Ԫ��Ϊ�����¼������˳���������������ʱȡ��һ����¼Ϊ�����ʹ�ÿ��������˻�Ϊ��������ʱ�临�Ӷ�ΪO(n2)����
���Ϊ������������˻�Ϊ��������ͨ���ڱ��м�¼������������ʱ����"����ȡ��"����ȡ�������㡣
*/

int Partition(Sqlist &L,int low,int high)
{//���������ѡȡ�ģ�ͨ��ѡ���һ����¼Ϊ����
	//ʹ����λ�ô�low��highλ�õļ�¼���������У�
	//���������ļ�¼���е�����֮�󣬷�����������ǰ��
	//�������к������¼��˳�����λ��
	int pivotkey;
	L.key[0]=L.key[low];//ѡ��һ��Ԫ��Ϊ�����¼�洢��0��Ԫλ��
	pivotkey=L.key[low];//ȡ�������¼�ؼ���
	while(low<high)
	{
		while(low<high&&L.key[high]>=pivotkey) high--;
		L.key[low]=L.key[high];
		while(low<high&&L.key[low]<=pivotkey) low++;
		L.key[high]=L.key[low];
	}
	L.key[low]=L.key[0];//�������¼�����������������ڵ���λ��
	return low;//�������������ڵ���λ��
}
void QSort(Sqlist &L,int low,int high)
{//��˳���L�д�low��high����������������
	int p;
	if(low<high)
	{
		p=Partition(L,low,high);
		QSort(L,low,p-1);//�Ե��ӱ��������p������λ��
		QSort(L,p+1,high);//�Ը��ӱ��������
	}
}
void QuickSort(Sqlist &L)
{//��������
	QSort(L,1,L.length);
}