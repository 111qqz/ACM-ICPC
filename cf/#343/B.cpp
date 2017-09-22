/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 00时30分10秒
File Name :code/cf/#343/B.cpp
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
const int N=5E4+7;
int n;
int m[N],f[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(m,0);
	ms(f,0);
	cin>>n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    char gen;
	    cin>>gen;
	    
	    
	    int x,y;
	    scanf("%d %d",&x,&y);
	    getchar();
	    for ( int j = x ; j <= y ;j++)
	    {
		if (gen=='M')
		    m[j]++;
		else f[j]++;
	    }

	  //  cout<<"gen:"<<gen<<" x:"<<x<<" y:"<<y<<endl;

	}
	int ans = 0;
	for ( int i = 1 ; i <= 366 ; i++ )
	{
	    if (f[i]==0) continue;
	    if (f[i]==m[i]&&2*f[i]>ans)
	    {
		    ans = 2*f[i];
	    }
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
