#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;

#define MP make_pair
#define PB push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second

typedef long long LL;
typedef long double LD;
const int INF = 0x3f3f3f3f;

typedef pair<LL, LL> pii;

const int N = 2e5 + 10;
const int M = 30 * 2 * N;

int ls[M], rs[M], root[N], tot, data[M];
inline int new_node(int lst = 0) {
	ls[++ tot] = ls[lst];
	rs[tot] = rs[lst];
	data[tot] = data[lst];
	return tot;
}
void build(int l, int r, int &rt) {
	rt = new_node();
	if(l == r) return ;
	int m = (l + r) >> 1;
	build(l, m, ls[rt]);
	build(m + 1, r, rs[rt]);
}
void update(int pos, int val, int lst, int l, int r, int &rt) {
	rt = new_node(lst);
	data[rt] += val;
	if(l == r) return ;
	int m = (l + r) >> 1;
	if(pos <= m) update(pos, val, ls[lst], l, m, ls[rt]);
	else update(pos, val, rs[lst], m + 1, r, rs[rt]);
}
int query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R) return data[rt];
	int m = (l + r) >> 1, ret = 0;
	if(L <= m) ret += query(L, R, l, m, ls[rt]);
	if(R > m) ret += query(L, R, m + 1, r, rs[rt]);
	return ret;
}
int ask_kth(int k, int l, int r, int rt) {
	if(l == r) return l;
	int m = (l + r) >> 1;
	return data[ls[rt]] >= k ? ask_kth(k, l, m, ls[rt]) : ask_kth(k - data[ls[rt]], m + 1, r, rs[rt]);
}


int a[N], pre[N];
int main() {
	int T;
	int cas = 0;
	cin >> T;
	while (T--){
		int n, m;
		scanf("%d %d", &n, &m);
		memset(pre,-1,sizeof(pre));
		//memset(pre, -1, sizeof(pre[0]) * (n + 5));
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		tot = 0;
		build(1, n, root[n + 1]);
		for(int i = n; i >= 1; i --) {
			if(~ pre[a[i]]) update(pre[a[i]], -1, root[i + 1], 1, n, root[i]);
			update(i, 1, root[~pre[a[i]] ? i : i + 1], 1, n, root[i]);
			pre[a[i]] = i;
		}
		printf("Case #%d:", ++cas);
		int ans = 0;
		while(m --) {
			int l, r;
			scanf("%d %d", &l, &r);
			l = (l + ans) % n + 1;
			r = (r + ans) % n + 1;
			if(l > r) swap(l, r);
			int cnt = query(l, r, 1, n, root[l]);
			ans = ask_kth((cnt + 1) >> 1, 1, n, root[l]);
			printf(" %d", ans);
		}
		puts("");
	}
	
}

