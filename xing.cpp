//��Ԫ��˳���ṹ�Ķ���,�����ת������
//T(i,j)=M(j,i)
#include<stdio.h>
#define number 100
//typedef int elemtype;
typedef struct
{
	int i,j;
    int data;
}triple;                      //3Ԫ��
typedef struct
{
	int m,n,num;
    triple data[number];
	int rpos[number];
}tsmatrix;                   //����

tsmatrix fasttransposematrix(tsmatrix M,tsmatrix T)  // ����Ŀ���ת��            
{
	int col;
	//�к��е�ת��
	T.m=M.n;
	T.n=M.n;
	T.num=M.num;
	if(T.num)
	{  
		//��ʼ��������array����
		int array[number];
		for(col=1;col<=M.m;col++)
		{
			array[col]=0;
		}
		for(int t=0;t<M.num;t++)
		{
			int j=M.data[t].j;
			array[j]++;
		}
    //��������ʼ��cpot����
	int cpot[100];
	cpot[1]=1;   //��һ���е�һ����0Ԫ�ص�λ��Ĭ��Ϊ1
	for( col=2;col<=M.m;col++)
	{
		cpot[col]=cpot[col-1]+array[col-1];
	}
	for(int p=0;p<M.num;p++)
	{
		//��ȡ��ǰ��Ԫ�������
		 col=M.data[p].j;

		//����������cpot���飬�ҵ���ǰԪ����Ҫ��ŵ�λ��
		int q=cpot[col];

		//ת�þ������Ԫ��Ĭ�ϴ������±�0��ʼ�����õ���qֵ�ǵ�����λ�ã�����Ҫ-1
		T.data[q-1].i=M.data[p].j;
		T.data[q-1].j=M.data[p].i;
		T.data[q-1].data=M.data[p].data;

		//�����ɺ�cpot�����Ӧ��λ��Ҫ+1,�Ա��´θ��д洢��һ����Ԫ��
		cpot[col]++;
	}
	}
	return T;
}
tsmatrix transposematrix(tsmatrix M,tsmatrix T)  
{
	//�к��е�ת��
	T.m=M.n;
	T.n=M.n;
	T.num=M.num;
	if(T.num)
	{
		int q=0;
		for(int col=1;col<=M.m;col++)
		{
			for(int p=0;p<M.num;p++)
			{
				if(M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].data=M.data[p].data;
					q++;
				}
			}
		}
	}
	return T;
}

int main()
{
	tsmatrix M;
	M.m=2;
	M.n=3;
	M.num=4;

	M.data[0].i=1;
	M.data[0].j=2;
	M.data[0].data=1;

	M.data[1].i=2;
	M.data[1].j=2;
	M.data[1].data=3;

	M.data[2].i=3;
	M.data[2].j=1;
	M.data[2].data=6;

	M.data[3].i=3;
	M.data[3].j=2;
	M.data[3].data=5;
    
	printf("�������ֵ��\n");
    for(int i=0;i<M.num;i++)
	{
		printf("(%d,%d,%d)",M.data[i].i,M.data[i].j,M.data[i].data);
	}
	printf("\n");

	tsmatrix T;
	T=transposematrix(M,T);
	printf("ʹ����ͨ�ķ���:\n");
	for(i=0;i<T.num;i++)
	{
		printf("(%d,%d,%d)",T.data[i].i,T.data[i].j,T.data[i].data);
	}
	printf("\n");
	tsmatrix T1;
	T1=fasttransposematrix(M,T1);
	printf("����ת�÷���\n");
	for(int j=0;j<T1.num;j++)
	{
		printf("(%d,%d,%d)",T1.data[j].i,T1.data[j].j,T1.data[j].data);
	}
    printf("\n");
    return 0;
}









