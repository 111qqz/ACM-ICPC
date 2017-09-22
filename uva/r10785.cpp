/* ***********************************************
Author :111qqz
Created Time :2016年01月27日 星期三 20时03分17秒
File Name :code/uva/r10785.cpp
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
int n;
char a[30],b[30];

void pre()
{
    a[1]='A';
    a[2]='U';
    a[3]='E';
    a[4]='O';
    a[5]='I';

    b[1]='J';
    b[2]='S';
    b[3]='B';
    b[4]='K';
    b[5]='T';
    b[6]='C';
    b[7]='L';
    b[8]='D';
    b[9]='M';
    b[10]='V';
    b[11]='N';
    b[12]='W';
    b[13]='F';
    b[14]='X';
    b[15]='G';
    b[16]='P';
    b[17]='Y';
    b[18]='H';
    b[19]='Q';
    b[20]='Z';
    b[21]='R';
    
}
void solve()
{
    int odd;
    int even;
    odd = (n+1)/2;
    even = n /2;

    int vowa = odd/21;
    int vowr = odd%21;
    int cona = even/5;
    int conr = even%5;

    sort(a+1,a+vowa+1);
    sort(b+1,b+cona+1);


    char ans[250];
    int num=0;
    int cnt = 1;
    for ( int i = 1 ; i <= odd ; i++)
    {
	num++;
	ans[2*i-1]=a[cnt];
	if (num==21)
	{
	    num = 0 ;
	    cnt++;
	}
    }

    num = 0 ;
    cnt = 1;
    for ( int i = 1 ; i <=even ;  i++)
    {
	num++;
	ans[2*i]=b[cnt];
	if (num==5)
	{
	    num = 0 ;
	    cnt++;
	}
    }

    for ( int i = 1 ;  i <=  n ;i++)
    {
	cout<<ans[i];
    }
    cout<<endl;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	int cas = 0 ;
	cin>>T;
	while (T--)
	{
	    pre();
	    scanf("%d",&n);
	    printf("Case %d: ",++cas);
	    solve();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
