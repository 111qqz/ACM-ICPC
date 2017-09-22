/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 00时19分46秒
File Name :code/poj/2926.cpp
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
#include <iomanip>
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
double p[16][N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	for ( int i = 0 ; i < n ;i++)
	{
	    double x1,x2,x3,x4,x5;
	    cin>>x1>>x2>>x3>>x4>>x5;
	    p[0][i]=x1+x2+x3+x4+x5;
	    p[1][i]=x1+x2+x3+x4-x5;
	    p[2][i]=x1+x2+x3-x4+x5;
	    p[3][i]=x1+x2+x3-x4-x5;

	    p[4][i]=x1+x2-x3+x4+x5;
	    p[5][i]=x1+x2-x3+x4-x5;
	    p[6][i]=x1+x2-x3-x4+x5;
	    p[7][i]=x1+x2-x3-x4-x5;

	    p[8][i]=x1-x2+x3+x4+x5;
	    p[9][i]=x1-x2+x3+x4-x5;
	    p[10][i]=x1-x2+x3-x4+x5;
	    p[11][i]=x1-x2+x3-x4-x5;

	    p[12][i]=x1-x2-x3+x4+x5;
	    p[13][i]=x1-x2-x3+x4-x5;
	    p[14][i]=x1-x2-x3-x4+x5;
	    p[15][i]=x1-x2-x3-x4-x5;
	}

	double mx = -1;
	for ( int i = 0 ; i < 16 ; i++)
	{
	    sort(p[i],p[i]+n);

	    mx = max(mx,p[i][n-1]-p[i][0]);

	}
	cout<<fixed<<setprecision(2)<<mx<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
