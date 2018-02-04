/* ***********************************************
Author :111qqz
Created Time :2015年12月26日 星期六 00时14分09秒
File Name :code/cf/edu4/D.cpp
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
const int N=1E6+7;
int n ,k;

vector< pi> v,ans;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>k;

	for ( int i =1  ;i <= n ; i++)
	{
	    int s,e;
	    scanf("%d %d",&s,&e);
	    v.push_back(MP(s,-1));
	    v.push_back(MP(e,1));
	}

	sort(v.begin(),v.end());

	n = v.size();
	
	int cnt = 0 ;
	pi tmp;
	for ( int i = 0 ; i < n ; i++)
	{
	    if (v[i].sec==-1)
	    {
		cnt++;
		if (cnt==k)
		{
		    tmp.fst = v[i].fst;
		}
	    }
	    else
	    {
		if (cnt==k)
		{
		    tmp.sec = v[i].fst;
		    ans.push_back(tmp);
		}
		cnt--;
	    }
	}
	n = ans.size();
	printf("%d\n",n);
	for ( int i = 0 ; i < n ; i++)
	{
	    printf("%d %d\n",ans[i].fst,ans[i].sec);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
