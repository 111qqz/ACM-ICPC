/* ***********************************************
Author :111qqz
Created Time :2017年11月14日 星期二 01时01分03秒
File Name :2565.cpp
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
const int N=1E5+7;
struct PAM
{
    int fail,cnt,len;
    int nxt[26];
}st[N];
char S[N],RS[N];
int n,now,sz;
void pam_init()
{
    ms(st,0);
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
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif 
	scanf("%s",S);
	pam_init();
	n = strlen(S);
	vector <int>ans;
	for ( int i = 0 ; i < n; i++) extend(S[i]-'a',i),ans.PB(sz-1);
	//for ( int i = 2 ; i <= sz ; i++) printf("len:%d cnt:%d\n",st[i].len,st[i].cnt);
	int siz = ans.size();
	for ( int i = 0 ; i < siz ; i++) printf("%d%c",ans[i],i==siz-1?'\n':' ');
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
