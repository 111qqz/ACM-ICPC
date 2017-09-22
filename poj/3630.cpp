/* ***********************************************
Author :111qqz
Created Time :2016年08月16日 星期二 00时46分23秒
File Name :code/poj/3630.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ctime>
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
int n;
char s[N][12];
int tot;
struct Trie
{
    int nxt[10];
    int cnt;
    bool flag;

    void init()
    {
	ms(nxt,0);
	cnt = 0;
	flag = false;
    }
}trie[N];
int add()
{
    memset(&trie[tot],0,sizeof(Trie));
    return tot++;
}
void Insert(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'0';
	if (!trie[rt].nxt[v]) trie[rt].nxt[v] = add();
        rt = trie[rt].nxt[v];
	trie[rt].cnt++;
    }
    trie[rt].flag = true;
}
void Delete(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'0';
	if (trie[rt].nxt[v])
	{
	    rt = trie[rt].nxt[v];
	    trie[rt].cnt--;
	}
    }
}
bool Find(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ;i++)
    {
	int v = s[i]-'0';
	if (!trie[rt].nxt[v]||trie[trie[rt].nxt[v]].cnt==0) return false;
	rt = trie[rt].nxt[v];
    }
//    if (trie[rt].flag) return true;
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T ; 
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    tot = 1;
	    trie[0].init();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%s",s[i]);
	//	cout<<"s[i]:"<<s[i]<<endl;
		Insert(s[i]);
	    }
	    bool ok = true;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		Delete(s[i]);
		if (Find(s[i]))
		{
		    ok = false;
		    break;
		}
		Insert(s[i]);
	    }
	    if (ok)
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
