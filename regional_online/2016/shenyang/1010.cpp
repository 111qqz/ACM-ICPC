#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 320000
using namespace std;

LL n, g[MAXN], f[MAXN];

LL sum(LL n)
{
    LL m=1, e;
    for(;m*m<=n;++m)f[m]=n/m-1;
    for(int i=1;i<=m;++i)g[i]=i-1;
    for(LL i=1;i<=m;++i)
        if(g[i]!=g[i-1])
        {
            e=min(n/(1ll),m-1);
            for(LL j=1;j<=e;++j)
                if(i*j<=m-1)f[j]-=f[i*j]-g[i-1];
                else f[j]-=g[n/(i*j)]-g[i-1];
            for(LL j=m;j>=1;--j)g[j]-=g[j/i]-g[i-1];
        }
    LL ans=0;
    for(int i=1;i<m;++i)if(g[i]!=g[i-1])ans+=f[i]-g[i];
    return ans;
}

int main()
{
    freopen("code/in.txt","r",stdin);
    while (scanf("%lld",&n)!=EOF){
	int k=pow(n,1.0);	
	cout<<sum(n)+g[k]<<'\n';
    }
    return 0;
}

