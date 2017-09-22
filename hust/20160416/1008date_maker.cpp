/* ***********************************************
Author :111qqz
Created Time :2016年04月16日 星期六 13时45分13秒
File Name :code/hust/20160416/1010.cpp
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
int n,m,c,d,k;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

    freopen("out.txt","w",stdout);
	n = rand()%1000;
	m = rand()%100000;
	c = rand()%1000;
	d = rand()%1000;
	if (d==c) d=(d+100)%1000;
	k = rand()%100000;
	cout<<n<<" "<<m<<" "<<c<<" "<<d<<" "<<k<<endl;
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v,w;
	    u = rand()%1000;
	    v = rand()%1000;
	    w = rand()%k+1;
	    cout<<u<<" "<<v<<" "<<w<<endl;
	}
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
