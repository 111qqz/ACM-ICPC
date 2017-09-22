/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 12时48分05秒
File Name :code/hdu/5477.cpp
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
const int N=105;
int n,len,a,b;
struct node
{
    int l,r;
}q[N];
bool swamp[1000005];
bool cmp(node a,node b)
{
    if (a.l<b.l) return true;
    return false;
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
	    ms(swamp,false);
	    scanf("%d%d%d%d",&n,&a,&b,&len);
	    for ( int i = 0 ; i < n ; i++) scanf("%d%d",&q[i].l,&q[i].r);
	    sort(q,q+n,cmp);
	    for ( int j = 0 ; j < n ; j++)
	    {
		for ( int i = q[j].l ; i <= q[j].r-1  ; i++)
		{
		    swamp[i] = true;
		}

	    }
	    int ans = 0 ;
	    int cur = b;
	    for (  int i = 0 ; i <= len-1 ; i++)
	    {
	//	if (swamp[i]) cout<<"a"<<endl;
	//	else cout<<"b";
		if (swamp[i]) cur -=a;
		    else cur +=b;
	//	cout<<"i:"<<i<<" cur:"<<cur<<endl;
		ans = min(ans,cur);
	    }

	    int cas = 0 ;
	    cas++;
	    printf("Case #%d: %d\n",cas,-ans);
	    
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
