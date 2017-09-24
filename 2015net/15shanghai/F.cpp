/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 01:15:18 PM CST
File Name :code/15shanghai/F.cpp
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
const int N=1E3+7;
int n;
char st[N];
vector<int>ans[30];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    for ( int i = 0 ; i  <= 29 ; i++) ans[i].clear();
	    scanf("%s",st);
	    int len = strlen(st);
	    for ( int i = 0 ; i < len ; i ++)
	    {
		int v = st[i]-'a'+1;
		ans[v].push_back(i);
	    }

	    int res = inf;
	    for ( int i = 1 ; i <= 26 ; i++)
	    {
		int siz = ans[i].size();
		for  ( int j = 1 ; j < siz ; j++)
		{
		    int tmp = ans[i][j]-ans[i][j-1];
		    if (tmp<res) res = tmp;
		}
	    }
	    if (res==inf) res = -1;
	    printf("Case #%d: %d\n",++cas,res);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
