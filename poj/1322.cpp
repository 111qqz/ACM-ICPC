/* ***********************************************
Author :111qqz
Created Time :2016年03月02日 星期三 18时57分58秒
File Name :code/poj/1322.cpp
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
const int N=105;
double c[N][N];
int C,n,m;



void pre()
{
    c[0][0] = 1;
    for ( int i = 1 ; i <  N ; i++)
    {
	c[i][0]=c[i][i] = 1;
	for ( int j = 1 ; j < i ; j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
}
double ksm( double a,int b)
{
    double res = 1.0;
    while (b)
    {
	if (b&1) res = (res*a);
	b = b>>1;
	a = a*a;
    }
    return res;
}
void solve()
{
    double posi[N],nega[N],a[N],b[N];
    
    ms(posi,0);
    ms(nega,0);
    ms(a,0);
    ms(b,0);

    double tmp1=ksm(0.5,m);
    double tmp2;
    for ( int i = 0 ; i <= m ; i++)
    {
	int j = i-(m-i);
	if ((m-i)&1) tmp2 = -tmp1;
	    else tmp2 = tmp1 ;   //正负项
	if (j>=0) a[j]+=tmp2*c[m][i];
	    else b[-j] +=tmp2*c[m][i];
    }

    tmp1 = ksm(0.5,C-m);
    for ( int i = 0 ; i <= C-m ; i++)
    {
	tmp2 = tmp1 *c[C-m][i];
	for (int j = 0 ; j <= m ; j++)
	{
	    int k = j+i-(C-m-i);
	    if (k>=0) posi[k]+=tmp2*a[j];
	    else nega[-k]+=tmp2*a[j];

	}

	for ( int j = 0 ; j <= m ; j ++)
	{
	    int k = -j+i-(C-m-i);
	    if (k>=0) posi[k]+=tmp2*b[j];
	    else nega[-k]+=tmp2*b[j];

	}
    }

    double ans =  0.0;
    for ( int i = 1 ; i <= C ; i++)
    {
	if (n&1) nega[i]=-nega[i];
	ans +=c[C][m]*ksm(1.0*i/(1.0*C),n)*(posi[i]+nega[i]);
//	cout<<c[C][m]<<" "<<ksm(1.0*i/C,n)<<" "<<posi[i]+nega[i]<<endl;
    }

    printf("%.3f\n",ans);


}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	pre();
	while (~scanf("%d",&C))
	{
	    if (C==0) break;
	    scanf("%d %d",&n,&m);
	    if ((n-m)%2||m>C||m>n)
	    {
		puts("0.000");
		continue;
	    }
	    if (n==0&&m==0)
	    {
		puts("1.000");
		continue;
	    }
	    solve();

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
