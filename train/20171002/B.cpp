/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 16时45分30秒
File Name :B.cpp
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
const string error = "Impossible";
int n,x,y;
int mx;
int get_mx( int n)
{
    if (n==2) return 2;
    if (n==3) return 5;
    return n+4;
}
string solve()
{
    mx = get_mx(n);
    string ret="";
    if ((x+y)%2!=n%2) return error;
    if (x+y>mx) return error;
    //cout<<"mx:"<<mx<<endl;
    if (n%2==0)
    {
	if (x==n&&y==0)
	{
	    for ( int i = 1 ; i <= n ; i++) ret = ret + 'B';
	    return ret;
	}
	if (x==0&&y==n)
	{
	    for ( int i = 1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}

	if (x==n&&y<n)
	{
	    int tmp = y/2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'G';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'B';
	    return ret;
	}
	if (y==n&&x<n)
	{
	    int tmp = x/2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'B';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}
	if (x>=mx/2 && x <= n && y==mx-x)
	{
	    int tmp = y-2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'G';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'B';
	    return ret;
	}
	if (y>=mx/2 && y<=n && x==mx-y)
	{
	    int tmp = x-2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'B';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}
	int sum = n + 2;
	if (x+y==sum && x!=y)
	{
	    if (x>y)
	    {
		int tmp = y-1;
		int cnt = 0;
		for ( int i = 1 ; i <= n ; i++) 
		    if (i%2==1&&cnt<tmp) 
		    {
			cnt++;
			ret = ret + 'G';
		    }
		    else ret = ret + 'B';
	    }else
	    {
		int tmp = x-1;
		int cnt = 0 ;
		for ( int i = 1 ; i <= n ; i++)
		    if (i%2==1&&cnt<tmp)
		    {
			cnt++;
			ret = ret + 'B';
		    }
		else ret = ret + 'G';
	    }
	    return ret;
	}
		

	if (x==mx/2 && y==mx/2)
	{
	    for ( int i = 1 ; i <= n/2 ; i++) ret = ret + 'B';
	    for ( int i = n/2+1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}
	if (x==n/2 && y==n/2)
	{
	    for ( int i = 1 ; i <= n ; i++)
		if (i%2) ret = ret +'B';
		else ret = ret + 'G';
	    return ret;
	}
    }
    else
    {
	int sum = n+2;
	if (x+y==sum)
	{
	    if (x>y)
	    {
		int tmp = y-1;
		int cnt = 0;
		for ( int i = 1 ; i <= n ; i++)
		{   if (i%2==1&&cnt<tmp)
		    {
			cnt++;
			ret = ret +'G';
		    }else ret = ret + 'B';
		}
	    }
	    else
	    {
		int tmp = x-1;
		int cnt = 0 ;
		for ( int i = 1 ; i <= n ; i++)
		{
		    if (i%2==1&&cnt<tmp)
		    {
			cnt++;
			ret = ret + 'B';
		    }else ret = ret + 'G';
		}
	    }
	    return ret;
	}

	if (x==n&&y==0)
	{
	    for ( int i = 1 ; i <= n ; i++) ret = ret +'B';
	    return ret;
	}
	if (x==0&&y==n)
	{
	    for ( int i = 1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}
	if (x==n&&y<n)
	{
	    int tmp = y/2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'G';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'B';
	    return ret;
	}
	if (y==n&&x<n)
	{
	    int tmp = x/2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'B';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret +'G';
	    return ret;
	}
	if (x>=mx/2 +1 && x<=n && x+y==mx)
	{
	    int tmp = y-2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'G';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'B';
	    return ret;
	}
	if (y>=mx/2+1 && y<=n && x+y==mx)
	{
	    int tmp = x-2;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'B';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret + 'G';
	    return ret;
	}

	if (x==mx/2+1 && y==mx/2)
	{
	    int tmp = n/2+1;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'B';
	    for ( int i = tmp+1 ; i <= n ; i++) ret = ret +'G';
	    return ret;
	}
	if (x==mx/2&&y==mx/2+1)
	{
	    int tmp = n/2+1;
	    for ( int i = 1 ; i <= tmp ; i++) ret = ret + 'G';
	    for ( int i = tmp + 1 ; i <= n ; i++) ret = ret +'B';
	    return ret;
	}
	if (x==n/2+2&&y==n/2+1)
	{
	    int tmp = n/2;
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (i%2==1&&cnt<tmp)
		{
		    ret = ret +'G';
		    cnt++;
		}else ret = ret + 'B';
	    }
	    return ret;
	}
	if (x==n/2+1&&y==n/2+2)
	{
	    int tmp = n/2;
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	      if (i%2==1&&cnt<tmp)
	      {
		  ret = ret + 'B';
		  cnt++;
	      }else ret = ret + 'G';
	    return ret;
	}
    }


    return error;
}
	    
	
bool check(string st)
{
    int len = st.length();
    int cntx=0,cnty=0;
    for ( int i = 0 ; i < len ; i++)
    {  int lst = ((i-1)%len + len)%len;
       int nxt = (i+1)%len;
       if (st[lst]=='B'||st[nxt]=='B') cntx++;
       if (st[lst]=='G'||st[nxt]=='G') cnty++;
    }
    return x ==cntx && y==cnty;
}
int main()
{
	freopen("boysgirls.in","r",stdin);
	freopen("boysgirls.out","w",stdout);
       while (cin>>n>>x>>y)
       {
	string ans = solve();
	//if (ans!=error && !check(ans))
	cout<<ans<<endl;
	}

    return 0;
}
