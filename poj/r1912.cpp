/*************************************************************************
	> File Name: code/poj/r1912.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月18日 星期三 21时07分47秒
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
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int N=1E5+7;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const double pi =acos(-1.0);
int dblcmp(double d)
{
    return d < -eps ? -1 : d > eps;
}
inline double sqr(double x){return x*x;}

struct point
{
    double x,y;
    point(){}
    point(double _x,double _y):
    x(_x),y(_y){};
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
   
    bool operator==(point a)const
    {
        return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
    }
    bool operator<(point a)const
    {
        return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
    }
    double len()
    {
        return hypot(x,y);
    }
    double len2()
    {
        return x*x+y*y;
    }
    double distance(point p)  //两点之间距离
    {
        return hypot(x-p.x,y-p.y);
    }
    double distance2(point p)
    {
        return sqr(x-p.x)+sqr(y-p.y);
    }
    point add(point p)
    {
        return point(x+p.x,y+p.y);
    }
    point operator + (const point & p) const{
        return point(x+p.x,y+p.y);
    }
    point sub(point p)
    {
        return point(x-p.x,y-p.y);
    }
    point operator - (const point & p) const{
        return point(x-p.x,y-p.y);
    }
    point mul(double b)
    {
        return point(x*b,y*b);
    }
    point div(double b)
    {
        return point(x/b,y/b);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double operator * (const point & p) const{
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
    double operator ^ (const point & p) const{
        return x*p.y-y*p.x;
    }
};
struct polygon
{
    int n;
    point p[N];
    line l[N];
    void input()
    {
        for (int i=0;i<n;i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
    	p[n++]=q;
    }
    void getline()
    {
        for (int i=0;i<n;i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp   //极角排序啊卧槽，原来有！！！
	{
	    point p;
	    cmp(const point &p0){p=p0;}
	    bool operator()(const point &aa,const point &bb)
	    {
	        point a=aa,b=bb;
	        int d=dblcmp(a.sub(p).det(b.sub(p)));
	        if (d==0)
	        {
	            return dblcmp(a.distance(p)-b.distance(p))<0;
	        }
	        return d>0;
	    }
	};
    void norm()
    {
        point mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex) //graham 
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    bool isconvex()
    {
    	bool s[3];
    	memset(s,0,sizeof(s));
    	int i,j,k;
    	for (i=0;i<n;i++)
    	{
    		j=(i+1)%n;
    		k=(j+1)%n;
    		s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1]=1;
    		if (s[0]&&s[2])return 0;
    	}
    	return 1;
    }
    //3 点上
	//2 边上
	//1 内部
	//0 外部
    int relationpoint(point q)
    {
    	int i,j;
    	for (i=0;i<n;i++)
    	{
    		if (p[i]==q)return 3;
    	}
    	getline();
    	for (i=0;i<n;i++)
    	{
    		if (l[i].pointonseg(q))return 2;
    	}
    	int cnt=0;
    	for (i=0;i<n;i++)
		{
			j=(i+1)%n;
			int k=dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
			int u=dblcmp(p[i].y-q.y);
			int v=dblcmp(p[j].y-q.y);
			if (k>0&&u<0&&v>=0)cnt++;
			if (k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
    }
    //1 在多边形内长度为正
    //2 相交或与边平行
	//0 无任何交点
    int relationline(line u)
    {
    	int i,j,k=0;
    	getline();
    	for (i=0;i<n;i++)
    	{
    		if (l[i].segcrossseg(u)==2)return 1;
    		if (l[i].segcrossseg(u)==1)k=1;
    	}
    	if (!k)return 0;
    	vector<point>vp;
    	for (i=0;i<n;i++)
    	{
    		if (l[i].segcrossseg(u))
    		{
    			if (l[i].parallel(u))
    			{
	    			vp.pb(u.a);
	    			vp.pb(u.b);
	    			vp.pb(l[i].a);
	    			vp.pb(l[i].b);
	    			continue;
    			}
    			vp.pb(l[i].crosspoint(u));
    		}
    	}
    	sort(vp.begin(),vp.end());
    	int sz=vp.size();
    	for (i=0;i<sz-1;i++)
    	{
    		point mid=vp[i].add(vp[i+1]).div(2);
    		if (relationpoint(mid)==1)return 1;
    	}
    	return 2;
    }
    //直线u切割凸多边形左侧
    //注意直线方向
    void convexcut(line u,polygon &po)
    {
        int i,j,k;
        int &top=po.n;
        top=0;
        for (i=0;i<n;i++)
        {
            int d1=dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
            int d2=dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
            if (d1>=0)po.p[top++]=p[i];
            if (d1*d2<0)po.p[top++]=u.crosspoint(line(p[i],p[(i+1)%n]));
        }
    }
    double getcircumference()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    bool getdir()//1代表逆时针 0代表顺时针
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        if (dblcmp(sum)>0)return 1;
        return 0;
    }
    point getbarycentre()
    {
        point ret(0,0);
        double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }

    double areacircle(circle c)
    {
		int i,j,k,l,m;
		double ans=0;
		for (i=0;i<n;i++)
		{
			int j=(i+1)%n;
			if (dblcmp(p[j].sub(c.p).det(p[i].sub(c.p)))>=0)
			{
				ans+=c.areatriangle(p[i],p[j]);
			}
			else
			{
				ans-=c.areatriangle(p[i],p[j]);
			}
		}
		return fabs(ans);
    }
    //多边形和圆关系
	//0 一部分在圆外
	//1 与圆某条边相切
	//2 完全在圆内
    int relationcircle(circle c)
    {
    	getline();
    	int i,x=2;
    	if (relationpoint(c.p)!=1)return 0;
    	for (i=0;i<n;i++)
    	{
    		if (c.relationseg(l[i])==2)return 0;
    		if (c.relationseg(l[i])==1)x=1;
    	}
    	return x;
    }
    void find(int st,point tri[],circle &c)
    {
    	if (!st)
    	{
    		c=circle(point(0,0),-2);
    	}
    	if (st==1)
    	{
    		c=circle(tri[0],0);
    	}
    	if (st==2)
    	{
    		c=circle(tri[0].add(tri[1]).div(2),tri[0].distance(tri[1])/2.0);
    	}
    	if (st==3)
    	{
    		c=circle(tri[0],tri[1],tri[2]);
    	}
    }
    void solve(int cur,int st,point tri[],circle &c)
    {
    	find(st,tri,c);
    	if (st==3)return;
    	int i;
    	for (i=0;i<cur;i++)
    	{
    		if (dblcmp(p[i].distance(c.p)-c.r)>0)
    		{
    			tri[st]=p[i];
    			solve(i,st+1,tri,c);
    		}
    	}
    }
    circle mincircle()//点集最小圆覆盖
	{
		random_shuffle(p,p+n);
		point tri[4];
		circle c;
		solve(n,0,tri,c);
	 	return c;
	}
	int circlecover(double r)//单位圆覆盖
	{
		int ans=0,i,j;
		vector<pair<double,int> >v;
		for (i=0;i<n;i++)
		{
			v.clear();
			for (j=0;j<n;j++)if (i!=j)
			{
				point q=p[i].sub(p[j]);
				double d=q.len();
				if (dblcmp(d-2*r)<=0)
				{
					double arg=atan2(q.y,q.x);
					if (dblcmp(arg)<0)arg+=2*pi;
					double t=acos(d/(2*r));
					v.push_back(make_pair(arg-t+2*pi,-1));
					v.push_back(make_pair(arg+t+2*pi,1));
				}
			}
			sort(v.begin(),v.end());
			int cur=0;
			for (j=0;j<v.size();j++)
			{
				if (v[j]/** 直线与凸多边形交点 */
	double theta[maxp];
	// 预处理凸包斜率，调整为升序
	void initLinecrossConvex(){
	    for (int i = 0; i < n ; ++i){
            point v = p[(i + 1) % n] - p[i];
            theta[i] = atan2(v.y , v.x);
	    }
	    for (int i = 1 ; i < n ; ++i)
            if (dblcmp(theta[i - 1] - theta[i]) > 0)
                theta[i] += 2. * pi;
	}
	//二分 [la , lb] 区间中与 li 相交的边
	int selectLine(int la , int lb , line li){
	    if (la > lb) lb += n;
	    int l = la , r = lb , mid;
	    while(l < r){
            mid = l + r + 1 >> 1;
            if (dblcmp((li.b - li.a) ^ (p[la] - li.a)) * dblcmp((li.b - li.a) ^ (p[mid % n] - li.a)) >= 0)
                l = mid;
            else r = mid - 1;
	    }
	    return l % n;
	}
	// 0 不相交
	// 1 相交于一个点
	// 2 相交于一条边
	// 3 规范相交
	int LinecrossConvex(line l , point &pa , point &pb){
	    //initLinecrossConvex
	    double tnow;
	    point v = l.b - l.a;
	    tnow = atan2(v.y , v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pl = lower_bound(theta , theta + n, tnow) - theta;
	    tnow = atan2(-v.y , -v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pr = lower_bound(theta , theta + n , tnow) - theta;
	    //pl 和 pr 是在 l 方向上的距离最远点对
	    pl %= n;
	    pr %= n;
	    if (dblcmp(v ^ (p[pl] - l.a)) == 0){
            pa = pb = p[pl];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pr] - l.a)) == 0){
            pa = pb = p[pr];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pl] - l.a)) * dblcmp(v ^ (p[pr] - l.a)) > 0) return 0;
	    int xa = selectLine(pl , pr , l);
	    int xb = selectLine(pr , pl , l);
	    if (xa > xb) swap(xa , xb);
	    // 与 [xa , xa + 1] 和 [xb , xb + 1] 相交
	    if (dblcmp(v ^ (p[(xa + 1) % n] - p[xa])) == 0){
            pa = p[xa];
            pb = p[(xa + 1) % n];
            return 2;
	    }
	    if (dblcmp(v ^ (p[(xb + 1) % n] - p[xb])) == 0){
            pa = p[xb];
            pb = p[(xb + 1) % n];
            return 2;
	    }
	    pa = line(p[xa] , p[(xa + 1) % n]).crosspoint(l);
	    pb = line(p[xb] , p[(xb + 1) % n]).crosspoint(l);
	    return 3;
	}
	
	int pointinpolygon(point q)//点在凸多边形内部的判定,在顶点和这条边形成的三角形内
	{
		if (getdir())reverse(p,p+n);
		if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0])))==0)
		{
			if (line(p[n-1],p[0]).pointonseg(q))return n-1;
			return -1;
		}
		int low=1,high=n-2,mid;
		while (low<=high)
		{
			mid=(low+high)>>1;
			if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>=0&&dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0])))<0)
			{
				polygon c;
				c.p[0]=p[mid];
				c.p[1]=p[mid+1];
				c.p[2]=p[0];
				c.n=3;
				if (c.relationpoint(q))return mid;
				return -1;
			}
			if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>0)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		return -1;
	struct circle
{
    point p;
    double r;
    circle(){}
    circle(point _p,double _r):
    p(_p),r(_r){};
    circle(double x,double y,double _r):
    p(point(x,y)),r(_r){};
    circle(point a,point b,point c)//三角形的外接圆
    {
    	p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
    	r=p.distance(a);
    }
    circle(point a,point b,point c,bool t)//三角形的内切圆
    {
    	line u,v;
    	double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
    	u.a=a;
		u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	v.a=b;
    	m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
    	v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	p=u.crosspoint(v);
    	r=line(a,b).dispointtoseg(p);
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
    void output()
    {
        printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
    }
    bool operator==(circle v)
    {
    	return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    bool operator<(circle v)const
    {
    	return ((p<v.p)||(p==v.p)&&dblcmp(r-v.r)<0);
    }
    double area()
    {
    	return pi*sqr(r);
    }
    double circumference()
    {
    	return 2*pi*r;
    }
    //0 圆外
    //1 圆上
    //2 圆内
    int relation(point b)
    {
        double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v)
    {
        double dst=v.dispointtoseg(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v)
    {
        double dst=v.dispointtoline(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    //过a b两点 半径r的两个圆
    int getcircle(point a,point b,double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    //与直线u相切 过点q 半径r1的圆
    int getcircle(line u,point q,double r1,circle &c1,circle &c2)
    {
    	double dis=u.dispointtoline(q);
    	if (dblcmp(dis-r1*2)>0)return 0;
    	if (dblcmp(dis)==0)
    	{
    		c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
    		c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
    		c1.r=c2.r=r1;
    		return 2;
    	}
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
		circle cc=circle(q,r1);
    	point p1,p2;
    	if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
    	c1=circle(p1,r1);
    	if (p1==p2)
		{
			c2=c1;return 1;
    	}
    	c2=circle(p2,r1);
    	return 2;
	}
	//同时与直线u,v相切 半径r1的圆
    int getcircle(line u,line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
    	if (u.parallel(v))return 0;
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
    	line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
    	line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
    	c1.r=c2.r=c3.r=c4.r=r1;
    	c1.p=u1.crosspoint(v1);
    	c2.p=u1.crosspoint(v2);
    	c3.p=u2.crosspoint(v1);
    	c4.p=u2.crosspoint(v2);
    	return 4;
	}
	//同时与不相交圆cx,cy相切 半径为r1的圆
	int getcircle(circle cx,circle cy,double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)//求与线段交要先判断relationseg
    {
        if (!(*this).relationline(v))return 0;
        point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (dblcmp(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    //5 相离
	//4 外切
	//3 相交
	//2 内切
	//1 内含
    int relationcircle(circle v)
    {
    	double d=p.distance(v.p);
    	if (dblcmp(d-r-v.r)>0)return 5;
    	if (dblcmp(d-r-v.r)==0)return 4;
    	double l=fabs(r-v.r);
    	if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
    	if (dblcmp(d-l)==0)return 2;
    	if (dblcmp(d-l)<0)return 1;
    }
    int pointcrosscircle(circle v,point &p1,point &p2)
    {
    	int rel=relationcircle(v);
    	if (rel==1||rel==5)return 0;
   		double d=p.distance(v.p);
   		double l=(d+(sqr(r)-sqr(v.r))/d)/2;
   		double h=sqrt(sqr(r)-sqr(l));
   		p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
    	p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
    	if (rel==2||rel==4)
    	{
    		return 1;
    	}
		return 2;
    }
    //过一点做圆的切线 (先判断点和圆关系)
    int tangentline(point q,line &u,line &v)
    {
    	int x=relation(q);
    	if (x==2)return 0;
    	if (x==1)
    	{
    		u=line(q,q.add(q.sub(p).rotleft()));
    		v=u;
    		return 1;
    	}
    	double d=p.distance(q);
    	double l=sqr(r)/d;
    	double h=sqrt(sqr(r)-sqr(l));
    	u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
    	v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
    	return 2;
	}
    double areacircle(circle v)
    {
    	int rel=relationcircle(v);
    	if (rel>=4)return 0.0;
  	  	if (rel<=2)return min(area(),v.area());
  	  	double d=p.distance(v.p);
  	  	double hf=(r+v.r+d)/2.0;
  	  	double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
  	  	double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
  	  	a1=a1*r*r;
  	  	double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
  	  	a2=a2*v.r*v.r;
  	  	return a1+a2-ss;
    }
    double areatriangle(point a,point b)
    {
        if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        double res=0;
        int i;struct circle
{
    point p;
    double r;
    circle(){}
    circle(point _p,double _r):
    p(_p),r(_r){};
    circle(double x,double y,double _r):
    p(point(x,y)),r(_r){};
    circle(point a,point b,point c)//三角形的外接圆
    {
    	p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
    	r=p.distance(a);
    }
    circle(point a,point b,point c,bool t)//三角形的内切圆
    {
    	line u,v;
    	double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
    	u.a=a;
		u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	v.a=b;
    	m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
    	v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	p=u.crosspoint(v);
    	r=line(a,b).dispointtoseg(p);
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
    void output()
    {
        printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
    }
    bool operator==(circle v)
    {
    	return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    bool operator<(circle v)const
    {
    	return ((p<v.p)||(p==v.p)&&dblcmp(r-v.r)<0);
    }
    double area()
    {
    	return pi*sqr(r);
    }
    double circumference()
    {
    	return 2*pi*r;
    }
    //0 圆外
    //1 圆上
    //2 圆内
    int relation(point b)
    {
        double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v)
    {
        double dst=v.dispointtoseg(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v)
    {
        double dst=v.dispointtoline(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    //过a b两点 半径r的两个圆
    int getcircle(point a,point b,double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    //与直线u相切 过点q 半径r1的圆
    int getcircle(line u,point q,double r1,circle &c1,circle &c2)
    {
    	double dis=u.dispointtoline(q);
    	if (dblcmp(dis-r1*2)>0)return 0;
    	if (dblcmp(dis)==0)
    	{
    		c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
    		c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
    		c1.r=c2.r=r1;
    		return 2;
    	}
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
		circle cc=circle(q,r1);
    	point p1,p2;
    	if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
    	c1=circle(p1,r1);
    	if (p1==p2)
		{
			c2=c1;return 1;
    	}
    	c2=circle(p2,r1);
    	return 2;
	}
	//同时与直线u,v相切 半径r1的圆
    int getcircle(line u,line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
    	if (u.parallel(v))return 0;
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
    	line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
    	line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
    	c1.r=c2.r=c3.r=c4.r=r1;
    	c1.p=u1.crosspoint(v1);
    	c2.p=u1.crosspoint(v2);
    	c3.p=u2.crosspoint(v1);
    	c4.p=u2.crosspoint(v2);
    	return 4;
	}
	//同时与不相交圆cx,cy相切 半径为r1的圆
	int getcircle(circle cx,circle cy,double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)//求与线段交要先判断relationseg
    {
        if (!(*this).relationline(v))return 0;
        point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (dblcmp(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    //5 相离
	//4 外切
	//3 相交
	//2 内切
	//1 内含
    int relationcircle(circle v)
    {
    	double d=p.distance(v.p);
    	if (dblcmp(d-r-v.r)>0)return 5;
    	if (dblcmp(d-r-v.r)==0)return 4;
    	double l=fabs(r-v.r);
    	if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
    	if (dblcmp(d-l)==0)return 2;
    	if (dblcmp(d-l)<0)return 1;
    }
    int pointcrosscircle(circle v,point &p1,point &p2)
    {
    	int rel=relationcircle(v);
    	if (rel==1||rel==5)return 0;
   		double d=p.distance(v.p);
   		double l=(d+(sqr(r)-sqr(v.r))/d)/2;
   		double h=sqrt(sqr(r)-sqr(l));
   		p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
    	p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
    	if (rel==2||rel==4)
    	{
    		return 1;
    	}
		return 2;
    }
    //过一点做圆的切线 (先判断点和圆关系)
    int tangentline(point q,line &u,line &v)
    {
    	int x=relation(q);
    	if (x==2)return 0;
    	if (x==1)
    	{
    		u=line(q,q.add(q.sub(p).rotleft()));
    		v=u;
    		return 1;
    	}
    	double d=p.distance(q);
    	double l=sqr(r)/d;
    	double h=sqrt(sqr(r)-sqr(l));
    	u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
    	v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
    	return 2;
	}
    double areacircle(circle v)
    {
    	int rel=relationcircle(v);
    	if (rel>=4)return 0.0;
  	  	if (rel<=2)return min(area(),v.area());
  	  	double d=p.distance(v.p);
  	  	double hf=(r+v.r+d)/2.0;
  	  	double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
  	  	double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
  	  	a1=a1*r*r;
  	  	double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
  	  	a2=a2*v.r*v.r;
  	  	return a1+a2-ss;
    }
    double areatriangle(point a,point b)
    {
        if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else
            {
                res+=fabs(q[i].sub(p).det(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
};
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,double angle)//绕点p逆时针旋转angle角度
    {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};
struct line
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
    	return (a==v.a)&&(b==v.b);
    }
    //倾斜角angle
    line(point p,double angle)
    {
    	a=p;
    	if (dblcmp(angle-pi/2)==0)
    	{
    		b=a.add(point(0,1));
    	}
    	else
    	{
    		b=a.add(point(1,tan(angle)));
    	}
    }
    //ax+by+c=0
    line(double _a,double _b,double _c)
    {
    	if (dblcmp(_a)==0)
    	{
    		a=point(0,-_c/_b);
    		b=point(1,-_c/_b);
    	}
    	else if (dblcmp(_b)==0)
    	{
    		a=point(-_c/_a,0);
    		b=point(-_c/_a,1);
    	}
    	else
    	{
    		a=point(0,-_c/_b);
    		b=point(1,(-_c-_a)/_b);
    	}
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
    	if (b<a)swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }
    double angle()//直线倾斜角 0<=angle<180
	{
		double k=atan2(b.y-a.y,b.x-a.x);
		if (dblcmp(k)<0)k+=pi;
		if (dblcmp(k-pi)==0)k-=pi;
		return k;
	}
    //点和线段关系
    //1 在逆时针
    //2 在顺时针
    //3 平行
    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    //2 规范相交
    //1 非规范相交 ()
    //0 不相交
}li;
struct polygon
{
    int n;
    point p[N];
    line l[N];
    void input()
    {
        for (int i=0;i<n;i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
    	p[n++]=q;
    }
    void getline()
    {
        for (int i=0;i<n;i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp   //极角排序啊卧槽，原来有！！！
	{
	    point p;
	    cmp(const point &p0){p=p0;}
	    bool operator()(const point &aa,const point &bb)
	    {
	        point a=aa,b=bb;
	        int d=dblcmp(a.sub(p).det(b.sub(p)));
	        if (d==0)
	        {
	            return dblcmp(a.distance(p)-b.distance(p))<0;
	        }
	        return d>0;
	    }
	};
    void norm()
    {
        point mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex) //graham 
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    //3 点上
	//2 边上
	//1 内部
	//0 外部
    double getcircumference()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    bool getdir()//1代表逆时针 0代表顺时针
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        if (dblcmp(sum)>0)return 1;
        return 0;
    }
    point getbarycentre()
    {
        point ret(0,0);
        double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }

    double areacircle(circle c)
    {
		int i,j,k,l,m;
		double ans=0;
		for (i=0;i<n;i++)
		{
			int j=(i+1)%n;
			if (dblcmp(p[j].sub(c.p).det(p[i].sub(c.p)))>=0)
			{
				ans+=c.areatriangle(p[i],p[j]);
			}
			else
			{
				ans-=c.areatriangle(p[i],p[j]);
			}
		}
		return fabs(ans);
    }
    //多边形和圆关系
	//0 一部分在圆外
	//1 与圆某条边相切
	//2 完全在圆内
    int relationcircle(circle c)
    {
    	getline();
    	int i,x=2;
    	if (relationpoint(c.p)!=1)return 0;
    	for (i=0;i<n;i++)
    	{
    		if (c.relationseg(l[i])==2)return 0;
    		if (c.relationseg(l[i])==1)x=1;
    	}
    	return x;
    }
    void find(int st,point tri[],circle &c)
    {
    	if (!st)
    	{
    		c=circle(point(0,0),-2);
    	}
    	if (st==1)
    	{
    		c=circle(tri[0],0);
    	}
    	if (st==2)
    	{
    		c=circle(tri[0].add(tri[1]).div(2),tri[0].distance(tri[1])/2.0);
    	}
    	if (st==3)
    	{
    		c=circle(tri[0],tri[1],tri[2]);
    	}
    }
    void solve(int cur,int st,point tri[],circle &c)
    {
    	find(st,tri,c);
    	if (st==3)return;
    	int i;
    	for (i=0;i<cur;i++)
    	{
    		if (dblcmp(p[i].distance(c.p)-c.r)>0)
    		{
    			tri[st]=p[i];
    			solve(i,st+1,tri,c);
    		}
    	}
    }
    circle mincircle()//点集最小圆覆盖
	{
		random_shuffle(p,p+n);
		point tri[4];
		circle c;
		solve(n,0,tri,c);
	 	return c;
	}
	int circlecover(double r)//单位圆覆盖
	{
		int ans=0,i,j;
		vector<pair<double,int> >v;
		for (i=0;i<n;i++)
		{
			v.clear();
			for (j=0;j<n;j++)if (i!=j)
			{
				point q=p[i].sub(p[j]);
				double d=q.len();
				if (dblcmp(d-2*r)<=0)
				{
					double arg=atan2(q.y,q.x);
					if (dblcmp(arg)<0)arg+=2*pi;
					double t=acos(d/(2*r));
					v.push_back(make_pair(arg-t+2*pi,-1));
					v.push_back(make_pair(arg+t+2*pi,1));
				}
			}
			sort(v.begin(),v.end());
			int cur=0;
			for (j=0;j<v.size();j++)
			{
				if (v[j]/** 直线与凸多边形交点 */
	double theta[maxp];
	// 预处理凸包斜率，调整为升序
	void initLinecrossConvex(){
	    for (int i = 0; i < n ; ++i){
            point v = p[(i + 1) % n] - p[i];
            theta[i] = atan2(v.y , v.x);
	    }
	    for (int i = 1 ; i < n ; ++i)
            if (dblcmp(theta[i - 1] - theta[i]) > 0)
                theta[i] += 2. * pi;
	}
	//二分 [la , lb] 区间中与 li 相交的边
	int selectLine(int la , int lb , line li){
	    if (la > lb) lb += n;
	    int l = la , r = lb , mid;
	    while(l < r){
            mid = l + r + 1 >> 1;
            if (dblcmp((li.b - li.a) ^ (p[la] - li.a)) * dblcmp((li.b - li.a) ^ (p[mid % n] - li.a)) >= 0)
                l = mid;
            else r = mid - 1;
	    }
	    return l % n;
	}
	// 0 不相交
	// 1 相交于一个点
	// 2 相交于一条边
	// 3 规范相交
	int LinecrossConvex(line l , point &pa , point &pb){
	    //initLinecrossConvex
	    double tnow;
	    point v = l.b - l.a;
	    tnow = atan2(v.y , v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pl = lower_bound(theta , theta + n, tnow) - theta;
	    tnow = atan2(-v.y , -v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pr = lower_bound(theta , theta + n , tnow) - theta;
	    //pl 和 pr 是在 l 方向上的距离最远点对
	    pl %= n;
	    pr %= n;
	    if (dblcmp(v ^ (p[pl] - l.a)) == 0){
            pa = pb = p[pl];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pr] - l.a)) == 0){
            pa = pb = p[pr];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pl] - l.a)) * dblcmp(v ^ (p[pr] - l.a)) > 0) return 0;
	    int xa = selectLine(pl , pr , l);
	    int xb = selectLine(pr , pl , l);
	    if (xa > xb) swap(xa , xb);
	    // 与 [xa , xa + 1] 和 [xb , xb + 1] 相交
	    if (dblcmp(v ^ (p[(xa + 1) % n] - p[xa])) == 0){
            pa = p[xa];
            pb = p[(xa + 1) % n];
            return 2;
	    }
	    if (dblcmp(v ^ (p[(xb + 1) % n] - p[xb])) == 0){
            pa = p[xb];
            pb = p[(xb + 1) % n];
            return 2;
	    }
	    pa = line(p[xa] , p[(xa + 1) % n]).crosspoint(l);
	    pb = line(p[xb] , p[(xb + 1) % n]).crosspoint(l);
	    return 3;
	}
	
	int pointinpolygon(point q)//点在凸多边形内部的判定,在顶点和这条边形成的三角形内
	{
		if (getdir())reverse(p,p+n);
		if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0])))==0)
		{
			if (line(p[n-1],p[0]).pointonseg(q))return n-1;
			return -1;
		}
		int low=1,high=n-2,mid;
		while (low<=high)
		{
			mid=(low+high)>>1;
			if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>=0&&dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0])))<0)
			{
				polygon c;
				c.p[0]=p[mid];
				c.p[1]=p[mid+1];
				c.p[2]=p[0];
				c.n=3;
				if (c.relationpoint(q))return mid;
				return -1;
			}
			if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>0)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		return -1;
	struct circle
{
    point p;
    double r;
    circle(){}
    circle(point _p,double _r):
    p(_p),r(_r){};
    circle(double x,double y,double _r):
    p(point(x,y)),r(_r){};
    circle(point a,point b,point c)//三角形的外接圆
    {
    	p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crosspoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
    	r=p.distance(a);
    }
    circle(point a,point b,point c,bool t)//三角形的内切圆
    {
    	line u,v;
    	double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
    	u.a=a;
		u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	v.a=b;
    	m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
    	v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
    	p=u.crosspoint(v);
    	r=line(a,b).dispointtoseg(p);
    }
    void input()
    {
        p.input();
        scanf("%lf",&r);
    }
    void output()
    {
        printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r);
    }
    bool operator==(circle v)
    {
    	return ((p==v.p)&&dblcmp(r-v.r)==0);
    }
    bool operator<(circle v)const
    {
    	return ((p<v.p)||(p==v.p)&&dblcmp(r-v.r)<0);
    }
    double area()
    {
    	return pi*sqr(r);
    }
    double circumference()
    {
    	return 2*pi*r;
    }
    //0 圆外
    //1 圆上
    //2 圆内
    int relation(point b)
    {
        double dst=b.distance(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationseg(line v)
    {
        double dst=v.dispointtoseg(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    int relationline(line v)
    {
        double dst=v.dispointtoline(p);
        if (dblcmp(dst-r)<0)return 2;
        if (dblcmp(dst-r)==0)return 1;
        return 0;
    }
    //过a b两点 半径r的两个圆
    int getcircle(point a,point b,double r,circle&c1,circle&c2)
    {
        circle x(a,r),y(b,r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    //与直线u相切 过点q 半径r1的圆
    int getcircle(line u,point q,double r1,circle &c1,circle &c2)
    {
    	double dis=u.dispointtoline(q);
    	if (dblcmp(dis-r1*2)>0)return 0;
    	if (dblcmp(dis)==0)
    	{
    		c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
    		c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
    		c1.r=c2.r=r1;
    		return 2;
    	}
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
		circle cc=circle(q,r1);
    	point p1,p2;
    	if (!cc.pointcrossline(u1,p1,p2))cc.pointcrossline(u2,p1,p2);
    	c1=circle(p1,r1);
    	if (p1==p2)
		{
			c2=c1;return 1;
    	}
    	c2=circle(p2,r1);
    	return 2;
	}
	//同时与直线u,v相切 半径r1的圆
    int getcircle(line u,line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
    	if (u.parallel(v))return 0;
    	line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
    	line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
    	line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
    	line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
    	c1.r=c2.r=c3.r=c4.r=r1;
    	c1.p=u1.crosspoint(v1);
    	c2.p=u1.crosspoint(v2);
    	c3.p=u2.crosspoint(v1);
    	c4.p=u2.crosspoint(v2);
    	return 4;
	}
	//同时与不相交圆cx,cy相切 半径为r1的圆
	int getcircle(circle cx,circle cy,double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointcrosscircle(y,c1.p,c2.p);
		if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    int pointcrossline(line v,point &p1,point &p2)//求与线段交要先判断relationseg
    {
        if (!(*this).relationline(v))return 0;
        point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (dblcmp(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    //5 相离
	//4 外切
	//3 相交
	//2 内切
	//1 内含
    int relationcircle(circle v)
    {
    	double d=p.distance(v.p);
    	if (dblcmp(d-r-v.r)>0)return 5;
    	if (dblcmp(d-r-v.r)==0)return 4;
    	double l=fabs(r-v.r);
    	if (dblcmp(d-r-v.r)<0&&dblcmp(d-l)>0)return 3;
    	if (dblcmp(d-l)==0)return 2;
    	if (dblcmp(d-l)<0)return 1;
    }
    int pointcrosscircle(circle v,point &p1,point &p2)
    {
    	int rel=relationcircle(v);
    	if (rel==1||rel==5)return 0;
   		double d=p.distance(v.p);
   		double l=(d+(sqr(r)-sqr(v.r))/d)/2;
   		double h=sqrt(sqr(r)-sqr(l));
   		p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
    	p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
    	if (rel==2||rel==4)
    	{
    		return 1;
    	}
		return 2;
    }
    //过一点做圆的切线 (先判断点和圆关系)
    int tangentline(point q,line &u,line &v)
    {
    	int x=relation(q);
    	if (x==2)return 0;
    	if (x==1)
    	{
    		u=line(q,q.add(q.sub(p).rotleft()));
    		v=u;
    		return 1;
    	}
    	double d=p.distance(q);
    	double l=sqr(r)/d;
    	double h=sqrt(sqr(r)-sqr(l));
    	u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
    	v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
    	return 2;
	}
    double areacircle(circle v)
    {
    	int rel=relationcircle(v);
    	if (rel>=4)return 0.0;
  	  	if (rel<=2)return min(area(),v.area());
  	  	double d=p.distance(v.p);
  	  	double hf=(r+v.r+d)/2.0;
  	  	double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
  	  	double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
  	  	a1=a1*r*r;
  	  	double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
  	  	a2=a2*v.r*v.r;
  	  	return a1+a2-ss;
    }
    double areatriangle(point a,point b)
    {
        if (dblcmp(p.sub(a).det(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointcrossline(l,q[1],q[2])==2)
        {
            if (dblcmp(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (dblcmp(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(dblcmp(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))swap(q[1],q[2]);
        double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else
            {
                res+=fabs(q[i].sub(p).det(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
};}


/** Unchecked */

	/** 直线与凸多边形交点 */
	double theta[maxp];
	// 预处理凸包斜率，调整为升序
	void initLinecrossConvex(){
	    for (int i = 0; i < n ; ++i){
            point v = p[(i + 1) % n] - p[i];
            theta[i] = atan2(v.y , v.x);
	    }
	    for (int i = 1 ; i < n ; ++i)
            if (dblcmp(theta[i - 1] - theta[i]) > 0)
                theta[i] += 2. * pi;
	}
	//二分 [la , lb] 区间中与 li 相交的边
	int selectLine(int la , int lb , line li){
	    if (la > lb) lb += n;
	    int l = la , r = lb , mid;
	    while(l < r){
            mid = l + r + 1 >> 1;
            if (dblcmp((li.b - li.a) ^ (p[la] - li.a)) * dblcmp((li.b - li.a) ^ (p[mid % n] - li.a)) >= 0)
                l = mid;
            else r = mid - 1;
	    }
	    return l % n;
	}
	// 0 不相交
	// 1 相交于一个点
	// 2 相交于一条边
	// 3 规范相交
	int LinecrossConvex(line l , point &pa , point &pb){
	    //initLinecrossConvex
	    double tnow;
	    point v = l.b - l.a;
	    tnow = atan2(v.y , v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pl = lower_bound(theta , theta + n, tnow) - theta;
	    tnow = atan2(-v.y , -v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2.0 * pi;
	    int pr = lower_bound(theta , theta + n , tnow) - theta;
	    //pl 和 pr 是在 l 方向上的距离最远点对
	    pl %= n;
	    pr %= n;
	    if (dblcmp(v ^ (p[pl] - l.a)) == 0){
            pa = pb = p[pl];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pr] - l.a)) == 0){
            pa = pb = p[pr];
            return 1;
	    }
	    if (dblcmp(v ^ (p[pl] - l.a)) * dblcmp(v ^ (p[pr] - l.a)) > 0) return 0;
	    int xa = selectLine(pl , pr , l);
	    int xb = selectLine(pr , pl , l);
	    if (xa > xb) swap(xa , xb);
	    // 与 [xa , xa + 1] 和 [xb , xb + 1] 相交
	    if (dblcmp(v ^ (p[(xa + 1) % n] - p[xa])) == 0){
            pa = p[xa];
            pb = p[(xa + 1) % n];
            return 2;
	    }
	    if (dblcmp(v ^ (p[(xb + 1) % n] - p[xb])) == 0){
            pa = p[xb];
            pb = p[(xb + 1) % n];
            return 2;
	    }
	    pa = line(p[xa] , p[(xa + 1) % n]).crosspoint(l);
	    pb = line(p[xb] , p[(xb + 1) % n]).crosspoint(l);
	    return 3;
	}

	/** 求点对于凸包的两个切点 */
	int selectLine(int la , int lb , int dir , point s){
	    if (la > lb) lb += n;
	    if (la == lb) return la;
	    int l = la + 1, r = lb , mid;
	    while(l < r){
            mid = l + r + 1 >> 1;
            int ret = dblcmp((p[mid % n] - s) ^ (p[(mid + n - 1) % n] - s));
            if (dir * ret < 0)
                l = mid;
            else if (dir * ret > 0)
                r = mid - 1;
            else{
                if (dir == 1) l = mid;
                else r = mid - 1;
            }
	    }

	    int ret = dblcmp((p[l % n] - s) ^ (p[(l + n - 1) % n] - s));
	    if (dir * ret < 0) return l % n;
	    if (dir * ret > 0) return (l + n - 1) % n;
	    if (dir == 1) return l % n;
	    return (l + n - 1) % n;
	}
	void pointTangentconvex(point s , int &pl , int &pr){
	    //initLinecrossConvex
	    line l = line(s , p[0]);
	    point v = l.b - l.a;
	    double tnow = atan2(v.y , v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2. * pi;
	    int tpl = lower_bound(theta , theta + n , tnow) - theta;
	    tnow = atan2(-v.y , -v.x);
	    if (dblcmp(tnow - theta[0]) < 0) tnow += 2. * pi;
	    int tpr = lower_bound(theta , theta + n , tnow) - theta;
	    pl = tpl = tpl % n;
	    pr = tpr = tpr % n;

	    int px = selectLine(pr , pl , l);
	    // pr -> px , px -> pl
	    pl = selectLine(tpr , px , 1 , s);
	    pr = selectLine(px , tpl , -1 , s);
	}
}pol,conv;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   pol.n = n;
   pol.input();
   pol.getconvex(conv);

   while (scanf("%lf %lf %lf %lf",&li.a.x,&li.a.y,&li.b.x,&li.b.y)!=EOF)
    {
	point p1,p2;
	int ret = conv.linecrossline(li,p1,p2);
	cout<<"ret:"<<ret<<end;
    }


   
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
