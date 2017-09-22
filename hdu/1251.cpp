/* ***********************************************
Author :111qqz
Created Time :2016年08月14日 星期日 19时58分41秒
File Name :code/hdu/1251.cpp
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
char s[20];

struct Trie
{
    struct Node
    {
	Node *nxt[26];
	int cnt;
	Node()
	{
	    for ( int i = 0 ; i < 26;  i++) nxt[i]=NULL;
	    cnt = 0 ;
	}
    };
    Node *root;
    void init()
    {
	root = new Node();
    }
    Trie()
    {
	root = new Node();
    }
    void Insert(char *s)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    if (u->nxt[v]==NULL) u->nxt[v]=new Node();
	    u = u->nxt[v];
	    u->cnt++;
	}
    }
    int Find(char *s)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    if (u->nxt[v]==NULL) return 0;
	    u = u->nxt[v];
	}
	return u->cnt;
    }

}trie;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (gets(s))
	{
	    int len = strlen(s);
	    if (len==0) break;
	    trie.Insert(s);
	}
	while (gets(s))
	{
	    int ans = trie.Find(s);
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
