
/**
date: 2012��09��
author: gaooz.com
*/

//-------------------��ϣ��-----------------------2012��10��4
typedef struct{
	int *elem;//����ؼ���Ϊ����
	int count;//��ǰ��ϣ���еĹؼ��ָ���
	int length;//��ǰ��ϣ�������
}HashTable;
HashTable H;
int Hash(int key)//��ϣ����
{return key%11;}
int Collision(int p,int c)
{//��ͻ������
	//������̽����ɢ����Ϊ��ͻ����ʽ
	return (p+c)%H.length;//�����ҵ��Ĺ�ϣ��ַ
}
int SearchHash(HashTable H,int key,int &p,int &c)
{//���ҹؼ���key�ڹ�ϣ���е�λ�ã�������ҳɹ��򷵻�SUCCESS
	//��p���عؼ����ڹ�ϣ���е�λ�á����򷵻�UNSUCCESS
	//��p���عؼ���Ҫ�����λ��,cΪ�����ͻ�Ĵ���
	int q;
	p=q=Hash(key);//ȡ�ùؼ��ֵĹ�ϣ��ַ
	while(H.elem[p]!=0&&H.elem[p]!=key)
		p=Collision(q,++c);//���ô洢λ�������йؼ��ֲ��ҹؼ���ֵ��key�����
	//����г�ͻ����
	if(H.elem[p]==key)
		return SUCCESS;
	else
	return UNSUCCESS;
}
int InsertHash(HashTable &H,int key)
{//����ϣ��H���޹ؼ���key�����֮
	int c=0,p;
	if(SearchHash(H,key,p,c))
		return ERROR;
	if(c<H.length/2)
	{
		printf("��ϣ��ַΪ%d ",p);
		H.elem[p]=key;
		H.count++;
		printf("��ͻ����Ϊ%d ",c);
		return OK;
	}
	else
	{
		printf("��ͻ�������࣬�붨����ʵĹ�ϣ������\n");
		return ERROR;
	}
}
