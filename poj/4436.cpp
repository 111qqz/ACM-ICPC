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
    node*root;
    int cnt;
    node*newnode(){
	return &no[cnt++];
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
    int LCS(string s)
    {
//	cout<<"S:"<<s<<endl;
	int ans=0,len=0;
	node *p=root;
	for ( auto i:s)
	{
	    int ID = i-'a';
	    //cout<<"id:"<<ID<<" s[i]:"<<i<<" i:"<<i<<endl;
	    if (p->nxt[ID]) p=p->nxt[ID],len++;
	    else
	    {
		while (p&&!p->nxt[ID]) p=p->fail;
		if (!p) p=root,len=0;else len=p->len+1,p=p->nxt[ID];
	    }
	    ans = max(ans,len);
	}
	return ans;
    }
};
SAM sam;
string A,B;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	node *cur =sam.root;
	cin>>A>>B;
	for ( auto i:A) cur = sam.add(i-'a',cur);
	int ans = sam.LCS(B);
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
