/* ***********************************************
Author :111qqz
Created Time :2017年11月01日 星期三 14时17分58秒
File Name :6038.cpp
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
const int N=1E5+7;
const LL mod = 1E9+7;
int a[N],b[N];
bool vis[N];
int n,m;
vector <int>loopa,loopb;
vector <int> findloop( int *a,int n)
{
    vector<int>res;
    ms(vis,false);
    for ( int i = 0 ; i < n ; i++)
    {
	int cur = i ;
	if (vis[cur]) continue;
	int len = 0;
	while (!vis[cur])
	{
	 //   cout<<"cur:"<<cur<<endl;
	    vis[cur] = true;
	    cur = a[cur];
	    len++;
	}
	res.PB(len); //只关心循环节的长度
    }
    return res; 
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
    int cas = 0 ;
    while (~scanf("%d %d",&n,&m))
    {
	for ( int i = 0 ; i < n ; i++) scanf("%d",a+i);
	for ( int i = 0 ; i < m ; i++) scanf("%d",b+i);
	loopa.clear();
	loopb.clear();
	loopa = findloop(a,n);
	loopb = findloop(b,m);

	int lena = loopa.size();
	int lenb = loopb.size();
	//cout<<"lena:"<<lena<<" lenb:"<<lenb<<endl;
	LL ans = 1;
	for ( int i = 0 ; i < lena ; i++)
	{
	    LL tmp = 0 ;
	    for ( int j = 0 ; j < lenb ; j++)
	    {
	//	cout<<"i:"<<i<<" j:"<<j<<" loopb[j]:"<<loopb[j]<<endl;
		if (loopa[i]%loopb[j]==0) tmp = (tmp + loopb[j])%mod;
	    }
	    ans = ans * tmp % mod;
	}
	printf("Case #%d: %lld\n",++cas,ans);
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
