/* ***********************************************
Author :111qqz
Created Time :2017年11月14日 星期二 00时13分44秒
File Name :103.cpp
************************************************ */

#include <bits/stdc++.h>
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
using namespace std;
const int N=3E5+7;
struct PAM
{
    int fail,cnt,len;
    int nxt[26];
}st[N];
char S[N];
int n,now,sz;
void pam_init()
{
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
    st[now].cnt++;
}
int main()
{
	scanf("%s",S);
	pam_init();
	for ( int i = 0 ,_=strlen(S); i < _ ; i++)
	    extend(S[i]-'a',i);
	LL ans = 0 ;
	for ( int i = sz ; i >= 1 ; i--)
	{
	    st[st[i].fail].cnt += st[i].cnt;
	    ans = max(ans,1LL*st[i].len*st[i].cnt);
	}
	cout<<ans<<endl;
    return 0;
}
