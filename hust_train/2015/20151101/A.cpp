/*************************************************************************
	> File Name: code/hust/20151101/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月01日 星期日 12时39分23秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=105;
LL a[N];
bool v[N][N];
LL f[1000055];
int n,k;

LL dis(LL x,LL y)
{
    LL res;
    res = abs(x-y);
  //  cout<<"x:"<<x<<" y:"<<y<<" res:"<<res<<endl;
    return res;
}

LL root( LL x)
{
    if (x==f[x]) return x;
    else return f[x] = root(f[x]);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
   scanf("%d",&T);
   int cas = 0 ;
   while (T--)
    {
	cas++;
	for ( int i = 1 ; i < 1000005 ; i++) f[i] = i;
	scanf("%d %d",&n,&k);
	ms(v,false);
    
	for ( int i =1 ; i <= n ; i++) scanf("%lld",&a[i]);
	
	int cnt = 0 ;
	for ( int i = 1 ; i <= n-1 ; i++)
	    for ( int j = i+1 ;  j <= n ; j++)
	    {
		LL tmp = dis(a[i],a[j]);
//		cout<<i<<" "<<j<<" "<<"tmp:"<<tmp<<endl;
		if (tmp<=k)
		{
		    v[i][j] = true;
		    int x = root(a[i]);
		    int y = root(a[j]);
		//    cout<<"x:"<<x<<" y:"<<y<<endl;
		    if (x!=y)
		    {
	//		cout<<"x:"<<x<<"y:"<<y<<endl;
//			f[x]=y;
			f[y]=x;
			
		    }
		}
	    }

	for ( int i = 1 ; i <= n ; i++)
	{
	    bool flag = false;
	    for ( int j = 1 ; j <= i-1 ; j++)
	    {
		if (root(a[i])==root(a[j]))
		{
		    flag = true;
		    break;

		}
	    }
	    if (!flag)
	    {
		cnt++;
	    }
	}
	printf("Case #%d: %d\n",cas,cnt);
	
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
