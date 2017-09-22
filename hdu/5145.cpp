/* ***********************************************
Author :111qqz
Created Time :2016年02月17日 星期三 14时20分01秒
File Name :code/hdu/5145.cpp
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
const int N=3E5+7;
const int MOD =1E9+7;
int n,m;
int a[N];
int pos[N];
LL ny[N]; 
LL p;
LL num;
int ans[N];
int cnt[N];

struct node
{
    int l,r;
    int id;

    bool operator <(node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l]<pos[b.l];
    }
}q[N];

LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) 
	    res =(res*a)%MOD;
	b = b>>1;
	a = (a*a)%MOD;
    }
    return res;
    
}


void update(int x,int d)
{
    if (d>0)
    {
	num++;
	p = (p*num)%MOD;
	cnt[a[x]]++;
//	if (cnt[a[x]]>3E4) return;
	p = (p*ny[cnt[a[x]]])%MOD;
    }
    else
    {
	
	p = (p*cnt[a[x]])%MOD;
	cnt[a[x]]--;
//	if (num>3E4||num<0) return;
	p = (p*ny[num])%MOD;
	num--;
    }
}



void getny()  //预处理逆元
{
    ms(ny,0);
    for ( int i = 1 ; i <= 30005 ;  i++)
    {
	ny[i]=ksm(LL(i),MOD-2);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	getny();
	int T;
	cin>>T;
	while (T--)
	{
	
	    scanf("%d %d",&n,&m);
	    ms(cnt,0);
	    p = 1LL;
	    num = 0LL;
	    ms(ans,0);

	    int siz  = 173; //sqrt(30000);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d",&a[i]);
		pos[i] = (i-1)/siz;
	    }
	    for ( int i = 1 ; i <= m ; i ++)
	    {
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i ;
	    }

	    sort(q+1,q+m+1);
//	    cout<<"ok2<"<<endl;
	    int pl = 1;
	    int pr = 0 ;
	    int id,l,r;

	    for ( int i = 1 ; i <= m ; i++)
	    {
		id = q[i].id;
		l  = q[i].l;
		r  = q[i].r;

		if (pr<r)
		{
		    for ( int j = pr+1 ; j <= r ; j++)
			update(j,1);
		}
		else
		{
		    for ( int j = r+1 ; j <= pr ; j++)
			update(j,-1);
		}
		pr = r;

		if (pl<l)
		{
		    for ( int j =  pl ; j  <=  l-1 ; j ++) 
			update(j,-1);
		}
		else
		{
		    for ( int j = l  ; j <= pl-1  ; j++)
			update(j,1);
		}
		pl = l;

		ans[id] = p;
	    }

	    for ( int i = 1 ;i <= m ; i++) printf("%d\n",ans[i]);

	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
