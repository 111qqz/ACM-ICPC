#include <bits/stdc++.h>
#define  ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int N=200005,mod=2012;
char s[N];
int n;
struct sam{
	  int p,q,np,nq,cnt,last,a[N][11],l[N],f[N];
	  sam(){cnt=0;last=++cnt;}
	  void init(){
	      cnt=0;last=++cnt;
	      ms(a,0);ms(l,0);ms(f,0);ms(b,0);ms(x,0);ms(sum,0);ms(t,0);
	  }
	  void extend(int c){
		    p=last;np=last=++cnt;l[np]=l[p]+1;
		    while(!a[p][c]&&p)a[p][c]=np,p=f[p];
		    if(!p)f[np]=1;
		    else{
			      q=a[p][c];
			      if(l[p]+1==l[q])f[np]=q;
			      else{
				        nq=++cnt;l[nq]=l[p]+1;
				        memcpy(a[nq],a[q],sizeof(a[q]));
				        f[nq]=f[q]; f[np]=f[q]=nq;
				        while(a[p][c]==q)a[p][c]=nq,p=f[p];
			      }
		    }
	  }int b[N],x[N]; // for radix sort
	  void build(){
	      int len=0;
	      while(n--){
	          scanf("%s",s);
		        for(int i=0;s[i];i++)len++,extend(s[i]-'0');
		        extend(10),len++;
		    }for(int i=1;i<=cnt;i++)b[l[i]]++;
		    for(int i=1;i<=len;i++)b[i]+=b[i-1];
		    for(int i=1;i<=cnt;i++)x[b[l[i]]--]=i;
	  }int sum[N],t[N];
	  // t[i]表示到达状态i的路径数量，sum[i]表示到达该节点的路径所表示的答案大小。
	  //做dp
	  //sum[i]表示处理到第i个状态
	  int solve(){
	  	  int ans=0;
	      sum[1]=0; t[1]=1;
	      for(int i=1;i<=cnt;i++){
	          int p=x[i];
	          for(int j=0;j<10;j++){
	              if(i==1&&j==0)continue;
	              if(a[p][j]){
	                  q=a[p][j];
	                  t[q]=(t[p]+t[q])%mod;
	                  sum[q]=(sum[q]+sum[p]*10+t[p]*j)%mod;
	              }
	          }ans=(ans+sum[p])%mod;
	      }return ans;
	  }
}sam;
int main(){
    while(~scanf("%d",&n)){
    	  sam.init();
        sam.build();
        printf("%d\n",sam.solve());
}return 0;
}
