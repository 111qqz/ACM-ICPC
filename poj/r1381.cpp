//*Author:Hacker_vision*/
#include<bits/stdc++.h>
using namespace std;

const int _max=1e3+10;
int Xr,Xi,Br,Bi,limit;
bool ok;
int tot,ans[_max];

void dfs(int Xr,int Xi,int deep){

  if(deep>100||ok)return;
  cout<<"real:"<<Xr<<" img:"<<Xi<<" deep:"<<deep<<endl;
  if(Xr==0&&Xi==0){
    tot=deep;//记录序列{an}的长度
    ok=true;//标记ok判断存在性
    return;
  }
  int a,b;//中间变量而已
  for(int i = 0; i*i < limit; ++ i) {
    ans[deep]=i;
    a=(Xr-i)*Br+Xi*Bi;
    b=Xi*Br-(Xr-i)*Bi;
    cout<<"a:"<<a<<" b:"<<b<<endl;
    if(a%limit==0&&b%limit==0){ //序列{an}一定都为整数，整除是必要的
      dfs(a/limit,b/limit,deep+1);
      if(ok) return;
    }
  }
}

int main(){
 freopen("code/in.txt","r",stdin);
 int T;cin>>T;
 while(T--){
   scanf("%d%d%d%d",&Xr,&Xi,&Br,&Bi);
   limit=Br*Br+Bi*Bi;
   ok=false;
   dfs(Xr,Xi,0);
   if(!ok) {puts("The code cannot be decrypted.");continue;}
   printf("%d",ans[tot-1]);//逆序输出
   for( int i=tot-2;i>=0;i--) printf(",%d",ans[i]);
   puts("");
 }
 return 0;
}

