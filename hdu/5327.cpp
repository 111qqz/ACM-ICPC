/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 13时25分36秒
File Name :code/hdu/5327.cpp
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
int a,b;
int sum[N];
int p[N];

bool ok ( int x)
{
    set<int>se;
    se.clear();
    int cnt  = 0 ;
    while (x)
    {
	int tmp = x % 10;
	se.insert(tmp);
	x =  x/10;
	cnt++;
    }
    if (se.size()==cnt) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	for ( int i = 1 ; i <= 100000 ; i ++)
	{
	    if (ok(i))
		p[i] = 1;
	    else p[i]  = 0;
	}

	sum[0] = 0 ;
	for ( int i = 1 ;i  <= 100000 ; i++)
	{
	    sum[i] = sum[i-1] + p[i];
	}

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d",&a,&b);
	    printf("%d\n",sum[b]-sum[a-1]);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
