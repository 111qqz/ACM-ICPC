/* ***********************************************
Author :111qqz
Created Time :2016年03月22日 星期二 18时56分04秒
File Name :code/cf/problem/653A.cpp
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
int n;
int t[100];
int a[100];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 0 ; i< n ; i++) cin>>a[i];
	sort(a,a+n);
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (a[i]==a[i-1]) continue;
	    t[++cnt] = a[i-1];
	}
	sort(t+1,t+cnt+1);

//	cout<<"cnt:"<<cnt<<endl;
//	for ( int i =1 ; i <= cnt ;i++) cout<<t[i]<<endl;
	for ( int i = 1 ; i <= cnt-2 ; i++)
	{
	    if (t[i+2]-t[i]<=2)
	    {
		puts("YES");
		return 0;
	    }
	}
    
	puts("NO");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
