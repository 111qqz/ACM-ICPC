#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <bitset>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
typedef pair<int,int> pii;
typedef long long LL;
const double PI=acos(-1.0);
const int N=2e5+7;
struct seg
{
    int lson,rson;
    int cnt;
    inline void init()
    {
        lson=rson=cnt=0;
    }
};
seg T[N*40];
int root[N],tot;
int arr[N],ans[N],pre[N];
 
void init(int n)
{
    CLR(root,0);
    tot=0;
    T[n+1].init();
    ans[0]=0;
    CLR(pre,-1);
}
inline  int add_node( int cnt,int lson,int rson)
{
    int idx = ++tot;
    T[idx].cnt = cnt;
    T[idx].rson = rson;
    T[idx].lson = lson;
    return idx;
}
inline void update(int &cur,int ori,int l,int r,int pos,int v)
{
//    T[cur].cnt+=v;
    cur = add_node(T[ori].cnt+v,T[ori].lson,T[ori].rson);
    if(l==r)  return ;
    int mid=(l+r)>>1;
    if(pos<=mid) update(T[cur].lson,T[ori].lson,l,mid,pos,v);
    else  update(T[cur].rson,T[ori].rson,mid+1,r,pos,v);
}
int query(int S,int E,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
        return T[E].cnt-T[S].cnt;
    int mid=(l+r)>>1,res=0;
  //  if (L<=mid) res += query(T[S].lson,T[E].lson,l,mid,L,R);
 //   if (R>=mid) res += query(T[S].rson,T[E].rson,mid+1,r,L,R);
 //   return res;
	
        if(qr<=mid)
            return query(T[S].lson,T[E].lson,l,mid,ql,qr);
        else if(ql>mid)
            return query(T[S].rson,T[E].rson,mid+1,r,ql,qr);
        else
            return query(T[S].lson,T[E].lson,l,mid,ql,mid)+query(T[S].rson,T[E].rson,mid+1,r,mid+1,qr);

	
    }
}
int findkth(int S,int E,int l,int r,int k)
{
    if(l==r)
        return l;
    else
    {
        int cnt=T[T[E].lson].cnt-T[T[S].lson].cnt;
        int mid=MID(l,r);
        if(k<=cnt)
            return findkth(T[S].lson,T[E].lson,l,mid,k);
        else
            return findkth(T[S].rson,T[E].rson,mid+1,r,k-cnt);
    }
}
int main(void)
{
    int tcase,n,m,i,l,r,L,R;
    scanf("%d",&tcase);
    for (int q=1; q<=tcase; ++q)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for (i=1; i<=n; ++i)
            scanf("%d",&arr[i]);
        int temp_rt=0;
        for (int i = n ; i >= 1 ; i--)
        {
            if(pre[arr[i]]==-1)
                update(root[i],root[i+1],1,n,i,1);
            else
            {
                update(temp_rt,root[i+1],1,n,pre[arr[i]],-1);
                update(root[i],temp_rt,1,n,i,1);
            }
            pre[arr[i]]=i;
        }
        for (i=1; i<=m; ++i)
        {
            scanf("%d%d",&l,&r);
            L=(l+ans[i-1])%n+1;
            R=(r+ans[i-1])%n+1;
            if(L>R)
                swap(L,R);
            int D=query(root[n+1],root[L],1,n,L,R);
            ans[i]=findkth(root[n+1],root[L],1,n,(D+1)/2);
        }
        printf("Case #%d:",q);
        for (i=1; i<=m; ++i)
            printf(" %d",ans[i]);
        putchar('\n');
    }
    return 0;
}
