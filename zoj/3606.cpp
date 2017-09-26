/* ***********************************************
Author :111qqz
Created Time :2017年09月26日 星期二 18时32分43秒
File Name :3606.cpp
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
const int N=1E5+7;
int n;
int total;
struct node
{
    int p,t;
    int id;
    bool operator < (const node &b) const
    {
	return t<b.t;
    }
}a[N],b[N];

struct Tree
{
    LL sum[3];//sum[i]表示当区间最左边的人买了i+1个面包时，该段区间的总销售额
    int cnt;
}tree[N<<2];

void PushUp(int rt)
{
    tree[rt].cnt = tree[rt<<1].cnt + tree[rt<<1|1].cnt;
    int len = tree[rt<<1].cnt;
    for ( int i = 0 ; i < 3 ; i++)
    {
	tree[rt].sum[i] = tree[rt<<1].sum[i] + tree[rt<<1|1].sum[(i+len)%3];
	//区间合并有点绕
	//将区间rt<<1和rt<<1|1合并到rt的时候，需要注意，我们只规定了区间rt的最左端的人是买了i+1个面包。
	//rt<<1|1区间的人买了几个面包无所谓，我们只要求这个销售额。
    }

}
void update( int x,int l,int r,int rt)
{
    if (l==r)
    {
	for ( int i = 0 ; i < 3 ; i++) tree[rt].sum[i] = 1LL*(i+1)*a[x].p;//printf("i:%d x:%d a[x]:%d sum[i]:%lld \n",i,x,a[x].p,tree[rt].sum[i]);
	tree[rt].cnt=1;
	return;
    }
    int m = (l+r)>>1;
    if (x<=m) update(x,lson);
    else update(x,rson);
    PushUp(rt);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    total = 0 ;
	    ms(tree,0);
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i].p);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i].t);
	    sort(a+1,a+n+1);

	    a[0].t=0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		b[i].t = a[i].t-a[i-1].t;
		b[i].p = a[i].p;
		b[i].id = i ;
	    }
	    sort(b+1,b+n+1);
	   /* 
	    for ( int i = 1 ; i <= n ; i++)
	    {
		printf("id:%d w:%d p:%d\n",b[i].id,b[i].t,b[i].p);
	    }
	    */
	    
	    double mx =  0.0;
	    double  ans_w;
	    for ( int i=1,j=1; i <= n ; i=j) 
	    {
		while (b[i].t==b[j].t&&j<=n)  //一样的要一起处理，否则可能得到不合理的平均值。
		{
		    total++;
		    update(b[j].id,1,n,1);
	//	    cout<<tree[1].sum[0]<<endl;
		    j++;
		}
		double ave = tree[1].sum[0]*1.0/total;
		//cout<<"total:"<<total<<endl;
		if (ave>mx)
		{
		    mx = ave;
		    ans_w = b[j-1].t;
		}
	    }
	    printf("%.6f %.6f\n",ans_w,mx);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
