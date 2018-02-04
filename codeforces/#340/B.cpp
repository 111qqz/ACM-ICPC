/* ***********************************************
Author :111qqz
Created Time :2016年01月23日 星期六 23时53分36秒
File Name :code/cf#340/B.cpp
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
int n;
int a[N];
LL p[N];
int cnt ;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	cnt = 0 ;
	for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	for ( int i = 0 ; i < n ; i++)
	{
	    if (a[i]==1)
	    {
		cnt++;
		p[cnt] = i;
	    }
	}
	if (cnt==0)
	{
	    puts("0");
	    return 0;
	}
	LL ans =  1;
	for ( int i = 1 ; i <=cnt -1 ; i++)
	{
	    ans =ans*(p[i+1]-p[i]);
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

