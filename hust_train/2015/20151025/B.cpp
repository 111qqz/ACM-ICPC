/*************************************************************************
	> File Name: code/hust/20151025/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 12时48分59秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const LL inf = 1E16+7;
const int N=4E3+7;
int n;

struct Q
{
    LL a,b;
}q[N];

bool cmp(Q x,Q y)
{
    if (x.a>y.a) return true;
    if (x.a==y.a&&x.b>y.b) return true;
  //  return x.a*x.b>y.a*y.b;
//  return x.a*1.0/y.a*1.0>y.b*1.0/x.b*1.0;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   ms(q,0);
   for ( int i = 1 ; i <= n ; i++)
    {
	cin>>q[i].a>>q[i].b;
	if (q[i].a<q[i].b) swap(q[i].a,q[i].b);
    }
   sort(q+1,q+n+1,cmp);
   q[0].a=inf;
   q[0].b=inf;
   
    
   LL res;
   LL ans = 0;
   LL tmpa,tmpb;
   LL tmpaa,tmpbb;
   LL la,lb;
   LL cura=q[0].a;
   LL curb=q[0].b;
   LL num = 0;
   
   for ( int i = 1 ; i <= n ; i++)
    {
	int flag = 0;
	tmpa = min(q[i].a,cura);
	tmpb = min(q[i].b,curb);
	cout<<"tmpa:"<<tmpa<<" tmpb:"<<tmpb<<endl;
	res = tmpa*tmpb*(i-num);
	if (res>ans)
	{
	    flag = 1;
	    ans = res;
	}
	cout<<"i:"<<i<<" res:"<<res<<endl;

	//roate
	tmpaa = min(q[i].b,cura);
	tmpbb = min(q[i].a,curb);
	res = tmpaa*tmpbb*(i-num);
	if (res>ans)
	{
	    flag = 2;
	    ans = res;
	}
	if (flag==2)
	{
	    cura = tmpaa;
	    curb = tmpbb;
	}
	else if (flag==1)
	{
	    cura = tmpa;
	    curb = tmpb;
//	    cout<<"i:"<<i<<endl;
	}
	// if (!flag) num++;
	cout<<"i:"<<i<<" res:"<<res<<endl;
    }
   if (cura<curb) swap(cura,curb);
    cout<<ans<<endl;
    cout<<cura<<" "<<curb<<endl;

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
