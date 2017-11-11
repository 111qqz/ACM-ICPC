#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500010;
int a[N], tree[N * 30][2], tn;
LL val[N * 30][2], cnt[N * 30][2], num[35][2];
void init(int n) {
    tn = 0;
    memset(num, 0, sizeof num);
    for (int i = 0; i <= n * 30; i++)
    for (int j = 0; j < 2; j++) 
        tree[i][j] = val[i][j] = cnt[i][j] = 0;
}
void insertTrie(int x) {
    int p = 0;
    for (int i = 29; i >= 0; i--) {
        int y = (x >> i) & 1;
        num[i][y]++; //统计二进制第i位为y的数的个数
        val[p][y]++; //统计trie树上当前节点数的个数
        cnt[p][y] += num[i][y]; //
	//把此时插入的数看做a[i]，那么cnt[p][y]就是满足j<=i 的j的数目
	//因为之后要用到，所以要提前维护
        if (tree[p][y] == 0) tree[p][y] = ++tn;
        p = tree[p][y];
    }
}
LL getAns(int x) {  //插入的数是a[k]
    int p = 0; LL res = 0;
    for (int i = 29; i >= 0; i--) {
        int y = (x >> i) & 1;
        res += num[i][y^1] * val[p][y^1] - cnt[p][y^1];
	// 对于此时插入的a[k]的二进制第i位（从低往高）的数y,只有当a[i]和a[j]的第i位为1-y时，才会贡献答案。
	// num[i][y^1]为第i位为1-y的a[j]的个数（a[j]的其他位，包括比i高的位和比i低的位都不受限制
	// val[p][y^1]表示trie树上，从rt到p节点所表示的二进制位上，a[i]与a[k]一直相同，p的下一个节点a[i]与a[k]的二进制位不同 的 a[i]的个数
    
        p = tree[p][y]; if (p == 0) break;
    }
    return res;
}
void solve() {
    LL ans = 0;
    int n; scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        ans += getAns(a[i]);
        insertTrie(a[i]);
    }
    printf("%lld\n", ans);
}
int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}
