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
const int N=1E5+7;
vector <>
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
    void LCS(string s,int id)
    {
//	cout<<"S:"<<s<<endl;
	int len=0;
	node *p=root;
	int s_len = s.length();
	for ( int i = 0 ; i < s_len ; i++)
	{
	    int ID = s[i]-'a';
	    //cout<<"id:"<<ID<<" s[i]:"<<i<<" i:"<<i<<endl;
	    if (p->nxt[ID]) p=p->nxt[ID],len++;
	    else
	    {
		while (p&&!p->nxt[ID]) p=p->fail;
		if (!p) p=root,len=0;else len=p->len+1,p=p->nxt[ID];
	    }
	    p->nxt = max(p->nxt)
	    ans[i+1] = max(ans[id][i],len);
	}
    }
};
SAM sam;
int mnlen[N];
string st[15];
int num = 0;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	ms(ans,0);
	while (cin>>st[num]) num++;  //0..num-1
	if (num==1)
	{
	    puts("0");
	    return 0;
	}
	node *cur =sam.root;
//	for ( int i = 0 ; i < num ; i++) cout<<st[i]<<endl;
	for ( auto i:st[0]) cur = sam.add(i-'a',cur);
	for ( int i = 1 ; i <= num-1 ; i++)
	{
	    sam.LCS(st[i],i);
	}
	ms(mnlen,0x3f);
	for ( int i = 1 ; i < N ; i++)
	{
	    for ( int j = 1 ; j <= num-1 ;j++)
	    {
		mnlen[i] = min(mnlen[i],ans[j][i]);
	    }
	}
	int ret = 0;
	for ( int i = 1 ; i < N ; i++) ret = max(ret,mnlen[i]);
	printf("%d\n",ret);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
