/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 02时10分20秒
File Name :code/bzoj/1622.cpp
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
string cow[N];
string eng[105];
int n,m;

string  aha ( string x)
{
    int len = x.length();
    for ( int i = 0 ; i < len ; i++)
    {
	if (x[i]>='A'&&x[i]<='Z') x[i] = char(x[i]+32);
    }
    return x;
}

bool ok (string x,string y)
{
  //  cout<<"x:"<<x<<" y:"<<y<<endl;
    int lx = x.length();
    int ly = y.length();
    int j = 0;
    for ( int i = 0 ; i < lx ; i++)
    {
	if (x[i]==y[j]) j++;
	if (j>=ly) return true;
    }
    return false;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>cow[i],cow[i]=aha(cow[i]);
	for ( int i = 1 ; i <= m ; i++) cin>>eng[i],eng[i]=aha(eng[i]);


	for ( int i = 1 ; i <= n ; i++)
	{

	    int ans =  0;
	    for ( int j = 1 ; j <= m ; j++)
	    {
		if (ok(cow[i],eng[j])) ans++;
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
