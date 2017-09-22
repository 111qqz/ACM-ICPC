/* ***********************************************
Author :111qqz
Created Time :2016年08月16日 星期二 02时55分22秒
File Name :code/poj/2001.cpp
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
const int N=1E3+7;
char s[N][25];
int n;
struct Trie
{
    struct Node
    {
	Node *nxt[26];
	int cnt;
	Node()
	{
	    for ( int i = 0 ; i < 26;  i++) nxt[i] = NULL;
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
	    if (u->nxt[v]==NULL) u->nxt[v] = new Node();
	    u = u->nxt[v];
	    u->cnt++;
	}
    }
    string Find(char *s)
    {
	Node *u = root;
	string res="";
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    res = res + s[i];
	    u = u->nxt[v];
	    if (u->cnt==1) return res; //cnt为1表示应该就唯一了吧。。。
	}
    }
}trie;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	n = 0 ;
	trie.init();
	while (~scanf("%s",s[n++])); 
	n--;
	for ( int i = 0 ; i <n ; i++)
	{
	    //cout<<"i:"<<i<<" s[i]:"<<s[i]<<endl;
	    trie.Insert(s[i]);
	}
	for ( int i = 0 ; i < n ; i++)
	{
	    string ans = trie.Find(s[i]);
	    cout<<s[i]<<" "<<ans<<endl;
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
