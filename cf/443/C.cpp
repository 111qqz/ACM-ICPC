/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 23时25分01秒
File Name :C.cpp
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
int n;
char opt[N][2];
int a[N];
vector < pair<int,int> >AND,OR,XOR;
int digit[20];
int cnt;
int ans[3][20]={};
void solve( int x)
{

    ms(digit,0);
    while (x)
    {
	digit[++cnt] = x % 2;
	x/=2;
    }
}
    
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	
	cin>>n;
	/*
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%s%d",opt[i],&a[i]);
	    if (opt[i][0]=='|') OR.PB(MP(i,a[i])) ; //pos,val
	    if (opt[i][0]=='^') XOR.PB(MP(i,a[i]));
	    if (opt[i][0]=='&') AND.PB(MP(i,a[i]));
	}
	*/

	for ( int i = 1 ;  i <= 10 ; i++) ans[2][i] = 1;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%s%d",opt[i],&a[i]);
	    cnt = 0 ;
	    solve(a[i]);
	    //for ( int j = 1 ; j <= 10 ; j++) printf("%d%c",digit[j],j==10?'\n':' ');
	    if (opt[i][0]=='|')
	    {
		for ( int k = 1 ; k <= 10 ; k++)
		{
		    ans[0][k] = ans[0][k] | digit[k];
		}
	    }
	    if (opt[i][0]=='^')
	    {
		for ( int k = 1 ; k <= 10 ; k++)
		{
		    ans[1][k] = ans[1][k] ^ digit[k];
		}
	    }
	    if (opt[i][0]=='&')
	    {
		for ( int k = 1;  k <= 10  ;k++)
		{
		    ans[2][k] = ans[2][k] & digit[k];
		}
	    }
	}

	//for ( int i = 1 ; i <= 10 ; i++ ) cout<<ans[0][i]<<" ";
	//cout<<endl;

	int num = 0 ;
	for ( int i = 10 ; i >= 1 ; i--)
	{
	    if (ans[0][i]!=0) 
	    {
		num++;
		break;
	    }
	}
	int ret[3] ={0};
	for ( int i = 10 ; i >= 1 ; i--) ret[0] = (ret[0] << 1) + ans[0][i];

	for ( int i =  10 ;  i >= 1 ; i--)
	{
	    if (ans[1][i]!=0)
	    {
		num++;
		break;
	    }
	}
	for ( int i  = 10 ; i >= 1 ; i--) ret[1] = (ret[1] <<1) + ans[1][i];

	for ( int i = 10 ;  i>= 1 ; i--)
	{
	    if (ans[2][i]==0)
	    {
		num++;
		break;
	    }
	}
	for ( int i = 10 ;  i>=1 ; i--) ret[2] = (ret[2] << 1) + ans[2][i];
	if ()


	//for ( int i = 0 ; i <3 ; i++) printf("ret[%d]:%d\n",i,ret[i]);
	cout<<num<<endl;
	if (ret[0]>0)
	printf("| %d\n",ret[0]);
	if (ret[1]>0)
	printf("^ %d\n",ret[1]);
	if (ret[2]>0&&)
	    printf("& %d\n",ret[2]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
