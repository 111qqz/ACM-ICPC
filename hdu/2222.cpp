/* ***********************************************
Author :111qqz
Created Time :2016年08月16日 星期二 06时00分48秒
File Name :code/hdu/2222.cpp
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
const int N = 5E5+7;
int n;
struct Trie
{
    int nxt[N][26],fail[N],end[N];
    int root,L;
    int newnode()
    {
	for ( int i = 0 ; i < 26 ; i++) nxt[L][i]=-1;
	end[L++] = 0 ;
	return L-1;
    }
    void init()
    {
	L = 0 ;
	root = newnode();
    }
    void Insert(char *s)
    {
	int len = strlen(s);
	int u = root;
	for ( int i = 0 ; i < len ; i++)
	{
	    int v = s[i]-'a';
	    if (nxt[u][v]==-1)
		nxt[u][v] = newnode();
	    u = nxt[u][v];
	}
	end[u]++;
    }
    void Getfail()
    {
	queue<int>Q;
	fail[root] = root;
	for ( int i = 0 ; i < 26 ; i++)
	    if (nxt[root][i]==-1)
		nxt[root][i] = root;
	    else 
	    {
		fail[nxt[root][i]] = root;
		Q.push(nxt[root][i]);
	    }
	while (!Q.empty())
	{
	    int cur = Q.front();
//	    cout<<"cur:"<<cur<<endl;
	    Q.pop();
	    for ( int i = 0 ; i < 26 ; i++)
		if (nxt[cur][i]==-1)
		    nxt[cur][i] = nxt[fail[cur]][i];
	    else
	    {
		fail[nxt[cur][i]] =nxt[fail[cur]][i];
		Q.push(nxt[cur][i]);
	    }
	}
    }
    int Search(char *s)
    {
	int len = strlen(s);
	int u = root;
	int res = 0 ;
//	cout<<"txt:"<<s<<endl;
	for ( int i = 0 ; i < len; i++)
	{
	    int v = s[i]-'a';
	    u = nxt[u][v];
	    int tmp = u;
	    while (tmp!=root)
	    {
		res +=end[tmp];
		end[tmp] = 0 ;
		tmp = fail[tmp];
	    }
	}
	return res;
    }
}ac;
char s[52];
char text[1000005];
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
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%s",s);
		ac.Insert(s);
//		cout<<"s:"<<s<<endl;
	    }
	    ac.Getfail();
	    scanf("%s",text);
//	    cout<<"txt:"<<text<<endl;
	    printf("%d\n",ac.Search(text));
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
