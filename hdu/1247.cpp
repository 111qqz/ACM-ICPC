/* ***********************************************
Author :111qqz
Created Time :2016年08月16日 星期二 00时08分01秒
File Name :code/hdu/1247.cpp
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
const int N = 5E4+7;
char s[N][200];
int n ;
struct Trie
{
    struct Node
    {
	Node *nxt[26];
	bool ok; //标记单词的结尾
	Node()
	{
	    for ( int i = 0 ; i < 26 ; i++) nxt[i] = NULL;
	    ok = false;
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
	}
	u->ok = true;
    }

    bool  Find(char *s)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    if (u->nxt[v]==NULL) return 0;
	    u=u->nxt[v];
	}
	return u->ok;
    }


}trie;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	n = 0 ;
	trie.init();
	while (~scanf("%s",s[++n]))
	{
	    trie.Insert(s[n]);
	}
	n--;
	char a[200],b[200];
	for ( int i = 1 ; i <= n ; i++)
	{
	    int len = strlen(s[i]);
	   // cout<<i<<" s:"<<s[i]<<endl;
	    for ( int j = 1 ; j < len ; j++) //枚举切割的位置
	    {
		ms(a,0);
		ms(b,0);
		strncpy(a,s[i],j);
		strncpy(b,s[i]+j,len);
	//	cout<<"a:"<<a<<" b:"<<b<<endl;
		if (trie.Find(a)&&trie.Find(b))
		{
		    printf("%s\n",s[i]);
		    break;
		}

	    }
	}
	

	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
