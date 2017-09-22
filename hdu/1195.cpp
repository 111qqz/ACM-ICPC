/*************************************************************************
	> File Name: code/hdu/1195.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月02日 星期五 14时42分21秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define yn hez111qqz
#define j1 cute111qqz
using namespace std;
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int x,y;
bool vis[10005];
struct Q
{
    int g,s,b,q;
    int d;
    
}s,tar;

int add( int x)
{
    int res = 0 ;
    res = (x+1);
    if (res == 10) res = 1;
    return res;
}
int minu( int x)
{
    int res = 0 ;
    res = (x-1);
    if (res==0) res =  9;
    return res;
}

int get(Q a)
{
    int res = 0 ;
    res = a.q*1000+a.b*100+a.s*10+a.g;
    return res;
}

void bfs()
{
    queue<Q>q;
    q.push(s);
    
    while (!q.empty())
    {
	
	Q pre = q.front();q.pop();
//	cout<<get(pre)<<" "<<pre.d<<endl;
	if (get(pre)==y)
	{
	    printf("%d\n",pre.d);
	 //   cout<<"aaahhh"<<endl;
	    return;
	}
	Q nxt = pre;
	nxt.d = pre.d + 1;

	nxt.g = add(pre.g);
	if (!vis[get(nxt)])
	{
	    vis[get(nxt)] = true;
	   // nxt.d = pre.d  +1;
	    q.push(nxt);
	}

	nxt.g = minu(pre.g);
	if (!vis[get(nxt)])
	{
	   // nxt.d = pre.d  +1;
	    vis[get(nxt)] =true;
	    q.push(nxt);
	}
        
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.s = add(pre.s);	
	if (!vis[get(nxt)])
	{
	   // nxt.d = pre.d  +1;
	    vis[get(nxt)]=true;
	    q.push(nxt);
	}

	nxt.s = minu(pre.s);
	if (!vis[get(nxt)])
	{
	//    nxt.d = pre.d  +1;
	    vis[get(nxt)] =true;
	    q.push(nxt);
	}
	
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.b =add(pre.b);
	if (!vis[get(nxt)])
	{
	  //  nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}

	nxt.b =minu(pre.b);
	if (!vis[get(nxt)])
	{
	    //nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}
	
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.q =add(pre.q);
	if (!vis[get(nxt)])
	{
	//    nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}

	nxt.q = minu(pre.q);
	if (!vis[get(nxt)])
	{
	  //  nxt.d = pre.d  +1;
	    vis[get(nxt)]= true;
	    q.push(nxt);
	}
	
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.g = pre.s;
	nxt.s = pre.g;
	if (!vis[get(nxt)])
	{
	//    nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}
	
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.s = pre.b;
	nxt.b = pre.s;
	if (!vis[get(nxt)])
	{
	  //  nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}
	
	nxt = pre;
	nxt.d = pre.d+1;
	nxt.b = pre.q;
	nxt.q = pre.b;
	if (!vis[get(nxt)])
	{
	   // nxt.d = pre.d  +1;
	    vis[get(nxt)] = true;
	    q.push(nxt);
	}	
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    scanf("%d",&T);
    while (T--)
    {
	memset(vis,false,sizeof(vis));
	scanf("%d %d",&x,&y);
	s.g = x %10;
	s.s = x%100/10;
	s.b = x/100%10;
	s.q = x/1000;
	s.d = 0 ;
	vis[x] = true;
	bfs();

    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
