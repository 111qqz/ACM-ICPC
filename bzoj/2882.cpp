/* ***********************************************
Author :111qqz
Created Time :2017年11月03日 星期五 18时20分42秒
File Name :2774_SAM.cpp
************************************************ */

//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
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
};
struct SAM{
    node no[maxn];
    node*root;
    int cnt;
    node*newnode(){
	ms(no[cnt].nxt,0);
	no[cnt].fail=NULL;
	no[cnt].len = no[cnt].cnt = 0;
	return &no[cnt++];
    }
    void init()
    {
	cnt = 0;
	root = newnode();
    }
    SAM(){
	cnt = 0;
	root = newnode();
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
    int calc(int L)
    {
	node *p =root;
	for ( int i = 0 ; i < L ; i++)
	{
	    bool flag = false;
	    for ( int j = 0 ; j < 26 ; j++) //找字典序最小的.
		if (p->nxt[j])
		{
		    flag = true;
		    p=p->nxt[j];
		    break;
		}
	    if (!flag) break;
	}
	return p->len + 1 - L;
    }
};
SAM sam;
string A,B;
int main()
{
	#ifndef  ONLINE_JUDGE 
    	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    sam.init();
	    node *cur =sam.root;
	    cin>>A;
	    for ( int i = 0 ; i < A.length() ; i++) cur = sam.add(A[i]-'a',cur);
	    for ( int i = 0 ; i < A.length() ; i++) cur = sam.add(A[i]-'a',cur);
	    int ans = sam.calc(A.length());
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
