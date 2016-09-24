/**
date: 2012年09月
author: gaooz.com
*/
/**
行逻辑连接顺序表定义
*/
typedef struct 
{
	int i,j;
	int num;
}Triple;
typedef struct 
{
	Triple data[MAXSIZE];
	int rpos[MAXRC];//存放每行中首个非零元的位置
	int mu,nu,tu;
}RLSMatrix;//行逻辑连接顺序表的定义