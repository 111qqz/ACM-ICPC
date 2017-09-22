/* ***********************************************
Author :111qqz
Created Time :2016年08月10日 星期三 21时05分52秒
File Name :code/poj/2752.cpp
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
const int N=4E6+7;
int n;
string a;
int nxt[N];
void getnxt( int n)
{
    int i = 0 ;
    int j = -1 ;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||a[i]==a[j]) nxt[++i]=++j;
	else j = nxt[j];
}
void print( int x)
{
    if (nxt[x]!=-1)
    {
	print(nxt[x]);
	printf("%d ",x);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	ios::sync_with_stdio(false);
	while (cin>>a)
	{
	    int len = a.length();
	    getnxt(len);
	  //  for ( int i = 0 ; i < len ; i++) cout<<i<<" nxt[i]:"<<nxt[i]<<endl;
	    print(nxt[len]);
	    printf("%d\n",len);
	
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
