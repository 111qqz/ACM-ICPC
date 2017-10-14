/* ***********************************************
Author :111qqz
Created Time :2017年10月14日 星期六 13时42分28秒
File Name :J.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
const int N=1005;
struct Trie
{
    struct Node
    {
	Node *nxt[2];
	int val;
	int cnt;
	Node()
	{
	    for ( int i = 0 ;i < 2 ; i++) nxt[i]=NULL;
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
    void Insert( char *s, int num)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'0';
	    if (u->nxt[v]==NULL)  u->nxt[v] = new Node();
	    u = u->nxt[v];
	    u->cnt++;
	}
	u->val = num;
    }
    void Delete(char *s)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'0';
	    if (u->nxt[v]!=NULL)
	    {
		u=u->nxt[v];
		u->cnt--;
	    }
	}
    }
    int Find(char *s)
    {
	Node *u =root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int x = s[i]-'0';
	    int y = !x;
	    if (u->nxt[y]!=NULL&&u->nxt[y]->cnt>0)
		u = u->nxt[y];
	    else u = u->nxt[x];
	}
	cout<<"Find?"<<endl;
	return u->val;
    }
}trie;
int n;
int a[N];
char str[50];
const int LEN = 32;
void change( int x)
{
    for ( int i = LEN-1 ,j=0; i>=0 ; i--,j++)
	str[i] = ((x>>j)&1)+'0';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    trie.init();
	    for ( int i = 1; i <= n ; i++)
	    {
		scanf("%d",&a[i]);
		trie.Insert(str,a[i]);
	    }
	    int ans = 0 ;
	    for ( int i = 1 ; i <= n-1 ; i++)
	    {
		cout<<"i:"<<i<<endl;
		change(a[i]);
		cout<<"change !"<<endl;
		trie.Delete(str);
		for ( int j = i+1 ; j <= n ; j++)
		{
		    cout<<"j:"<<j<<endl;
		    change(a[j]);
		    cout<<" change:J"<<endl;
		    trie.Delete(str);
		    change(a[i]+a[j]);
		    cout<<"before find"<<endl;
		    int cur = trie.Find(str)^(a[i]+a[j]);
		    cout<<" cur:"<<cur<<endl;
		    ans = max(ans,cur);
		}
	    }
	    printf("%d\n",ans);
	}


		
	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
