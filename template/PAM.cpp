/* ***********************************************
Author :111qqz
Created Time :2017年11月15日 星期三 20时31分58秒
File Name :PAM.cpp
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
struct PAM
{
    //cnt表示某个节点的回文串的数量
    //len表示的是该状态所表示的回文串的长度
    //PAM有２个根，分别为状态０和状态１
    //初２个根外，其余每个状态表示一个本质不同的回文串,总数为sz-1
    struct state
    {
	int fail,cnt,len;
	int nxt[26];
    }st[N];
    char S[N],RS[N];
    int n,now,sz;
    int Right[N];//Right[i]表示以i结尾的最长回文串的长度
    int Left[N]; //Left[i]表示以i开头的最长回文串的长度...只需要倒序构建PAM就行了
    void init()
    {
	ms(st,0);
	now = 0 ;
	st[0].fail = st[1].fail = 1;
	st[1].len = -1;
	sz = 1;
    }
    void extend(int c,int pos)  
    {
	int p = now;
	while (S[pos-st[p].len-1]!=S[pos]) p = st[p].fail;
	if (!st[p].nxt[c]){
	    int np=++sz,q=st[p].fail;
	    st[np].len=st[p].len+2;
	    while (S[pos-st[q].len-1]!=S[pos]) q=st[q].fail;
	    st[np].fail=st[q].nxt[c];
	    st[p].nxt[c] = np;
	}
	now=st[p].nxt[c];
	Right[pos] = st[now].len;
	st[now].cnt++;
    }
    void Cnt() //构建之后跑cnt得到的才是真正的cnt
    {
	for ( int i = sz ; i >= 2;  i--) st[st[i].fail].cnt += st[i].cnt;
    }
    void build ()
    {
	init();
	int len = strlen(S+1);
	for ( int i = 1 ; i <= len ; i++) extend(S[i]-'a',i);
    }
}A,B;
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
