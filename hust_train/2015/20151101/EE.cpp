#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <stack>
#define MAXN 20005
#define MAXK 5005
using namespace std;
set<int> G[MAXN];
struct operation{
    char s[3];
    int x,y;
}op[MAXK];
int fa[MAXN],n,k,father[MAXN];
bool cut[MAXN];
void input(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++){
        scanf("%d",&fa[i]);
    }
    for(int i = 1; i <= n; i++)G[i].clear();
    for(int i = 1; i <= n; i++)G[fa[i]].insert(i);
    for(int i = 1; i <= k; i++){
        scanf("%s",op[i].s);
        if(op[i].s[0] == 'Q'){
            scanf("%d%d",&op[i].x,&op[i].y);
        }
        else{
            scanf("%d",&op[i].x);
            G[fa[op[i].x]].erase(op[i].x);
            //cut[op[i].x] = true;
        }
    }
    for(int i = 1; i <= n; i++)father[i] = i;
    memset(cut,false,sizeof(cut));
}
int getfather(int x){
    if (x==father[x]) return x;
    else return father[x]= getfather(father[x]);
}
void _merge(int x,int y){
    int fx = getfather(x), fy = getfather(y);
    father[fy] = fx;
}
void maketree(){
    for(int i = 1; i <= n; i++){
        for(set<int>::iterator it = G[i].begin(); it != G[i].end(); it++){
            _merge(i,*it);
        }
    }
}
stack<int> Stackans;
void solve(){
    input();
    maketree();
    while(!Stackans.empty())Stackans.pop();
    for(int i = k; i >= 1; i--){
        if(op[i].s[0] == 'Q'){
            int xx = op[i].x , yy = op[i].y;
            if(getfather(xx) == getfather(yy)){
                Stackans.push(1);
            }
            else{
                Stackans.push(0);
	    }
        }
        else{
            int xx = op[i].x;
            //cut[xx] = false;
         //   if(fa[xx] != 0)_merge(xx,fa[xx]);
            //printf("Merge %d and %d\n",xx,fa[xx]);
        }
    }
    while(!Stackans.empty()){
        if(Stackans.top()){
            puts("YES");
        }
        else{
            puts("NO");
        }
        Stackans.pop();
    }
}
int main(){
    int T;
  //  freopen("in.txt","r",stdin);
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d:\n",i);
        solve();
    }
    return 0;
}
