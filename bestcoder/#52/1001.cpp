/*************************************************************************
	> File Name: code/bc/#52/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月22日 星期六 18时51分44秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
  #endif
    int x,y,w,n;
    while (scanf("%d%d%d%d",&x,&y,&w,&n)!=EOF){
	int num = 1;
	int cnt;
	int q;
	bool on = true;
	bool flag = false;
	int t = 0;
	while (t<N&&!flag){
	    if (num==n) {
		cout<<t<<endl;
		flag = true;
		break;
	    }
	    cnt = t+x;
	    q =  0;
	    while (t<cnt){
		q++;
		t++;
		if (q%w==0){
//		     cout<<"aaat:"<<t<<endl;
		     num++;
		}
	    if (num == n){
		cout<<t<<endl;
		flag = true;
		break;
	    }
	    }
	    on = false;
	    t = t + y;
	    on = true;
	    num++;
	    if (num==n){
		cout<<t<<endl;
		flag = true;
	    }

	}

    }


    
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
