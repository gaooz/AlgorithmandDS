/**
date: 2012��09��
author: gaooz.com
*/
/**
���߼�����˳�����
*/
typedef struct 
{
	int i,j;
	int num;
}Triple;
typedef struct 
{
	Triple data[MAXSIZE];
	int rpos[MAXRC];//���ÿ�����׸�����Ԫ��λ��
	int mu,nu,tu;
}RLSMatrix;//���߼�����˳���Ķ���