//三元组顺序表结构的定义,矩阵的转置运算
//T(i,j)=M(j,i)
#include<stdio.h>
#define number 100
//typedef int elemtype;
typedef struct
{
	int i,j;
    int data;
}triple;                      //3元组
typedef struct
{
	int m,n,num;
    triple data[number];
	int rpos[number];
}tsmatrix;                   //矩阵

tsmatrix fasttransposematrix(tsmatrix M,tsmatrix T)  // 矩阵的快速转置            
{
	int col;
	//行和列的转置
	T.m=M.n;
	T.n=M.n;
	T.num=M.num;
	if(T.num)
	{  
		//初始化并创建array数组
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
    //创建并初始化cpot数组
	int cpot[100];
	cpot[1]=1;   //第一列中第一个非0元素的位置默认为1
	for( col=2;col<=M.m;col++)
	{
		cpot[col]=cpot[col-1]+array[col-1];
	}
	for(int p=0;p<M.num;p++)
	{
		//提取当前三元组的列数
		 col=M.data[p].j;

		//根据列数和cpot数组，找到当前元素需要存放的位置
		int q=cpot[col];

		//转置矩阵的三元组默认从数组下标0开始，而得到的q值是单纯的位置，所以要-1
		T.data[q-1].i=M.data[p].j;
		T.data[q-1].j=M.data[p].i;
		T.data[q-1].data=M.data[p].data;

		//存放完成后，cpot数组对应的位置要+1,以便下次该列存储下一个三元组
		cpot[col]++;
	}
	}
	return T;
}
tsmatrix transposematrix(tsmatrix M,tsmatrix T)  
{
	//行和列的转置
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
    
	printf("矩阵的数值：\n");
    for(int i=0;i<M.num;i++)
	{
		printf("(%d,%d,%d)",M.data[i].i,M.data[i].j,M.data[i].data);
	}
	printf("\n");

	tsmatrix T;
	T=transposematrix(M,T);
	printf("使用普通的方法:\n");
	for(i=0;i<T.num;i++)
	{
		printf("(%d,%d,%d)",T.data[i].i,T.data[i].j,T.data[i].data);
	}
	printf("\n");
	tsmatrix T1;
	T1=fasttransposematrix(M,T1);
	printf("快速转置法：\n");
	for(int j=0;j<T1.num;j++)
	{
		printf("(%d,%d,%d)",T1.data[j].i,T1.data[j].j,T1.data[j].data);
	}
    printf("\n");
    return 0;
}









