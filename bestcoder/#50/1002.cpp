/*************************************************************************
	> File Name: code/bc/#50/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 20时31分14秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
bool v[10][10];
int n;
int x[30],y[30];

int dis( int x1,int y1,int x2,int y2)
{
    int res ;
    res = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return res;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
	int ans = 0;
	memset(v,false,sizeof(v));
	for ( int i = 0 ;  i < n ; i++ )
	{
	    scanf("%d%d",&x[i],&y[i]);
	}
	for ( int i = 0  ; i < n ; i++ )
	{
	    for (int j = i+1 ; j < n ; j ++)
	    {
		for ( int k =  j + 1 ; k < n ; k ++)
		{
		    for ( int l = k + 1 ; l < n ; l++)
		    {
			int d[10];
			d[0]=dis(x[i],y[i],x[j],y[j]);
			d[1]=dis(x[i],y[i],x[k],y[k]);
			d[2]=dis(x[i],y[i],x[l],y[l]);
			d[3]=dis(x[j],y[j],x[k],y[k]);
			d[4]=dis(x[j],y[j],x[l],y[l]);
			d[5]=dis(x[k],y[k],x[l],y[l]);
			sort(d,d+6);
			if (d[0]==d[1]&&d[2]==d[3]&&d[0]==d[2]&&d[4]==d[5]&&d[4]==2*d[0])
			{
			    ans++;
			}
		    }
		}
	    }
	}
	cout<<ans<<endl;

    }
	return 0;
}
