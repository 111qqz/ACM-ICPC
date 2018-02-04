/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 14时34分00秒
File Name :B.cpp
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
const int N=1E3+7;
const int M = 5E6+7;
int n,m;
int a[M];
int b[N];
string st;
int nxt[M];
set<string>se;
void getnxt( int n)
{

    int i = 0 ;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
    {
//	int tmp = b[i] | (b[j] ^ b[i]);
	if (j==-1||((b[i]&b[j])>0)) nxt[++i]=++j;
    else j = nxt[j];
    }
}
vector <string>res;
void kmp( int n,int m)
{
    getnxt(n);
 //   for ( int i = 0 ; i < n ; i++) printf("nxt[%d]:%d\n",i,nxt[i]);
    int i = 0;
    int j = 0 ;
    while (i<m)
    {

	if  (j==-1||(a[i]&b[j])>0) i++,j++;
	else j = nxt[j];
	cout<<"i:"<<i<<" j:"<<j<<" n:"<<n<<endl;
	if (j==n)
	{
	    string tmp="";
	    for ( int k = i-j ; k < i ; k++)
		tmp+=st[k];
	    res.PB(tmp);
	  //  i = i-n+1;
	    //i = nxt[i];
	    j = nxt[j];

	    
	}
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(a,0);
	    ms(b,0);
	    res.clear();
	   // se.clear();
	    for ( int i = 0 ; i < n ; i++)
	    {
		int m;
		scanf("%d",&m);
		int tmp = 0;
		while (m--)
		{
		    int x;
		    scanf("%d",&x);
		    tmp = tmp | (1<<x);
		}
		b[i] = tmp;
	    }
	    cin>>st;
	   // cout<<"st:"<<st<<endl;
	    m = st.length();
	    for ( int i = 0 ; i < m ; i++)
	    {
		int v = st[i]-'0';
		a[i] = 1<<v;
	    }

	   // for ( int i = 0 ; i < m ; i++) printf("%d%c",a[i],i==m-1?'\n':' ');
	   // for ( int i = 0 ; i < n ; i++) printf("%d%c",b[i],i==n-1?'\n':' ');
	    kmp(n,m);
//	    for ( auto it = se.begin() ; it!=se.end() ; it++)
//		cout<<*it<<endl;
	    int siz = res.size();
	    for ( int i = 0 ; i < siz ; i++) cout<<res[i]<<endl;
	}




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
