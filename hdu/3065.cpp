/* ***********************************************
Author :111qqz
Created Time :2016年08月18日 星期四 00时17分38秒
File Name :code/hdu/3065.cpp
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
const int sizTrie = 26;
map<int,int>mp;
char ill[1005][50];
struct Trie
{
    struct Node
    {
	Node *nxt[sizTrie];
	Node *fail;
	int cnt;
	int id;
	Node()
	{
	    for ( int i = 0 ; i < sizTrie; i++) nxt[i]=NULL;
	    cnt = 0 ;
	    id = 0 ;
	    fail = NULL;
	}
    };

    Node *root;
    void init()
    {
	root = new Node();
    }
    void Insert(char *s,int x)
    {
	int len = strlen(s);
	Node *u = root;
	for ( int i = 0 ; i < len ; i++ )
	{
	    int v = s[i]-'A';
	    if (u->nxt[v]==NULL) u->nxt[v] = new Node();
	    u = u->nxt[v];
	}
	u->cnt++;
	u->id = x;
//	cout<<"s:"<<s<<" cnt:"<< u->cnt <<endl;
    }
    void getFail()
    {
	root->fail = root;
	queue<Node*>Q;
	for ( int i = 0 ; i < sizTrie ; i++)
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
	    Node * cur = Q.front();
	    Q.pop();
	    for ( int i = 0 ; i < sizTrie ; i++)
	    {
		if (cur->nxt[i]==NULL)
		    cur->nxt[i] = cur->fail->nxt[i];
		else
		{
		    cur->nxt[i]->fail = cur->fail->nxt[i];
		    Q.push(cur->nxt[i]);
		}
	    }
	}
    }

	void Search(char *s)
	{
	    int len = strlen(s);
	    Node *u = root;
	    mp.clear();
	    for ( int i = 0 ; i < len ; i++)
	    {
		if (s[i]<'A'||s[i]>'Z')
		{
		    u = root;
		    continue;
		}
		int v = s[i]-'A';
		u = u->nxt[v];
		Node * tmp = u;
		while (tmp!=root)
		{
		    if (tmp->id)
		    mp[tmp->id]++;
		    tmp = tmp->fail;
		}
		
	    }

	    for (auto it = mp.begin() ; it!=mp.end() ; it++)
//		if (strcmp(ill[it->fst],"")!=0)
		printf("%s: %d\n",ill[it->fst],it->sec);

/*	    //sort(ans.begin(),ans.end());
	    int siz = ans.size();
	    cout<<"anszie:"<<ans.size()<<endl;
	    for ( int i = 0 ; i < siz;  i++)
	    {
		printf("%s: %d\n",ill[ans[i].fst],ans[i].sec);
	    }   */
	}
    
}ac;
const int N=2E6+7;
int n;
char str[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{   
	    ac.init();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%s",ill[i]);
		ac.Insert(ill[i],i);
	    }
	    ac.getFail();
	    scanf("%s",str);
	    //	cout<<"str:"<<str<<endl;
	    ac.Search(str);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
