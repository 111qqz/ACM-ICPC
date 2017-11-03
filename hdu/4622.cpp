
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
const int N=2017;
const int maxn = 4017;


struct node{
    node*nxt[26],*fail;
    LL len,cnt;
    void init()
    {
	for ( int i = 0 ; i < 26 ; i++) nxt[i]=NULL;
	fail=NULL;
	len=cnt=0;
    }
};
struct SAM{
    node no[maxn];
    node*root;
    int cnt;
    node*newnode(){
	ms(no[cnt].nxt,0);
	no[cnt]
	return &no[cnt++];
    }
    SAM(){
	cnt = 0;
	root = newnode();
    }
    void init()
    {
	//for ( int i = 0 ; i < cnt ; i++) no[i].init();
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
    LL calc()
    {
	LL ans = 0;
//	cout<<"cnt:"<<cnt<<endl;
	for ( int i = 1 ; i < cnt ; i++) {ans = ans + no[i].len - no[i].fail->len;/*cout<<ans<<endl;*/}
	return ans;
    }
};


SAM sam;
string A;
LL ans[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>A;
	    int q;
	    ms(ans,0);
	    int len = A.length();
	    //预处理一下，就只需要2000个SAM了
	    for ( int i = 0 ; i < len ; i++)
	    {
		sam.init();
		node *cur = sam.root;
		for ( int j = i ; j < len ; j++)
		{
		    cur = sam.add(A[j]-'a',cur);
		    ans[i][j] = sam.calc();
		}
	    }
		    

	    scanf("%d",&q);
	    while (q--)
	    {
		int l,r;
		scanf("%d %d",&l,&r);
		l--;
		r--;
		printf("%lld\n",ans[l][r]);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
