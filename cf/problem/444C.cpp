/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 03时04分37秒
File Name :code/cf/problem/444C.cpp
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
int n,m;
int col[N];
LL ans[N];
int siz = 313; //sqrt(1E5)
int bkcol[400]; //bk[col]表示某一块的颜色，当且仅当块内颜色相同的时候为正，否则为-1.
int pos[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(bkcol,-1);
	scanf("%d %d",&n,&m);
	for ( int i = 1; i  <= n ; i++) 
	{
	    col[i] = i ;
	    pos[i] = (i-1)/siz;
	}

	ms(col,0);
	while (m--)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
		int l,r,x;
		scanf("%d %d",&l,&r,&x);

		bkcol[pos[l]]=-1;
		bkcol[pos[r]]=-1;
		if (pos[l]==pos[r])
		{
		    for ( int i = l ; i <=r  ; i++)
		    {
			ans[i] +=1LL*abs(x-col[i]);
			col[i] = x;
		    }
		    
		}
		else
		{
		    for ( int i = l ; i <= pos[l]*siz-1 ; i++)  //两端分别暴力更新
		    {
			ans[i] += 1LL*abs(x-col[i]);
			col[i] = x;
		    }

		    for ( int i = pos[r]*siz ; i<= r; i++)
		    {
			ans[i] +=1LL*abs(x-col[i]);
			col[i] = x;
		    }


		    //整块更新
		    

		    for ( int i = pos[l]+1 ; i<=pos[r]-1 ; i++)
		    {
			
			if (bk)
		    }
		}

		
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
