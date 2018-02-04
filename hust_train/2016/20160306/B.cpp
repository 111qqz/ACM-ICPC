/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 17时18分41秒
File Name :code/hust/20160306/B.cpp
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

#define maxn 50005
#define LL long long

using namespace std;
const int N=5E4+88;
int n;
int t[N];
bool vis[N];
struct node
{
    int a,b;
    int c;

    bool operator <(node p)const
    {
        if (b==p.b) return a>p.a;
            return b<p.b;
    }
}q[N];

int lowbit(int x)
{
    return x&(-x);
}

void update ( int x,int delta)
{
    for ( int i = x; i < N ; i+=lowbit(i))
    {
        t[i] +=delta;
    }
}

int Sum( int x)
{
    int res = 0 ;
    for ( int i = x ; i >= 1 ; i-=lowbit(i))
    {
        res +=t[i];
    }
    return res;
}

int main()
{
   // ios::sync_with_stdio(false);
    cin>>n;
    puts("aaa");
    memset(t,0,sizeof(t));
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; i++) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q+1,q+n+1);

  //  for ( int i = 1 ; i <= n ; i++) cout<<q[i].a<<" "<<q[i].b<<" "<<q[i].c<<endl;

    cout<<"n:"<<n<<endl;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int num = q[i].c;
        num -=max(0,Sum(q[i].b+2)-Sum(q[i].a+1));
        cout<<"num:"<<num<<endl;
        for ( int j = q[i].b,cnt=1; cnt<=num; j--)
        {
	    if (!vis[j])
	    {
		update(j+2,1);
		cnt++;
		vis[j] = true;
	    }
	
	
          //  cout<<j<<" ";
            ans++;

        }
    //    cout<<endl;
    }

    cout<<ans<<endl;
    return 0;


}
