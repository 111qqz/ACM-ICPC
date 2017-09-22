/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 13时52分32秒
File Name :code/hdu/5416.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,LL >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
vector<pi>edge[N];
int n;
LL sum[N];
LL  cnt[N*10];
int q;
void dfs( int x,LL val)
{
    sum[x] = val;

    for ( int i = 0 ; i< edge[x].size() ; i++)
    {
	pi v = edge[x][i];
	if (sum[v.fst]!=-1) continue ; //表示已经访问过了。
	dfs(v.fst,val^v.sec);
    }
}

LL cal( LL x)
{
    LL res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
	res +=cnt[sum[i]^x];
//	cout<<"i:"<<i<<" res:"<<res<<endl;
    }
    if (x==0) res +=n; //f(u,u)

    res /=2; //因为要求无序。。。 （u,v）和(v,u)算一种。
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		edge[a].push_back(make_pair(b,c));
		edge[b].push_back(make_pair(a,c));
	    }
	    ms(sum,-1);
	    dfs(1,0);
	    ms(cnt,0);
//	    for ( int i = 1 ;  i <= n ; i++) cout<<"sum[i]:"<<sum[i]<<endl;
	    for ( int i = 1 ; i <= n ; i++)
		if (sum[i]>=0)
		cnt[sum[i]]++;
	    
	    
	    scanf("%d",&q);
	    while (q--)
	    {
		LL s;
		scanf("%lld",&s);
		LL ans = cal(s);
		printf("%lld\n",ans);
	    }
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
