/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 13时02分35秒
File Name :code/hust/2016/C.cpp
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
const int M=1E4+7;
int n,m;
int cnt[N];
int l[M];
int a[M],tmp[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d",&n,&m))
	{
	    ms(cnt,0);
	    ms(a,0);
	    ms(tmp,0);
	    int mx = -1;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		scanf("%d",&x);
		cnt[x]++;
		mx = max(x,mx);
	    }
	    
	    int num  = 0;
	    mx = min(m,mx);
	    for ( int i = 1 ; i <= mx  ; i++)
	    {
		if (cnt[i]!=0)
		{
		    l[++num] = i;
		}
	    }

	    for ( int i = 1 ; i <= num ; i++) cout<<"l[i]:"<<l[i]<<" cnt[l[i]]:"<<cnt[l[i]]<<endl;

	    for ( int i = 0 ; i <=cnt[l[1]] ; i++)
	    {
		a[i] = 1;
		tmp[i] = 0 ;
	    }

	    for ( int i = 2 ; i <= num ; i++)
	    {
		for ( int j = 0 ; j <= m ; j++)
		{
		    for ( int k = 0 ; k <= cnt[l[i]] && j+k*l[i]<= m ; k++)
		    {
			tmp[j+k*l[i]] += a[j];
		    }
		}
		for ( int j = 0 ; j <= m ; j++)
		{
		    cout<<j<<" "<<tmp[j]<<endl;
		    a[j] = tmp[j];
		    tmp[j] = 0;
		}
		cout<<endl;
	    }
	    printf("%d\n",a[m]);


	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
