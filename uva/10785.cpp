/* ***********************************************
Author :111qqz
Created Time :2016年01月26日 星期二 15时10分28秒
File Name :code/uva/10785.cpp
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


char a[30],b[30];
char oddans[210],evenans[210];
int n;
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

void solve ()
{
    int odd = (n+1)/2;
    int even = n/2;

    int vowa = odd/21;
    int vowr = odd%21;
    int cona = even/5;
    int conr = even%5;

    int cnt  = 0 ;
    for ( int i = 1 ; i <= vowa ; i++)
    {
	for ( int j =1 ; j <=21 ; j++)
	{
		cnt++;
		oddans[cnt] = a[i];
	}
    }

    for ( int i = 1 ; i <=vowr ; i++)
    {
	cnt++;
	oddans[cnt]=a[vowa+1];
    }
    
    cnt = 0 ;
    for ( int i = 1 ; i <= cona ; i++)
    {
	for ( int j = 1 ; j <= 5 ; j++)
	{
	    cnt++;
	    evenans[cnt]=b[i];
	}
    }
    for ( int i = 1 ; i <=conr ; i++)
    {
	cnt++;
	evenans[cnt]=b[cona+1];
    }

    sort(oddans+1,oddans+odd+1);
    sort(evenans+1,evenans+even+1);

    for ( int i = 1 ;i  <= n ; i++)
    {
	if (i%2==1)
	{
	    printf("%c",oddans[i/2+1]);
	}
	else
	{
	    printf("%c",evenans[i/2]);
	}
    }
    puts("");
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	pre();
	//cout<<good<<endl;
	int T;             //之前想错了。以为不是完整的就必须在最后。但是实际上只要数量不变就不影响权值和。那么在这个前提下就应该把非完整的字典序小的放在前面。
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    printf("Case %d: ",++cas);
	    scanf("%d",&n);
	    solve();
	}
	
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
