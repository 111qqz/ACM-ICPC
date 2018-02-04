/* ***********************************************
Author :111qqz
Created Time :2016年03月05日 星期六 18时56分49秒
File Name :code/bc/#74/1001.cpp
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
const LL mod = 1E9+7;

struct node
{
    int a,b;
    int d;
}p[5];

int n,m;
int solve (int s,int t,int x,int y,int z)
{
    int res = t-s;
    int cur  = 0;
    int f = -1;
    if (x==1)
    {
	f = 1;
	if (s<=p[f].a&&t>=p[f].b)
	{
	    cout<<"sadhd"<<endl;
	    cur +=p[f].b-s;
	    s = p[f].b;
	}
	
	if (s>=p[f].a&&s<=p[f].b&&t>=p[f].a&&t<=p[f].b)
	{
	    cur += (s-p[f].a+1);
	    s = p[f].b;
	}

	if (s<=p[f].a&&t>=p[f].a&&t<=p[f].b)
	{
	    cur += (p[f].a-s+1);
	    s = p[f].b;
	}

	if (s>=p[f].a&&s<=p[f].b&&t>=p[f].b)
	{
	    cur +=(s-p[f].a+1);
	    s = p[f].b;
	}
    }
    if (y==1)
    {

	f = 2;
	if (s<=p[f].a&&t>=p[f].b)
	{
	    cur +=p[f].b-s;
	    s = p[f].b;
	}
	
	if (s>=p[f].a&&s<=p[f].b&&t>=p[f].a&&t<=p[f].b)
	{
	    cur += (s-p[f].a+1);
	    s = p[f].b;
	}

	if (s<=p[f].a&&t>=p[f].a&&t<=p[f].b)
	{
	    cur += (p[f].a-s+1);
	    s = p[f].b;
	}

	if (s>=p[f].a&&s<=p[f].b&&t>=p[f].b)
    	{
	    cur +=(s-p[f].a+1);
	    s = p[f].b;
	
	 }
    }


	if (z==1)
	{
	    f = 3;
	    if (s<=p[f].a&&t>=p[f].b)
	    {
	    cur +=p[f].b-s;
	    s = p[f].b;
	    }

	    if (s>=p[f].a&&s<=p[f].b&&t>=p[f].a&&t<=p[f].b)
	    {
	    cur += (s-p[f].a+1);
	    s = p[f].b;
	    }

	    if (s<=p[f].a&&t>=p[f].a&&t<=p[f].b)
	    {
		cur += (p[f].a-s+1);
		s = p[f].b;
	    }

	    if (s>=p[f].a&&s<=p[f].b&&t>=p[f].b)
	    {
		cur +=(s-p[f].a+1);
		s = p[f].b;
	
	    }
	}
	cur += abs(s-t);
	cout<<"cur:"<<cur<<endl;

    res = min(res,cur);
    return res;
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
	    scanf("%d %d",&n,&m);
	    for ( int i = 1 ; i <= 3 ; i++)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		if (x>y) swap(x,y);
		p[i].a = x;
		p[i].b = y;
		p[i].d = y-x; //小心出现自环。。。如果出现就不考虑。。。。

	    }
	    LL cas = 0LL ;
	    LL ANS = 0LL;
	    while (m--)
	    {
		int s,t;
		scanf("%d %d",&s,&t);
		if (s>t) swap(s,t);
		int ans = inf;
		ans = min(ans,solve(s,t,0,0,0));
		cout<<"****************"<<endl;
		ans = min(ans,solve(s,t,1,0,0));
	    
		cout<<"*************ans1::"<<ans<<endl;
		ans = min(ans,solve(s,t,0,1,0));
		ans = min(ans,solve(s,t,0,0,1));
		ans = min(ans,solve(s,t,1,1,0));
		ans = min(ans,solve(s,t,1,0,1));
		ans = min(ans,solve(s,t,0,1,1));
		ans = min(ans,solve(s,t,1,1,1));
		cas++;
		cout<<"ans:"<<ans<<endl;	
		ANS =(ANS + 1LL*ans*cas)%mod;
		
	    }
	    printf("%lld\n",ANS);

	       
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
