/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 16时00分23秒
File Name :code/cf/#346/BB.cpp
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
int n;
int m;
int cnt[N];

struct node
{
    string nam;
    int s;
    bool operator <(node b)const
    {
	return s>b.s;
    }
};

vector<node>v[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	ms(cnt,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    string nam;
	    node tmp;
	    int x,y;
	    cin>>nam>>x>>y;
	    tmp.nam = nam;
	    tmp.s = y;
	    v[x].push_back(tmp);
	}

	for ( int i = 1 ; i <= m ; i++)   //终点是第二个和第三个不能相等，和第一个没什么关系...
	{				    //就算前两个相等，只要第二个不和第三个相等，那也有唯一解。
	    sort(v[i].begin(),v[i].end());

	    if (v[i].size()==2)
	    {
		cout<<v[i][0].nam<<" "<<v[i][1].nam<<endl;
		continue;
	    }
	    if (v[i][1].s==v[i][2].s)
	    {
		puts("?");
		continue;
	    }
	    cout<<v[i][0].nam<<" "<<v[i][1].nam<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
