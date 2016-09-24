
/**
date: 2012年09月
author: gaooz.com
*/

//-------------------哈希表-----------------------2012年10月4
typedef struct{
	int *elem;//定义关键字为整型
	int count;//当前哈希表中的关键字个数
	int length;//当前哈希表的容量
}HashTable;
HashTable H;
int Hash(int key)//哈希函数
{return key%11;}
int Collision(int p,int c)
{//冲突处理函数
	//以线性探测再散列作为冲突处理方式
	return (p+c)%H.length;//重新找到的哈希地址
}
int SearchHash(HashTable H,int key,int &p,int &c)
{//查找关键字key在哈希表中的位置，如果查找成功则返回SUCCESS
	//用p返回关键字在哈希表中的位置。否则返回UNSUCCESS
	//用p返回关键字要插入的位置,c为处理冲突的次数
	int q;
	p=q=Hash(key);//取得关键字的哈希地址
	while(H.elem[p]!=0&&H.elem[p]!=key)
		p=Collision(q,++c);//若该存储位置上已有关键字并且关键字值与key不相等
	//则进行冲突处理
	if(H.elem[p]==key)
		return SUCCESS;
	else
	return UNSUCCESS;
}
int InsertHash(HashTable &H,int key)
{//若哈希表H中无关键字key则插入之
	int c=0,p;
	if(SearchHash(H,key,p,c))
		return ERROR;
	if(c<H.length/2)
	{
		printf("哈希地址为%d ",p);
		H.elem[p]=key;
		H.count++;
		printf("冲突次数为%d ",c);
		return OK;
	}
	else
	{
		printf("冲突次数过多，请定义合适的哈希函数！\n");
		return ERROR;
	}
}
