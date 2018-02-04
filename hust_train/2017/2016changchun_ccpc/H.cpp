/* ***********************************************
Author :111qqz
Created Time :2017年10月16日 星期一 15时21分12秒
File Name :H.cpp
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
#define PB push_back
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
int getint() {
    int k = 0, fh = 1; char c = getchar();
    for(; c < '0' || c > '9'; c = getchar())
        if (c == '-') fh = -1;
    for(; c >= '0' && c <= '9'; c = getchar())
        k = k * 10 + c - '0';
    return k * fh;
}
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int n,m,p;
int a[N],b[N];
int nxt[N];

void getnxt( int n)
{
    int i = 0;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
        if (j==-1||b[i]==b[j]) nxt[++i]=++j;
    else j = nxt[j];
}
int ans;
void kmp(int st ,int n,int m)
{
    int i = st ;
    int j = 0 ;
    //getnxt(m);
    
    //for ( int i = 0 ; i < m ; i++) cout<<i<<" "<<nxt[i]<<endl;
    while (i<n)
    {
	//cout<<"i:"<<i<<" j:"<<j<<endl;
        if (j==-1||a[i]==b[j]) i+=p,j++;
        else j = nxt[j];
        if (j==m) ans++,j=nxt[j];
 
//        cout<<"n:"<<n<<" i:"<<i<<" j:"<<j<<endl;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	int cas = 0;
	cin>>T;
	while (T--)
	{
	    ans = 0 ;
	    //ms(nxt,0);
	    scanf("%d %d %d",&n,&m,&p);
	    for ( int i = 0 ; i < n  ; i ++) a[i] = getint();
	    for ( int i = 0 ; i < m ; i++)  b[i] = getint();
	    if (n<m)
	    {
		printf("Case #%d: 0\n",++cas);
		continue;
	    }
	    getnxt(m);
	    for ( int i = 0 ; i < p ; i++)
		kmp(i,n,m);
	    printf("Case #%d: %d\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
