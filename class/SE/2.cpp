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
    void output()
    {
        printf("%.2f %.2f\n",x,y);
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
    double rad(point a,point b)
    {
    	point p=*this;
    	return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
	}
    point trunc(double r)
	{
		double l=len();
		if (!dblcmp(l))return *this;
		r/=l;
		return point(x*r,y*r);
	}
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
    	if (dblcmp(_a)==0)circle(point _p,double _r):
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
