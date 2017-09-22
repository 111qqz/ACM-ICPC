#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
const int maxn=10010;
using namespace std;
int n;double mins=1e100;
struct poi{double x,y,g;}p[maxn],ans;
double dis(const poi &a,const poi &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double check(poi a){
	double res=0.0;
	for (int i=1;i<=n;i++) res+=dis(a,p[i])*p[i].g;
	if (res<mins) ans=a,mins=res;
	return res;
}
double getrd(){return rand()%10000/10000.0;}

void SA(double T){
	poi now=ans;
	while (T>0.001){
		poi newp;
		newp.x=now.x+T*(getrd()*2-1.0);
		newp.y=now.y+T*(getrd()*2-1.0);
		double delta=check(now)-check(newp);
		if (delta>0||exp(delta/T)>getrd()) now=newp;
		T*=0.991;
	}
	for (int i=1;i<=1000;i++){
		poi newp;
		newp.x=ans.x+T*(getrd()*2-1.0);
		newp.y=ans.y+T*(getrd()*2-1.0);
		check(newp);
	}
}

int main(){
	srand(8226312452);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].g);
		ans.x+=p[i].x,ans.y+=p[i].y;
	}
	ans.x/=(double)n,ans.y/=(double)n;
	SA(100000.0);
	printf("%.3lf %.3lf\n",ans.x,ans.y);
	return 0;
}
