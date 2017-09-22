/*************************************************************************
	> File Name: code/whust/#2/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Wed 22 Jul 2015 12:29:35 PM CST
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const double eqs = 1E-6;
const int N = 25;
const int inf = 0x7fffffff;
int x[N],y[N];
int n;
double an[2000][5];
struct Q
{
    int xx,yy;
}q[N];
double dis(int a,int b)
{
    double res;
    res = (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
    res = sqrt(res);
    return res;
}
double angle(double a,double b,double c)
{
    double res;
	  res = (b*b+c*c-a*a)/(2*b*c);
   // cout<<a<<" "<<b<<" "<<c<<" "<<res<<endl;
	  res = acos(res);
    return res;
}

bool cmp(Q a,Q b)
{
    if (a.xx<b.xx) return true;
    if (a.xx==b.xx&&a.yy<b.yy) return true;
    return false;
}
bool ok(int t)
{
    if (q[t].xx==q[t+1].xx&&q[t].yy==q[t+1].yy)
	  return false;
    return true;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
 {  
	  if (n==0) break;

 //   memset(ang,0,sizeof(ang));
 //   memset(angl,0,sizeof(angl));
    memset(an,0,sizeof(an));
    int sum = 0; //三角形的个数
    for ( int i =1 ; i <= n ; i++ )
    {
	  cin>>q[i].xx>>q[i].yy;
    }
    sort(q+1,q+n+1,cmp);
    q[n+1].xx=inf;
    q[n+1].yy=inf;

    int n_dif=0;
    for ( int i = 1; i <= n ; i++)
    {
	  if (ok(i))
	  {
		n_dif++;
		x[n_dif]=q[i].xx;
		y[n_dif]=q[i].yy;
	  }

    }
    n = n_dif;
   // cout<<"n_dif:"<<n_dif<<endl;
    for ( int i = 1 ; i <= n-2  ; i++ )
    {
	  for ( int j = i + 1 ; j <= n-1 ; j++)
	  {
		for ( int k = j +1 ; k <= n ; k++)
		{
		    if (x[i]==x[j]&&y[i]==y[j]) continue;
		    if (x[i]==x[k]&&y[i]==y[k]) continue;
		    if (x[j]==x[k]&&y[j]==y[k]) continue; //难道还有一样的点？？？
		    if (x[i]==x[j]&&x[i]==x[k]) continue;  //三点共线，且斜率不存在，构不成三角形。
		    //相同的三角形的点只算一个？
		    double k1,k2;
		    k1 = (y[i]-y[j])*1.0/(x[i]-x[j]);
		    k2 = (y[i]-y[k])*1.0/(x[i]-x[k]);
		    if (fabs(k1-k2)<=eqs) continue;   //共线，不恩能够构成三角形
		    double si = dis(j,k);
		    double sj = dis(i,k);
		    double sk = dis(i,j);
		    double ai = angle(si,sj,sk);
		    double aj = angle(sj,si,sk);
		    double ak = angle(sk,si,sj);
		    double ang[10];
		 //   cout<<"si:"<<si<<" sj:"<<sj<<" sk:"<<sk<<endl;
		 //   cout<<"ai:"<<ai<<" aj:"<<aj<<" ak:"<<ak<<endl;
		    ang[0]=ai;
		    ang[1]=aj;
		    ang[2]=ak;
		    sort(ang,ang+3); //把角度从小到大排序
		 //   angl[i][j][k][0]=ang[0];
		 //   angl[i][j][k][1]=ang[1];
		 //   angl[i][j][k][2]=ang[2];       //重要的是角度是多少，某个三角形是哪三个点得到的并不重要。
		    sum++;
		    an[sum][0]=ang[0];
		    an[sum][1]=ang[1];
		    an[sum][2]=ang[2];
		    
		}
	  }
    }
    int ans = 0;  //初始是０不是１，因为可能恰好所有点共线，没有三角形，也就没有相似的三角形
    if (sum!=0) ans = 1;
 //   for ( int i = 1 ; i <= sum ; i++ ) cout<<"an[i][0]"<<an[i][0]<<"  an[i][1] "<<an[i][1]<<endl; 
    for ( int i = 1; i <= sum -1 ; i++ )
    {
	  int cnt = 1;
	  for ( int j = i+1 ; j <= sum ; j++ )
	  {
		double tmp1 = fabs(an[i][0]-an[j][0]);
		double tmp2 = fabs(an[i][1]-an[j][1]);
		if (tmp1<=eqs&&tmp2<=eqs)
		{
		    cnt++;
		}
		ans = max(ans,cnt);
	  }
    }
    cout<<ans<<endl;
		
}
	return 0;
}
