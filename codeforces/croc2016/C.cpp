/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 00时21分28秒
File Name :code/cf/croc2016/C.cpp
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
const int N=1E5+7;
int ban[N];
int k,n;
int sum[N];
int pos0[N];
string st;

int dis(int x,int l,int r)
{
    return max(pos0[x]-pos0[l],pos0[r]-pos0[x]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>k;
	cin>>st;
	ms(ban,0);
	ms(pos0,0);
	k++;
	int len = st.length();
	int cnt0 =  0;
	for ( int i = 0 ;  i < len ; i++)
	{
	    if (st[i]=='0')
	    {
		ban[i+1] = 0;
		cnt0++;
		pos0[cnt0] = i ;
	    }
	    else
	    {
		ban[i+1] = 1;
	    }
	}

	sum[0] = 0 ;
	
	for ( int i = 1 ; i <= n ; i++)
	{
	    sum[i] = sum[i-1] + ban[i];
	}
	int ans = inf;
	int l =  1 ;  int r = k;
	int mid =  0;
	for ( int i = 1 ; i <= r ; i++)
	{
	    if (dis(i,l,r)<dis(mid,l,r))
	    {
		mid =  i;
	    }
	}

	ans = dis(mid,l,r);
	for ( ; r <= cnt0 ; r++,l++)
	{
	    while (dis(mid+1,l,r)<dis(mid,l,r)) mid++;
	    ans = min(ans,dis(mid,l,r));
	}
	cout<<ans<<endl;
	
	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
