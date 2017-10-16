#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <cmath>
#include <stack>
#include <sstream>
#include <list>
#define debug() puts("++++");
#define gcd(a, b) __gcd(a, b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define freopenr freopen("in.txt", "r", stdin)
#define freopenw freopen("out.txt", "w", stdout)
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const double inf = 0x3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int maxn = 30000 + 10;
const int maxm = maxn * 100;
const int mod = 10;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int n, m;
int a[maxn], T[10005];
int lch[maxm], rch[maxm], c[maxm];
int tot;
map<int, int> mp;
 
int build(int l, int r){
  int rt = tot++;
  c[rt] = 0;
  if(l == r)  return rt;
  int m = (l + r )>> 1;
  lch[rt] = build(l, m);
  rch[rt] = build(m+1, r);
  return rt;
}
 
int update(int rt, int pos, int val){
  int newrt = tot++;
  int tmp = newrt;
  int l = 1, r = n;
  c[newrt] = c[rt] + val;
  while(l < r){
    int m = l + r >> 1;
    if(pos <= m){
      lch[newrt] = tot++;
      rch[newrt] = rch[rt];
      newrt = lch[newrt];
      rt = lch[rt];
      r = m;
    }
    else{
      rch[newrt] = tot++;
      lch[newrt] = lch[rt];
      newrt = rch[newrt];
      rt = rch[rt];
      l = m + 1;
    }
    c[newrt] = c[rt] + val;
  }
  return tmp;
}
 
int query(int rt, int pos){
  int l = 1, r = n;
  int ans = 0;
  while(pos < r){
    int m = l + r >> 1;
    if(pos <= m){
      rt = lch[rt];
      r = m;
    }
    else{
      l = m + 1;
      ans += c[lch[rt]];
      rt = rch[rt];
    }
  }
  return ans + c[rt];
}

int main()
{

    freopen("./in.txt","r",stdin);
    int cas = 0 ;
    int TT;
    cin>>TT;
    while (TT--)
    {
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; ++i)
	    scanf("%d", a+i);
	mp.clear();
	tot = 0;
	T[n+1] = build(1, n);
	for(int i = n; i; --i)
	{
	    if(mp.count(a[i])){
		int tmp = update(T[i+1], mp[a[i]], -1);
		T[i] = update(tmp, i, 1);
	    }
	    else T[i] = update(T[i+1], i, 1);
	    mp[a[i]] = i;
	}
	int lstans=0;
	printf("Case #%d: ",++cas);
	while(m--)
	{
	    int l, r;
	    scanf("%d %d", &l, &r);
	    l = (l+lstans)%n+1;
	    r = (r+lstans)%n+1;
	    //printf("l:%d r:%d\n",l,r);
	    int num = query(T[l],r);
	    num = ( num + 1)/2;
	    lstans = mp[a[r-num+1]];
	    printf("%d%c",lstans,m==0?'\n':' ');
	}
    }
    return 0;
}
