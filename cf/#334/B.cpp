/* ***********************************************
Author :111qqz
Created Time :2015年12月02日 星期三 00时00分22秒
File Name :code/cf/#334/B.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n,k;
int s[N];
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(s,0);
	ms(a,0);  
	scanf("%d %d",&n,&k);
	for ( int i = 1 ; i <= n ; i++)
	     scanf("%d",&s[i]);
	int duoyu = k*2-n;
//	cout<<"duoyu:"<<duoyu<<endl;
	int nn = n - duoyu;
//	cout<<"nn:"<<nn<<endl;
	int ans = -1;
	for ( int i = nn+1 ; i <= n;i++) ans = max(ans,s[i]);
	for ( int i = 1 ; i <= nn/2 ; i++)
	{
	    ans = max(ans,s[i]+s[nn-i+1]);
//	    cout<<"i:"<<i<<" "<<s[i]<<endl;
//	    cout<<"nn-i+1"<<nn-i+1<<" s[nn-i+1]:"<<s[nn-i+1]<<endl;
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
