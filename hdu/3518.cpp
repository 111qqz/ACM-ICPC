/* ***********************************************
Author :111qqz
Created Time :2017年11月08日 星期三 18时50分18秒
File Name :4436.cpp
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
#define MAXALP 30
const int mod = 2012;
struct state
{
	int len, link, nxt[MAXALP];
	int leftmost; //由于要求出现位置最小的，所以维护某个状态的right集合中r值最小的
	int rightmost;
};
const int N =1E3+7;
state st[N*2];
int sz, last,rt;
char s[N];
int cnt[2*N],rk[2*N];//for radix sort
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    st[1].rightmost=0;
    ms(st[1].nxt,-1);
}
void sa_extend(int c,int head)
{
	int cur = ++sz;
	st[cur].len = st[last].len + 1;
	st[cur].leftmost = st[cur].rightmost = head;
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
			st[clone].leftmost = st[q].leftmost;
			st[clone].rightmost = st[q].rightmost;
			for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
				st[p].nxt[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
void topo()
{
	ms(cnt,0); 
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
	for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
}
char S[N];
int main()
{
#ifndef  ONLINE_JUDGE 
    	freopen("./in.txt","r",stdin);
#endif

	while (~scanf("%s",S))
	{
	    if (S[0]=='#') break;
	    sa_init();
	    for ( int i = 0,len = strlen(S) ; i < len ; i++)
	    {
		sa_extend(S[i]-'a',i);
	    }
	    
	    topo();
	    for ( int i = sz ; i >=1 ; i--)
	    {
		int v = rk[i];
		int fa = st[v].link;
		st[fa].rightmost = max(st[fa].rightmost,st[v].rightmost);
//		printf("len:%d rightmost %d leftmost:%d\n",st[i].len,st[i].rightmost,st[i].leftmost);
	    } 
	    
	    LL ans = 0 ;
	    for ( int i = 1 ; i <= sz ; i++) if (st[i].link!=-1&&st[i].rightmost-st[i].leftmost>st[st[i].link].len)
		    ans += min(st[i].len,st[i].rightmost-st[i].leftmost)-st[st[i].link].len;
	    printf("%lld\n",ans);
	}



#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}

