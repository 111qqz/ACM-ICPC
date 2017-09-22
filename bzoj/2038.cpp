/* ***********************************************
Author :111qqz
Created Time :2016年02月10日 星期三 15时06分20秒
File Name :code/bzoj/2038.cpp
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
const int N=5E4+7;
int n,m;
int col[N];
int pos[N];  //pos[i]表示第i个袜子在第几块
struct node
{
    int l,r,id;

    bool operator <(node b)const
    {
	if (pos[l]==pos[b.l])
	    return r<b.r;
	return pos[l]<pos[b.l];
    }

}q[N];


struct node2
{
    LL fz,fm;
}ans[N];
LL num[N];
LL sum;


void update ( int x,int delta)
{
    
    sum-=LL(num[col[x]]*num[col[x]]);
  //  cout<<"sum:::"<<sum<<endl;
    num[col[x]]+=delta;
    sum+=LL(num[col[x]]*num[col[x]]);

   // cout<<x<<" "<<delta<<" "<<"sum::"<<sum<<endl;

}

LL gcd( LL a,LL b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	ms(num,0LL);
	int siz = int(sqrt(n));
//	cout<<"siz:"<<siz<<endl;
	for ( int i =  1 ; i  <= n ; i++)
	{
	    scanf("%d",&col[i]);
	    pos[i] = (i-1)/siz;
	}
//	cout<<"aaa"<<endl;
	for ( int i = 1 ; i <= m ; i++)
	{
	    scanf("%d %d",&q[i].l,&q[i].r);
	    q[i].id = i ;  //离线处理，记得记录id
	}
	sort(q+1,q+m+1);
	//for ( int i = 1 ; i <= m ; i++) cout<<"q[i].l:"<<q[i].l<<" q[i].r:"<<q[i].r<<endl;
//	cout<<"bbb"<<endl;

	int prel=1,prer=0;
	sum=0LL;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int id = q[i].id;
	    
//	    cout<<"q[i].l:"<<q[i].l<<" q[i].r:"<<q[i].r<<endl;
	    if (q[i].l==q[i].r)  //只有一直袜子的话是不可能配成一对的。
	    {
		ans[id].fz = 0LL;
		ans[id].fm = 1LL;
		continue;
	    }
	  //  cout<<"prel:"<<prel<<" prer:"<<prer<<endl;
	    if (q[i].r>prer)
	    {
		for ( int j = prer +1 ; j <=q[i].r ; j++) update(j,1);
//		cout<<"sumaa:"<<sum<<endl;
	    }
	    else
	    {
		for (int j = prer ; j > q[i].r ; j--) update(j,-1);
	    }
	    
	    prer = q[i].r;

	    if (q[i].l<prel)
	    {
		for ( int j = q[i].l ; j < prel  ;j++) update(j,1);
	    }
	    else
	    {
//		cout<<"sum1:"<<sum<<endl;
		for ( int j = q[i].l -1 ; j>=prel  ; j--) update(j,-1);
//		cout<<"sum2:"<<sum<<endl;
	    }
	    prel = q[i].l;
//	    cout<<q[i].l<<"   "<<q[i].r<<"   "<<sum<<endl;
	    LL fz = sum +(-1LL)*(q[i].r-q[i].l+1);
	    LL fm = 1LL*(q[i].r-q[i].l)*1LL*(q[i].r-q[i].l+1);
//	    cout<<"fz:"<<fz<<" fm:"<<fm<<endl;
	    if (fz==0)
	    {
		fm = 1;
	    }
	    else
	    {
		LL GCD = gcd(fz,fm);
		fz/=GCD;
		fm/=GCD;
	    }
	    ans[id].fz = fz;
	    ans[id].fm = fm;

//	    cout<<endl;
	}

	for ( int i = 1 ; i <= m ; i++)
	    printf("%lld/%lld\n",ans[i].fz,ans[i].fm);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
