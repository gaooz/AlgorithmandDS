/**
date: 2012��09��
author: gaooz.com
*/

/**
2012��9��28
��̬���ұ�˳�����
��n�ܴ�ʱ����Ч�ʺܵͣ���ʹ�÷�Χ�ܹ�
*/

int Sequence_search(OrderList l,int num)
{//numΪ��Ҫ���ҵ�Ԫ�ص�ֵ�����ظ�ֵ��˳����е�λ��
	int i;
	for(i=0;i<l.length;i++)
		if(l.a[i]==num)
			return i;
}