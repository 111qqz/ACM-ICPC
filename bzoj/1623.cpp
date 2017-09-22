/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 02时26分34秒
File Name :code/bzoj/1623.cpp
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
const int N=5E4+7;
int n,m;
int s[N];
int D,L;
int num[N];  //num[i]表示第i个车道现在的有多少辆车
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m>>D>>L;
	int cnt = 0 ;
	int total = n ;
	for ( int i = 0;i  <  n ; i++)
	{
	    int x;
	    cin>>x;
	    if (x>=L)
	    {
		s[cnt++] = x;
	    }
	}
	int sad = n-cnt;
	n = cnt;
	sort(s,s+n);
	ms(num,0);
	for ( int i = 0 ; i < n ; i++)
	{
	    int sp;
	    sp = s[i]-num[i%m]*D;
	    if (sp>=L)
	    {
		num[i%m]++;
	    }
	    else
		sad++;
	}
	cout<<total-sad<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
