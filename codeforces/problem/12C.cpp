/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 15时30分54秒
File Name :code/cf/problem/12C.cpp
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
const int  N=105;
int n,m;
map<string,int>mp;
int a[N];
map<string,int>::iterator it;
vector<int >v;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	mp.clear();
	cin>>n>>m;
	for ( int i =  0; i < n ; i++) cin>>a[i];
	sort(a,a+n);

	for ( int i = 0 ; i < m ; i++)
	{
	    string tmp;
	    cin>>tmp;
	    if (!mp[tmp])
	    {
		mp[tmp] = 1;
	    }
	    else
	    {
		mp[tmp]++;
	    }
	}

	
	for ( it = mp.begin() ; it !=mp.end() ; it++)
	{
	    v.push_back(it->second);
	}
	int mi,mx;
	mi=mx=0;
	sort(v.rbegin(),v.rend());
	for ( int  i = 0 ; i < v.size() ; i++)
	{
	    mi +=a[i]*v[i];
//	    cout<<"v[i]:"<<v[i]<<endl;
	    mx +=a[n-1-i]*v[i];\
	    //cout<<"mi:"<<mi<<" mx:"<<mx<<endl;
	}
	cout<<mi<<" "<<mx<<endl;
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
