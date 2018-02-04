/* ***********************************************
Author :111qqz
Created Time :2016年02月10日 星期三 22时56分52秒
File Name :code/cf/edu7/C.cpp
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
const int N=2E5+7;
int n,m;
int a[N];

struct node
{
    int l,r,x;
    int id;
void PushUP(int rt) {
	tree[rt] = max(tree[rt<<1] , tree[rt<<1|1]);
}
void build(int l,int r,int rt) {
	if (l == r) {
		scanf("%d",&tree[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt) {
	if (l == r) {
		tree[rt] = sc;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p , sc , lson);
	else update(p , sc , rson);
	PushUP(rt);
}
int query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return tree[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) {
        int res= query(L , R , lson);
        ret = max(ret ,res);
	}
	if (R > m) {
       int res= query(L , R , rson);
       ret = max(ret ,res);
    }
	return ret;
}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
