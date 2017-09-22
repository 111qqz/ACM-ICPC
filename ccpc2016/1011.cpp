/* ***********************************************
Author :111qqz
Created Time :2016年08月14日 星期日 12时13分22秒
File Name :code/ccpc2016/1011.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
char s[N];
int a[N];
int dp[N];
int g[N];
set<int>se;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{
	    scanf("%s",s);
	    ms(a,0);
	    ms(dp,0);
	    ms(g,0x3f);
	    int len = strlen(s);
	    for ( int i = 0 ; i < len ; i++)
		a[i+1] = s[i]-'a'+1;

	    int res = 0 ;
	    se.clear();
	    for ( int i = 1 ; i <= len ;i++) se.insert(a[i]);
	    res = se.size();
	    
	/*    for ( int i = 1 ; i <= len ; i++)
	    {
	//	cout<<"i:"<<a[i]<<endl;
		int k = lower_bound(g+1,g+len+1,a[i])-g;
		dp[i] = k;
		g[k] = a[i];
		res = max(res,dp[i]);
	    } */
	    printf("Case #%d: %d\n",++cas,res);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
