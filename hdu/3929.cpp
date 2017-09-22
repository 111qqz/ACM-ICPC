/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 18时55分21秒
File Name :code/hdu/3929.cpp
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
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=20;
int n;
LL x[N],ans;
LL getbit(LL x)
{
    LL res = 0LL;
    while (x)
    {
	x=x&(x-1);
	res++;
    }
    return res;
}

void dfs(int id,LL msk,LL f)
{
    ans +=(1LL<<getbit(msk))*f;
    for ( LL i = id+1 ; i < n ; i++)
	dfs(i,msk&x[i],-2*f);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	ios::sync_with_stdio(false);
	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    for ( int i =  0  ; i < n ; i++) scanf("%lld",&x[i]);

	    ans = 0LL;
	    for ( int i = 0 ; i < n ; i++)
	    {
		dfs(i,x[i],1);
//		cout<<"ans:"<<ans<<endl;
	    }

	    printf("Case #%d: %lld\n",++cas,ans);
	    

	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
