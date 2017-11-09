/* ***********************************************
Author :111qqz
Created Time :2017年11月08日 星期三 18时50分18秒
File Name :nsubstr.cpp
************************************************ */

#include <bits/stdc++.h>
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
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
#define MAXALP 26

struct state
{
	int len, link, nxt[MAXALP];
};
const int N =3E5+7;
state st[N*2];
int Right[2*N]; //right[i]表示第i个状态的right集合大小
int sz, last,rt;
char s[N];
int cnt[2*N],a[2*N];//for radix sort
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
    ms(cnt,0);
}
void sa_extend(int c)
{
	int cur = ++sz;
	st[cur].len = st[last].len + 1;
	memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
	int p;
	for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
		st[p].nxt[c] = cur;
	if (p == -1) {
		st[cur].link = rt;
	} else {
		int q = st[p].nxt[c];
		if (st[p].len + 1 == st[q].len) {
			st[cur].link = q;
		} else {
			int clone = ++sz ;
			st[clone].len = st[p].len + 1;
			st[clone].link = st[q].link;
			memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
			for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
				st[p].nxt[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
int f[N]; //答案
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	sa_init();
	ms(f,0);
	ms(Right,0);
	scanf("%s",s+1);
	int len = strlen(s+1);
	for ( int i = 1 ; i <= len ; i++)
	{
	    Right[sz+1] = 1; //初始化right集合的大小
	    sa_extend(s[i]-'a');
	}
	//  a simple radix sort
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= len ; i++) cnt[i]+=cnt[i-1];
	for (int i = 1 ; i <= sz  ;i++) a[cnt[st[i].len]--] = i;
	//将len按照从大到小的顺序存入临时数组a，a[1]表示len最短的状态的标号。

	for ( int i = sz ; i >= 1 ; i--) Right[st[a[i]].link]+=Right[a[i]]; 
	//按照len从大到小的顺序更新right集合。
	//考虑一棵parent树，某个状态的right集合就是其就是其所有儿子节点的并集。
	//我们对parent树自底向上更新，由于儿子的len一定比父亲的len长，所以自底向上更新也就是按照len从大到小更新
	//
	//
	for ( int i = rt ; i <= sz ; i++) f[st[i].len] = max(f[st[i].len],Right[i]) ; 
	//长度为st[i].len的字符串出现了right[i]次
	
	for ( int i = len ; i >= 1 ; i--) f[i] = max(f[i],f[i+1]);
	//由于我们之前对于一个状态，只是更新了其表示的子串中长度最长的那个(也就是st[i].len)
	//但实际上每个状态表示的子串的长度是在区间[st[st[i].link]+1,st[i].len]
	//这个状态表示的每一个长度在该区间中的子串实际上都出现了right[i]次
	//我们只更新了最大，所以最后要倒序更新一下。
	//这样做的正确性在于，长度i-1的子串出现的次数一定大于等于长度为i的子串出现的次数。
	for ( int i = 1 ; i <= len ; i++) printf("%d\n",f[i]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
