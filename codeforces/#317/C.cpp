/*************************************************************************
	> File Name: code/cf/#317/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月14日 星期一 19时09分46秒
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
LL a,b,c,l,ans;
LL cal(LL a,LL b,LL c,LL l)
{
    LL mxv = a + b + c + l ;
    LL res = 0 ;
   // cout<<"max:"<<mxv<<endl;
    for ( int i = a ; i <= a +  l ; i++)
    {
	if ( b +  c > l ) continue;
	LL miv = min (LL(i),mxv-i)-b-c; //因为是找不满足两边之和大于第三边，所以要小于i
					//同时还由于范围最大为mxv,所以最大不能超过mvx-i

//	cout<<"miv:"<<miv<<endl;
	res  = res + (miv + 1) * (miv + 2)/2; //C(miv+2,2),三角形数
    }
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
//  freopen("%in.txt","r",stdin); 
  #endif
    cin>>a>>b>>c>>l;
    LL ans = (l+1)*(l+2)*(l+3)/6;
  //  cout<<"total:"<<ans<<endl;
    ans -= cal(a,b,c,l);
    ans -= cal(b,a,c,l);
    ans -= cal(c,a,b,l);
    cout<<ans<<endl;
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
