/*************************************************************************
	> File Name: code/class/7.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 19时31分50秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int n;
int a[105][105];


int fix_x( int x,int k,int n)  //维护边界，k为幻方的种类。
{
    if (k%2==1)
    {
	if (x==0)
	    return n;
	else return x;
    }
    else
    {
	if (x==n)
	    return n+n;
	else return x;
    }
}
int fix_y ( int y,int k,int n) //维护边界，k为幻方的种类。
{
    if (k<3)
    {
	if (y==n+1)
	    return 1;
	else return y;
    }
    else
    {
	if (y==2*n+1)
	    return n+1;
	else return y;
    }
 //   if (y==n+1)
 //   return 1;
  //  else return y;
}
void print()  //输出答案
{
    for ( int i = 1 ; i <= n ; i++)
    {
	for ( int j = 1 ; j <= n ; j++)
	    printf("%d  ",a[i][j]);

	printf("\n");
    }
    
}

void OddMagic(int n,int x,int y,int k) 
{
    
    int cur ; //表示当前要填充的数字
    if (k==1) cur = 1;
    if (k==4) cur = n*n+1;
    if (k==3) cur = n*n*2+1;
    if (k==2) cur = n*n*3+1;
    int cnt = 0;//表示当前填充了的个数
    while (cnt<n*n)
    {
	a[x][y]=cur;
	int prex = x;
	int prey = y;   //保留之前的x,y，因为右上角的被填充时，要填充当前下面的。
	cur++;
	cnt++;
	x--;
	y++; //向右上方移动 
	x = fix_x(x,k,n);
	y = fix_y(y,k,n);//维护边界
	if (a[x][y])  //初始a数组为0，当a不为0时，表示被填充过了。
	{
	    x = prex+1;
	    y = prey;
	}

    }

}
int main()
{
    memset(a,sizeof(a),0);
    scanf("%d",&n);
    if (n%2==1)		//奇数阶
    {
	int x = 1;
	int y = n/2+1;
	OddMagic(n,x,y,1);
    }
    else
    {
	if (n%4==0)  //双偶阶
	{
	    for ( int i = 1,num=1 ; i <= n ; i++)
		for ( int j  = 1 ; j <= n  ; j++,num++)
		    a[i][j]=num;
	    
	    
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= n ; j++)
		{
		   if (i==j||i+j>=n+1) continue;
		    int tmp;
		    tmp = a[i][j];
		    a[i][j] = a[n+1-i][n+1-j];
		    a[n+1-i][n+1-j] = tmp;
		}
	    }
	}
	else   //单偶阶
	{
	    int x = 1;
	    int y = n/4+1;
	    int hn = n/2;  //
	    //均分成四部分，分别构造4个奇数阶幻方
	    OddMagic(hn,x,y,1);            //分别为第1，第2，第3,第4种幻方。
	    OddMagic(hn,x+hn,y,2);
	    OddMagic(hn,x,y+hn,3);
	    OddMagic(hn,x+hn,y+hn,4);

	    int  m = n/4;
	    for ( int i = 1 ; i <= hn ;i++)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		    int tmp;
		    if (i==m+1&&j==m) //中心
		    {
			tmp = a[m+1][m+1];
			a[m+1][m+1] = a[m+1+hn][m+1];
			a[m+1+hn][m+1] = tmp;
			continue;

		    }
		    tmp = a[i][j];
		    a[i][j] = a[i+hn][j];
		    a[i+hn][j] = tmp;
		  //  swap(a[i][j],a[i+n][j]);
		}
	    }

	    for ( int i = 1 ; i <= hn ; i++)
	    {
		for ( int j = n ; j>=n-m+2 ; j--)
		{
		    int tmp;
		    tmp = a[i][j];
		    a[i][j] = a[i+hn][j];
		    a[i+hn][j] = tmp;
		}
	    }
	}
    }
    print();
    return 0;
}
