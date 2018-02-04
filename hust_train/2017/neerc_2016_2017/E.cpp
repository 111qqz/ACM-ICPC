/* ***********************************************
Author :111qqz
Created Time :2017年10月03日 星期二 12时06分38秒
File Name :E.cpp
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
#define PB push_back
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
string st;
vector< pair<char,int> >vec;
int l;
int n,m;
string maze[N];
//去掉  l,r,u,d之外的字母
void pr( vector< pair<char,int> > V)
{
    int siz = V.size();
    for ( int i = 0 ; i < siz ; i++) printf("%c %d\n",vec[i].fst,vec[i].sec);
}
void solve(string st)
{
    cout<<"st:"<<st<<endl;
    int len = st.length();
    for ( int i = 0 ; i < len ; i++)
    {
	if (st[i]=='u'||st[i]=='d'||st[i]=='l'||st[i]=='r') vec.PB(MP(st[i],i+1));
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	scanf("%d\n",&l);
	getline(cin,st);
	cout<<"st:"<<st<<endl;
	solve(st);
	scanf("%d%d",&n,&m);
	for ( int i = 0 ; i < n ; i++) cin>>maze[i];
	pr(vec);
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
   #endif
    return 0;
}
