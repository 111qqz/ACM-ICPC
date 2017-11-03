#include "bits/stdc++.h"
//#include "ext/pb_ds/tree_policy.hpp"
//#include "ext/pb_ds/assoc_container.hpp"
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define EX0 exit(0);
#define twop(x) (1LL<<x)

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ld eps = 1e-9;
const int inf = mod;
const db PI = atan(1)*4;
template<typename T>
inline int sign(const T&a){if(a<0)return -1;if(a>0)return 1;return 0;}


template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

template<typename A,typename B > inline void in(A&x,B&y){in(x);in(y);}
template<typename A,typename B,typename C>inline void in(A&x,B&y,C&z){in(x);in(y);in(z);}
template<typename A,typename B,typename C,typename D> inline void in(A&x,B&y,C&z,D&xx){in(x);in(y);in(z);in(xx);}




struct node{
    node*nxt[26],*fail;
    ll len,cnt;
    int ind;
    int occ;
};

const int maxn = 200010;
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
    
    ll calc(ll n){
        return n*(n+1)/2;
    }
    void bfs(const string&s){
        queue<node*>q;
        q.push(root);
        REP(i,0,cnt){
            REP(j,0,26)if(no[i].nxt[j])no[i].nxt[j]->ind++;
        }
        root->cnt = 1;
        while(sz(q)){
            auto f = q.front();q.pop();
            REP(i,0,26){
                if(f->nxt[i]){
                    f->nxt[i]->cnt+=f->cnt;
                    f->nxt[i]->ind--;
                    if(!f->nxt[i]->ind)q.push(f->nxt[i]);
                }
            }
        }
        ll ans = 0;
        node*cur = root;
        for(auto i:s){
            i-='a';
            cur = cur->nxt[i];
            cur->occ++;
        }
        REP(i,1,cnt){
            no[i].fail->ind++;
        }
        REP(i,1,cnt){
            if(!no[i].ind)q.push(&no[i]);
        }
        while(q.front()!=root){
            auto f = q.front();q.pop();
            f->fail->ind--;
            f->fail->occ+=f->occ;
            if(!f->fail->ind)q.push(f->fail);
        }
        
        REP(i,1,cnt){
            ans+=1LL*calc(no[i].occ)*no[i].cnt;
        }
        cout<<ans<<endl;
    }
};

SAM sam;
int main(){
    node*cur = sam.root;
    string s;cin>>s;
    for(auto i:s)cur = sam.add(i-'a', cur);
    //return 0;
    sam.bfs(s);
    return 0;
}
