/* ***********************************************
Author :111qqz
Created Time :2016年04月15日 星期五 16时31分35秒
File Name :code/bzoj/1660.cpp
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
const int N=8E4+7;
int n;
int h[N];
int st[N];
int top = 0;
LL ans=0;
void update(int x)
{
    while (top&&h[x]>=st[top]) top--;
    ans+=top;
    st[++top] = h[x];
  //  for ( int i = 1 ; i <=top ; i++) cout<<st[i]<<" ";
  //  cout<<"ans:"<<ans<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&h[i]);
	for ( int i = 1 ; i <= n ; i++) update(i);
	
	printf("%lld\n",ans);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
