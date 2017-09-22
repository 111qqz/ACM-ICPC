/* ***********************************************
Author :111qqz
Created Time :2016年02月14日 星期日 09时50分10秒
File Name :code/hdu/5213.cpp
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
const int N=6E4+7;
int a[N];
int n,k;
int m;
int sum;
int ans[N];
int pos[N];
int cnt[N];
struct node
{
int l,r;
int add;
int id;
node(){}
node(int a,int b,int c,int d){l=a,r=b,add=c,id = d;}
bool operator <(node b)const
{
    if (pos[l]==pos[b.l]) return r<b.r;
    return pos[l]<pos[b.l];
}
}q[2*N];


void update(int x,int  d)
{

//    cout<<"sum1:"<<sum<<endl;
    cnt[a[x]]+=d;
    if (k-a[x]>=0)
	sum = sum + LL(cnt[k-a[x]]*d);

//    cout<<"sum2:"<<sum<<endl;

 //   cout<<endl;


}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif

    while (scanf("%d",&n)!=EOF)
    {
	ms(ans,0);  //多组数据不清空ans数组。。。逗比。。。
	scanf("%d",&k);
	ms(pos,-1);
	ms(cnt,0);
	int siz = 175;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    pos[i] = (i-1)/siz;
	}

	scanf("%d",&m);
	int total =  0;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int l1,r1,l2,r2;
	    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	    q[++total]=node(r1+1,l2-1,1,i);
	    q[++total]=node(l1,r2,1,i);
	    q[++total]=node(l1,l2-1,-1,i);
	    q[++total]=node(r1+1,r2,-1,i);
	}
	sort(q+1,q+total+1);
    //    for ( int i = 1 ; i <= total ; i++) cout<<q[i].l<<" "<<q[i].r<<endl;
    
	    int pl = 1;
	    int pr = 0;
	    sum = 0;
	    int id,l,r;
	    ms(cnt,0);

	    for ( int i = 1 ; i <= total ; i++)
	    {
		id = q[i].id;
		l = q[i].l;
		r = q[i].r;


		if (pr<r)
		{
		    for ( int j = pr +1 ; j <= r ; j++)
			update(j,1);
		}
		else
		{
		    for ( int j = r +1 ; j <= pr; j++)
			update(j,-1);
		}

		pr = r;

		if (l<pl)
		{
		    for ( int j = l; j <= pl-1 ; j++) update(j,1);
		}
		else
		{
		    for ( int j = pl ; j <= l-1 ; j++) update(j,-1);
		}
		pl = l;

	    //   cout<<"sum:"<<sum<<endl;
	   //    cout<<"q[i].d:"<<q[i].add<<endl;
		ans[id] += q[i].add*sum;   
	    }

	    for ( int i = 1 ; i <= m ; i++) printf("%d\n",ans[i]);
	
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
