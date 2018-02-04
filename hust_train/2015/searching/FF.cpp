#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>

typedef long long LL;

using namespace std;
// head
bool prime[10005];
void getPrime() {
    for (int i = 2; i <= 10000; i++) {
		if (!prime[i]) {
			for (int j = 2; j*i <= 10000; j++) {
				prime[i*j] = true;
			}
		}
    }
}
int dis[10005];
int num[4];
void sett(int x) {
	for (int i = 3; i > -1; i--) {
		num[i] = x % 10;
		x /= 10;
	}
}
int get() {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		res *= 10;
		res += num[i];
	}
	return res;
}
void bfs(int x) {
	queue<int> q;
	dis[x] = 0;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		sett(x);
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				if (num[i]++ == 9) {
					num[i] = 0;
				}
				int nxt = get();
				if (nxt >= 1000 && !prime[nxt] && dis[nxt] == -1) {
					dis[nxt] = dis[x]+1;
					q.push(nxt);
				}
			}
		}
	}
}
int main()
{
	getPrime();
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
        memset(dis, -1, sizeof dis);
        bfs(a);
        if (dis[b] == -1) {
			puts("Impossible");
        } else {
			printf("%d\n", dis[b]);
        }
	}
	return 0;
}

