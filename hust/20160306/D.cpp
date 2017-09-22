/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 13时59分36秒
File Name :code/hust/20160306/D.cpp
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
int n,A,B;
const int N=1E3+7;
struct node{
    int num;
    int da,db;
    int d;

    bool operator <(node b)const
    {
	return d<b.d;
    }
}q[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	ios::sync_with_stdio(false);

	while (scanf("%d %d %d",&n,&A,&B)!=EOF)
	{
	    if (n==0&&A==0&&B==0) break;
	    LL total = 0LL ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d %d %d",&q[i].num,&q[i].da,&q[i].db);
		q[i].d = q[i].da-q[i].db;
		total +=q[i].num;
	    }
	    sort(q+1,q+n+1);


	    LL ans =  0 ;
	    //check
	 //   for ( int i = 1; i  <= n ; i++) cout<<q[i].num<<" "<<q[i].da<<" "<<q[i].db<<endl;
	    
	    for ( int i =1 ; i <= n ; i++)
	    {
		ans +=q[i].db*q[i].num;
	    }
	 //   cout<<"prersum:"<<ans<<endl;
	    for (  int i = 1 ; i <= n ; i++)
	    {

		if (q[i].d>0)
		{
		    if (total <=B)
		    {
			//continue;
			break;
		    
		    }
		    else
		    {
			if (total -B <=q[i].num)
			{
			    ans +=(total-B)*q[i].d;
			    total = B;
			}
			else
			{
			    ans +=q[i].num*q[i].d;
			    total -=q[i].num;
			}
			
		    }
		}
		else
		{
		    if (A-q[i].num>=0)
		    {
			A-=q[i].num;
			ans += q[i].num*q[i].d;
			//		    cout<<"q[i].num:"<<q[i].num<<" "<<q[i].d<<endl;
			total -=q[i].num;
		    }
		    else if (A>0)
		    {
			ans += A*q[i].d;
			total -=A;
			A = 0 ;
		    }
		    //		cout<<"ans:"<<ans<<endl;
		}
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
