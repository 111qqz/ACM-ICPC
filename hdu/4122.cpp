/* ***********************************************
Author :111qqz
Created Time :2016年05月18日 星期三 19时37分03秒
File Name :code/hdu/4122.cpp
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
const int M[15]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //平年每月天数，1 indexed.
int n,m;
int T,S;
pi o[N];
int a[N];
int dp[N][18];
int toval(string mon)
{
    if (mon=="Jan") return 1;
    if (mon=="Feb") return 2;
    if (mon=="Mar") return 3;
    if (mon=="Apr") return 4;
    if (mon=="May") return 5;
    if (mon=="Jun") return 6;
    if (mon=="Jul") return 7;
    if (mon=="Aug") return 8;
    if (mon=="Sep") return 9;
    if (mon=="Oct") return 10;
    if (mon=="Nov") return 11;
    if (mon=="Dec") return 12;
    return -1; //不然总报 waring...
}
bool leap( int year)
{
    if (year%400==0) return true;
    if (year%4==0&&year%100!=0) return true;
    return false;
}
int tohour(int mon, int day,int year,int hour)
{
    int curday = 0 ;
    for ( int i = 2000 ; i <year ;  i++ )
    {
	if (leap(i)) curday+=366;
	else curday+=355;
    }
    for ( int i = 1 ; i < mon ; i ++) curday+=M[i];
    if (leap(year)&&mon>2) curday++;

    curday = curday + day-1;

    return curday*24+hour+1;
}

int _min(int l,int r)
{
  //  cout<<"ll:"<<l<<" rr:"<<r<<endl;
    if (a[l]<a[r]) return l;
    else return r;
}
void init_rmq()
{
    for ( int i = 1 ; i <= m ; i++) dp[i][0] = i;

    for ( int j = 1 ; (1<<j)<= m ; j++)
	for ( int i = 1 ; i+ (1<<j)-1 <= m ; i++)
	    dp[i][j] = _min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_min(int l,int r)
{
  //  cout<<"l:"<<l<<" r:"<<r<<endl;
    int k = 0 ;
    l = max(l,1);
    while (1<<(k+1)<=r-l+1) k++;
  //  cout<<"k:"<<k<<endl;
    return _min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d %d",&n,&m)!=EOF)
	{
	    if (n==0&&m==0) break;
	    for ( int i = 1 ; i <= n ;  i++)
	    {
		string month;
		int day,year,hour,num;
		cin>>month;
		scanf("%d %d %d %d",&day,&year,&hour,&num);
		int val_month = toval(month);
	//	cout<<"month:"<<val_month<<" day:"<<day<<" year:"<<year<<" hour:"<<hour<<endl;
		o[i] = make_pair(tohour(val_month,day,year,hour),num);
	    }
//	    for ( int i = 1 ; i <= n ; i++) printf("%d %d\n",o[i].fst,o[i].sec);
	    scanf("%d %d",&T,&S);
	    for ( int i = 1 ; i <= m ; i++) scanf("%d",&a[i]);

	    int cnt = 0 ;
	    for ( int i = m ; i >=1 ; i--)
	    {
		a[i]+=cnt*S;
		cnt++;
	    }

//	    for ( int i = 1 ; i <= m ; i++) printf("%d\n",a[i]);

	    init_rmq();
	    LL ans = 0LL;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int maketime = rmq_min(o[i].fst-T,o[i].fst);
		//cout<<"maketime:"<<maketime<<endl;
		int cost = a[maketime]-(m-o[i].fst)*S;
		//cout<<"cost:"<<cost<<endl;
		ans = ans + LL(cost)*LL(o[i].sec);
	    }

	    printf("%lld\n",ans);
	    


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
