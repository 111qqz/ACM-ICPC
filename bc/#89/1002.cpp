/* ***********************************************
Author :111qqz
Created Time :Sat 29 Oct 2016 08:30:14 PM CST
File Name :code/bc/#89/1002.cpp
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
int x,k,t;
/*
int solve( int a,int b,int c)
{
    if (a==1) return 0;
    if (a<=c+1) return 1;
    if (a%k==0) return 1 + solve(a/k,x,t);
    else{
	int r = a % b;
	int cnt = 
    }

}
*/
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d%d",&x,&k,&t);
	    //int ans = solve(x,k,t);
	    int ans = 0 ;
	    while (x>1)
	    {
	//	cout<<"x:"<<x<<" ans:"<<ans<<endl;
		if (x<=t+1)
		{
		    x = 1;
		    ans++;
		}
		if (x==1) break;
		if (k==1)
		{
		    x-=t;
		    ans++;
		}
		else
		{
		    if (x%k==0)
		    {
			x/=k;
			ans++;
		    }
		    else
		    {
			int r = x % k;
			int cnt = (r+t-1)/t;
			ans +=cnt;
			x = x-r;
		    }
		}
	    }
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
