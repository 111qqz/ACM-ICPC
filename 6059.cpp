/* ***********************************************
Author :111qqz
Created Time :2017年11月12日 星期日 01时30分29秒
File Name :6059.cpp
************************************************ */

#include <bits/stdc++.h>
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
const int N=5E5+7;
int a[N];
int num[35][2];//cnt[i][j] 表示二进制表示中第i位为j的数的个数
struct Trie
{
    struct Node
    {
        Node *nxt[2];
        LL cnt[2];//需要统计前缀为某个串，该位置为0和该位置为1的个数。
	LL ext[2];
        Node()
        {
            for ( int i = 0 ; i < 2;  i++) nxt[i] = NULL;
            cnt[0]=cnt[1]=0 ;
	    ext[0]=ext[1]=0;
        }
    };
    Node *root;
    void init()
    {
        root = new Node();
    }
    Trie()
    {
        root = new Node();
    }
    void Insert(int x)
    {
        Node *u = root;
	for ( int i = 29 ; i >= 0 ; i--)
        {
            int y = (x>>i)&1;
	    num[i][y]++; //统计二进制第i位为y的数的个数
	    u->cnt[y]++; //统计trie树上当前节点数的个数
	    u->ext[y]+=num[i][y]; //把此时插入的数看做a[i]，那么u->ext[y]就是满足j<=i 的j的数目
	//因为之后要用到，所以要提前维护
            if (u->nxt[y]==NULL) u->nxt[y] = new Node();
            u = u->nxt[y];
        }
    }
    LL Cal( int x)
    {
	Node *u = root;
	LL res = 0 ;
	for ( int i = 29 ; i >= 0 ; i--)
	{
	    int y =  (x>>i)&1;
	    res += num[i][y^1]*u->cnt[y^1]-u->ext[y^1];
//对于此时插入的a[k]的二进制第i位（从低往高）的数y,只有当a[i]和a[j]的第i位为1-y时，才会贡献答案。
	// num[i][y^1]为第i位为1-y的a[j]的个数（a[j]的其他位，包括比i高的位和比i低的位都不受限制
	// u->cnt[y^1]表示trie树上，从rt到p节点所表示的二进制位上，a[i]与a[k]一直相同，p的下一个节点a[i]与a[k]的二进制位不同 的 a[i]的个数
	    u = u->nxt[y];
	    if (u==NULL) break;
	}
	return res;
    }
}trie;
void solve()
{
    trie.init();
    ms(num,0);
    LL ans = 0 ;
    int n;
    scanf("%d",&n);
    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
    for ( int i = 1 ; i <= n ; i++)
    {
	ans = ans + trie.Cal(a[i]);
	trie.Insert(a[i]);
    }
    cout<<ans<<endl;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--) solve();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
