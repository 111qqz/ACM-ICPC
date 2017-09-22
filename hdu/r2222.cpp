/* ***********************************************
Author :111qqz
Created Time :2016年08月16日 星期二 15时26分42秒
File Name :code/hdu/r2222.cpp
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
struct Trie
{
    struct Node
    {
	Node *nxt[26];
	Node *fail;
	int cnt;
	Node()
	{
	    for ( int i = 0 ; i < 26 ; i++) nxt[i] = NULL;
	    cnt = 0 ;
	    fail=NULL;
	}
    };
    Node *root;
    void init()
    {
	root = new Node();
    }
    void Insert(char *s)
    {
	int len = strlen(s);
	Node *u = root;
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    if (u->nxt[v]==NULL) u->nxt[v] = new Node();
	    u = u->nxt[v];
	}
	u->cnt++;
    }
    void getFail()
    {
	root->fail = root;
	queue<Node*>Q;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    if (root->nxt[i]==NULL)
		root->nxt[i] = root;
	    else
	    {
		root->nxt[i]->fail = root;
		Q.push(root->nxt[i]);
	    }
	}
	while (!Q.empty())
	{
	    Node *cur = Q.front();
	    Q.pop();
	    for ( int i = 0 ; i < 26 ; i++)
		if (cur->nxt[i]==NULL)
		{
		    cur->nxt[i] = cur->fail->nxt[i];
		}
		else
		{
		    cur->nxt[i]->fail = cur->fail->nxt[i];
		    Q.push(cur->nxt[i]);
		}
	}
    }
    int Search(char *s)
    {
	int len = strlen(s);
	Node *u = root;
	int res = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    u = u->nxt[v];
	    Node *tmp = u;
	    while (tmp!=root)
	    {
		res = res + tmp->cnt;
		tmp->cnt = 0 ;
		tmp = tmp->fail;
	    }
	}
	return res;
    }
}ac;
char text[1000010];
int n ;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    ac.init();
	    for ( int i = 1 ; i <= n ; i ++)
	    {
		scanf("%s",text);
		ac.Insert(text);
	    }
	    ac.getFail();
	    scanf("%s",text);
	    printf("%d\n",ac.Search(text));
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
