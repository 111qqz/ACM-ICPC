/* ***********************************************
Author :111qqz
Created Time :2016年03月30日 星期三 23时59分56秒
File Name :code/cf/#346/B.cpp
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
int p[N];
struct node
{
    string nam;
    int reg;
    int score;

    bool operator <(node b)const
    {
	if (reg<b.reg) return true;
	if (reg==b.reg&&score>b.score) return true;
	return false;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	for ( int i = 1; i <= n ; i++)
	{
	    cin>>a[i].nam>>a[i].reg>>a[i].score;
	}

	sort(a+1,a+n+1);
	
	int id = a[1].reg;
	int cnt = 0 ;
	cnt++;
	p[cnt] = id;
	for ( int i = 2 ; i <= n ; i++)
	{
	    if (a[i].reg!=id)
	    {
		cnt++;
		id = a[i].reg;
		p[cnt] = i;
	    }
	}


	for ( int i = 1 ; i <= cnt ; i++)
	{
	    if (a[p[i]].score==a[p[i]+1].score)
	    {
		if (p[i]+2==p[i+1])
		    cout<<a[p[i]].nam<<" "<<a[p[i]+1].nam<<endl;
		else cout<<"?"<<endl;
		continue;
	    }
	    if (a[p[i]+1].reg==a[p[i]+2].reg&&a[p[i]+1].score==a[p[i]+2].score)
	    {
		cout<<"?"<<endl;
		continue;
	    }

	    cout<<a[p[i]].nam<<" "<<a[p[i]+1].nam<<endl;
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
