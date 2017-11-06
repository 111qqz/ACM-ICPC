/* ***********************************************
Author :111qqz
Created Time :2017年11月03日 星期五 18时20分42秒
File Name :2774_SAM.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
#define fst first
#define sec second
#define lnxt l,m,rt<<1
#define rnxt m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;

const int maxn = 5E5;
struct node{
    node*nxt[26],*fail;
    LL len,cnt;
    int ind;
    int occ;
};
struct SAM{
    node no[maxn];
    int pos[maxn];
    node*root;
    int cnt;
    bool cmp( int x,int y)
    {
	return no[x].len < no[y].len;
    }
    node*newnode(){
	return &no[cnt++];
    }
    SAM(){
	cnt = 0;
	root = newnode();
    }
    void init()
    {
	cnt = 0;
	root =newnode();
    }
    node*add(int c,node*p){
        node*cur = newnode();
        cur->len = p->len+1;
        while(p&&!p->nxt[c]){
            p->nxt[c] = cur;
            p = p->fail;
        }
        if(!p){
            cur->fail = root;
            return cur;
        }
        node*q = p->nxt[c];
        if(p->len+1==q->len){
            cur->fail = q;
        }else{
            node*nq = newnode();
            *nq = *q;
            q->fail = cur->fail = nq;
            nq->len = p->len+1;
            while(p&&p->nxt[c]==q){
                p->nxt[c] = nq;
                p = p->fail;
            }
        }
        return cur;
    }
    void solve()
    {
	for ( int i = 0 ; i < cnt ; i++) pos[i] = i;
	sort(pos,pos+cnt,cmp);
	for ( int i = 0 ; i < cnt ; i++)
	{
	    int u = pos[i];
	    for ( int j = 0 ; j < 10 ; j++)
		if (u==0&&j==0) continue;
	    if (u-)
};
SAM sam;
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
    while (scanf("%d",&n)!=EOF)
    {
	sam.init();
	node *cur = sam.root;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>st;
	    for (auto i :st) cur = sam.add(i-'0',cur);
	    cur = sam.add(10,cur);  //10是字符集合中没有出现的字符,起分割作用
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
