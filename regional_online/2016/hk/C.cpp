#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 2e5+10;
struct Pair{
    int a,b;
    Pair(int pa1 = 0, int pa2 = 0):
        a(pa1),b(pa2){}
}arr[maxn];
bool cmp(const Pair &x, const Pair &y){
    return (x.b==y.b)?(x.a<y.a):(x.b<y.b);
}
bool operator < (const Pair &x,const Pair &y){
    return x.b < y.b;
}
multiset<Pair> S;
int n,m,res;
int main(){
#ifndef ONLINE_JUDGE
    freopen("code/in.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF){
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&arr[i].a,&arr[i].b);
    }
    sort(arr+1,arr+n+1,cmp);
    res = 0;
    S.clear();
    for(int i = 1; i <= n; i++){
        if(S.size() < m){
            S.insert(arr[i]);
            res++;
        }
        else{
            set<Pair>::iterator it = S.lower_bound(Pair(0,arr[i].a));
            if(it != S.begin()){
                it--;
                S.erase(it);
                S.insert(arr[i]);
                res++;
            }
        }   
    }
    printf("%d\n",res);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
#endif
    return 0;
}
