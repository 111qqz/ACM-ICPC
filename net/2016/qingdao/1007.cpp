/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 01:54:38 PM CST
File Name :code/net/2016/qingdao/1007.cpp
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
const int N=1E5+7;
LL a[N];
int n,TOT;


bool check(int k)
{
    cout<<"k:"<<k<<endl;
    queue<int>q;
    LL cost = 0 ;
    LL cur = 0 ;
    for ( int i = 1 ; i <= k ; i++) cur+=a[i];
    q.push(cur);
    cost +=cur;
    int i = k+1;
    int num = 0 ;
    while (i<=n)
    {

//	cout<<"cost:"<<cost<<endl;
	num = 1 ;
	cur = 0 ;
	while (num<=k) //每次合并
	{
//	    cout<<"cur:"<<cur<<" num:"<<num<<" k:"<<k<<endl;
	    int x = a[i];
	    int y = q.front();
	    cout<<"x:"<<x<<" y:"<<y<<endl;
	    if (x<y&&i<=n)
	    {
		cur+=x;
		i++;
	    }
	    else
	    {
		cur+=y;
		q.pop();
	    }
	    cout<<"num:"<<num<<" k:"<<k<<endl;
	    num++;
	    cout<<"num2:"<<num<<endl;
	}
	q.push(cur);
	cost+=cur;
    }
//    cout<<"cur:"<<cur<<" cost:"<<endl;
    return cost<=TOT;
    
}
int  bin()
{
    int l = 1;
    int r = n;
    int res = n+1;
    while (l<=r)
    {
	int mid = (l+r)>>1;
	if (check(mid)) r = mid-1,res = mid;
	else l = mid+1;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d",&n,&TOT);
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	    sort(a+1,a+n+1);
	    int ans = bin();
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
