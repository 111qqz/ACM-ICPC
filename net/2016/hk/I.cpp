#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define N 2020
#define M 400030
#define mod 100000007
#define LL long long


struct pt {
    int num[N], len[N], cnt[N], ch[N][26], fail[N], S[N];
    int tot, n, last;

    int creat(int l) {
        memset(ch[tot], 0, sizeof ch[tot]);
        cnt[tot] = num[tot] = 0;
        len[tot] = l;
        return tot++;
    }
    void init() {
        tot = 0;
        creat(0);
        creat(-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while(S[n-len[x]-1] != S[n]) {
            x = fail[x];
        }
        return x;
    }
    void add(int c) {
        S[++n] = c;
        int cur = get_fail(last);
        if(ch[cur][c] == 0) {
            int now = creat(len[cur] + 2);
            fail[now] = ch[get_fail(fail[cur])][c];
            ch[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = ch[cur][c];
        cnt[last]++;
    }
    void calc() {
        for(int i = tot - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
    }
}A;

char s[N];
int ans[N][N];

int n;
int readint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9'));
    int ret = c - 48;
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - 48;
    return ret;
}
int main() {
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for(int i = 1; i <= n; ++i) {
            A.init();
            for(int j = i; j <= n; ++j) {
                A.add(s[j] - 'a');
                ans[i][j] = A.tot;
            }
        }
        int q;
        scanf("%d", &q);
        while(q--) {
            int l, r;
            l = readint();
            r = readint();
            printf("%d\n", ans[l][r] - 2);
        }
    }
    return 0;
}
Close

