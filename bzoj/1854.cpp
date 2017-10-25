/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 17时00分25秒
File Name :1854.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
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
const int N=1E6+7;
const int M=1E4+7;
int n;
bool ok[M];
int f[M];

void init()
{
    ms(ok,false);
    for ( int i = 1 ; i < M ; i++) f[i] =  i;
}
int root ( int x)
{
    if (x!=f[x]) f[x] = root(f[x]);
    return f[x];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	cin>>n;
	init();
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x,y;
	    int fx,fy;
	    scanf("%d %d",&x,&y);
	    fx = root(x);
	    fy = root(y);
	    if (fx!=fy)
	    {
		if (fx<fy) swap(fx,fy);
		ok[fy] = true;
		f[fy] = fx;
	    }
	    else ok[fy] = true;
	}
	int ans;
	for ( int i = 1 ; i < M ; i++)
	    if (!ok[i]) 
	    {
		ans = i-1;
		break;
	    }

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
