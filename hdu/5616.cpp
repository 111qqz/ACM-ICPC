/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 15时35分32秒
File Name :code/hdu/5616.cpp
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
const int N=2E3+7;
int w[N];
int a[N],tmp[N];
int n;
int m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    for ( int i = 1 ; i <= n ; i++) cin>>w[i];

	    ms(a,0);
	    ms(tmp,0);
	    a[0] = 1;
	    a[w[1]] = 1;

	    int cur = w[1];
	    for ( int i = 2 ; i <= n ; i++)
	    {
		for ( int j = 0 ; j <= cur ; j++)
		{
		    tmp[j+w[i]] += a[j]; //放左边
		    tmp[j] +=a[j];      //不放

		    if (j-w[i]>0) tmp[j-w[i]] += a[j];  //放右边
		    if (w[i]-j>0) tmp[w[i]-j] += a[j];
		}


		cur += w[i];
		for ( int j  = 0 ; j <= cur ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] =  0;
		}
	    }

	    cin>>m;
	    while (m--)
	    {
		int x;
		cin>>x;
		if (a[x]==0)
		{
		    puts("NO");
		}
		else
		{
		    puts("YES");
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
