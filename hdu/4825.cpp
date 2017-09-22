/* ***********************************************
Author :111qqz
Created Time :2016年08月15日 星期一 20时03分05秒
File Name :code/hdu/4825.cpp
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
const int LEN = 32;
int n,m;
char str[35];
struct Trie
{
    struct Node
    {
	Node *nxt[2];
	int val;
	Node()
	{
	    for ( int i = 0 ; i < 2 ; i++) nxt[i]=NULL;
	    val = 0 ;
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
    void Insert(char *s,int num)
    {
	Node *u =root;
	int len = strlen(s);
//	cout<<" len :"<<len<<endl;
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'0';
	    if (u->nxt[v]==NULL) u->nxt[v] = new Node();
	    u = u->nxt[v];
	}
	u->val = num;
    }
    int Find(char *s)
    {
	Node *u = root;
	int len = strlen(s);
	for ( int i = 0 ; i < len ; i++)
	{
	    int x = s[i]-'0';
	    int y = !x;
	    if (u->nxt[y]==NULL)  //相反的方向有路就走相反的，没路就只能走一样的。
		u = u->nxt[x];
	    else u = u->nxt[y];
	}
	return u->val;
    }
}trie;
void bianshen( int x)
{
    for ( int i = LEN-1,j=0 ; i>=0 ; i--,j++) //高位补0，以及str[0]是最高位，str[LEN-1]是最低位
	str[i] =((x>>j)&1)+'0';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    trie.init();
	    printf("Case #%d:\n",++cas);
	    scanf("%d%d",&n,&m);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		scanf("%d",&x);
		bianshen(x);
		trie.Insert(str,x);		
	    }
	    while (m--)
	    {
		int x;
		scanf("%d",&x);
		bianshen(x);
		printf("%d\n",trie.Find(str));
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
