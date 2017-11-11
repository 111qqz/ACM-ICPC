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
#define MAXALP 26
const int mod = 2012;
struct state
{
	int len, link, nxt[MAXALP];
};
const int N =1E5+7;
state st[N*2];
int sz, last,rt;
char s[N];
int cnt[2*N],rk[2*N];//for radix sort
int dp[2*N],maxlen[2*N];
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
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
void topo()
{
	ms(cnt,0); 
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
	for (int i = sz ; i >=1  ;i--) rk[cnt[st[i].len]--] = i;
}
char ST[N];
int main()
{
#ifndef  ONLINE_JUDGE 
    	freopen("./in.txt","r",stdin);
#endif

    int flag = 1;
    ms(maxlen,0x3f);
    while (scanf("%s",ST)!=EOF)
    {
//	cout<<"ST:"<<ST<<endl;
	if (flag)
	{
	    sa_init();
	    for (int i = 0,len = strlen(ST);  i < len ; i++)
	    {
		sa_extend(ST[i]-'a');
	    }
	    topo();
	    flag = 0 ;
	}
	else
	{
	//    ms(dp,0);
	    int now = rt,len = 0;
	    for ( int i = 0,_len = strlen(ST) ; i < _len ; i++)
	    {
		if (st[now].nxt[ST[i]-'a']!=-1)
		{
		    now = st[now].nxt[ST[i]-'a'];
		    len++;
		    dp[now] = max(dp[now],len);
		  //  printf("now:%d dp[now]:%d len: %d\n",now,dp[now],len);
		}
		else 
		{
		    while (now!=-1&&st[now].nxt[ST[i]-'a']==-1) now = st[now].link;
		    if (now==-1) now=rt,len=0;else len = st[now].len + 1,now=st[now].nxt[ST[i]-'a'],dp[now] = max(dp[now],len);
		}
	    }
//	    printf("sz:%d\n",sz);
	    for ( int i = sz ; i >= 1 ; i--)
	    {
		int v = rk[i];
		maxlen[v] = min(maxlen[v],dp[v]);
		dp[st[v].link] = max(dp[st[v].link],dp[v]);
		dp[v] = 0;
	//	int fa = st[v].link;
	//	if (fa!=-1) dp[fa] = min(st[fa].len,max(dp[fa],dp[v]));
	    }
	}

    }

	int ans = 0 ;
	for ( int i = 1 ; i <= sz ; i++) ans = max(ans,maxlen[i]);
	printf("%d\n",ans);
//	cout<<ans<<endl;
    


#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}

