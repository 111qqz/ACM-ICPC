/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 06:35:39 PM CST
File Name :code/cf/problem/379B.cpp
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
const int N=305;
int n;
int a[N];
int fst;
vector<char>ans;
int cnt,sum;
void forward()
{
    for ( int i = fst ; i <= n ; i++)
    {
	if (a[i])
	{
	    a[i]--;
	    ans.push_back('P');
	    cnt++;
	}
	if (i<n)
	ans.push_back('R');
	else if ( cnt<sum ) ans.push_back('L');
    }
    fst = n-1;
}
void backward()
{
    for ( int i = fst ; i >= 1 ; i--)
    {
	if (a[i])
	{
	    a[i]--;
	    ans.push_back('P');
	    cnt++;
	}
	if (i>1)
	    ans.push_back('L');
	else if (cnt<sum) ans.push_back('R');
    }
    fst = 2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	sum = 0 ;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i],sum+=a[i];

	fst = 1;
	cnt = 0 ;
	while (cnt< sum)
	{
	    forward();
	    if (cnt==sum) break;
	    backward();
	}
	int siz = ans.size();
	for ( int i = 0 ; i < siz; i ++) printf("%c",ans[i]);
	printf("\n");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
