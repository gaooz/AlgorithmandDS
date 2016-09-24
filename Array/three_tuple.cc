/**
date: 2012年09月
author: gaooz.com
*/

/**
三元组数据结构定义
*/
#define MAX 12500//假设一个稀疏矩阵最多有12500个非零元
typedef struct
{
	int i,j;//i,j用于存储矩阵中元素的行、列下标
	int num;//num为矩阵中非零元的值
}Triple;//定义一个三元组
typedef struct 
{
	Triple data[MAX+1];
	int mu,nu,tu;//mu,nu非别表示一个稀疏矩阵的行数和列数
	//tu表示该稀疏矩阵的非零元个数
}TSMatrix;