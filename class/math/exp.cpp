/* ***********************************************
Author :111qqz
Created Time :Mon 17 Oct 2016 07:10:38 PM CST
File Name :exp.cpp
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
const int N=20;
int n,T;
int ti[N];//表示每个工作站还能工作多少时间的工序，初始为 T
set<int>work[N]; //工作站
bool vis[N]; //表示第i个工序是否已经被安排。
set<int>undo;//保存因为依赖关系不满足而暂时没有做的工序。
struct node
{
    int t;
    set<int>pre;
    int id;
    bool operator < ( node b)const
    {
	int siz1 = pre.size();
	int siz2 = b.pre.size();
	if (t==b.t) return siz1<siz2;// 对于时间相同的，优先选依赖关系少的。。。
	return t<b.t;
    }
}a[N];
vector< pi >nopre;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>T; //n道工序，一个工作站的时间不能超过T
	for ( int i = 1 ; i <=  n ; i++) ti[i] = T;
	cout<<"T:"<<T<<endl;
	ms(vis,false);
	for ( int i = 1 ; i <= n ; i++)
	{
	     cin>>a[i].t;
	     a[i].id = i ;
	     int x; //一道工序的前驱工序数量。
	     cin>>x;
	     if (x==0) nopre.push_back(make_pair(a[i].t,i));
	     a[i].pre.clear();
	     while (x--)
	     {
		 int y;
		 scanf("%d",&y);
		 a[i].pre.insert(y);
	     }
	}
	sort(a+1,a+n+1);
	sort(nopre.begin(),nopre.end());
	int siz = nopre.size();
	int r = siz-1;
	int cnt = 0 ;
	for ( int i = 0  ; i < siz ; i++)
	{
	    int u = nopre[i].sec;
	    int v = nopre[r].sec;
	    if (a[u].t+a[v].t<=T)
	    {
		cnt++;
		work[cnt].insert(u);
		work[cnt].insert(v);
		ti[cnt] -= nopre[i].fst + nopre[r].fst;
		vis[u] = true;
		vis[v] = true;
		r--;
	    }
	    if (i>=r) break;
	}
	//for ( int i = 1 ;i <=  n; i++) if (!vis[i]) printf("undo %d\n",i);	
//	for ( int i = 1 ; i <= n ; i++) cout<<"a[i].t:"<<a[i].t<<endl;
	int l  = 1;
	for ( int i = n ; i >= 1 ; i--)
	{
	    if (a[i].t+a[l].t>T)
	    {
		bool ok = true;
		for ( auto it = a[i].pre.begin() ; it !=a[i].pre.end() ; it++)
		{
		    int tmp = * it;
		    if (!vis[tmp])
		    {
			ok = false;
			break;
		    }
		}
		if (ok)
		{
		    cnt++;
		    work[cnt].insert(i);
		    ti[cnt]-=a[i].t;
		    vis[i] = true;
		}
		else
		{
		    undo.insert(i);
		}
		continue;
	    }
	    bool ok = true;
//	    cout<<"sad:"<<endl;
	    for (  auto it = a[i].pre.begin() ; it!= a[i].pre.end(); it++)
	    {
		int tmp = *it;
		if (!vis[tmp])
		{
		    ok = false;
		    break;
		}
	    }
	    if (!ok) continue;	
//	    cout<<"wwww"<<endl;
	    for ( auto it = a[l].pre.begin() ; it!=a[l].pre.end() ; it++)
	    {
		int tmp = * it;
		if (!vis[tmp])
		{
		    ok = false;
		    break;
		}
	    }
	    if (!ok) continue;
//	    cout<<"a[i].id"<<a[i].id<<" a[l].id:"<<a[l].id<<endl;
	    cnt ++;
	    work[cnt].insert(a[i].id);
	    work[cnt].insert(a[l].id);
	    ti[cnt]-=a[i].t;
	    ti[cnt]-=a[l].t;
	    vis[a[i].id] = true;
	    vis[a[l].id] = true;
	    l--;
	    if (i>=l) break;
	}
//	for ( int i = 1 ;i <=  n; i++) if (!vis[i]) printf("undo %d\n",i);
	for ( int i = 1 ; i <= n  ; i++)
	{
	    if (!vis[i]) undo.insert(a[i].id);
	}
	siz = undo.size();
	//cout<<"siz:"<<siz<<endl;
//	for ( int i = 1 ; i <= 3 ; i++) cout<<"ti[i]:"<<ti[i]<<endl;
	for ( auto it =  undo.begin() ;  it!=undo.end() ; it++)
	{
	    int tmp = *it;
	    int mx = inf;
	    int mxid = -1;
	    for ( int i = 1 ; i <= cnt ; i++ )
	    {
		int r = ti[i]-a[tmp].t;
//		cout<<i<<" "<<r<<endl;
		if (r<0) continue;
		if (r<mx)
		{
		    mx = r;
		    mxid = i;
		}
	    }
	    if (mxid==-1)
	    {
		cnt++;
		ti[cnt]-= a[tmp].t;
//		cout<<"tmp:"<<tmp<<" cnt:"<<cnt<<" ti[cnt]:"<<ti[cnt]<<" a[tmp].t:"<<a[tmp].t<<endl;
		vis[tmp] = true;
	    }
	}
	cout<<cnt<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
} 
