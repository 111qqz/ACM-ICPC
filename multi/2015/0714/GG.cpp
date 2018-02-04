/*************************************************************************
	> File Name: code/2015summer/0714/GG.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月14日 星期二 16时51分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 27
int map[max][max],x[max],y[max];
int p,q,t=0,sign;
int step[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
void cxbdfs(int a,int b)// 深搜
{
	int x1,y1,i;
	if(sign)// 标记退出 
		return;
	t++;
	x[t]=a;
	y[t]=b;
	if(t==p*q) // 当全部走遍，标记 
	{
		sign=1;
		return;
	}
	map[a][b]=1;
	for(i=0;i<8;i++)
	{
		x1=a+step[i][0];
		y1=b+step[i][1];
		if(x1>0 && y1>0 && x1<=q && y1<=p && map[x1][y1]==0)// 符合条件进入搜索 
		{
			cxbdfs(x1,y1);
			t--;
		}
	}
	map[a][b]=0;//不符合条件回溯时地图从新标记 
}
int main()
{
	int i,n,j=0;
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	while(n--)
	{
		j++;		
		sign=0;
		scanf("%d%d",&p,&q);
		cxbdfs(1,1);
		printf("Scenario #%d:\n",j);
		if(sign)
		{
			for(i=1;i<=p*q;i++)
				printf("%c%d",x[i]+'A'-1,y[i]);
			printf("\n");
		}
		else
			printf("impossible\n");
		printf("%s",n==0?"":"\n");
	}
}

