/* ***********************************************
Author :111qqz
Created Time :2016年05月18日 星期三 13时44分47秒
File Name :code/poj/3368.cpp
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
int n;
pi a[N];
int q;
int dp[N][20];

void init_rmq()
{
    for ( int i =  1 ;i  <= n ; i++) dp[i][0] = a[i].sec;

    for ( int j = 1  ; (1<<j)<= n ; j++)
	for ( int i = 1 ; i + (1<<j)-1 <= n ; i++)
	    dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_max(int l,int r)
{
    if (l>r) return 0; //因为l+1可能大于b
    int k = 0  ;
    while (1<<(k+1)<=(r-l+1)) k++;
    return max(dp[l][k],dp[r-(1<<k)+1][k]);

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    ms(dp,0);
	    ms(a,0);

	    if (n==0) break;
	    scanf("%d",&q);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		scanf("%d",&x);
		a[i]=make_pair(x,1);
	    }
	    a[n+1].fst = inf;

	    for ( int i = 2 ; i <= n ; i++)
	    {
		if (a[i].fst==a[i-1].fst)
		{
		    a[i].sec = a[i-1].sec+1;
		}
	    }

//	    for ( int i = 1 ;i  <= n ; i++) cout<<a[i].fst<<" "<<a[i].sec<<endl;

	    init_rmq();
	    while (q--)
	    {
		int l,r;
		scanf("%d %d",&l,&r);
		int tmp = l;
		while (tmp<r&&a[tmp].fst==a[tmp+1].fst) tmp++; //mdzz，最坏复杂度1E10啊。。。题解都是面向数据编程吗
		int ans = rmq_max(tmp+1,r);
//		cout<<"tmp-l:"<<tmp-l+1<<endl;
		ans = max(ans,tmp+1-l);
		printf("%d\n",ans);
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
