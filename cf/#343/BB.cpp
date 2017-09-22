/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 01时02分42秒
File Name :code/cf/#343/BB.cpp
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
const int N=5E3+7;
int n;
int cnt[3][400];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(cnt,0);
	scanf("%d",&n);
	string sx;
	int sex;
	for ( int i  = 1 ; i <= n ;i++)
	{
	    cin>>sx;
	    
	    if (sx=="M")
	    {
		sex = 1;
	    }
	    else
	    {
		sex = 0 ;
	    }
	    int x,y;
	    scanf("%d%d",&x,&y);
	    for ( int j = x; j <= y ; j++)
	    {
		cnt[sex][j]++;
	    }
	}

	for ( int i = 1 ; i <=366 ; i++) cout<<cnt[0][i]<<" "<<cnt[1][i]<<endl;

	int ans = 0 ;
	for ( int i = 1 ; i <=366 ; i++)
	{
	 //   cout<<"cnt[1][i]:"<<cnt[1][i]<<" "<<cnt[0][i]<<endl;
	    if (cnt[1][i]==cnt[0][i]&&2*cnt[1][i]>=ans)
	    {
		ans = 2*cnt[1][i];
	    }
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
