/* ***********************************************
Author :111qqz
Created Time :2016年02月26日 星期五 12时19分21秒
File Name :code/hdu/2069.cpp
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
const int N=255;
int n;
int a[N][105],tmp[N][105];  //a[i][j]表示j个硬币构成i元钱的方案数
int s[10]={0,1,5,10,25,50};
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    
	    ms(tmp,0);
	    ms(a,0); //多组数据，a数组也要记得初始化
	    for ( int i = 0 ; i <= min(n,100) ; i++)
	    {
		a[i][i] = 1;                   
	    }
	    for ( int i = 2 ; i <= 5 ; i++)
	    {
		for (int j = 0 ; j <= n ; j++)
		{
		    for ( int k = 0 ; k*s[i]+j<= n ; k++)
		    {
			for ( int z = 0 ; z+k <=100 ; z++)
			{
			    tmp[j+k*s[i]][z+k]+=a[j][z];
			}
		    }
		}	
		for ( int j = 0 ; j <= n ; j++)
		{
		    for ( int z = 0 ; z <= 100 ; z++)
		    {
			a[j][z] = tmp[j][z];
			tmp[j][z] = 0 ;
		    }
		}
	    }


	    int ans = 0;
	    for ( int z = 0 ; z <= 100 ; z++)
	    {
		if (a[n][z]==0) continue;
	//	cout<<z<<"  "<<a[n][z]<<endl;
		
		ans += a[n][z];
	    }

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
