/* ***********************************************
Author :111qqz
Created Time :2016年08月04日 星期四 14时40分17秒
File Name :code/multi2016/1002r.cpp
 ************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int H=120000;
const int N=105;
struct node
{
    LL x,y;

}a[N];
LL fac[H],inv[H],f[H];
LL rinv[H];
LL MOD;
LL p,q,h,w,n,cnt;
LL q_mul(LL a,LL b)  //快速加
{
    LL ans = 0 ;
    while (b)
    {
	if (b&1)
	{
	    b--;
	    ans = (ans+a)%MOD;
	}
	b/=2;
	a = (a+a)%MOD;
    }
    return ans;
}
LL ksm(LL a,LL b)
{
     LL ans = 1;
     while (b)
     {
	 if (b&1)
	 {
	     ans = q_mul(ans,a);
	 }
	 b/=2;
	 a = q_mul(a,a);
     }
     return ans;
}

void prepare2()
{
   fac[0] = inv[0] = 1;
   for ( int i = 1 ; i <= MOD ; i++)
    {
	fac[i] = (fac[i-1]*i)%MOD;
	inv[i] = ksm(fac[i],MOD-2);
	//cout<<"i:"<<i<<" fac[i]:"<<fac[i]<<endl; 
    }
}
void prepare()
{
    //fac[0] = inv[0] = 1;
    inv[0]=inv[1] = 1;
    fac[0] =fac[1]= 1;
    for ( int i = 2 ; i < H ; i++)
    {
	fac[i] = (fac[i-1] * i)%MOD;
	//inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[i] = q_mul(MOD-MOD/i,inv[MOD%i]);
    if (inv[i]<0) inv[i]+=MOD;
    }
    for ( int i = 0 ;i < H; i++)
    {
	rinv[i] = inv[fac[i]];
//	cout<<"i:"<<i<<" fac[i]:"<<fac[i]<<" rinv[i]:"<<rinv[i]<<endl;  
    }
    for ( int i = 0 ;i < H ; i++)
    {
	inv[i] = rinv[i];
//	cout<<"i:"<<inv[i]<<endl;
    }
    
}
bool cmp(const node &aa,const node  &bb)
{
    return aa.x<bb.x||(aa.x==bb.x&&aa.y<bb.y);
}
LL calc(LL aa,LL bb)
{
    LL ta =aa%MOD,tb=bb%MOD;
    if (ta<tb) return 0;
    LL tmp = 1;
    if (max(aa,bb)>=MOD)
	tmp = calc(aa/MOD,bb/MOD);
    LL t1 = q_mul(tmp,fac[ta]);
       t1 = q_mul(t1,inv[tb]);
       t1 = q_mul(t1,inv[ta-tb]);
//    return tmp*fac[ta]%MOD*inv[tb]%MOD*inv[ta-tb]%MOD;
    return t1;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    p = 1;
    q = 2;
    MOD = 110119;
    prepare();
    int cas = 0 ;
    while (scanf("%lld%lld%lld",&h,&w,&n)!=EOF)
    {
	ms(a,0);
	ms(f,0);
	cnt = 0 ;
	//cout<<"h:"<<h<<"w:"<<w<<"n:"<<n<<endl;
	bool flag = false;
	LL tx,ty;
	bool die = false;
	for ( int i = 1 ; i <= n+1 ; i++)
	{
	    if (i<=n)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	    else
	    {
		a[i].x = h;
		a[i].y = w;
	    }
//	    cout<<"i:"<<i<<" "<<a[i].x<<" "<<a[i].y<<endl;
	    if (i<=n)
	    {
		if (a[i].x==h&&a[i].y==w) die = true;
	    }
	
	    --a[i].x;
	    --a[i].y;
	    LL t1 = a[i].x*p-a[i].y*q;
	    LL t2 = p*p-q*q;
	    if (t1%t2) continue;
	    t1/=t2;
	    LL t3 = a[i].x*q-a[i].y*p;
	    LL t4 = q*q-p*p;
	    if (t3%t4) continue;
	    t3/=t4;
	    if (t1<0||t3<0) continue;
	    a[i].x = t1;
	    a[i].y = t3;
	    a[++cnt] = a[i];
	    if (i==n+1)
	    {
		flag = 1;
		tx = t1;
		ty = t3;
	    }
	}
	if (!flag||die)
	{
	    printf("Case #%d: 0\n",++cas);
	    continue;
	}
	sort(&a[1],&a[1+cnt],cmp);
	for ( int i = 1 ; i <= cnt ; i++)
	{
	    if (a[i].x==tx&&a[i].y==ty)
	    {
		n = i ;
		break;
	    }
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	    f[i]= calc(a[i].x+a[i].y,a[i].x);
	    for ( int j = 1 ; j < i ; j++)
		if (a[j].y<=a[i].y)
		{
		   // f[i]-=f[j]*calc(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x);
		      f[i] = f[i] - q_mul(f[j],calc(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x));
		    f[i] = (f[i]+MOD)%MOD;
		}
	}
	
//	cout<<"sad"<<endl;
	printf("Case #%d: %lld\n",++cas,(f[n]+MOD)%MOD);
    }

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
