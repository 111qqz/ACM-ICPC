/* ***********************************************
Author :111qqz
Created Time :2016年01月21日 星期四 00时08分50秒
File Name :uva/152.cpp
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
#include <cassert>
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
const int N=5E3+11;
int n;
int cnt;
int ans[30];
int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}
struct point 
{
    int x,y,z;

    int dis(point q)
    {
	int res = (x-q.x)*(x-q.x)+(y-q.y)*(y-q.y)+(z-q.z)*(z-q.z);
	return  (int)sqrt(res);
    }
    
}p[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(ans,0);
	cnt =  0;
	
	while (scanf("%d%d%d",&p[cnt].x,&p[cnt].y,&p[cnt].z)!=EOF)
	{
	    if (p[cnt].x==0&&p[cnt].y==0&&p[cnt].z==0) break;
	    cnt++;
	}
	
//	cout<<"cnt:"<<cnt<<endl;
//	cnt--;
// 	for ( int i = 0 ; i < cnt ; i++)
//	{
//	    cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<endl;
//	}
	
	for ( int i = 0 ; i < cnt ; i++)
	{
	    int mind = 10000;
	    for ( int j = 0 ; j < cnt ; j++)
	    {
		if (i==j) continue;
		int tmp = p[i].dis(p[j]);

		if (tmp<mind)
		{
		    mind = tmp;
		}

	    }
	    
		if (mind<10&&mind>=0) 	
		ans[mind]++;
	    
	}


	
	for ( int i = 0 ; i < 10 ; i++)
	printf("%4d",ans[i]);

	printf("\n");

	
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
