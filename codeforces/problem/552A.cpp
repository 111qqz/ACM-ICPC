/* ***********************************************
Author :111qqz
Created Time :2015年12月14日 星期一 14时01分14秒
File Name :code/cf/problem/552A.cpp
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
const int N=1E2+7;
int n;
int c[N][N];
struct Point
{
    int x1,y1,x2,y2;

    void input()
    {
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);
    }
}p[N];

int lowbit( int x)
{
    return x&(-x);
}
void update( int x,int y,int delta)
{
    for ( int i = x ; i <= 105 ; i += lowbit(i))
    {
	for ( int j =  y ; j <= 105 ; j +=lowbit(j))
	{
	    c[i][j] +=delta;
	}
    }
}

int sum ( int x,int y)
{
    int res = 0 ;
    for ( int i =  x;  i>= 1 ; i-=lowbit(i))
    {
	for ( int j = y ; j >= 1 ; j-=lowbit(j))
	{
	    res += c[i][j];
	   // cout<<"res:"<<res<<endl;
	}
    }

    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(c,0);
	cin>>n;
	for ( int i = 0 ; i < n; i++) p[i].input();
	
//	puts("aahhhhhh");
	for ( int i = 0 ; i <n ; i++)
	{
	    update(p[i].x2+1,p[i].y2+1,1);
	   // cout<<"www?"<<endl;
	    update(p[i].x2+1,p[i].y1,-1);
	    update(p[i].x1,p[i].y2+1,-1);
	    update(p[i].x1,p[i].y1,1);
	//    puts("yyyyepppppp");
	}
	int ans = 0;
	for ( int i = 1 ; i <= 101 ; i ++)
	    for ( int j = 1 ; j <= 101;  j++)
		
		ans += sum(i,j);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
