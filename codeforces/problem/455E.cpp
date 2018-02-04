/* ***********************************************
Author :111qqz
Created Time :Sun 25 Sep 2016 10:50:45 PM CST
File Name :code/cf/problem/455E.cpp
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
#define lson l,m,(rt<<1)+1
#define rson m+1,r,(rt<<1)+2
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int maxn = 1E5+7;
long double intersect(int k, int b, int kk, int bb) {
    return (long double)(b - bb) / (kk - k);
}

struct ConvexHull {
    int * k, * b;
    int len;
    ConvexHull() : k(0), b(0), len(0) {}
    void addLine(int kk, int bb) {
        if (len == 1 && k[len - 1] == kk) {
            bb = max(b[len - 1], bb);
            len = 0;
        }
        if (len <= 1) {
            k[len] = kk;
            b[len] = bb;
            len++;
            return;
        }
        while (len >= 2 && ((k[len - 1] == kk && b[len - 1] > bb) || (kk != k[len - 1] && intersect(k[len - 2], b[len - 2], k[len - 1], b[len - 1]) >= intersect(k[len - 1], b[len - 1], kk, bb)))) len--;
        while (len >= 1 && k[len - 1] == kk && b[len - 1] > bb) len--;
        if (len >= 1 && k[len - 1] == kk && b[len - 1] <= bb) return;
        k[len] = kk;
        b[len] = bb;
        len++;
    }
    int get(int idx, int x) {
        return k[idx] * x + b[idx];
    }
    bool f(int idx, int x) {
        return get(idx, x) >= get(idx + 1, x);
    }
    int getMin(int x) {
        int l = -1, r = len - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (f(mid, x)) l = mid;
            else r = mid;
        }
        return get(r, x);
    }
};

int n, q, a[maxn], s[maxn];
ConvexHull t[maxn * 4];

void mergeCHs(ConvexHull & res, ConvexHull & a, ConvexHull & b) {
    res.len = 0;
    res.k = new int[a.len + b.len];
    res.b = new int[a.len + b.len];
    int l = 0, r = 0;
    while (l + r != a.len + b.len)
        if (l == a.len) {
            res.addLine(b.k[r], b.b[r]);
            r++;
        }
        else if (r == b.len) {
            res.addLine(a.k[l], a.b[l]);
            l++;
        }
        else if (a.k[l] > b.k[r]) {
            res.addLine(a.k[l], a.b[l]);
            l++;
        }
        else {
            res.addLine(b.k[r], b.b[r]);
            r++;
        }
}

void PushUp( int rt)
{
    mergeCHs(t[rt],t[(rt<<1)+1],t[(rt<<1)+2]);
}
void build ( int l,int r,int rt)
{
    if (l==r)
    {
	t[rt].k = new int[1];
	t[rt].b = new int[1];
	t[rt].k[0] = a[l];
	t[rt].b[0] = a[l] * l - s[l];
	t[rt].len = 1;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
    
}
int query(int L,int R,int x,int l,int r,int rt)
{
    if (L<=l&&r<=R) return t[rt].getMin(x);
    int m = (l+r)>>1;
    int ret = inf;
    if (L<=m) ret = min(ret,query(L,R,x,lson));
    if (R>=m+1) ret = min(ret,query(L,R,x,rson));
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	s[0] = 0 ;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]),s[i] = s[i-1] + a[i];
	build(1,n,0);
	int q;
	scanf("%d",&q);
	while (q--)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    printf("%d\n",s[y] + query(y-x+1,y,x-y,1,n,0));
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
