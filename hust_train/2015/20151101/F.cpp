/*************************************************************************
	> File Name: code/hust/20151101/F.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月01日 星期日 13时33分39秒
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
#include<cctype>
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;

struct Q
{
    int a,b,c;
    int id;
}q[N],uq[N];


bool cmp(Q x,Q y)
{
    if (x.a<y.a) return true;
    else if (x.a==y.a&&x.b<y.b) return true;
	else if (x.a==y.a&&x.b==y.b&&x.c<y.c) return true;
    return false;
}
int n;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    int cas = 0 ;
    int cnt;
    scanf("%d",&T);
    while (T--)
    {
	cas++;
	scanf("%d",&n);
	cnt = 2*n;
	cout<<"n:"<<n<<endl;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d %d %d",&q[i].a,&q[i].b,&q[i].c);
	}

	sort(q,q+n,cmp);
	//去重
	int k = 0 ;
	for ( int i = 0 ; i < n-1 ; i++)
	{
	    if (q[i].a==q[i+1].a)
	    {
		k++;
	    }
	}
	
//	for ( int i = 0 ; i < n ; i++)
//	{
//	    if (q[i].a!=0)
//	    {
//		uq[k].a = q[i].a;
//		uq[k].b = q[i].b;
//		uq[k].c = q[i].c;
//		k++;
//	    }
//	
//	}
	cout<<"k:"<<k<<endl;
	cnt = cnt - k;

//	for ( int i = 0 ; i < k ; i++) uq[i].id = i ;
	

	int j;
	for ( int i = 0 ; i < n ; i++)
	{
	   // if (q[i].a==0) continue;
	    j = 0;
	    while (j<n&&!(q[j].b<=q[i].a&&q[i].a<=q[j].c))
	    {
		j++;
		if (q[i].a<q[j].b) break;
	    }
	    if (j<k&&q[j].b<=q[i].a&&q[i].a<=q[j].c)
	    {
		cnt--;
		q[j].b = 0;
		q[j].c = 0;
	//	cout<<"j:"<<j<<endl;
	    }
	}
	
    
	


	printf("Case #%d: %d\n",cas,cnt);
	

	
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
