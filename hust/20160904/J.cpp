/* ***********************************************
Author :111qqz
Created Time :2016年09月04日 星期日 12时50分22秒
File Name :code/hust/20160904/J.cpp
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
const int N=1005;
int pri[N];
int n;
int cnt;
bool prime( int n)
{
    if (n<=3) return true;
    for ( int i = 2 ; i*i <= n ; i++)
	if (n%i==0) return false;
    return true;
}

bool solve(int  n)
{
    for ( int i = 1 ; i <= cnt ; i++)
	for ( int j = 1 ; j <= cnt ; j++)
	{
	    int tmp = n-pri[i]-pri[j];
	    if (tmp>=2)
	    {
		if (prime(tmp)) 
		{
		    vector<int>ans;
		    ans.push_back(tmp);
		    ans.push_back(pri[i]);
		    ans.push_back(pri[j]);
		    sort(ans.begin(),ans.end());
		    for ( int i = 0 ; i < ans.size() ; i++)
			printf("%d ",ans[i]);
		    puts("");
		    return true;
		}
	    }
	    else break;
	}
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	 cnt = 0 ;
	for ( int i = 2 ; i <= 1000 ; i++)
	    if (prime(i))
	    {
		pri[++cnt] = i ;
	    }
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    if(!solve(n))
		puts("0");
		    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
