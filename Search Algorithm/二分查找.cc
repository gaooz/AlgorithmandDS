
/**
date: 2012��09��
author: gaooz.com
*/

/**
��̬���ұ��۰����
ֻ�����������˳����ұ�Ч�����Ը���˳�����.
*/

int Binary_search(OrderList l,int num)
{//�۰���ҡ�����num��˳���l�е�λ��
	//ֻ�����������˳���
	int i,low,high,mid;
	low=0;//˳����е�Ԫ��λ���Ǵ�0��ʼ��
	high=l.length-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(l.a[mid]==num)
			return mid;
		else
			if(l.a[mid]>num)
				high=mid-1;
			else
				low=mid+1;
	}
	return 0;
}