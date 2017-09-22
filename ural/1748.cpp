/* ***********************************************
Author :111qqz
Created Time :Wed 21 Sep 2016 05:26:55 PM CST
File Name :code/ural/1748.cpp
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
LL n;
LL ans,mx;
LL prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void dfs(int depth,LL val,LL num,int limit)
{
    if (depth>15) return;
    if (num>mx||(num==mx&&val<ans))
    {
	mx = num;
	ans = val;
    }
    for ( int i = 1; i <= limit ; i++) //limit这个剪枝是基于反素数的性质2，也就是后面的质因子的指数一定不超过前面的。
    {
	if (val>n/prime[depth]) break; //最大是n，剪！//之前错写成val>ans/prime[depth]
	dfs(depth+1,val*=prime[depth],num*(i+1),i);
    }
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
	    scanf("%lld",&n);
	    ans = 1LL<<60;
	    mx = 0;
	    dfs(0,1,1,63);
	    printf("%lld %lld\n",ans,mx);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
