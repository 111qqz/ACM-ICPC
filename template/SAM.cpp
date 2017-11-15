/* ***********************************************
Author :111qqz
Created Time :2017年11月15日 星期三 19时06分15秒
File Name :SAM.cpp
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
const int N=5E5+7;
struct SAM
{
    #define MAXALP 30
    struct state
    {
	int len, link, nxt[MAXALP];
	int leftmost; //某个状态的right集合中r值最小的
	int rightmost;//某个状态的right集合的r的最大值
	int Right; //right集合大小
    };
    state st[N*2];
    char S[N];
    int sz, last,rt;
    LL tot_str; //子串总数   每个状态本质不同的子串数*出现的次数
    LL tot_unique_str; //本质不同的子串总数  st[v].len - st[st[v].link].len  (v属于1..sz)
    int cnt[2*N],rk[2*N];//for radix sort
    int idx(char c)
    {
	if (c>='a'&&c<='z') return c-'a';
	return c-'A'+26;
    }
    void init()
    {
	sz = 0;
	ms(st,0);
	last = rt = ++sz;
	st[1].len = 0;
	st[1].link=-1;
	st[1].rightmost=0;
	ms(st[1].nxt,-1);
    }
    void extend(int c,int head)
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
    void build()
    {
	init();
	for ( int i = 0,_len = strlen(S) ; i < _len ; i++)
	{
	    st[sz+1].Right = 1;
	    extend(idx(S[i]),i);
	}
    }
    void topo()
    {
	ms(cnt,0); 
	for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
	for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
	//rk[1]是len最小的状态的标号
	for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
    }
    void pre()  //跑拓扑序，预处理一些东西
    {
	tot_str = tot_unique_str = 0;
	for ( int i = sz ; i >= 2 ; i--)
	{
	    int v = rk[i];
	    int fa = st[v].link;
	    if (fa==-1) continue;
	    tot_str += 1LL*st[v].Right*(st[v].len-st[fa].len);
	    tot_unique_str += 1LL*(st[v].len-st[fa].len);
	    st[fa].rightmost = max(st[fa].rightmost,st[v].rightmost);
	    st[fa].Right += st[v].Right;
	}
    }
    void solve()
    {
	LL ans = 0 ;
	for ( int i = sz ; i >= 2 ; i--)
	{
	    int v = rk[i];
	    if (st[v].link==-1) continue;
	    ans = ans + 1LL * st[v].Right*(st[v].Right+1)/2 * (st[v].len-st[st[v].link].len);
	}
	printf("%lld\n",ans);
    }
    int LCS(char *s)
    {
	int ans = 0,len = 0 ;
	int p = rt;
	for ( int i = 0 ,_len = strlen(s) ; i < _len ; i++)
	{
	    int ID = s[i]-'a';
	    if (st[p].nxt[ID]!=-1) p = st[p].nxt[ID],len++;
	    else
	    {
		while (p!=-1&&st[p].nxt[ID]==-1) p = st[p].link;
		if (p==-1) p=rt,len=0;else len = st[p].len+1,p = st[p].nxt[ID];
	    }
	  //  printf("len:%d\n",len);
	    ans = max(ans,len);
	}
	return ans;
    }

    //把原串复制一遍到后面，然后构建后缀自动机。
    //从初始状态开始，每次走字典序最小的转移，走|S|之后得到的就是最小循环表示。
    //如果求的是最小后缀，就在原串后加入一个比字符集中所有字符的字典序都小的字符作为终止后，再添加一遍原串。
    int smallest_string()  //求一个串的最小循环表示，返回起始位置下标
    {
	int p = 1;
	int slen = strlen(S);
	for ( int i = 0 ; i < slen ; i++)
	{
	    bool flag = false;
	    for ( int j = 0 ; j < 26 ; j++) //找字典序最小的
		if (st[p].nxt[j])
		{
		    flag = true;
		    p = st[p].nxt[j];
		    break;
		}
	    if (!flag) break;
	}
	return st[p].len + 1 - slen;
    }
}A;
char B[N]; 
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while (T--)
    {
	cin>>A.S;
	A.build();
	int ans = A.smallest_string();
	cout<<ans<<endl;
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
 
 
 

