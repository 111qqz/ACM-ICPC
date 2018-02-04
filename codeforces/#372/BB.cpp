/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 10:59:07 PM CST
File Name :code/cf/#372/BB.cpp
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
char st[N];
char ans[N];
int len;
set<int>se;
int vis[30];

void print( int l,int r)
{
    for ( int i = 0 ; i < l ; i++)
	ans[i] = st[i]=='?'?'A':st[i];
    for ( int i = l ; i <= r ; i++)
    {
	if (st[i]!='?') ans[i]=st[i];
	else for ( int j = 1 ; j <= 26 ; j++)
		if (vis[j]==0)
		{
		
		    ans[i] = char (j+64);
//		    cout<<"i:"<<i<<" ans[i]:"<<ans[i]<<endl;
		    vis[j]++;
		    break;
		}
    }
    for ( int i = r + 1 ; i < len ; i++)
	ans[i]= st[i]=='?'?'A':st[i];
    ans[len]='\0';
    cout<<ans<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>st;
	len = strlen(st);
	if (len<26)
	{
	    puts("-1");
	    return 0;
	}
	
	int cnt = 0 ;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    if (st[i]=='?')
	    {
		cnt++;
		continue;
	    }
	    int x = st[i]-'A'+1;

	    vis[x]++;
	    se.insert(x);
	}

	if (se.size()+cnt==26)
	{
	    print(0,25);
	    return 0;
	}

	for ( int i = 26 ; i < len ; i++)
	{
	    
	    if (st[i-26]=='?')
	    {
		cnt--;
	    }
	    else
	    {
		int x = st[i-26]-'A'+1;
		if (vis[x])
		{
		    vis[x]--;
		    if (vis[x]==0) se.erase(x);
		}
	    }

	    if (st[i]=='?')
	    {
		cnt++;
	    }
	    else
	    {
		int y = st[i]-'A'+1;
		vis[y]++;
		se.insert(y);
	    }

	    if (se.size()+cnt==26)
	    {
		print(i-25,i);
		return 0;
	    }

	}
	puts("-1");
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
