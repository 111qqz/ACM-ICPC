/* ***********************************************
Author :111qqz
Created Time :2016年03月08日 星期二 22时32分24秒
File Name :code/class/algorithm/count.cpp
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
const int N=1E4+7;
const int M=1E6+7;
int n;
int a[N];

int cnt[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	memset(cnt,0,sizeof(cnt));

	cin>>n;
	int mx = - 1;
	for ( int i = 0 ; i <n ; i++)
	{
	    cin>>a[i];
	    mx = max(mx,a[i]);
	    cnt[a[i]]++;
	}

	for ( int i = 0 ; i < n;  i++) cout<<a[i]<<" ";

	cout<<endl;

	for ( int i = 1 ; i <= mx; i ++)
	{
	    if (cnt[i]==0) continue;
	    while (cnt[i]--)
	    {
		cout<<i<<" ";
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
