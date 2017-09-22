/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 14时16分30秒
File Name :code/hust/2016/CC.cpp
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
const int M=10005;
int n,m;
int val[N];
int a[M],tmp[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d %d",&n,&m)!=EOF)
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&val[i]);

	    ms(a,0);
	    ms(tmp,0);
	    
	    a[0] = 1;
	    a[val[1]] = 1;
	    int cur = val[1];
	    for ( int i = 2 ; i <= n ; i++)
	    {
		if (cur>m) cur = m;
		for ( int j = 0 ; j <= m ; j++ )
		{
		    tmp[j+val[i]] += a[j];
		    tmp[j] += a[j];
		}
		cur += val[i];
//		cout<<"cur:"<<cur<<endl;
		for ( int j = 0 ; j <= m ; j++)
		{
//		    cout<<"j:"<<j<<" a[j]:"<<a[j]<<endl;
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }
//	    for ( int i = 0 ; i <= m ; i++) cout<<"i:"<<i<<" a[i]:"<<a[i]<<endl;
	    printf("%d\n",a[m]);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
