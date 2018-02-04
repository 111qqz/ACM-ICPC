/* ***********************************************
Author :111qqz
Created Time :2016年09月02日 星期五 15时56分14秒
File Name :code/cf/problem/623A.cpp
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
const int N=505;
int n,m;
bool conc[N][N];
int degree[N];
char ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(degree,0);
	ms(conc,false);
	ms(ans,0);
	cin>>n>>m;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    u--;
	    v--;
	    conc[u][v] = conc[v][u] = true;
	    degree[u]++;
	    degree[v]++;
	}
	
	for ( int i = 0 ; i < n ; i++) if (degree[i]==n-1) ans[i]='b'; // 字符串第一位为空的话。。。会输出空串。。。
	for ( int i = 0 ; i < n ; i++)
	{
	    if (!ans[i])
	    {
		ans[i] = 'a';
		for ( int j = 0 ; j < n ;j++)
		    if (conc[i][j]&&!ans[j]) ans[j]='a';
		break;
	    }

	}
	for ( int i = 0 ; i < n ; i++) if (!ans[i]) ans[i]='c';
	for ( int i = 0 ; i < n ; i++)
	    for ( int j = 0 ; j < n ; j++)
	    {
		if (i==j) continue;
		if (ans[i]=='b'||ans[j]=='b') continue;
		if (conc[i][j]&&(ans[i]!=ans[j]))
		{
		    puts("No");
		    return 0;
		}
		if (!conc[i][j]&&(ans[i]==ans[j]))
		{
		    puts("No");
		    return 0;
		}
	    }
	cout<<"Yes"<<endl;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
