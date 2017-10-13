#include<bits/stdc++.h>  
#define LL unsigned long long                   //数字可能很大，所以用ULL  
#define N 401000  
  
using namespace std;  
  
int pri[N],num[N],sz,tot;  
LL a[N],n,mod,p[N];  
bool ispri[N];  
  
struct matrix  
{  
    LL a[3][3];  
  
    void init(){memset(a,0,sizeof(a));}  
  
    friend matrix operator *(matrix x,matrix y)  
    {  
        matrix ans; ans.init();  
        for(int i=1;i<3;i++)  
            for(int j=1;j<3;j++)  
                for(int k=1;k<3;k++)  
                    ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;  
        return ans;  
    }  
  
    friend matrix operator ^(matrix x,LL y)  
    {  
        matrix ans;  
        if (y==0)  
        {  
            memset(ans.a,0,sizeof(ans.a));  
            for(int i=1;i<3;i++) ans.a[i][i]=1;  
            return ans;  
        } else while ((y&1)==0) y>>=1,x=x*x;  
        ans=x; y>>=1;  
        for(;y!=0;y>>=1)  
        {  
            x=x*x; if ((y&1)!=0) ans=ans*x;  
        }  
        return ans;  
    }  
} x;  
  
void init()  
{  
    memset(ispri,1,sizeof(ispri));  
    ispri[1]=0;  
    for(int i=2;i<N;i++)  
    {  
        if(ispri[i])pri[++sz]=i;  
         for(int j=1;j<=sz&&(LL)i*pri[j]<N;j++)  
         {  
            ispri[i*pri[j]]=0;  
            if(i%pri[j]==0)break;  
        }  
    }  
}  
  
LL qpow(LL x,LL n,LL p)  
{  
    LL ret=1;  
    while (n)  
    {  
        if (n&1) ret=ret*x%p;  
        x=x*x%p; n>>=1;  
    }  
    return ret;  
}  
  
  
void divide(LL n)  
{  
    for(int i=1;(LL)pri[i]*pri[i]<=n&&i<=sz;i++)  
    {  
        if (n%pri[i]) continue;  
        p[++tot]=pri[i]; num[tot]=0;  
        while (n%pri[i]==0) n/=pri[i],++num[tot];  
    }  
    if (n>1)  
    {  
        p[++tot]=n;  
        num[tot]=1;  
    }  
}  
  
bool legendre(LL p,int x)               //勒让德符号  
{  
    return qpow(x,(p-1)>>1LL,p)==1;  
}  
  
LL getT(LL n)                       //在n的约数中招循环节  
{  
    int tot=0;  
    for(int i=1;(LL)i*i<=n;i++)  
    {  
        if (n%i) continue;  
        a[++tot]=i;  
        if ((LL)i*i!=n) a[++tot]=n/i;  
    }  
    sort(a+1,a+tot+1);  
    for(int i=1;i<=tot;i++)  
    {  
        matrix ans=x^(a[i]-1);              //矩阵快速幂求fib数列第n项  
        LL X=(ans.a[1][1]+ans.a[1][2])%mod;  
        LL Y=(ans.a[2][1]+ans.a[2][2])%mod;  
        if (X==1&&Y==0) return a[i];            //如果找到循环节那么返回  
    }  
}  
  
int main()  
{
   
    //freopen("./in.txt","r",stdin);
    sz=0; init();                   //线性筛素数表  
    x.a[1][1]=x.a[1][2]=x.a[2][1]=1;  
    while(~scanf("%lld",&n))  
    {  
        LL ans=1LL;  
        tot=0; divide(n);               //分解质因数  
        for(int i=1;i<=tot;i++)  
        {  
            LL T=1LL,P;  
            if (p[i]==2) T=3LL; else  
            if (p[i]==3) T=8LL; else  
            if (p[i]==5) T=20LL; else  
            {  
                if (legendre(p[i],5)) P=p[i]-1LL;           //如果5是p下二次剩余，那么是p-1约数，否则是2*(p+1)  
                             else P=2LL*(p[i]+1LL);  
                mod=p[i]; T=getT(P);  
            }  
            for(int j=1;j<num[i];j++)                    //乘以p的num[i]-1次方  
                T*=p[i];  
            ans=ans/__gcd(ans,T)*T;                 //求lcm  
        }  
        if (n==2) puts("3"); else  
        printf("%llu\n",ans>>1LL);                   //如果用了ULL而不用%I64u那么和不用ULL是一样的，不能是%I64d  
    }  
    return 0;  
}  
