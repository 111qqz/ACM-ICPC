/* ***********************************************
Author :111qqz
Created Time :2017年07月23日 星期日 11时11分00秒
File Name :2417.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PB push_back
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
LL p,b,n;
map<LL,LL>Hash;
map<LL,LL>::iterator it;
inline LL ksm(LL a,LL b,LL MOD)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) res = (res*a)%MOD;
	b = b >> 1;
	a = (a*a)%MOD;
    }
    return res;
}
LL BSGS(LL a,LL b ,LL p) // a^x = b (mod p),求x 
{
    a%=p;
    b%=p;
    if (!a&&!b) return 1;
    if (!a) return -1;
    Hash.clear();
    LL m = ceil(sqrt(double(p)));
    LL tmp = b;
    for (LL j = 0 ; j <= m ; j++)
    {
	Hash[tmp]=j;
	tmp = (tmp*a)%p;
    }
    tmp = ksm(a,m,p);
    LL ret = 1;

    for (LL i = 1  ; i <= m+1 ; i++)
    {
	ret = ret*tmp%p;
	if (Hash[ret]) return i*m-Hash[ret]; //注意处理下%....虽然其实不处理也没关系...
    }
    return -1;

}
int main()
{
        #ifndef  ONLINE_JUDGE 
       // freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%lld",&p,&b,&n))   // B^L = n(mod p)
	{
	    LL ans = BSGS(b,n,p);
	    if (ans==-1) printf("no solution\n");
	    else printf("%lld\n",(ans%p+p)%p);
	}
	    
    
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
