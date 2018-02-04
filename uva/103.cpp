#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
#define ri register int
using namespace std;
#define MAXALP 30
#define ms(a,x) memset(a,x,sizeof(a)) 
const int N = 3E5+7;
struct PAM
{
    int cnt,len,fail;
    int nxt[MAXALP];
}st[N];
int n, m, sz , last, cur;
char s[N];
inline int new_node(int x)
{
	st[sz].len = x; st[sz].cnt = 0;
	ms(st[sz].nxt,0);
	return sz++;
}
inline int get_fail(int x, int n)
{
	while(s[n-st[x].len-1] != s[n]) x = st[x].fail;
	return x;
}
inline void pam_init()
{
	sz = 0 ;
	new_node(0);
	new_node(-1);
	st[0].fail = 1;
	ms(st[0].nxt,0);
	last = 0;
}
void pam_insert( int c,int head)
{
    cur = get_fail(last,head);
    if (!st[cur].nxt[c])
    {
	int nw = new_node(st[cur].len+2);
	st[nw].fail = st[get_fail(st[cur].fail,head)].nxt[c];
	st[cur].nxt[c] = nw;
    }
    last = st[cur].nxt[c];
    st[last].cnt++;
}
int main()
{
	scanf("%s",s);
	n = strlen(s);
	pam_init();
	for(int i=0;i<n;i++) pam_insert(s[i]-'a',i);
	for(int i=sz-1;i>=0;i--) st[st[i].fail].cnt += st[i].cnt;
	LL ans = 0;
	for(int i=2;i<sz;i++) ans = max(ans, 1LL*st[i].len*st[i].cnt);
	cout<<ans<<endl;
	return 0;
}
