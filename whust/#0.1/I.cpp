/*************************************************************************
	> File Name: code/whust/#0.1/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月08日 星期六 13时36分24秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
string st;
int ans;
int len;
bool vis[100005];
char ch[3]={'L','O','L'};

void dfs (int x,int num)
{
    cout<<"x:"<<x<<" num:"<<num<<endl;
    if (num==3)
    {
	ans++;
	cout<<"ans+++++"<<"  x:"<<x<<"  num:"<<num<<endl;
	dfs(x+1,num-1);
    }
    for ( int i = x  ; i < len ; i ++)
    {
	if (st[i]==ch[num]&&!vis[i])
	{
	    vis[i]=true;
	    dfs(x+1,num+1);
	    num--;
	}
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	memset(vis,false,sizeof(vis));
	cin>>st;
	len = st.length();
	ans  =0;
	for ( int i = 0 ;  i < len -2 ; i ++)
	{
	    dfs(i,0);
	}
	cout<<ans<<endl;
    }
	return 0;
}
