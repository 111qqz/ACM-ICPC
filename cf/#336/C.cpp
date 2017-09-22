/* ***********************************************
Author :111qqz
Created Time :2015年12月24日 星期四 00时32分39秒
File Name :code/cf/#336/C.cpp
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
const int N=1E5+27;
const int LEN =1E6+27;
const int C=9;
int n;
struct node
{
    int a,b;

    bool operator<(node p)const
    {
	return a<p.a;
    }
}q[N];
int sum[LEN];
bool v[LEN];
bool boom[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(v,false);
	ms(boom,false);
	for ( int i  = 1 ; i <= n ; i++)
	{
	    scanf("%d%d",&q[i].a,&q[i].b);
	    if (q[i].b>q[i].a) q[i].b = q[i].a;
	    v[q[i].a] = true;
	}
	sort(q+1,q+n+1);
//	for ( int i = 1 ;  i <= n ; i++)  cout<<q[i].a<<" "<<q[i].b<<endl;
	ms(sum,0);
	if (v[0]) sum[C] = 1;
	for ( int i = 1 ; i < LEN-25 ; i++)
	{
	    sum[i+C] = sum[i-1+C];
	    if (v[i]) sum[i+C]++;
	 //   if (v[i]) cout<<"i:"<<i<<endl;
	}
	int ans = 0 ;
	for ( int i = n ; i >= 1 ; i--)
	{
	    int tmp = sum[q[i].a-1+C]-sum[q[i].a-q[i].b-1+C];
//	    cout<<"tmp:"<<tmp<<endl;
	    if (tmp>=2)
	    {
		boom[i] = true;
	//	i = i-tmp;
		ans++;
	    }
	}
	for ( int i = n ; i >= 1 ; i--)
	{
	    if (boom[i]) continue;
	    //cout<<"i:"<<i<<endl;
	    int tmp = sum[q[i].a-1+C]-sum[q[i].a-q[i].b-1+C];
	    ans +=tmp;
	    if (tmp!=0) i=i-tmp;
	    
	}
	cout<<max(0,ans)<<endl;
	

	
	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
