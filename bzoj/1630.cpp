/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 17时49分19秒
File Name :code/bzoj/1630.cpp
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
const int M=1E5+1007;
const int MOD=1E6;
int T,A,S,B;
int cnt[N];
int a[M],tmp[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(cnt,0);
	cin>>T>>A>>S>>B;
	for ( int i = 1 ; i <= A  ; i++)
	{
	    int x;
	    cin>>x;
	    cnt[x]++;
	}
	ms(a,0);
	ms(tmp,0);
	for ( int i = 0 ; i <= cnt[1]  ; i++)
	{
	    a[i] = 1;
	    tmp[i] = 0 ;
	}

	for ( int i = 2; i <= T ; i++)
	{
	    for ( int j = 0 ; j <= B ; j++)
	    {
		for ( int k = 0 ; k <= cnt[i] && j + k <= B ; k++)
		{
		    tmp[j+k] = (tmp[j+k] + a[j])%MOD;
		}
	    }

	    for (int j = 0 ; j <= B ; j++)
	    {
		a[j] = tmp[j];
		tmp[j] =  0;
	    }
	}
	int ans = 0 ;
	for ( int i = S ; i <= B ; i++)
	{
	    ans = (ans + a[i])%MOD;
	}

	cout<<ans<<endl;




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
