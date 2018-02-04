/*************************************************************************
	> File Name: code/hust/20151115/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月23日 星期一 23时04分42秒
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
#include<cctype>
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=505;
int x[N],y[N];
int n,t;

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   cin>>T;
   while (T--)
    {
	
	scanf("%d",&n);
	scanf("%d",&t);

	for ( int i = 0 ; i < n ; i++) scanf("%d",&x[i]);
	for ( int i = 0 ; i <  n; i++) scanf("%d",&y[i]);

	sort(x,x+n);
	sort(y,y+n,cmp);

	int ans = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    int tmp = max(0,x[i]+y[i]-t);
	    ans += tmp;
	}
	printf("%d\n",ans);
    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
