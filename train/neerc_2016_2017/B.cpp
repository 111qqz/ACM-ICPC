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
char more,less;
int get_mx( int n)
{
    if (n==2) return 2;
    if (n==3) return 5;
    if (n==4) return 8;
    int a = (n+2)%3;
    int b = (n+2)/3;
    int ret = 5*(b-1)+3+a;
    return ret;
}
string tail( int x)
{
    string add = "";
    if (x==1) add = less;
    if (x==2) add = less+more;
    return add;
}
string work( int n,int y)
{
    string add ="";
    if (n%3==0)
    {
	if (y%3==0) add+='GGB'; i                            
string solve()
{
    mx = get_mx(n);
    string ret="";
    string block = more + more + less; 
    string block2 = more + less + less;
    if ((x+y)%2!=n%2) return error;
    if (x+y>mx) return error;
    if (y==1) return error;
    if (x==n&y==0) {for ( int i = 1 ; i <= n ; i++) ret = ret + more; return ret;}
    if (x==(n+1)/2&&y==x+n%2) { for ( int i = 1 ; i<=n ;i++) if (i<=(n+1)/2) ret +=more;else ret+=less;return ret;}
    if (x==n&&y==mx-x){for (int i=1;i<=n/3;i++)ret+=block;ret+=tail(n%3);return ret;}
    int bk_cnt=(y+2)/3;
    int tot=0;
    int num;
    for ( int i=1;i<=bk_cnt;i++)ret+=block;
    ret += work(n,y)


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
//	freopen("boysgirls.in","r",stdin);
//	freopen("boysgirls.out","w",stdout);
       while (cin>>n>>x>>y)
       {
	   more = 'B';
	   less = 'G';
	   if (x<y) swap(more,less),swap(x,y);
	string ans = solve();
	//if (ans!=error && !check(ans))
	cout<<ans<<endl;
	}

    return 0;
}
