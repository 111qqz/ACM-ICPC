/* ***********************************************
Author :111qqz
Created Time :2016年07月30日 星期六 16时20分55秒
File Name :code/learn/sa.cpp
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
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	string s;
	map<string,int> m;
	vector<string>v;
	cin>>s;
	int len = s.length();
	for ( int i = 0 ; i < len ; i++)
	{
	    string tmp = s.substr(i,len);
	    cout<<tmp<<endl;
	    m[tmp] = i;
	    v.push_back(tmp);
	}

	sort(v.begin(),v.end());
	cout<<"****************after sorted*********"<<endl;
	for ( int i = 0 ; i < len ; i++)
              cout<<m[v[i]]<<":"<<v[i]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
