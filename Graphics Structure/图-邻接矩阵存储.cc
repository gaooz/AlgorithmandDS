/**
date: 2012��09��
author: gaooz.com
*/

//----�ڽӾ���洢��ʾ��ʵ���������Ĺ��켰������ȵļ���----2012��09��11
/*�ڽӾ���洢��ʾ��������洢��ʾ��������������ͼ������������Ҳ����������ͼ����������
�ŵ㣺���ڴ洢�����ڼ���ͼ�ṹ�и�����Ķȣ�
ȱ�㣺��ͼ�ж�����Ŀ�϶��ж���֮�����ϵ����ʱ�������ִ洢�ṹ�Ƚ��˷Ѵ洢�ռ䡣*/
#include<stdio.h>
#define MAX_NUM 20//��󶥵���ĿΪ20
typedef enum {DG,DN,UDG,UDN} GraphKind;//ͼ���ͱ�־������ͼ��������������ͼ����������
typedef enum {Border,UnBorder} Graph_Border;
typedef struct {
	int data;
}VertexNode;//ͼ�ж���ṹ����
typedef struct {
	union {
		Graph_Border adj;//������ͼ����ʾ�Ƿ�����
		int Value;//����Ȩֵ(���ﶨ��Ȩֵ����Ϊint��)
	}Graph_Net;
	char *info;//�洢�߻��߻��������Ϣ
}ArcCell,AdjMatrix[MAX_NUM][MAX_NUM];//�߻򻡽ṹ�Ķ���
typedef struct {
	VertexNode Vertex[MAX_NUM];//�洢��������
	AdjMatrix arcs;//�洢����֮��Ĺ�ϵ�����߻�(�ڽӾ���)
	int Vexnum,Arcnum;//��ǰ;�ж�����Ŀ���߻���Ŀ
	GraphKind kind;//ͼ������
}MGraph;//ͼ�ṹ�Ķ���
void CreatGraph_DN(MGraph &G)
{//�����������ṹ
	int i,j,isign,jsign;
	VertexNode v1,v2;ArcCell arc;
	printf("������������\n");
	G.kind=DN;//˵��ͼ�Ľṹ
	printf("���������ж�����Ŀ�ͻ�����Ŀ��");
	scanf("%d%d",&G.Vexnum,&G.Arcnum);
	printf("���ʼ����Щ���㣺");
	for(i=0;i<G.Vexnum;i++)
		scanf("%d",&G.Vertex[i].data);
	for(i=0;i<G.Vexnum;i++)
		for(j=0;j<G.Vexnum;j++)
			G.arcs[i][j].Graph_Net.Value=-1;//�ȳ�ʼ���ڽӾ���
	printf("���ʼ������֮�����ϵ����������Ϣ����\n");
	printf("��ʽ������1 ����2 Ȩֵ����ʾ����1�ڽӵ�����2��\n");
	for(i=0;i<G.Arcnum;i++)
	{
		scanf("%d%d%d",&v1.data,&v2.data,&arc.Graph_Net.Value);
		isign=-1;jsign=-1;
		for(j=0;j<G.Vexnum;j++)
		{
			if(G.Vertex[j].data==v1.data)
				isign=j;
			if(G.Vertex[j].data==v2.data)
				jsign=j;//�ҵ�������֮��Ĺ�ϵ�������ڵ��ڽӾ����е�λ��
		}
		if(isign==-1||jsign==-1)
			printf("������������\n");
		else
		{
			G.arcs[isign][jsign].Graph_Net.Value=arc.Graph_Net.Value;
			//��ʼ���ڽӾ����и�λ�û�Ȩֵ����Ϣ
		}
	}

}
int *CountVexNum_DN(MGraph G)
{//������������ȵļ���
	int D[MAX_NUM],ID[MAX_NUM],OD[MAX_NUM];//�ֱ��Ŷ���Ķȡ���ȡ�����
	int i,j,k;
	for(i=0;i<G.Vexnum;i++)
	{//��ʼ��
		D[i]=0;
		ID[i]=0;
		OD[i]=0;
	}
	for(i=0;i<G.Vexnum;i++)
	{
		for(j=0;j<G.Vexnum;j++)
			if(G.arcs[i][j].Graph_Net.Value!=-1)
				OD[i]++;//���㶥�����
		for(k=0;k<G.Vexnum;k++)
			if(G.arcs[k][i].Graph_Net.Value!=-1)
				ID[i]++;//���㶥�����
		D[i]=ID[i]+OD[i];//����ͼ�����������ж���Ķ�Ϊ��ȼӳ���
	}
	return D;
}