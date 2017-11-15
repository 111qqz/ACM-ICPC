#include <bits/stdc++.h>
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
const int N=5E5+79;
int t[2*N];
char st[N];
int p[2*N];  //p[i]为以第i个位置的字符为中心的回文串的半径长，默认为1.
vector<int>vec[N];
int a[2*N];
char Ma[2*N];
int Mp[2*N];
int Manacher( char *s)
{
    int len = strlen(s);
    int id = 0; //id表示之前位置的能延伸到最远位置的字符串的中心位置。
    int maxlen = 0 ;  //maxlen是为了更新答案而用。。。就是记录了一个最大值。。。
    int mx = 0 ;//mx为当前位置之前的回文串能延伸到的最远位置 即：max(p[j]+j) (j<i)
                //如果知道之前能延伸到最远位置的字符串的中心位置的下标为id，那么就是p[id]+id;
    for ( int i = len ; i >= 0 ; i--)  //插入'#'是为了将字符串长度奇偶性不同的统一考虑。
    {
        Ma[i+i+2] = s[i];
        Ma[i+i+1] = '#';
    }
    Ma[0]='*'; //s[0] ='*'以及用字符数组最后默认的s[len+len+2]='\0'是为了下面while 循环的时候不溢出。。
                //两边的字符一定要不一样。。用string的话记得两边都加字符。。。
    for ( int i = 2 ; i < 2*len+1 ; i++)
    {
        if (Mp[id]+id>i) Mp[i] = min(Mp[2*id-i],Mp[id]+id-i);
        else Mp[i] = 1;
        while (Ma[i-Mp[i]]==Ma[i+Mp[i]]) Mp[i]++;
        if (id+Mp[id]<i+Mp[i]) id = i;
        if (maxlen<Mp[i]) maxlen = p[i];
    }
    return 2*len+2;
    //这道题是问最长回文串的长度。。。如果是问回文串是什么的话。。。根据id和maxlen也可以构造出来。。。
}

int lowbit( int x) { return x&(-x);}
void update ( int x,int delta)
{
    for ( int i = x; i < 2*N ; i+=lowbit(i))
	t[i]+=delta;
}
int Sum( int x)
{
    int res = 0 ;
    for ( int i = x ; i >= 1 ; i-=lowbit(i))
	res = res + t[i];
    return res;
}
int main()
{
        #ifndef  ONLINE_JUDGE 
       freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(t,0);
	    for ( int i = 0 ; i < N ; i++) vec[i].clear();
	    scanf("%s",st);
	    int n = strlen(st);
	    int len = Manacher(st);
	    int j = 1;
	    for ( int i = 2 ; i < len ; i+=2)
	    {
		a[j] = Mp[i]/2-1;
		
		printf("k:%d a[k]：%d p[i]:%d\n",k,a[k],Mp[i]);
		vec[j-a[j]].push_back(j);
		j++;
	    }
	    LL ans = 0 ;
	    for ( int i = 1 ; i <= n  ; i++)
	    {
//		cout<<"a[i]:"<<a[i]<<endl;
		for ( int j = 0 ; j < vec[i].size() ; j++)
		    update(vec[i][j],1);
		ans += Sum(min(i+a[i],n)) -Sum(i);
	    }
//	    cout<<Sum(2*N)<<endl;
	    cout<<ans<<endl;
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
 
 
 
 

