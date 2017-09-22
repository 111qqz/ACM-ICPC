/* ***********************************************
Author :111qqz
Created Time :2016年02月13日 星期六 21时47分47秒
File Name :code/cf/#340/E.cpp
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
const int N=3E6+7;
int n,m,k;
int siz;
LL a[N];
LL sum[N];
int pos[N];
LL cur;
LL cnt[N];
LL ans[N];

struct node
{
    int l,r;
    int id;

    bool operator <(node b)const
    {
	if (pos[l]==pos[b.l])
	    return r<b.r;
	return pos[l]<pos[b.l];
    }
}q[N];


void update ( int x,int d)
{
    
  /* cnt[sum[x]]+=d;
   // if (sum[x]^k>3E7) return;
   // cout<<"pp:"<<pp<<endl;
    cur = cur + d*(cnt[sum[x]^k]);  */
    if (d>0)
    {
//	cnt[sum[x]]++;
	cur +=cnt[sum[x]^k];
	cnt[sum[x]]++;   //两种更新的顺序不一定一样，所以最好还是分开写....//why?
    }
    else
    {
	cnt[sum[x]]--;
	cur -=cnt[sum[x]^k];
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m>>k;
	ms(cnt,0);
	int siz = 340;

	ms(sum,0);
	ms(pos,-1);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%I64d",&a[i]);
	    sum[i] = sum[i-1] ^ a[i];
        pos[i] = (i-1)/siz;
	}


	for ( int i = 1  ; i <= m ; i++) scanf("%d %d",&q[i].l,&q[i].r),q[i].id =  i;
	sort(q+1,q+m+1);

//	for ( int i = 1;i  <= m ; i++) cout<<"l r id "<<q[i].l<<" "<<q[i].r<<" "<<q[i].id<<endl;


	cur = 0LL ; 
	int pl = 1 ;
	int pr = 0;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int id = q[i].id;
	    int l = q[i].l-1; //此处需要注意，因为是i到j的异或和是sum[i-1]^sum[j]
	    int r = q[i].r;

	    if (r<pr)
	    {
		for ( int j = r +1 ; j <= pr ; j ++) update(j,-1);
	    }
	    else
	    {
		for ( int j = pr +1 ; j <= r ; j ++) update(j,1);
	    }

	    pr = r;

	    if (l<pl)
	    {
		for ( int j = l ; j <= pl-1 ; j++) update(j,1);
	    }
	    else
	    {
		for ( int j = pl ;  j <= l-1 ; j++) update(j,-1);
	    }

	    pl = l;
	    ans[id] = cur;
	    
	}
	for ( int i = 1 ;i <= m ; i++) printf("%I64d\n",ans[i]);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
