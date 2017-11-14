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
int Right[N],Left[N]; 
//right[i]表示以i结尾的最长回文串的长度
//left[i]表示以i开头的最长回文串的长度,需要反转母串构建PAM求得
void pam_init()
{
    ms(st,0);
    st[0].fail = st[1].fail = 1;
    st[1].len = -1;
    sz = 1;
}
void extend(char *S,int c,int pos,bool flag)  //忘记加*S这个参数了。。。以至于没有真正反着做orz
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
    if (flag)
    Right[pos]=st[now].len;
    else Left[n-pos-1]=st[now].len;
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
	for ( int i = 0 ; i < n; i++) extend(S,S[i]-'a',i,true),RS[n-i-1]=S[i];
	pam_init();
	for ( int i = 0 ; i < n; i++) extend(RS,RS[i]-'a',i,false);
	int ans = 0 ;
//	for ( int i = 0 ; i < n ; i++) printf("Right:%d Left:%d\n",Right[i],Left[i]);
	for ( int i = 0 ; i < n-1 ; i++) ans = max(ans,Right[i]+Left[i+1]); //枚举断点
	printf("%d\n",ans);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
