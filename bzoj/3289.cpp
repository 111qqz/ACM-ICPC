/* ***********************************************
Author :111qqz
Created Time :2016年02月17日 星期三 20时18分51秒
File Name :code/bzoj/3289.cpp
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
const int N=5E4+11;
int n,m;
int a[N],b[N];
int pos[N];
LL c[N];
LL ans[N];
LL sum;
struct node
{
    int l,r;
    int id;

    bool operator < (node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l]<pos[b.l];
    }
}q[N];

int lowbit( int x)
{
    return x&(-x);
}

void update ( int x,int delta)
{
    for ( int i = x ;i <=n ; i+=lowbit(i))
    {
	c[i] +=delta;
    }
}

LL Sum( int x)
{
    LL res = 0LL ;
    for ( int i = x; i >=1 ; i-=lowbit(i))
    {
	res += 1LL*c[i];
    }
    return res;
}


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	int siz = 223; //sqrt(50000);
  	for ( int i = 1 ;i  <= n ; i++)
 	{
	    scanf("%d",&a[i]);
	    pos[i] = (i-1)/siz;
	    b[i] = a[i];
	}
	 sort(b+1,b+n+1);
	 int t = unique(b+1,b+n+1)-b-1;
	 for ( int i = 1 ; i <= n ; i++) a[i] = lower_bound(b+1,b+t+1,a[i])-b;

//	 for ( int i = 1 ;i <= n ; i++) cout<<"a[i]:"<<a[i]<<endl;
	 scanf("%d",&m);
	 for ( int i = 1 ;i  <= m;  i++)
	 {
	     scanf("%d %d",&q[i].l,&q[i].r);
	     q[i].id = i ;
	 }
	 
	 sort(q+1,q+m+1);

	 int pl=1,pr=0;
	 int l,r,id;
	 sum = 0 ;
	 ms(c,0);
	 ms(ans,0LL);
	 for ( int i = 1; i <= m; i++)
	 {
	     l = q[i].l;
	     r = q[i].r;
	     id = q[i].id;
	     while (pr<r)
	    {
		update(a[++pr],1);
		sum +=pr-pl-Sum(a[pr]-1);
	    }
	     while (pr>r)
	     {
		 sum -= pr-pl-Sum(a[pr]-1);
		 update(a[pr--],-1);
	     }
	     while (pl<l)
	     {
		 sum -= Sum(a[pl]-1);
		 update(a[pl++],-1);
	     }
	     while (pl>l)
	     {
		 update(a[--pl],1);
		 sum +=Sum(a[pl]-1);
	     }

	//     cout<<"sum:"<<sum<<endl;
	     
	     ans[id] = sum;
	 }
	 for ( int i = 1 ; i <= m ; i++) printf("%lld\n",ans[i]);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
