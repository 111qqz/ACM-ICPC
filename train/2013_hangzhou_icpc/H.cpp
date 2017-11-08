#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int NN = 2e5+10, KK = 2e4+10;
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
int prime[KK],rePrime[NN],a[NN],q,cntPrime;
bool isprime[NN];
set<int> S[KK];
int n,m;
void getPrime(){
	ms(isprime,1);
	for(int i = 2; i <= 200000; i++){
		if(!isprime[i])continue;
		for(int j = 2; j * i <= 200000; j++){
			isprime[i*j] = false;
		}
	}
	cntPrime = 0;
	for(int i = 2; i <= 200000; i++){
		if(isprime[i])prime[++cntPrime] = i;
		rePrime[i] = cntPrime;
	}
}

void getSet(){
	for(int i = 1; i <= cntPrime; i++)S[i].clear();
	for(int i = 1; i <= n; i++){
		int tmp = a[i];
		for(int j = 1; j <= cntPrime && 1LL*prime[j]*prime[j] <= a[i]; j++){
			if(tmp % prime[j] == 0){
				while(tmp%prime[j]==0){
					tmp /= prime[j];
				}
				S[j].insert(i);
			}
			if(tmp==1)break;
		}
		if(tmp>1)S[rePrime[tmp]].insert(i);
	}
}
pair<int,int> getLR(int id){
	int l = 0, r = n+1, tmp = a[id];
	for(int j = 1; j<=cntPrime && 1LL*prime[j]*prime[j]<=a[id]; j++){
		if(tmp % prime[j] == 0){
			while(tmp%prime[j] == 0){
				tmp /= prime[j];
			}
			auto it = S[j].find(id);
			auto it1 = it, it2 = it;
			if(it != S[j].begin()){
				it1--, l = max(l, *it1);
			}
			it2++;
			if(it2 != S[j].end()){
				r = min(r, *it2);
			}
		}
	}
	if(tmp>1){
		auto it = S[rePrime[tmp]].find(id);
		auto it1 = it, it2 = it;
		if(it != S[rePrime[tmp]].begin()){
			it1 --;
			l = max(l, *it1);
		}
		it2++;
		if(it2 != S[rePrime[tmp]].end()){
			r = min(r, *it2);
		}
	}
	return make_pair(l+1,r-1);
}

struct QUERY
{
	int l,r;
	int id;
	bool operator < ( QUERY b)
	{
		return l < b.l;
	}
}qu[NN];
int t[NN];
int lowbit( int x) { return x&(-x);}
void update ( int x,int delta)
{
	for ( int i = x ; i < NN ; i+=lowbit(i))
		t[i]+=delta;
}
int Sum( int x)
{
	int res = 0 ;
	for ( int i = x ; i >= 1 ; i-=lowbit(i))
		res = res + t[i];
	return res;
}
int ans[NN];
struct POS
{
	int l,r;
	int id;
	bool operator < (POS b)
	{
		return l<b.l;
	}
}pos[NN];
vector <int>L[NN]; //维护有哪些位置最左边界可以到达L[i]
void solve(){
//	ms(pos,0);
	for ( int i = 1 ; i <= n ; i++)
	{
		pair <int,int> tmp = getLR(i);
		pos[i].id = i ;
		pos[i].l = tmp.first;
		pos[i].r = tmp.second;
		L[pos[i].l-1].push_back(i);
	}
	//预处理出每个a[i],左右能达到的最大区间[pos[i].l,pos[i].r],使得区间中所有的数都与a[i]互质
	//check
//	for ( int i = 1 ; i <= n ; i++) printf("i:%d l:%d  r: %d\n",i,pos[i].l,pos[i].r);
	//sort(pos+1,pos+n+1);
//	for ( int i = 1 ; i <= n ; i++) printf("i:%d l:%d  r: %d\n",i,pos[i].l,pos[i].r);
	
	//
	
	for ( int i = 1 ; i <= n ; i++) if (pos[i].l==1)
	{
	    update(i,1);
	    update(pos[i].r+1,-1);
	}
	
	//统计下标在区间[qu[i].l,qu[i].r]之间，并且l<=qu[i].l&&r>=qu[i].r
	//
	//1要特殊处理
	int j = 1;
	for ( int i = 1 ; i <= m ; i++)
	{
	    while (j<qu[i].l)
	    {
		update(j,-1);  //因为这个j已经在qu[i].l的左边，对答案没有贡献，所以取消之前的操作。
		update(pos[j].r+1,1);
		int siz = L[j].size();
		for ( int k = 0 ; k < siz ; k++)  //对于某个左边界在j的点v,其对[v,R[v]]是1的贡献的。
		{
		    int v = L[j][k]; //以j为最左边界的的点
		    update(v,1);
		    update(pos[v].r+1,-1);
		}
		j++;
	    }
	    ans[qu[i].id] = Sum(qu[i].r) - Sum(qu[i].l-1);
	    //ans[qu[i].id] = Sum(qu[i].r);

	}
	for ( int i = 1 ; i <= m ; i++) printf("%d\n",ans[i]);
}
int main(){
	freopen("./in.txt","r",stdin);
	getPrime();
	while (~scanf("%d %d",&n,&m))
	{
		ms(t,0);
		ms(ans,0);
		for ( int i = 0 ; i < NN ; i++) L[i].clear();
		for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
		getSet();
		
		for ( int i = 1 ; i <= m ; i++) 
		{
			scanf("%d %d",&qu[i].l,&qu[i].r);
			qu[i].id = i;
		}
		sort(qu+1,qu+m+1);
		
		solve();
	}

	return 0;
}
