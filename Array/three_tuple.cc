/**
date: 2012��09��
author: gaooz.com
*/

/**
��Ԫ�����ݽṹ����
*/
#define MAX 12500//����һ��ϡ����������12500������Ԫ
typedef struct
{
	int i,j;//i,j���ڴ洢������Ԫ�ص��С����±�
	int num;//numΪ�����з���Ԫ��ֵ
}Triple;//����һ����Ԫ��
typedef struct 
{
	Triple data[MAX+1];
	int mu,nu,tu;//mu,nu�Ǳ��ʾһ��ϡ����������������
	//tu��ʾ��ϡ�����ķ���Ԫ����
}TSMatrix;