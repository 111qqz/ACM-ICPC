/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 22时02分40秒
File Name :code/cf/#341/B.cpp
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
const int N=2E5+7;
const int C=1000;
struct point 
{
    int x,y;

    void in()
    {
	scanf("%d %d",&x,&y);
    }
}p[N];
int n ;
LL a[2005],b[2005];  //b :2..2000
			//a:-999 ..999
			//
LL cal( LL x)
{
    LL res = x*(x-1)/2;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 0 ;i < n ; i++) p[i].in();
	
	ms(a,0);
	ms(b,0);

	for ( int i = 0 ; i < n ; i++)
	{
	    a[p[i].x-p[i].y+C]++;
	    b[p[i].x+p[i].y]++;
	}
	LL ans = 0 ;
	for ( int i = 1 ; i <=2001 ; i++)
	{
	    if (a[i]==0) continue;
	    ans += cal(a[i]);
	}
	for ( int i = 1  ; i <= 2001 ; i ++)
	{
	    if (b[i]==0) continue;
	    ans += cal(b[i]);
	}
	cout<<ans<<endl;
	 

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
