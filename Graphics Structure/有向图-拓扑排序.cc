
/**
date: 2012��09��
author: gaooz.com
*/

//--------------------------------��������----------------------------------
/*AOV����������
AOV���������޻�����һ�֣����ж����ʾ�������ʾ�ִ�е�����˳��
�����������AOV�������ж���----2012��9��21*/
void TopologicalSort(ALGraph G)
{//��������
	int indegree[MAX_NUM],count=0,k,i;Acnode *p;node e;
	stack s;
	CreatStack(s);
	for(i=0;i<G.Vexnum;i++)
		indegree[i]=0;//��ʼ�����������Ϣ
	for(i=0;i<G.Vexnum;i++)
	{//�����ڽӱ����ͼ��ÿ����������
		p=G.Vertex[i].firstarc;
		while(p)
		{
			indegree[p->adjvex]++;
			p=p->next;
		}
	}
	for(i=0;i<G.Vexnum;i++)//�ҵ�indegree���������Ϊ0�Ķ���Ȼ����ջ
		if(!indegree[i]){ e.adjvex=i;	push(s,e);}
	while(!EmptyStack(s))
	{ 
		pop(s,e);printf("%d ",G.Vertex[e.adjvex]);
		count++;//������Ķ������
		for(p=G.Vertex[e.adjvex].firstarc;p!=NULL;p=p->next)
		{
			k=p->adjvex;
			indegree[k]--;
			if(!indegree[k]) { e.adjvex=k;	push(s,e);}
			//ɾ���±�Ϊp->adjvex�Ķ�����صıߣ�������Ϊ0�Ķ�����ջ
		}
	}
	if(count<G.Vexnum)
		printf("δ�����ͼ�����ж��㣬ͼ�ж����ڻ���\n");
}