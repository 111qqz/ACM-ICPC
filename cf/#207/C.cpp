/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 20时24分58秒
File Name :code/cf/#207/C.cpp
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
const int N=3E5+7;
int n,m;
set<int>se;
set<int>::iterator it;
int ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	se.clear();
	for ( int i = 1 ; i <= n ; i++) se.insert(i);
	ms(ans,0);
	for ( int i = 0 ; i < m ; i++)
	{
	   // cout<<"assd"<<endl;
	    int l,r,x;
	    scanf("%d %d %d",&l,&r,&x);
	    it = se.lower_bound(l);
	    while (it!=se.end()&&*it<=r)
	    {
		int tmp = *it;
		it++;
		if (tmp!=x)
		{
		    ans[tmp] = x;
		    se.erase(tmp);
		}
	    }
	    
	    
	}
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
