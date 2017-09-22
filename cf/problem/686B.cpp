/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 06:57:55 PM CST
File Name :code/cf/problem/686B.cpp
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
const int N=105;
vector< pi >ans;
int n;
int a[N];
void print()
{
    for ( int i = 1 ; i <= n ; i++) printf("%d ",a[i]);
    printf("\n");
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n;  i++) cin>>a[i];

	bool flag = true;
	while (flag)
	{
	    flag = false;
	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		int j = i;
		bool SWAP = false;
		while (a[j]>a[j+1]&&j+1<=n)
		{
		    swap(a[j],a[j+1]);
		    flag = true;
		    SWAP = true;
		    j+=2;
		}
		if (!SWAP) continue;
		j-=2;
		ans.push_back(make_pair(i,j+1));
	    }
	}

	int siz = ans.size();
	for ( int i = 0 ; i < siz; i++) printf("%d %d\n",ans[i].fst,ans[i].sec);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
