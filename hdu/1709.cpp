/* ***********************************************
Author :111qqz
Created Time :2016年02月26日 星期五 17时57分05秒
File Name :code/hdu/1709.cpp
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
const int N=1E4+7;
int a[N],tmp[N];
int n;
int w[N];
int ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&w[i]);
	  //  sort(w+1,w+n+1);
	    ms(ans,0);
	    ms(tmp,0);
	    ms(a,0);
	    a[0] = 1;
	    a[w[1]] = 1;

	    int cur = w[1];
	    for ( int i = 2 ; i <= n ; i++)
	    {
		for ( int j = 0 ; j <= cur ; j++)
		{
		    tmp[j] +=a[j];
		    tmp[j+w[i]]+=a[j];
		    if (j-w[i]>0) tmp[j-w[i]] +=a[j];
		    if (w[i]-j>0) tmp[w[i]-j] +=a[j];  //一开始忘记考虑，wa了好多次

		}

		cur += w[i];
		
		for ( int  j = 0 ; j <= cur ; j++)
		{
		   // cout<<"j:"<<j<<" tmp[j]:"<<tmp[j]<<endl;
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}

	    }
	    int cnt = 0 ;
	    for ( int i = 1 ; i <= cur ; i++)
	    {
		if (a[i]==0) ans[++cnt] =  i;
	    }

	    printf("%d\n",cnt);
	    if (cnt==0) continue;
	    for ( int i = 1 ; i <= cnt-1 ; i++) printf("%d ",ans[i]);
	    
	    printf("%d\n",ans[cnt]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
