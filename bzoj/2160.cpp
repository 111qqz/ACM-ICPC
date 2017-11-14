/* ***********************************************
Author :111qqz
Created Time :2017年11月14日 星期二 19时05分14秒
File Name :2160.cpp
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
const LL mod = 19930726;
const int N=1E6+7;
LL k;
int n;
char S[N];
struct PAM
{
    int fail;
    LL cnt,len;
    int nxt[26];
}st[N];
int now,sz;
int Right[N],Left[N]; 
void pam_init()
{
    ms(st,0);
    st[0].fail = st[1].fail = 1;
    st[1].len = -1;
    sz = 1;
}
void extend(int c,int pos)  //忘记加*S这个参数了。。。以至于没有真正反着做orz
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
LL ksm(LL a,LL b)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = res * a % mod;
	b = b >> 1LL;
	a = a * a % mod;
    }
    return res;
}
pair<LL,LL>group[N];
LL solve()
{
   // puts("fuck");
    for ( int i = sz ; i >= 2 ; i--) st[st[i].fail].cnt += st[i].cnt; //这才是真正的cnt
    LL ret = 1;
    int tot = 0 ;
    LL sum = 0;
    for ( int i = 2 ; i <= sz ; i++) if (st[i].len%2==1)
    {
	group[++tot]=MP(st[i].len,st[i].cnt);//升序排列
	sum = sum + st[i].cnt;
    }
    if (sum<k) return -1;
    sort(group+1,group+tot+1); // 1.. sz-1
//    for ( int i = 1 ; i <= sz-1 ; i++) printf("[len:cnt]:[%d,%d]\n",group[i].fst,group[i].sec);
    int id = tot;
    while (k>0&&id>=1)
    {
//	printf("K:%lld id:%d\n",k,id);
	if (k>=group[id].sec) 
	{
	    k-=group[id].sec;
	    LL tmp = ksm(group[id].fst,group[id].sec);
	    ret = ret * tmp % mod;
	    id--;
	}else
	{
	    LL tmp = ksm(group[id].fst,k);
	    ret = ret * tmp % mod;
	    k = 0 ;
	    id--;
	}
    }
    return ret;
}	
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	scanf("%d %lld",&n,&k);
	cin>>S;
	pam_init();
	for ( int i = 0 ,_=strlen(S); i < _ ; i++) extend(S[i]-'a',i);
	LL ans = solve();
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
