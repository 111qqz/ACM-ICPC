/* ***********************************************
Author :111qqz
Created Time :2016年08月10日 星期三 21时26分31秒
File Name :code/poj/3461.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
string a,b;
int nxt[N];
int ans;
void getnxt( int n)
{
    int i = 0 ;
    int j = -1;
    nxt[0] = - 1;
    while (i<n)
	if (j==-1||b[i]==b[j]) nxt[++i]=++j;
	else j = nxt[j];
}
void kmp( int n,int m)
{
    int i = 0 ;
    int j = 0 ;
    getnxt(m);
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];

	if (j==m) ans++,j=nxt[j];
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>a>>b;
	    swap(a,b);
	    int la = a.length();
	    int lb = b.length();
	    ans = 0;
	    kmp(la,lb);
	    cout<<ans<<endl;

	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
