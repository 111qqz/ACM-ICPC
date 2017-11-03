/* ***********************************************
Author :111qqz
Created Time :2017年11月03日 星期五 18时20分42秒
File Name :2774_SAM.cpp
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
struct SAM
{
    static const int maxn = 2*N;
    struct node
    {
	node *nxt[26],*fail;
	int len;
    }
    node *root;int cnt;
    node no[maxn];
    node *newnode()
    {
	return &no[cnt++];
    }
    SAM(){
	cnt = 0;
	root = newnode();
    }
    node* (node *p,int c)
    {
	node *cur = newnode();
	cur->len = p->len + 1;
	while (p&&!p->nxt[c]) p->nxt[c] = cur,p=p->fail;
	if (!p){
	    cur->fail = root;return cur;
	}
	node *q = p->nxt[c];
	if (q->len==p->len+1)
	    cur->fail = q;
	else
	{
	    node * nq = newnode();
	    *nq = *q;
	    nq->len = p->len+1;
	    q->fail = cur->fail = nq;
	    while (p&&p->nxt[c]==q) p->nxt[c] = nq,p = p->fail;
	}
	return cur;
    }



int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
