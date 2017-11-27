   







#                       ACM-ICPC 模板

















































































































[TOC]



##组合数学

####Mobius反演

```c++
oid mobius(){
	memset(flag,0,sizeof(flag));
	tot=0;miu[1]=1;
	for(int i=2;i<maxn;i++){
		if(!flag[i]){
			p[tot++]=i;
			miu[i]=-1;
		}
		for(int j=0;j<tot && i*p[j]<maxn;j++){
			flag[i*p[j]]=true;
			if(i%p[j]) miu[i*p[j]]=-miu[i];
			else{
				miu[i*p[j]]=0;break;
			}
		}
	}
}
```
####组合数取模

求C(n,m)%p
（1）1=<m<=n<=1000 和 1<=p<=1E9
 这个问题比较简单，组合数的计算可以靠杨辉三角，那么由于n和m的范围小，直接两层循环即可。
 （2）1<=m<=n<=1E18,2<=p<=1E5,p是素数

	LL n,m,p;  

```c++
LL quick_mod(LL a, LL b)  
{  
    LL ans = 1;  
    a %= p;  
    while(b)  
    {  
	if(b & 1)  
	{  
	    ans = ans * a % p;  
	    b--;  
	}  
	b >>= 1;  
	a = a * a % p;  
    }  
    return ans;  
}  
  
LL C(LL n, LL m)  
{  
    if(m > n) return 0;  
    LL ans = 1;  
    for(int i=1; i<=m; i++)  
    {  
	LL a = (n + i - m) % p;  
	LL b = i % p;  
	ans = ans * (a * quick_mod(b, p-2) % p) % p;  
    }  
    return ans;  
}  
  
LL Lucas(LL n, LL m)  
{  
    if(m == 0) return 1;  
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;  
}  
  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while(T--)  
    {  
	scanf("%I64d%I64d%I64d", &n, &m, &p);  
	printf("%I64d\n", Lucas(n,m));  
    }  
    return 0;  
}  
```

 （3）1<=m<=n<=1E6,2<=p<=1E5,p可能是合数
 这样的话先采取暴力分解，然后快速幂即可。

```c++
 const int N = 200005;  
bool prime[N];  
int p[N];  
int cnt;  
void isprime()  
{  
    cnt = 0;  
    memset(prime,true,sizeof(prime));  
    for(int i=2; i<N; i++)  
    {  
	if(prime[i])  
	{  
	    p[cnt++] = i;  
	    for(int j=i+i; j<N; j+=i)  
	        prime[j] = false;  
	}  
    }  
}  
LL quick_mod(LL a,LL b,LL m)  
{  
    LL ans = 1;  
    a %= m;  
    while(b)  
    {  
	if(b & 1)  
	{  
	    ans = ans * a % m;  
	    b--;  
	}  
	b >>= 1;  
	a = a * a % m;  
    }  
    return ans;  
}  
LL Work(LL n,LL p)  
{  
    LL ans = 0;  
    while(n)  
    {  
	ans += n / p;  
	n /= p;  
    }  
    return ans;  
}  
LL Solve(LL n,LL m,LL P)  
{  
    LL ans = 1;  
    for(int i=0; i<cnt && p[i]<=n; i++)  
    {  
	LL x = Work(n, p[i]);  
	LL y = Work(n - m, p[i]);  
	LL z = Work(m, p[i]);  
	x -= (y + z);  
	ans *= quick_mod(p[i],x,P);  
	ans %= P;  
    }  
    return ans;  
}  
int main()  
{  
    int T;  
    isprime();  
    cin>>T;  
   while(T--)  
    {  
	LL n,m,P;  
	cin>>n>>m>>P;  
	n += m - 2;  
	m--;  
	cout<<Solve(n,m,P)<<endl;  
    }  
    return 0;  

}

```



##数据结构

####kd树
#####动态k-d树（带插入），曼哈顿距离
bzoj 2716 现在有n个在二维平面，m个操作，2种类型，一种是加入一个点，另一种是对于一个定点，询问距离其最近的点的距离。

```c++
const LL linf = 1LL<<60;
const int N=5E5+7;
int n,m;
int idx,rt;
LL ans;
struct KDT
{
    LL coor[2];
    LL mn[2],mx[2]; //需要维护四个方向的最值，是因为是曼哈顿距离。
    int son[2];
    bool operator < (const KDT &u)const{ return coor[idx]<u.coor[idx];}
    void init() { for ( int i = 0 ; i < 2 ;i++) mn[i]=mx[i]=coor[i];}
    void input() { for ( int i = 0 ; i < 2 ; i++) scanf("%lld",&coor[i]);}
}v[N<<1],tar; //开一倍空间是因为可能全都是插点。
inline LL getDis(KDT a,KDT b) {return abs(a.coor[0]-b.coor[0]) + abs(a.coor[1]-b.coor[1]);}
void up( int x)
{
    for ( int i = 0 ; i < 2 ; i++) if (v[x].son[i]){
    int y =v[x].son[i];
    for (int j = 0 ; j < 2 ; j++) 
	v[x].mn[j]=min(v[x].mn[j],v[y].mn[j]),v[x].mx[j]=max(v[x].mx[j],v[y].mx[j]);
    }
}
int build( int l=1,int r=n,int dim=0)
{
    idx = dim;
    int mid = (l+r)>>1;
    nth_element(v+l,v+mid,v+r+1);
    v[mid].init();
    if (l!=mid) v[mid].son[0] = build(l,mid-1,1-dim);
    if (r!=mid) v[mid].son[1] = build(mid+1,r,1-dim);
    up(mid);
    return mid;
}
LL ask( int x,KDT p)
{
    LL ret=0;
    for ( int i = 0 ; i < 2 ; i++)
    {
    ret = ret +max(0LL,v[x].mn[i]-p.coor[i])+ max(0LL,p.coor[i]-v[x].mx[i]);
    }
    return ret;
}
void insert(int x=rt,int dim=0)
{
    bool fg=v[n].coor[dim]>v[x].coor[dim];
    if (v[x].son[fg]) insert(v[x].son[fg],1-dim);
    else v[x].son[fg]=n;
    up(x);
}
void query(int x=rt,int dim=0)
{
    LL dis=getDis(v[x],tar),dl=linf,dr=linf;
    ans=min(dis,ans);
    if (v[x].son[0]) dl=ask(v[x].son[0],tar);
    if (v[x].son[1]) dr=ask(v[x].son[1],tar);
    int xx = v[x].son[0],yy=v[x].son[1];
    if (dl>=dr) swap(dl,dr),swap(xx,yy);
    if (dl<ans) query(xx,1-dim);
    if (dr<ans) query(yy,1-dim);
}
 
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    cin>>n>>m;
    for ( int i = 1 ; i <= n ; i++) v[i].input();
    rt =build();
    while (m--)
    {
	int t;
	scanf("%d",&t);
	ans=linf;
	if (t==1) v[++n].input(),v[n].init(),insert();
	else tar.input(),query(),printf("%lld\n",ans);
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
} 
```
#####kd-tree +优先队列，求M紧邻
hdu 4347 给出若干个点，在给出一个定点，求距离该定点最近的m个点。
（以及这次采用了轮盘转的策略划分维度，也就是按照深度，所有维度轮流作为split-method（实际用起来效果还是挺棒的orz）

```c++
const int N=5E4+7;
const int M = 10;
int n,m,k,t;
int idx;
struct Point
{
    LL coor[M];
    int id;
    void print()
    {
    for ( int i = 1 ; i <= k ; i++)
	printf("%lld%c",coor[i],i==k?'\n':' ');
    }
    bool operator < (const Point &u)const
    {
    return coor[idx]<u.coor[idx];
    }
}po[N];
typedef pair< LL,Point >PI;
priority_queue< PI >pq; //用优先队列一定要定义小于关系啊orz...我怎么这么傻
struct KdTree
{
    Point p[N<<2];
    bool leaf[N<<2];
    void build ( int l,int r, int rt = 1,int dep=0)
    {
    if (l>r) return;
    leaf[rt] = false;
    leaf[rt<<1] = leaf[rt<<1|1] = true;
    idx = dep % k;
    int mid = (l+r)>>1;
    nth_element(po+l,po+mid,po+r+1);
    p[rt] = po[mid];
    build(l,mid-1, rt<<1,dep+1);
    build(mid+1,r,rt<<1|1,dep+1);
    }
    void query(Point tar,int rt=1,int dep=0)
    {
    if (leaf[rt]) return;
    PI cur(0,p[rt]);
    for ( int i = 1 ; i <= k ; i++) cur.fst += (p[rt].coor[i]-tar.coor[i])*(p[rt].coor[i]-tar.coor[i]);
    int idx = dep%k;
    int x=rt<<1,y=rt<<1|1,flag=0;
    LL d = tar.coor[idx]-p[rt].coor[idx];
    if (d>0) swap(x,y);
    if (!leaf[x]) query(tar,x,dep+1);
    if (pq.size()<m) pq.push(cur),flag=1;
    else
    {
	if (cur.fst < pq.top().fst) pq.pop(),pq.push(cur);
	if (d*d<pq.top().fst) flag = 1;
    }
    //cout<<pq.top().second.coor[0]<<" "<<pq.top().second.coor[1]<<endl;
    if (!leaf[y]&&flag) query(tar,y,dep+1);
    }
}kd;
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    while (~scanf("%d %d",&n,&k))
    {
	for ( int i = 1 ;  i <= n ; i++)
	{
	for ( int j = 1 ; j <= k ; j++) scanf("%lld",&po[i].coor[j]);
	}
	scanf("%d",&t);
	kd.build(1,n);
	while (t--)
	{
	Point ask;
	for ( int i = 1 ; i <= k ; i++) scanf("%lld",&ask.coor[i]);
	scanf("%d",&m);
	kd.query(ask);
	printf("the closest %d points are:\n",m);
	Point ret[20];
	//cout<<"pq_siz:"<<pq.size()<<" pq.top()"<<pq.top().sec.coor[1]<<endl;
	for ( int i = 1 ; !pq.empty() ; i++) ret[i] = pq.top().second,pq.pop();
	for ( int i = m ; i >= 1 ; i--)  ret[i].print();
	}
    }
```

静态kd-tree
hdu 2966 给出二维平面上n(1E5)个点，问对于每个点，其他距离其最近的点的距离是多少。

```c++
const int N=1E5+7;
int n;
struct Point
{
    LL x,y;
}p[N],p2[N]; //复制一份，因为nth_element的时候会把顺序打乱。
bool dv[N]; //划分方式
bool cmpx( const Point & p1, const Point &p2)
{
    return p1.x<p2.x;
}
bool cmpy(const Point &p1 ,const Point &p2)
{
    return p1.y<p2.y;
}
LL getDis( Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
void build ( int l,int r)
{
    if (l>r) return;
    int mid = (l+r) >> 1;
    int minx = min_element(p+l,p+r,cmpx)->x;
    int miny = min_element(p+l,p+r,cmpy)->y;
    int maxx = max_element(p+l,p+r,cmpx)->x;
    int maxy = max_element(p+l,p+r,cmpy)->y;
    dv[mid] = maxx-minx >= maxy-miny;
    nth_element(p+l,p+mid,p+r+1,dv[mid]?cmpx:cmpy);
    build(l,mid-1);
    build(mid+1,r);
    
}
LL res;
void query( int l,int r,Point a)
{
    if (l>r) return;
    int mid = (l+r)>>1;
    LL dis = getDis(a,p[mid]);
    //printf("%lld %lld  %lld %lld    %lld\n",a.x,a.y,p[mid].x,p[mid].y,dis);
    if (dis>0) res = min(res,dis);//判掉和自己的距离。 
    LL d = dv[mid]?(a.x-p[mid].x):(a.y-p[mid].y);
    int l1=l,r1=mid-1,l2=mid+1,r2=r;
    if (d>0) swap(l1,l2),swap(r1,r2);
    query(l1,r1,a); //左儿子
    if (d*d<res) query(l2,r2,a);//如果与分界线相交，则也要查询右儿子。
}
 
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) {
	scanf("%lld %lld",&p[i].x,&p[i].y);
	p2[i] = p[i];
	}
	build (1,n);
	for ( int i = 1 ; i <= n ; i++)
	{
	res = 1LL<<60;
	query(1,n,p2[i]);
	printf("%lld\n",res);
	}
 
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```


####单调队列
#####求每连续k个元素的最大值

```c++
const int N=3E4+7;
int a[N];
int f[N];
int n,k;
deque<int>dq;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&k);
	n = 0 ;
	while (scanf("%d",&a[++n])!=EOF)
	{
	    if (a[n]==-1) 
	    {
	        n--;
	        break;
	    }
	}
	//for ( int i = 1 ; i <= n ; i++) cout<<"a[i]:"<<a[i]<<endl;
	dq.clear();
	for (  int i = 1 ; i <= n ; i++)
	{
	    while (!dq.empty()&&dq.front()<i-k+1) dq.pop_front(); //不断删除队首过期元素。以第i个元素结尾的连续K个元素的开头位置是i-k+1,在这之前的已经“失效”，因此出队.
	    while (!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();//不断删除队尾破坏单调性的元素。能删除的原因是比i早出现并且不比i大的元素一定不会成为答案。
	    dq.push_back(i);
	   // cout<<"dq.size():"<<dq.size()<<endl;
	    //cout<<"i:"<<i<<" "<<dq.front()<<endl;
	    if (i>=k)
	        printf("%d\n",a[dq.front()]);
	}
```
####线段树
#####线段树单点更新询问区间最大值模板

```c++
int n,m;
int a[N];
int MAX[N<<2];//MAX[i]表示的是第i个节点所存储的信息，根据题目会有所变化，这道题存储的是以i节点为根节点的子树的最大值（也就是i节点所表示的区间的最大值）
void PushUp(int rt)
{
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);  //线段树上每一个节点代表一段区间，该区间的最大值是把区间分成两部分，每一部分的最大值的最大值，也就是该节点（rt)的两个子节点取最大值。
}                                           //编号为i节点的两个子节点的编号为i*2和 i*2+1,写成位运算也就是 rt<<1和rt<<1|1（因为左移动一位以后末尾肯定为0，“或”1就相当于+1
	                                    //写成位运算是因为不用考虑优先级的问题。。因为加法的优先级比位移高，而或运算的优先级比位移低。
void update(int p,int sc,int l,int r,int rt) //p表示要更新的的节点的位置，sc表示要更新成什么，l,r,rt三个参数表示当前的树，初始就是整个线段树。
{
   // printf("p:%d sc:%d l:%d r:%d rt:%d\n",p,sc,l,r,rt);
    if (l==r) //此时该区间只有一个数，说明已经到了线段树的底部（叶子节点），一个数的最大值就是本身。直接更新
    {
	MAX[rt]= sc;
	return ;
    }
    int m = (l+r)>>1; //单点更新的时候，要更新所有包含该单点的子区间（子树）
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
 
    PushUp(rt);//当前区间的子区间更新完成后，可能对当前区间的答案有影响，记得更新（从下往上)
}
void build(int l,int r,int rt)
{
 //   printf("l:%d r:%d rt:%d\n",l,r,rt);
    if (l==r)
    {
	scanf("%d",&MAX[rt]);
	return;
    }
    int m = (l+r)>>1;//当前树的两个子树对应到区间的角度，就是把当前区间分成尽可能相同长度的两部分，m为分界点，前一半区间为[l,m]后一半为[m+1,r].
    build(lson);
    build(rson);  //递归建树，建一棵树只需要先建该树的两棵子树，递归的终点是(l==r)，此时到达线段树的叶子节点，对应区间中只有一个数。
    PushUp(rt);  //当当前树的左右子树都建好，就可以向上更新了。
}
int query(int L,int R,int l,int r,int rt) //L,R为当前询问的区间，l,r,rt表示当前的子树,初始是在整棵线段树中查询。
{
    if ( L<=l&&r<=R ) //如果当前询问的区间可以完整覆盖当前树的区间，那么这棵子树所代表的区间的最大值就有可能成为当前查询区间的答案，因此直接返回。
    {
	return MAX[rt];
    }
    int m = (l+r)>>1;  //如果当前询问的区间不能完整覆盖当前树的区间，那么就继续查询当前树的区间的子区间（子树），因为子树表示的区间越来越小，总会完全覆盖。
    int ret = 0 ;
    if (L<=m){// 只有当前询问区间和左子树的区间由交点时，左子树对应的区间的答案才会对当前询问的区间有意义。
	int res = query(L,R,lson);
	ret = max(ret,res); //答案是所有当前询问区间所能覆盖到的树上的子区间所代表的最大值中的最大值。
    }
    if (R>m){//其实是R>=m+1，同理。
	int res = query(L,R,rson);
	ret = max(res,ret);
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
 
	while (~scanf("%d%d",&n,&m))
	{
	    build(1,n,1);//直接建树的时候读入，根节点为1.
	    while(m--)
	    {
	        char opt[10];
	        int a,b;
	        scanf("%s%d%d",opt,&a,&b);
	        if (opt[0]=='Q') printf("%d\n",query(a,b,1,n,1));
	        else update(a,b,1,n,1);
	    }
	}
```
#####线段树+扫描线 求矩形面积并

```c++
const int N=205;
int n;
 
double X[N]; //存储所有x坐标，用来离散化。
//扫描线
struct Seg
{
    double l,r,h;
    //表示扫面线的起点，终点，所在的高度(y坐标）
    int d;//1或者-1，表示扫描线对面积是正向影响还是负向影响
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg &rhs)const
    {
    return h<rhs.h;
    }
    //从下向上处理扫描线。
}seg[N];
struct Tree
{
    int cnt;
    double len;
}tree[N<<2];
void PushUp(int l,int r,int rt)
{
    /*由于线段树的节点表示的其实是长度为1的区间
     * 因此线段树的区间[l,r]，对应的点的端点是l,r+1
     */
    if (tree[rt].cnt) tree[rt].len = X[r+1]-X[l]; //当前区间已经完全被线段覆盖
    else if (l==r) tree[rt].len=0; //是叶子节点而且没有被覆盖。
    else tree[rt].len = tree[rt<<1].len + tree[rt<<1|1].len; //没有完全被覆盖，从其子区间获得信息。
}
 
void update( int L,int R,int v,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
    tree[rt].cnt+=v;
    PushUp(l,r,rt);
    return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,v,lson);
    if (R>=m+1) update(L,R,v,rson);
    PushUp(l,r,rt);
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    int cas = 0;
    while (~scanf("%d",&n)&&n)
    {
	ms(tree,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	double x1,y1,x2,y2;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	seg[i] = Seg(x1,x2,y1,1);
	seg[i+n]= Seg(x1,x2,y2,-1);
	X[i] = x1;
	X[i+n] = x2;
	}
	n<<=1;
	sort(X+1,X+n+1);
	int m = unique(X+1,X+1+n)-X-1;
	
	sort(seg+1,seg+n+1);
	double ans = 0;
	for ( int i = 1 ; i < n ; i++)
	{
	int l = lower_bound(X+1,X+1+m,seg[i].l)-X;
	int r = lower_bound(X+1,X+1+m,seg[i].r)-X;
	if (l<r)
	update(l,r-1,seg[i].d,1,m,1);
	ans += tree[1].len * (seg[i+1].h-seg[i].h);
	}
	printf("Test case #%d\nTotal explored area: %.2f\n\n",++cas,ans);
	
    }   
```

#####线段树+扫描线 求矩形面积交 （hdu 1255）

```c++
const int N=2E3+7;
int n;
struct Seg
{
    double l,r,h;
    int d;
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg & rhs)const
    {
    return h<rhs.h;
    }
}a[N];
struct Tree
{
    double one,two; //分别是被覆盖一次以上的长度和被覆盖两次以上的长度。
    int cnt;
}tree[N<<2];
double X[N];
void PushUp( int l,int r,int rt)
{
    //整段区间被完全覆盖2次，长度可以直接得到。
    if (tree[rt].cnt>=2) tree[rt].one = tree[rt].two = X[r+1]-X[l];
    else if (tree[rt].cnt==1)  
    {
    tree[rt].one = X[r+1]-X[l];
    if (l==r) tree[rt].two = 0;
    else tree[rt].two = tree[rt<<1].one + tree[rt<<1|1].one;
    //父节点本身覆盖了一次，这样只需要左右子节点再至少覆盖一次即可。
    //此处更新是本题唯一的难点。
    }
    else
    {
    if (l==r) tree[rt].one =  tree[rt].two = 0;
    else 
    {
	tree[rt].one = tree[rt<<1].one + tree[rt<<1|1].one;
	tree[rt].two = tree[rt<<1].two + tree[rt<<1|1].two;
    }
    }
}
void update(int L,int R,int val,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
    tree[rt].cnt+=val;
    PushUp(l,r,rt);
    return ;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson);
    if (R>=m+1) update(L,R,val,rson);
    PushUp(l,r,rt);
}
 
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    int T;
    scanf("%d",&T);
    while (T--)
    {
	    scanf("%d",&n);    
	for ( int i = 1 ; i <= n ; i++)
	{
	double x1,y1,x2,y2;
	//给的坐标实际是左下角和右上角，而不是“左上角和右下角”，题目说错了。
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	X[i] = x1;
	X[i+n]=x2;
	a[i]=Seg(x1,x2,y1,1);
	a[i+n]=Seg(x1,x2,y2,-1);
	}
	n<<=1;
	sort(X+1,X+n+1);
	sort(a+1,a+n+1);
	int m = unique(X+1,X+1+n)-X-1;
	ms(tree,0);
	double ans=0;
	for (  int i = 1 ; i < n ; i++)
	{
	int l = lower_bound(X+1,X+m+1,a[i].l)-X;
	int r = lower_bound(X+1,X+m+1,a[i].r)-X;
    //  cout<<"l:"<<l<<" r:"<<r<<endl;
	update(l,r-1,a[i].d,1,m,1);
	ans+=tree[1].two * (a[i+1].h-a[i].h);
    //  cout<<"len:"<<tree[1].two<<" h:"<<a[i+1].h-a[i].h<<" ans:"<<ans<<endl;
	}
	//是四舍五入保留2位小数，题目没说清楚。
	ans = round(ans*100)*0.01;
	printf("%.2f\n",ans);
    }
```


#####线段树+扫描线 求 矩形周长并 (hdu 1828)
以及一个小细节是，求面积的时候，最后一条扫描线对答案是没有贡献的（因为每次是求当前扫描线与下一条扫描线之间的面积）

但是求周长的时候，最后一条扫描线是一定会对答案有贡献的。
```c++
const int N=1E4+7;
int n;
struct Seg
{
    double l,r,h;
    int d;
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg &rhs)const
    {
    return h < rhs.h;
    }
}a[N],b[N];
 
struct Tree
{
     int cnt;
     double len; 
}tree[N<<2];
double X[N],Y[N];
void pushUP(int l,int r,int rt,double *X)
{
    if (tree[rt].cnt) tree[rt].len = X[r+1] - X[l];
    else
    if (l==r) tree[rt].len = 0 ;
    else tree[rt].len = tree[rt<<1].len + tree[rt<<1|1].len;
}
void update( int L,int R,int val,int l,int r,int rt,double *X)
{
    if (L<=l && r<=R)
    {
    tree[rt].cnt+=val;
//  cout<<"val:"<<val<<" rt:"<<rt<<" tree[rt].cnt:"<<tree[rt].cnt<<endl;
    pushUP(l,r,rt,X);
    return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson,X);
    if (R>=m+1) update(L,R,val,rson,X);
    pushUP(l,r,rt,X);
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    while (~scanf("%d",&n))
    {
	for ( int i = 1 ; i<= n ; i++)
	{
	double x1,y1,x2,y2;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	X[i] = x1;
	X[i+n] = x2;
	Y[i] = y1;
	Y[i+n] = y2;
	a[i]=Seg(x1,x2,y1,1);
	a[i+n]=Seg(x1,x2,y2,-1);
	b[i] = Seg(y1,y2,x1,1);
	b[i+n] = Seg(y1,y2,x2,-1); //从左到右扫描
 
	}
 
	n=n<<1;
	double ans =  0;
	double lstlen = 0 ;
	sort(X+1,X+n+1);
	sort(a+1,a+n+1);
 
	int m = unique(X+1,X+n+1)-X-1;
	ms(tree,0);
	//求面积的时候不需要计算最后一条扫描线（因为答案是0),但是求周长的时候要计算）
	for ( int i = 1 ; i <= n ; i++)
	{
	int l = lower_bound(X+1,X+1+m,a[i].l)-X;
	int r = lower_bound(X+1,X+1+m,a[i].r)-X;
//      cout<<"l:"<<l<<" r:"<<r<<endl;
	update(l,r-1,a[i].d,1,m,1,X);
	ans += abs(tree[1].len-lstlen);
	lstlen = tree[1].len;
	//cout<<"lstlen:"<<lstlen<<endl;
	}
	//cout<<"ans:"<<ans<<endl;
	
	ms(tree,0);
	sort(Y+1,Y+n+1);
	sort(b+1,b+n+1);
	m = unique(Y+1,Y+n+1)-Y-1;
	lstlen = 0 ;
//      cout<<"m:"<<m<<endl;
	for ( int i = 1 ; i <= n ; i++)
	{
	int l = lower_bound(Y+1,Y+1+m,b[i].l)-Y;
	int r = lower_bound(Y+1,Y+1+m,b[i].r)-Y;
    //  cout<<"l:"<<l<<" r:"<<r<<endl;
	update(l,r-1,b[i].d,1,m,1,Y);
	ans += abs(tree[1].len - lstlen);
	lstlen = tree[1].len;
	}
	printf("%.0f\n",ans);
	
    }
 
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```

##### 线段树+扫描线，求矩形至少交三次的面积



```c++
void PushUp(int l,int r,int rt)
{
    //cout<<"l:"<<l<<" r:"<<r<<" rt:"<<rt<<" id:"<<id<<endl;
    if (tree[rt].cnt>=3)
    {
	tree[rt].one = tree[rt].two = tree[rt].three = X[r+1]-X[l];
    }
    else 
    if (tree[rt].cnt==2)
    {
    tree[rt].one = tree[rt].two = X[r+1]-X[l];
    
    if (l==r) tree[rt].three = 0 ;
    else tree[rt].three = tree[rt<<1].one + tree[rt<<1|1].one;
 
    }else if (tree[rt].cnt==1)
    {
	tree[rt].one = X[r+1] - X[l];
 
    if (l==r) tree[rt].two = tree[rt].three = 0;
    else 
    {
	tree[rt].two = tree[rt<<1].one + tree[rt<<1|1].one;
	tree[rt].three = tree[rt<<1].two + tree[rt<<1|1].two;
    }
    }
    else
    {
    if (l==r) tree[rt].one = tree[rt].two =  tree[rt].three = 0;
    else 
    {
	tree[rt].one = tree[rt<<1].one + tree[rt<<1|1].one;
	tree[rt].two = tree[rt<<1].two + tree[rt<<1|1].two;
	tree[rt].three = tree[rt<<1].three + tree[rt<<1|1].three;
    }
    }
}
```
#####线段树求逆序三元组



```c++
const int N=1E6+7;
int a[N];
int A[N];
int H[N];
int n;
int m;
int tree1[N<<2],tree2[N<<2];
pair<LL,LL>ans[N];
void PushUp(int rt,int *tree)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update(int p,int l,int r,int rt,int *tree)
{
    if (l==r)
    {
	tree[rt]++;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,lson,tree);
    else update(p,rson,tree);
    PushUp(rt,tree);
}
int query(int L,int R,int l,int r,int rt,int *tree)
{
//    cout<<"L:"<<L<<" R:"<<R<<" l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (L>R) return 0; 
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m)
    {
	int res = query(L,R,lson,tree);
	ret+=res;
    }
    if (R>=m+1)
    {
	int res =  query(L,R,rson,tree);
	ret +=res;
    }
    return ret;
}
int Hash( int x)
{
    return lower_bound(H,H+m,x)-H;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	m = n;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    H[i] = a[i];
	}
	sort(H,H+m);
	m = unique(H,H+m)-H;
	int mx = 0 ;
	for ( int i = 0 ; i < n ; i++) A[i] = Hash(a[i])+1,mx = max(mx,A[i]);
	ms(tree1,0);
	ms(tree2,0);
	for ( int i = n-1 ; i >=0 ; i--)
	{
	    LL tmp = LL(query(1,A[i]-1,1,mx,1,tree1));
	    ans[i].fst = tmp;
	    update(A[i],1,mx,1,tree1);
	}
	for ( int i =  0 ; i < n ; i++)
	{
	    LL tmp = LL(query(A[i]+1,mx,1,mx,1,tree2));
	    ans[i].sec = tmp;
	    update(A[i],1,mx,1,tree2);
	}
	LL res = 0LL;
	for ( int i = 0 ; i < n ; i++) res = res + ans[i].fst*ans[i].sec;
	cout<<res<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```

#####线段树动态维护区间最大子段和
```c++
const int N=5E5+7;
int n,m;
int a[N];
struct Tree
{
    int sum;
    int mxl;
    int mxr;
    int mx;
}tree[N<<2];
void PushUp(int rt)
{
    tree[rt].sum = tree[rt<<1].sum+tree[rt<<1|1].sum;
    if (tree[rt<<1].mxr>0&&tree[rt<<1|1].mxl>0)
	tree[rt].mx = tree[rt<<1].mxr+tree[rt<<1|1].mxl;
    else tree[rt].mx = max(tree[rt<<1].mxr,tree[rt<<1|1].mxl);
    tree[rt].mx = max(tree[rt].mx,max(tree[rt<<1].mx,tree[rt<<1|1].mx));
    tree[rt].mxl=max(tree[rt<<1].mxl,tree[rt<<1].sum+tree[rt<<1|1].mxl);
    tree[rt].mxr=max(tree[rt<<1|1].mxr,tree[rt<<1|1].sum+tree[rt<<1].mxr);
}
void build(int l,int r,int rt)
{
 //   cout<<"l:"<<l<<" r:"<<r<< " rt:"<<rt<<endl;
    if (l==r)
    {
	int tmp;
	scanf("%d",&tmp);
//        cout<<"tmp:"<<tmp<<endl;
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = tmp;
	return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = sc;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
Tree query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    if (L<=m&&R>=m+1)
    {
	Tree root,ltree,rtree;
	ltree=query(L,R,lson);
	rtree=query(L,R,rson);
	root.sum = ltree.sum + rtree.sum;
	if (ltree.mxr>0&&rtree.mxl>0)
	    root.mx = ltree.mxr + rtree.mxl;
	else root.mx = max(ltree.mxr,rtree.mxl);
	root.mx = max(root.mx,max(ltree.mx,rtree.mx));
	root.mxl = max(ltree.mxl,rtree.mxl+ltree.sum);
	root.mxr = max(rtree.mxr,ltree.mxr+rtree.sum);
	return root;
    }
    else
    if (L<=m) return query(L,R,lson);
    else   return query(L,R,rson);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while (m--)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        if (a>b) swap(a,b);
	        int ans = query(a,b,1,n,1).mx;
	        printf("%d\n",ans);
	    }else
	    {
	        int p,x;
	        scanf("%d%d",&p,&x);
	        update(p,x,1,n,1);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```


#####线段树动态维护最大连续子段（hit oj 2687 ）
给出n个数,m个修改，每次修改后询问整个区间的最大连续子段。

```c++
const int N=1E5+7;
int n,m;
struct
{
    int mx;
    int mxr;
    int mxl;
    int sum;
}tree[N<<2];
void PushUp( int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    if (tree[rt<<1].mxr>0&&tree[rt<<1|1].mxl>0) //区间合并
	tree[rt].mx = tree[rt<<1].mxr + tree[rt<<1|1].mxl;
    else tree[rt].mx = max(tree[rt<<1].mxr,tree[rt<<1|1].mxl);
    tree[rt].mx = max(tree[rt].mx,max(tree[rt<<1].mx,tree[rt<<1|1].mx));
    tree[rt].mxl = max(tree[rt<<1].mxl,tree[rt<<1|1].mxl+tree[rt<<1].sum);
    tree[rt].mxr = max(tree[rt<<1|1].mxr,tree[rt<<1].mxr+tree[rt<<1|1].sum);
}
void build(int l,int r,int rt)
{
    if (l==r)
    {
	int x;
	scanf("%d",&x);
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = x;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
 
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    build(1,n,1);
	    while (m--)
	    {
	        int p,x;
	        scanf("%d%d",&p,&x);
	        update(p,x,1,n,1);
	        printf("%d\n",tree[1].mx);
	    }
	}
```

##### 二维线段树之四叉树模板（单点更新，区间询问最值）

```c++
const int N=805;
int n;
int a[N][N];
struct Tree
{
    int mn,mx;
    Tree()
    {
        mn = 1E9;
        mx = 0;
    }
    void init()
    {
        mn = 1E9;
        mx = 0;
    }
}tree[N*10000];
int _max( int a,int b,int c,int d)
{
    int ret = max(a,b);
    ret = max(ret,c);
    ret = max(ret,d);
    return ret;
}
int _min( int a,int b,int c,int d)
{
    int ret = min(a,b);
    ret = min(ret,c);
    ret = min(ret,d);
    return ret;
}
void PushUp( int rt)
{
//  cout<<"rt:"<<rt<<endl;
    tree[rt].mn = _min(tree[rt*4+1].mn,tree[rt*4+2].mn,tree[rt*4+3].mn,tree[rt*4+4].mn);
    tree[rt].mx = _max(tree[rt*4+1].mx,tree[rt*4+2].mx,tree[rt*4+3].mx,tree[rt*4+4].mx);
}
 
 
void insert( int idx,int lx,int rx,int ly,int ry,int X,int Y,int val)
{
//  cout<<"val:"<<val<<endl;
    if (lx==rx&&ly==ry)
    {
        tree[idx].mn = tree[idx].mx = val;
//      cout<<"fuck"<<" val:"<<val<<" mn:"<<tree[idx].mn <<" mx:"<<tree[idx];
        return;
    }
    int mx = (lx+rx) >> 1;
    int my = (ly+ry) >> 1;
    if (X<=mx&&Y<=my) insert(idx*4+1,lx,mx,ly,my,X,Y,val);
    if (X<=mx&&Y>=my+1) insert(idx*4+2,lx,mx,my+1,ry,X,Y,val);
    if (X>=mx+1&&Y<=my) insert(idx*4+3,mx+1,rx,ly,my,X,Y,val);
    if (X>=mx+1&&Y>=my+1) insert(idx*4+4,mx+1,rx,my+1,ry,X,Y,val);
//  puts("miao");
    PushUp(idx);
}
int queryMN( int idx,int lx,int rx,int ly,int ry,int Lx,int Rx,int Ly,int Ry)
{
    if (Lx<=lx && Rx>=rx && Ly<=ly && Ry>=ry) return tree[idx].mn;
    int mx = (lx+rx)>>1,my = (ly+ry)>>1,t=1E9;
    if (Lx<=mx && Ly<=my)  t = min(t,queryMN(idx*4+1,lx,mx,ly,my,Lx,Rx,Ly,Ry));
    if (Lx<=mx && Ry>my) t = min(t,queryMN(idx*4+2,lx,mx,my+1,ry,Lx,Rx,Ly,Ry));
    if (Rx>mx  && Ly<=my) t = min (t,queryMN(idx*4+3,mx+1,rx,ly,my,Lx,Rx,Ly,Ry)); 
    if (Rx>mx&&Ry>my) t = min (t,queryMN(idx*4+4,mx+1,rx,my+1,ry,Lx,Rx,Ly,Ry));
    return t;
}
int queryMX( int idx,int lx,int rx,int ly,int ry,int Lx,int Rx,int Ly,int Ry)
{
    if (Lx<=lx && Rx>=rx && Ly<=ly && Ry>=ry) return tree[idx].mx;
    int mx = (lx+rx)>>1,my = (ly+ry)>>1,t=0;
    if (Lx<=mx && Ly<=my)  t = max(t,queryMX(idx*4+1,lx,mx,ly,my,Lx,Rx,Ly,Ry));
    if (Lx<=mx && Ry>my) t = max(t,queryMX(idx*4+2,lx,mx,my+1,ry,Lx,Rx,Ly,Ry));
    if (Rx>mx  && Ly<=my) t = max (t,queryMX(idx*4+3,mx+1,rx,ly,my,Lx,Rx,Ly,Ry)); 
    if (Rx>mx&&Ry>my) t = max(t,queryMX(idx*4+4,mx+1,rx,my+1,ry,Lx,Rx,Ly,Ry));
    return t;
}
void init()
{
    for ( int i = 0 ; i < 8E6 ; i++) tree[i].init();
}
int main(){
#ifdef YourCodeHasBug
//  freopen("in2","r",stdin);
#endif
    int T;
    cin>>T;
    int cas = 0 ;
    while (T--)
    {
        init();
        scanf("%d",&n);
        for ( int i = 1 ; i <= n ; i++)
            for ( int j = 1 ; j <= n ; j++)
            {
                scanf("%d",&a[i][j]);
//              cout<<"a[i][j]:"<<a[i][j]<<endl;
                insert(0,1,n,1,n,i,j,a[i][j]);
            }
//      for ( int i = 0 ; i <= 20 ; i++) printf("tree_mn:%d mx:%d\n",tree[i].mn,tree[i].mx);
        int m;
        scanf("%d",&m);
            printf("Case #%d:\n",++cas);
        while (m--)
        {
            int x,y,L;
            scanf("%d %d %d",&x,&y,&L);
            int Lx = max(x-L/2,1);
            int Rx = min(n,x+L/2);
            int Ly = max(y-L/2,1);
            int Ry = min(n,y+L/2);
//          printf("x:[%d,%d] y:[%d,%d]\n",Lx,Rx,Ly,Ry);
            int mn = queryMN(0,1,n,1,n,Lx,Rx,Ly,Ry);
            int mx = queryMX(0,1,n,1,n,Lx,Rx,Ly,Ry);
            int newval = floor((mn+mx)/2);
            //printf("mn:%d mx:%d %d\n",mn,mx,newval);
            printf("%d\n",newval);
            insert(0,1,n,1,n,x,y,newval);
        }
    }

```

##### 二维线段树之树套树（推荐写法）模板（单点更新，区间最值）

```c++
const int N=803;
struct Treey
{
    int l,r;
    int Max,Min;
};
int n;
int rtx[N],rty[N] ; //rtx[i]表示横坐标为i的点属于哪棵线段树
struct  Treex
{
    int l,r;
    Treey treey[N<<2];
    void build ( int _l,int _r,int rt)
    {
    treey[rt].l = _l;
    treey[rt].r = _r;
    treey[rt].Max = -inf;
    treey[rt].Min = inf;
    if (_l==_r)
    {
        rty[_l] = rt;
        return;
    }
    int m = (_l + _r) / 2;
    build (_l,m,rt<<1);
    build(m+1,_r,rt<<1|1);
    }
    int QMin( int L,int R,int rt)
    {
    if (treey[rt].l >= L && treey[rt].r <= R) return treey[rt].Min;
    int m = (treey[rt].l + treey[rt].r) / 2;
    int ret = 1E9;
    if (L<=m) ret = QMin(L,R,rt<<1);
    if (R>=m+1) ret = min(ret,QMin(L,R,rt<<1|1));
    return ret;
    }
    int QMax( int L,int R,int rt)
    {
    if (treey[rt].l >= L && treey[rt].r <= R) return treey[rt].Max;
    int m = (treey[rt].l + treey[rt].r) / 2;
    int ret = 0 ;
    if (L<=m) ret = QMax (L,R,rt<<1);
    if (R>=m+1) ret = max(ret,QMax(L,R,rt<<1|1));
    return ret;
    }
}treex[N<<2];
 
void build (int l,int r,int rt)
{
    treex[rt].l = l;
    treex[rt].r = r;
    treex[rt].build(1,n,1);
    if (l==r)
    {
    rtx[l] = rt;
    return;
    }
    int m = (l+r)>>1;
    build (lson);
    build (rson);
}
void update ( int x,int y,int val) //单点更新，更新a[x,y]到val
{
    int rx = rtx[x];
    int ry = rty[y];
    treex[rx].treey[ry].Min = treex[rx].treey[ry].Max = val;
    for ( int i = rx ; i ; i >>=1)
    for ( int j = ry ; j ; j >>=1)
    {
        if (i==rx && j==ry) continue; //上面更新过了
        if (j==ry)
        {
        treex[i].treey[j].Min = min(treex[i<<1].treey[j].Min,treex[i<<1|1].treey[j].Min);
        treex[i].treey[j].Max = max(treex[i<<1].treey[j].Max,treex[i<<1|1].treey[j].Max);
        }
        else
        {
            treex[i].treey[j].Min = min(treex[i].treey[j<<1].Min,treex[i].treey[j<<1|1].Min);
        treex[i].treey[j].Max = max(treex[i].treey[j<<1].Max,treex[i].treey[j<<1|1].Max);
        }
    }
}
int QMin( int L1,int R1,int L2,int R2,int rt)
{
    if (treex[rt].l >= L1 && treex[rt].r <= R1) return treex[rt].QMin(L2,R2,1);
    int m = (treex[rt].l + treex[rt].r)/2;
    int ret = 1E9;
    if (L1<=m) ret = QMin(L1,R1,L2,R2,rt<<1);
    if (R1>=m+1) ret = min(ret,QMin(L1,R1,L2,R2,rt<<1|1));
    return ret;
}
int QMax ( int L1,int R1,int L2,int R2,int rt)
{
 //   printf("rt:%d l:%d r:%d  L1:%d R1:%d \n",rt,treex[rt].l,treex[rt].r,L1,R1);
    if (treex[rt].l >= L1 && treex[rt].r <=R1) return treex[rt].QMax(L2,R2,1);
    int m = (treex[rt].l + treex[rt].r) / 2;
    int ret = 0 ;
    if (L1<=m) ret = QMax(L1,R1,L2,R2,rt<<1);
    if (R1>=m+1) ret = max(ret, QMax(L1,R1,L2,R2,rt<<1|1));
    return ret;
}
 
int main() 
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
    int T,cas=0;
    cin>>T;
    while (T--)
    {
    printf("Case #%d:\n",++cas);
    scanf("%d",&n);
    build (1,n,1);
    for ( int i = 1 ; i  <= n ; i++)
        for ( int j = 1; j <= n ; j++)
        {
        int x;
        scanf("%d",&x);
        update(i,j,x);
        }
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int x,y,L;
        scanf("%d %d %d",&x,&y,&L);
        int L1 = max(x-L/2,1);
        int R1 = min(x+L/2,n);
        int L2 = max(y-L/2,1);
        int R2 = min(y+L/2,n);
//      printf("[%d,%d] [%d,%d]\n",L1,R1,L2,R2);
        int Mx = QMax(L1,R1,L2,R2,1);
        int Mn = QMin(L1,R1,L2,R2,1);
        int val = floor((Mx+Mn)/2);
        printf("%d\n",val);
        update(x,y,val);
    }
    }   
```



####cdq分治 (离线算法，复杂度nlgn)

#####cdq分治求三维偏序
hdu5618 If two point such as (xi,yi,zi) and (xj,yj,zj) xi≥xj yi≥yj zi≥zj, the bigger one level add 1

问每个point的level是多少。
cdq分治，先去重并统计相同的点的数量，需要注意要记录原id对应到了哪个新id

```c++
const int N=1E5+7;
int n;
struct point
{
    int x,y,z;
    int id;
    int cnt,sum;
    void input( int _id)
    {
    scanf("%d %d %d",&x,&y,&z);
    id=_id;
    }
    bool operator < (const point &b)const
    {
    if (x!=b.x) return x<b.x;
    if (y!=b.y) return y<b.y;
    return z<b.z;
    }
    bool operator !=(const point &b)const
    {
    return x!=b.x||y!=b.y||z!=b.z;
    }
}p[N];
struct BIT
{
    int n,t[N];
    void init( int _n)
    {
    n = _n;
    ms(t,0);
    }
    inline int lowbit(int x){ return x&(-x);}
    void update( int x,int delta)
    {
    for ( int i = x ; i <= n ; i+=lowbit(i)) t[i] +=delta;
    }
    int Sum( int x)
    {
    int ret = 0 ;
    for ( int i = x ; i >=1 ;  i-=lowbit(i)) ret+=t[i];
    return ret;
    }
}bit;
bool cmpcdq(point a,point b){return a.y<b.y;}
bool cmpid(point a,point b){return a.id < b.id;}
void cdq( int l,int r)
{
    if (l==r) return;
    int mid = (l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(p+l,p+mid+1,cmpcdq);
    sort(p+mid+1,p+r+1,cmpcdq);
    int j = l;
    for ( int i = mid + 1 ; i <= r ; i++)
    {
    for ( ; j <= mid && p[j].y <= p[i].y ; j++) bit.update(p[j].z,p[j].cnt);
    p[i].sum+=bit.Sum(p[i].z);
    }
    for ( int i = l ; i < j ; i++) bit.update(p[i].z,-p[i].cnt);
}
int tot;
int ans[N];
int id[N]; //记录原id对应到了哪个新id
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    int T;
    scanf("%d",&T);
    while (T--)
    {
	tot=0;
	ms(p,0); //多组数据orz
	scanf("%d",&n);
	bit.init(N-1);
	for ( int i = 1 ; i <= n ; i++) p[i].input(i);
	int cnt = 0;
	sort(p+1,p+n+1);
	for ( int i = 1 ; i <= n ; i++)
	{
	cnt++;
	if (p[i]!=p[i+1])
	{
	    p[i].cnt = cnt;
	    id[p[i].id]=tot+1;
	    p[++tot]=p[i];
	    p[tot].id = tot;
	    cnt=0;
	}
	else
	{
	    id[p[i].id] = tot+1;
	}
 
	}
	cdq(1,tot);
	//for ( int i = 1 ; i <= n ; i++)  ans[id[p[i].id]] = p[i].sum ;
	//for ( int i = 1 ; i <= n ; i++) printf("%d\n",ans[i]);
	
	sort(p+1,p+tot+1,cmpid);
	for ( int i = 1 ; i <= n ; i++) printf("%d\n",p[id[i]].sum+p[id[i]].cnt-1);
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```




####st表的rmq算法
	int a[N];
	int mx[N][20];
	int mi[N][20];


```c++
void init_mx()
{
    for ( int i = 1 ; i <= n ; i++)  mx[i][0] = a[i];  //初始化
    for ( int j = 1 ; (1<<j)<=n ; j ++)  //循环外面是j,里面是i的原因是，当更新一个长度为4的区间的最值时，依赖于长度为2的区间的最值。
    for ( int i =1 ; i + (1<<j)-1<= n ; i++)  //因此要先完全更新完区间长度为2^j的，才能更新区间长度为2^(j+1)的
	mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
}
int rmq_max(int L,int R)
{
    int k = 0 ;
    while (1<<(k+1)<=(R-L+1)) k++;  //使得两倍的区间长度大于所查询的区间
    return max(mx[L][k],mx[R-(1<<k)+1][k]);
}
```


快速求log2(i)，不然可能被卡。

```c++
   LOG[0] = -1;
    for ( int i = 1 ; i < 2* N ; i++) LOG[i] =LOG[i>>1]+1;
    
   int	   rmq( int l,int r)
{
    if (l>r) return 0;
int k = log(double (r-l+1)/log2);
//int k = LOG[r-l+1];
//int k = 0;
//while (1<<(k+1)<=r-l+1) k++;
    int mx = max(dp[l][k],dp[r-(1<<k)+1][k]);
    int mn = min(dp2[l][k],dp2[r-(1<<k)+1][k]);
    return mx - mn;
}
```

  有时候可能需要返回最值的位置

```c++
  int _min(int l,int r)
{
    if (a[l]<a[r]) return l;
    return r;
}
```

####主席树
#####主席树套BIT,求区间动态第k大
```c++
const int N = 2E5+7;
int n,m;
int a[N],H[N];
int root[N];
int cnt,p[2];
int num;
int prefix_l[100],prefix_r[100];
 
struct node
{
    int a,b,c;
    char opt[3];
}querys[N];
struct PTree
{
    int sum;
    int left,right;
}tree[N*30];
int Hash( int x){ return lower_bound(H+1,H+num+1,x)-H;}
inline int lowbit( int x) { return x&(-x);}
inline int add_node( int _sum,int _left,int _right)
{
    int idx = ++cnt;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void build( int &root,int pre_rt,int pos,int l,int r)
{
    root = add_node(tree[pre_rt].sum+1,tree[pre_rt].left,tree[pre_rt].right);
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
    build(tree[root].left,tree[root].left,pos,l,mid);
    else
    build(tree[root].right,tree[root].right,pos,mid+1,r);
}
void Insert( int &root,int pos,int l,int r,int val)
{
    if (!root) root = add_node(0,0,0);
    tree[root].sum += val;
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
    Insert(tree[root].left,pos,l,mid,val);
    else
    Insert(tree[root].right,pos,mid+1,r,val);
}
int query(int l,int r,int k)
{
    if (l==r) return l;
    int mid = (l+r)>>1,sum=0;
    for ( int i = 0 ; i < p[0] ; i++)
    sum += tree[tree[prefix_r[i]].left].sum;
    for ( int i = 0 ; i < p[1] ; i++)
    sum -= tree[tree[prefix_l[i]].left].sum;
    if (k<=sum)
    {
    for (int i = 0 ; i < p[0] ; i++)
	prefix_r[i] = tree[prefix_r[i]].left;
    for ( int i = 0 ; i < p[1] ; i++)
	prefix_l[i] = tree[prefix_l[i]].left;
    return query(l,mid,k);
    }
    else
    {
    for ( int i = 0 ; i < p[0] ; i++)
	prefix_r[i] = tree[prefix_r[i]].right;
    for ( int i = 0 ; i < p[1] ; i++)
	prefix_l[i] = tree[prefix_l[i]].right;
    return query(mid+1,r,k-sum);
    }
}
 
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif 
    scanf("%d %d",&n,&m);
    int p_val = n;
    ms(root,0);
    for ( int i = 1 ; i <= n ; i++) scanf("%d",a+i),H[i] = a[i];
    cnt = 0;
    for ( int i = 0 ; i < m; i++) //读入所有操作是为了离散化
    {
	scanf("%s %d %d",querys[i].opt,&querys[i].a,&querys[i].b);
	if (querys[i].opt[0]=='Q') scanf("%d",&querys[i].c);
	else H[++p_val] = querys[i].b;
    }
    sort(H+1,H+p_val+1);
    num = unique(H+1,H+p_val+1)-(H+1);
    for ( int i = 1 ; i <= n ; i++)
    {
	a[i] = Hash(a[i]);
    }
//  for ( int i = 1 ; i <= n ; i++) printf("a[%d]=%d\n",i,a[i]);
    for ( int i = 1 ; i <= n ; i++)
    {
	build(root[i+n],root[(i-1)+n],a[i],1,num);
    }
    for ( int i = 0 ; i < m ; i++)
    {
	if (querys[i].opt[0]=='Q')
	{
	p[0] = p[1] = 1;
	prefix_r[0] = root[querys[i].b + n];
	prefix_l[0] = root[querys[i].a-1==0?0:querys[i].a-1+n];
	for ( int arr = querys[i].b; arr ; arr-=lowbit(arr))
	    prefix_r[p[0]++] = root[arr];
	for ( int arr = querys[i].a-1 ; arr ; arr-=lowbit(arr))
	    prefix_l[p[1]++] = root[arr];
	int id = query(1,num,querys[i].c);
	printf("%d\n",H[id]);
	}
	else
	{
	for ( int j = querys[i].a ; j <= n ; j+=lowbit(j))
	    Insert(root[j],a[querys[i].a],1,num,-1);
	a[querys[i].a] = Hash(querys[i].b);
	for ( int j = querys[i].a ; j <= n ; j+=lowbit(j))
	    Insert(root[j],a[querys[i].a],1,num,1);
	}
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```

#####主席树，静态区间第k大 hdu 2665
```c++
const int N=1E5+7;
int a[N],H[N];
int cnt;
int Hash( int x){ return lower_bound(H,H+cnt,x)-H;}
int n,m;
int tot;//线段树的总数。
int root[N];//每个元素对应的根节点
struct PTree
{
    int sum,left,right;
}tree[N*30];
inline int add_node( int _sum,int _left,int _right)
{
    int idx = ++tot;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void Insert( int &root,int pre_rt,int pos,int l,int r)
{
    root = add_node(tree[pre_rt].sum + 1,tree[pre_rt].left,tree[pre_rt].right);
    //printf("l:%d r %d root:%d\n",l,r,root);
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
    Insert(tree[root].left,tree[pre_rt].left,pos,l,mid);
    else
    Insert(tree[root].right,tree[pre_rt].right,pos,mid+1,r);
}
int Query( int L,int R,int l,int r,int k)//区间第k大
{
    if (l==r) return l;
    int mid = (l+r)>>1;
    int sum = tree[tree[R].left].sum - tree[tree[L].left].sum;
    //sum表示 左区间的元素个数
    if (k<=sum)
    return Query(tree[L].left,tree[R].left,l,mid,k);
    else return Query(tree[L].right,tree[R].right,mid+1,r,k-sum);
}
```


​	 
```c++
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--){
    tot = 0 ;
    scanf("%d%d",&n,&m);
    for ( int i = 1 ; i <= n ; i++) scanf("%d",a+i),H[i] = a[i];
    root[0] = 0;
    sort(H+1,H+n+1);
    cnt = unique(H+1,H+n+1)-(H+1);
    for ( int i = 1; i <= n ; i++)
    {
	int pos = Hash(a[i]);
	//printf("pos:%d\n",pos);
	Insert(root[i],root[i-1],pos,1,cnt);
	//cout<<"i"<<i<<endl;
    }
    while (m--)
    {
	int l,r,k;
	scanf("%d %d %d",&l,&r,&k);
	int pos = Query(root[l-1],root[r],1,cnt,k);
	printf("%d\n",H[pos]);
    }
    }
```


#####主席树求在线[l,r]中不同数的个数
```c++
const int N=3E4+7;
const int M=2E5+7;
int n,Q;
int a[N],root[N];
map<int,int>mp;
int cnt;
struct Ptree
{
    int sum;
    int left,right;
}tree[N*30];
void build (int &rt,int l,int r)
{
    rt =++cnt;
    tree[rt].sum = 0 ;
    if (l==r) return;
    int mid = (l+r)>>1;
    build (tree[rt].left,l,mid);
    build (tree[rt].right,mid+1,r);
}
inline int add_node(int _sum,int _left,int _right)
{
    int idx = ++cnt;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void Insert(int &root,int pre_rt,int pos,int val,int l,int r)
{
//    printf("l:%d r:%d\n",l,r);
    root = add_node(tree[pre_rt].sum + val,tree[pre_rt].left,tree[pre_rt].right);
   // root = ++cnt;
   // tree[root].sum = tree[pre_rt].sum+ val;
   // tree[root].left = tree[pre_rt].left;
   // tree[root].right = tree[pre_rt].right;
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid) Insert(tree[root].left,tree[pre_rt].left,pos,val,l,mid);
    else Insert(tree[root].right,tree[pre_rt].right,pos,val,mid+1,r);
}
int query(int pos,int l,int r,int rt)
{
    if (l==r) return tree[rt].sum;
    int mid = (l+r)>>1;
    if (pos<=mid) return query(pos,l,mid,tree[rt].left);
    else return tree[tree[rt].left].sum + query(pos,mid+1,r,tree[rt].right);
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
    ms(tree,0);
    cnt = 0 ;
    cin>>n;
    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
    build (root[n+1],1,n);
    mp.clear();
    for ( int i = n ; i >= 1 ; i--)
    {
	if (mp.find(a[i])==mp.end())
	{
	Insert(root[i],root[i+1],i,1,1,n);
	}
	else
	{
	Insert(root[i],root[i+1],mp[a[i]],-1,1,n);
	Insert(root[i],root[i],i,1,1,n);
	}
	mp[a[i]] = i;
    }
    cin>>Q;
    while (Q--)
    {
	int l,r;
	scanf("%d %d",&l,&r);
       // printf("l:%d r:%d\n",l,r);
	int ans = query(r,1,n,root[l]);
	printf("%d\n",ans);
    }
```


​	    

##数论
####逆元
ksm(a,mod-2)的方法求逆元只适用于mod为质数且 gcd(a,mod)==1

扩展欧几里得算法求逆元只适用于gcd(a,mod)==1
用欧几里德算法求模的逆元：

       同余方程ax≡b (mod n)，如果 gcd(a,n)== 1，则方程只有唯一解。

      在这种情况下，如果 b== 1，同余方程就是 ax=1 (mod n ),gcd(a,n)= 1。

      这时称求出的 x 为 a 的对模 n 乘法的逆元。

      对于同余方程 ax= 1(mod n )， gcd(a,n)= 1 的求解就是求解方程

      ax+ ny= 1，x, y 为整数。这个可用扩展欧几里德算法求出，原同余方程的唯一解就是用扩展欧几里德算法得出的 x 。
####裴蜀定理
ax+by能得到的最小正数解就是(a,b),也就是gcd(a,b)
ax+by=d的有解条件是d是gcd(a,b)的整数倍

####扩展欧几里得算法
问a*x+b*y=1的一组x>0的解，如果无解输出sorry.
```c++
cint exgcd( int a,int b,int &x,int &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return a;
    }
    int ret = exgcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - a/b*y;
    return ret;
}
```

#####扩展欧几里得算法解一般线性同余方程组
给出k个方程，形式为 x%a1==r1,求最小的正数x，无解输出-1.

```c++
const int N=1E6+7;
int n;
LL a[N],r[N];
 
LL exgcd( LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return a;
    }
    LL ret = exgcd(b,a%b,y,x);
    y-=x*(a/b); //简化版本的exgcd...
    return ret;
}
LL ex_crt( LL *m, LL *r,int n)
{
    LL M = m[1],R = r[1],x,y,gcd;
    for ( int i = 2 ; i <= n ; i++)
    {
	gcd = exgcd(M,m[i],x,y);
	if ((r[i]-R)%gcd) return -1;
	LL gx = m[i]/gcd;
	x = x*(r[i]-R)/gcd;
	x = x % gx;
	R = R + x*M;
	M = M / gcd * m[i];
	R%=M;
    }
    return R>0?R:R+M;
}
 
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
 
	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld %lld",&a[i],&r[i]);
	    printf("%lld\n",ex_crt(a,r,n));
	}
```


#####exgcd求解一般线性同余方程组解的个数（hdu 1573）
```c++
const int N =15;
LL a[N],r[N];
LL nn;
int m;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
	x = 1;
	y = 0 ;
	return a;
    }
    LL ret = exgcd( b, a%b,y,x);
    y-=x*(a/b);
    return ret;
}
LL ex_crt(LL *m,LL *r,int n)
{
     LL M = m[1] , R = r[1],x,y,gcd;
     for ( int i = 2 ; i <= n ; i++)
	{
	    gcd = exgcd(M,m[i],x,y);
	    if ((r[i]-R)%gcd) return 0;
	    LL gx = m[i]/gcd;
	    x = x*(r[i]-R)/gcd;
	    x %=gx;
	    R += x*M;
	    M = M / gcd * m[i];
	    R%=M;
	}
     if (R<=0) R+=M;
     if (nn<R) return 0;
     return (nn-R)/M + 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld %d",&nn,&m);
	    for ( int i = 1 ; i <= m ; i++) scanf("%lld",&a[i]);
	    for ( int i = 1 ; i <= m ; i++) scanf("%lld",&r[i]);
	    LL res = ex_crt(a,r,m);
	    printf("%lld\n",res);
	}
```
####线性筛

```c++
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000;
const int maxl=10000;
int tot=0;
int prime[maxn];
bool check[maxl];
void Euler_sieve(){
	memset(check,0,sizeof(check));
	for(int i=2;i<maxl;i++){
		if(!check[i]) prime[tot++]=i;
		for(int j=0;j<tot;j++){
			if(i*prime[j]>maxl) break;
			check[i*prime[j]]=1;
			if(!i%prime[j]) break;
		}
	}
	return;
}
```
####广义斐波那契循环节
g(n) = 3g(n - 1) + g(n - 2)

```c++
	struct Mat
	{
	    LL mat[2][2];
	    void clear()
	    {
		ms(mat,0);
	    }
	}M,M1;
	Mat mul (Mat a,Mat b,LL mod)
	{
	    Mat c;
	    c.clear();
	    for ( int i = 0 ; i < 2 ; i++)
		for ( int j = 0 ; j < 2 ; j++)
		    for ( int k  = 0 ; k < 2 ; k++)
			c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]%mod)%mod;
	    return c;
	}
	Mat mat_ksm(Mat a,LL b,LL mod)
	{
	    Mat res;
	    res.clear();
	    for ( int i = 0 ; i < 2 ; i++) res.mat[i][i] = 1;
	    while (b>0)
	    {
		if (b&1) res = mul(res,a,mod);
		b = b >> 1LL;
		a = mul(a,a,mod);
	    }
	    return res;
	}
	LL gcd(LL a,LL b)
	{
	    return b?gcd(b,a%b):a;
	}
	const int N = 1E6+7;
	bool prime[N];
	int p[N];
	void isprime() //一个普通的筛
	{
	    int cnt = 0 ;
	    ms(prime,true);
	    for ( int i = 2 ; i < N ; i++)
	    {
		if (prime[i])
		{
		    p[cnt++] = i ;
		    for ( int j = i+i ; j < N ; j+=i) prime[j] = false;
		}
	    }
	}
	LL ksm( LL a,LL b,LL mod)
	{
	   LL res = 1;
	   while (b>0)
	   {
	       if (b&1) res = (res * a) % mod;
	       b = b >> 1LL;
	       a = a * a % mod;
	   }
	   return res;
	}
	LL legendre(LL a,LL p) //勒让德符号,判断二次剩余
	{
	    if (ksm(a,(p-1)>>1,p)==1) return 1;
	    return -1;
	}
	LL pri[N],num[N];//分解质因数的底数和指数。
	int cnt; //质因子的个数
	void solve(LL n,LL pri[],LL num[])
	{
	    cnt = 0 ;
	    for ( int  i = 0 ; p[i] * p[i] <= n ; i++)
	    {
		if (n%p[i]==0)
		{
		    int Num = 0 ;
		    pri[cnt] = p[i];
		    while (n%p[i]==0)
		    {
			Num++;
			n/=p[i];
		    }
		    num[cnt] = Num;
		    cnt++;
		}
	    }
	    if (n>1)
	    {
		pri[cnt] = n;
		num[cnt] = 1;
		cnt++;
	    }
	}
	LL fac[N];
	int cnt2; //n的因子的个数
	void get_fac(LL n)//得到n的所有因子
	{
	    cnt2 = 0 ;
	    for (int i =  1 ; i*i <= n ; i++)
	    {
		if (n%i==0)
		{
		    if (i*i!=n)
		    {
			fac[cnt2++] = i ;
			fac[cnt2++] = n/i;
		    }
		    else fac[cnt2++] = i;
		}
	    }
	}
	int get_loop( LL p) //暴力得到不大于13的素数的循环节。
	{                    
	    LL a,b,c;
	    a = 0 ;
	    b = 1 ;
	    for ( int i = 2; ; i++)
	    {
		c = (a+3*b%p)%p;
		a = b;
		b = c;
		if (a==0&&b==1) return i-1;
	    }
	}
	/*
	    2->3
	    3->2
	    5->12
	    7->16
	    11->8
	    13->52
	    */
	const LL LOOP[10]={3,2,12,16,8,52};
	LL ask_loop(int id)
	{
	    return LOOP[id];
	}
	LL find_loop(LL n)
	{
	    solve(n,pri,num);
	    LL ans = 1;
	    for ( int i = 0 ; i < cnt ; i++)
	    {
		LL rec = 1;
		if (pri[i]<=13) rec = ask_loop(i);
		else
		{
		    if (legendre(13,pri[i])==1)  //13就是delta值
			get_fac(pri[i]-1);
		    else get_fac((pri[i]+1)*(3-1)); //为什么可以假设循环节不大于2*(p+1)???
		    sort(fac,fac+cnt2);
		    for ( int j = 0 ; j < cnt2 ; j++) //挨个验证因子
		    {
			Mat tmp = mat_ksm(M,fac[j],pri[i]); //下标从0开始，验证fac[j]为循环节，应该看fib[0]==fib[fac[j]]和fib[1]==fib[fac[j]+1]是否成立
			tmp = mul(tmp,M1,pri[i]);
			if (tmp.mat[0][0]==0&&tmp.mat[1][0]==1)
			{
			    rec = fac[j];
			    break;
			}
		    }
	 
		}
		for ( int j = 1 ; j < num[i] ; j++)
		    rec *=pri[i];
		ans = ans / gcd(ans,rec) * rec;
	    }
	    return ans;
	}
	void init()
	{
	    M.clear();
	    M.mat[0][1] = M.mat[1][0] = 1;
	    M.mat[1][1] = 3;
	    M1.clear();
	    M1.mat[1][0] = 1;
	}
	LL n;
	LL loop0 = 1E9+7;
	LL loop1,loop2;
	int main()
	{
		#ifndef  ONLINE_JUDGE 
		freopen("code/in.txt","r",stdin);
	  #endif
		/*
		printf("%d\n",get_loop(2));
		printf("%d\n",get_loop(3));
		printf("%d\n",get_loop(5));
		printf("%d\n",get_loop(7));
		printf("%d\n",get_loop(11));
		printf("%d\n",get_loop(13));
		*/
		init();
		isprime();
		while (~scanf("%lld\n",&n))
		{
		    if (n==0||n==1)
		    {
			printf("%lld\n",n);
			continue;
		    }
		    LL loop1 = find_loop(loop0);
		    LL loop2 = find_loop(loop1);
	//            printf("loop1:%lld loop2:%lld\n",loop1,loop2);
		    LL cur = n;
		    Mat ans = mat_ksm(M,cur-1,loop2);
		    ans = mul(ans,M1,loop2);
		    cur = ans.mat[1][0];
		    if (cur!=0&&cur!=1)
		    {
			Mat ans = mat_ksm(M,cur-1,loop1);
			ans = mul(ans,M1,loop1);
			cur = ans.mat[1][0];
		    }
		    if (cur!=0&&cur!=1)
		    {
			Mat ans = mat_ksm(M,cur-1,loop0);
			ans = mul(ans,M1,loop0);
			cur = ans.mat[1][0];
		    }
		    printf("%lld\n",cur);
	 
		}
	 
	#ifndef ONLINE_JUDGE  
		fclose(stdin);
	#endif
		return 0;
	}
```

​		 
求斐波那契循环节板子：（hdu4794）

```c++
struct Mat
{
    LL mat[2][2];
    void clear()
    {
    ms(mat,0);
    }
    void pr()
    {
    for ( int i = 0 ; i < 2 ; i++)
        for ( int j = 0 ; j < 2 ; j++)
        printf("%lld%c",mat[i][j],j==1?'\n':' ');
    }
}M,M1;
const Mat P = {1,1,1,0};
Mat mul (Mat a,Mat b,LL mod)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < 2 ; i++)
    for ( int j = 0 ; j < 2 ; j++)
        for ( int k  = 0 ; k < 2 ; k++)
        c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]%mod)%mod;
    return c;
}
Mat mat_ksm(Mat a,LL b,LL mod)
{
    Mat res;
    res.clear();
    for ( int i = 0 ; i < 2 ; i++) res.mat[i][i] = 1;
    while (b>0)
    {
    if (b&1) res = mul(res,a,mod);
    b = b >> 1LL;
    a = mul(a,a,mod);
    }
    return res;
}
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}
const int N = 5E6+7;
bool prime[N];
int p[N];
int pri_tot;
void Lineisprime() //换成线性晒了。
{
   // int cnt = 0 ;
    ms(prime,true);
    for ( int i = 2 ; i < N ; i++)
    {
    if (prime[i]) p[pri_tot++] = i ;
    for ( int j =  1 ;  j < pri_tot && i*p[j] < N ; j++)
    {
        prime[i*p[j]] = false;
        if (i%p[j]==0) break;
    }
    }
}
 
LL ksm( LL a,LL b,LL mod)
{
   LL res = 1;
   while (b>0)
   {
       if (b&1) res = (res * a) % mod;
       b = b >> 1LL;
       a = a * a % mod;
   }
   return res;
}
LL legendre(LL a,LL p) //勒让德符号,判断二次剩余
{
    if (ksm(a,(p-1)>>1,p)==1) return 1;
    return -1;
}
 
LL pri[N],num[N];//分解质因数的底数和指数。
int cnt; //质因子的个数
void solve(LL n,LL *pri,LL *num)
{
    cnt = 0 ;
    for ( int  i = 0 ; 1LL*p[i] * p[i] <= n  && i < pri_tot ; i++)
    {
    if (n%p[i]==0)
    {
        int Num = 0 ;
        pri[cnt] = p[i];
        while (n%p[i]==0)
        {
        Num++;
        n/=p[i];
        }
        num[cnt] = Num;
        cnt++;
    }
    }
    if (n>1)
    {
    pri[cnt] = n;
    num[cnt] = 1;
    cnt++;
    }
}
LL fac[N];
int cnt2; //n的因子的个数
void get_fac(LL n)//得到n的所有因子
{
    cnt2 = 0 ;
    for (int i =  1 ; i*i <= n ; i++)
    {
    if (n%i==0)
    {
        if (i*i!=n)
        {
        fac[cnt2++] = i ;
        fac[cnt2++] = n/i;
        }
        else fac[cnt2++] = i;
    }
    }
}
LL delta;
const LL LOOP[10]={3,8,20};
LL ask_loop(int id) //我好傻啊。。并不一定所有因子都有啊。。。
{
    return LOOP[id];
}
LL find_loop(LL n)
{
    //cout<<"n:"<<n<<endl;
    solve(n,pri,num);
    //puts("pri:");
   // for ( int i = 0 ; i < cnt ; i++)  printf("i:%d %lld\n",i,pri[i]);
    LL ans = 1;
    //cout<<"CNT:"<<cnt<<endl;
    for ( int i = 0 ; i < cnt ; i++)
    {
    LL rec = 1;
    if (pri[i]==2) rec =  3;
    else if (pri[i]==3) rec = 8;
    else if (pri[i]==5) rec = 20;
    else
    {
        if (legendre(5,pri[i])==1)
        get_fac(pri[i]-1);
        else get_fac((pri[i]+1LL)*(3-1)); //为什么可以假设循环节不大于2*(p+1)???
        sort(fac,fac+cnt2);
       // for  ( int qqq = 0; qqq < cnt2 ; qqq++) printf("fac: %lld  ",fac[qqq]);
        for ( int j = 0 ; j < cnt2 ; j++) //挨个验证因子
        {
        Mat tmp = mat_ksm(M,fac[j],pri[i]); //下标从0开始，验证fac[j]为循环节，应该看fib[0]==fib[fac[j]]和fib[1]==fib[fac[j]+1]是否成立
        tmp = mul(tmp,M1,pri[i]);
        if (tmp.mat[0][0]==1&&tmp.mat[1][0]==0)
        {
            rec = fac[j];
            break;
        }
        }
 
    }
    for ( LL j = 1 ; j < num[i] ; j++)
        rec *=pri[i];
    ans = ans / gcd(ans,rec) * rec;
    }
    return ans;
}
void init()
{
    M.clear();
    M.mat[0][0] = M.mat[0][1] = M.mat[1][0] = 1;
    M1.clear();
    M1.mat[0][0] = 1;
}
LL n;
int main()
{
    
    
    init();
    Lineisprime();
    while (~scanf("%llu",&n))
    {
      //  cout<<"n:"<<n<<endl
        if (n==2) puts("3");
        else 
        printf("%llu\n",find_loop(n)/2);
 
    }
 
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
 
 
 
 
```

​	

##图论
####并查集

并查集判断无相图的连通性
hdu 5631给出一张n个点n+1（n<=100）条边的无向图，现在删除若干条边（至少一条边），问删完之后图依然联通的方案数。做法是：先把所有的点孤立出来，然后开始添加边，每次union成功（就是添加了一条边）的时候计数器+1，n个点如果能合并n-1次，也就是添加了n-1条有效边（最多也只可能是n-1条，那么说明这n个点之间是联通的。

```c++
const int N=105;
int n;
int f[N];
bool ban[N];
pi edge[N];
```


```c++
void init()
{
    ms(f,0);
    for ( int i = 0 ; i < N ; i++) f[i] =  i;
}
 
int root ( int x)
{
    if (f[x]!=x)
    f[x]=root(f[x]);
    return f[x];
}
 
int Union( int x,int y)
{
    int rootx = root(x);
    int rooty = root(y);
  //  cout<<"rootx:"<<rootx<<" rooty:"<<rooty<<endl;
    if (rootx!=rooty)
    {
    f[rootx]=rooty;
    
    return 1;
    }
    return 0;
}
 
int solve()       //用并查集判断图连通性。如果是联通图，那么一定会合并(union)n-1次（得到一棵生成树）      
    //每次合并相当于添加了一条边，而且是不会使得图出现环的边。
{
    init();  //对于每一种情况，都要初始化一次。
 
    int cnt_merge = 0;
    
    for ( int i = 0 ; i <= n ; i++)
    {
    if (!ban[i])
    {
	cnt_merge+=Union(edge[i].fst,edge[i].sec);
    }
    }
    return cnt_merge==n-1;
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
  #endif
 
    ios::sync_with_stdio(false);
    int T;
    cin>>T;          
    while (T--)
    {
      //  init();
	cin>>n;
	for ( int i = 0 ; i <= n ; i++) cin>>edge[i].fst>>edge[i].sec;
 
	ms(ban,false);
 
	int ans = 0  ;
	for ( int i = 0 ; i <= n ; i++)
	{
	ban[i] = true;
	ans +=solve();
	for ( int j = i+1 ; j <= n ; j++)
	{
	    ban[j] = true;
	    ans +=solve();
	    ban[j] = false; //回溯
	//    cout<<"ans:"<<ans<<endl;
	}
	ban[i] = false ;//回溯
	
	}
	cout<<ans<<endl;
    }
```

####树的直径

poj 2631 一棵树中求两个点的最远距离。。

```c++
const int N=1E4+7;
int n,m;
vector < pi> edge[N];
int lst;
int ans;
int d[N];
bool vis[N];
 
 
void bfs( int s)
{
    ms(d,0x3f);
    ms(vis,false);
    queue<int>q;
    q.push(s);
    vis[s] = true;
    d[s] =  0 ;
 
    while (!q.empty())
    {
        int u = q.front() ; q.pop();
        lst = u ;
//        cout<<"u:"<<u<<endl;
        int siz = edge[u].size();
 
        for ( int i = 0 ; i < siz ; i++)
        {
            int v = edge[u][i].fst;
            if (vis[v]) continue;
            vis[v] = true;
            d[v] = d[u] + edge[u][i].sec;
            ans = max(d[v],ans);
            q.push(v);
        }
    }
 
    int mx = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
//        cout<<"i:"<<i<<" d[i]:"<<d[i]<<endl;
        if (d[i]>mx)
        {
            mx = d[i];
            lst = i ;
        }
    }
 
}
int main()
{
        #ifndef  ONLINE_JUDGE 
        freopen("code/in.txt","r",stdin);
  #endif
 
        int u,v,w;
        m = 0;
        n = 0;
        while (scanf("%d%d%d",&u,&v,&w)!=EOF)
        {
            edge[u].push_back(make_pair(v,w));
            edge[v].push_back(make_pair(u,w));
            m++;
            n = max(n,u);
            n = max(n,v);
        }
        ans = inf;
        bfs(1);
        ans = 0;
//        cout<<"lst:"<<lst<<endl;
        bfs(lst);
        cout<<ans<<endl;
```

####欧拉路
如果图G中的一个路径包括每个边恰好一次，则该路径称为欧拉路径(Euler path)。
如果一个回路是欧拉路径，则称为欧拉回路(Euler circuit)。

* 有向图G为欧拉图(存在欧拉回路)，当且仅当G的基图连通（弱联通，），且所有顶点的入度等于出度。

* 有向图G为半欧拉图(存在欧拉路)，当且仅当G的基图连通（弱联通），且存在顶点u的入度比出度大1、v的入度比出度小1，其它所有顶点的入度等于出度。

* 无向图存在欧拉回路:  图连通，所有点都是偶数度，

* 无向图存在欧拉路：图联通，只有两个点的度数为奇数。


####交叉染色法判断无向图的奇偶环

```c++
const int N=1E5+7;
const int M=3E5+7;
int n,m;
int col[N];
bool even,odd;
bool vis[N];
int cnt ;
int head[N];
struct Edge
{
    int v;
    int nxt;
    bool vis;
}edge[2*M];  
void addedge( int u,int v)
{
    edge[cnt].v = v;
    edge[cnt].nxt = head[u];
    edge[cnt].vis = false;
    head[u] = cnt;
    cnt++;
}
void dfs( int u,int x,int fa)
{
    col[u] = x;
    for ( int i = head[u] ; i !=-1 ; i = edge[i].nxt)
    {
	int v = edge[i].v;
	if (v==fa) continue;交叉染色法判断无向图的奇偶环
	if (col[v]!=-1)
	{
	    if (col[v]==x) odd = true;
	    else even = true;
	}
	if (!edge[i].vis)
	{
	    edge[i].vis = true;
	    dfs(v,1-x,u);
	}
    }
    col[u] = -1;
}
void solve()
{
    odd = false;
    even = false;
    for ( int i = 1 ; i <= n ; i++){
	if (col[i]==-1) dfs(i,0,-1);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d%d",&n,&m);
	    ms(col,-1);
	    ms(head,-1);
	    cnt = 0 ;
	    for ( int i = 1 ;i <= m ; i++)
	    {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	    }
	    solve();
	    if (odd) puts("YES");else puts("NO");
	    if (even) puts("YES");else  puts("NO");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```


####交叉染色法判断二分图
```c++
const int N=205;
vector <int>edge[N];
int n,m;
int col[N];
bool dfs( int u,int x)
{
    col[u] = x;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (col[v]==1-x) continue;
	if (col[v]==x) return false;
	if (!dfs(v,1-x)) return false;
    }
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    ms(col,-1);
	    for ( int i =  0 ;i <= n ; i++) edge[i].clear();
	    scanf("%d",&m);
	    for ( int i = 1 ; i <= m ; i++)
	    {
	        int u,v;
	        scanf("%d%d",&u,&v);
	        edge[u].push_back(v);
	        edge[v].push_back(u);
	    }
	    if (dfs(0,0))
	        puts("BICOLORABLE.");
	    else puts("NOT BICOLORABLE.");
	}
```
####匈牙利算法
```c++
bool dfs(int u)
{
 //   cout<<"u:"<<u<<endl;
    for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt) //对于每个妹子，枚举她喜欢的蓝孩纸
    {
	int v = edge[i].to; //v为妹子u喜欢的蓝孩纸的编号
	if (vis[v]) continue; //避免递归反复寻找同一个男孩子陷入死循环。
	vis[v] = true;
	if (link[v]==-1||dfs(link[v])) //如果这个男孩子是单身狗或者这个男孩子的女票还有其他男孩子可以选择（可以腾出位置）
	{
	    link[v] = u ;// 男孩子v和女孩子u在一起了。
	    return true;
	}
    }
    return false;
}
int hung(int n)
{
    int ans = 0 ;
    ms(link,-1);
    for ( int i = 1 ; i <= n ; i++) //扫描每个妹子
    {
	ms(vis,false);
	if (dfs(i)) ans++;
    }
    return ans;
}
```



1)二分图的最小顶点覆盖
最小顶点覆盖要求用最少的点（X或Y中都行），让每条边都至少和其中一个点关联。
Knoig定理：二分图的最小顶点覆盖数等于二分图的最大匹配数。

(2)DAG图的最小路径覆盖
用尽量少的不相交简单路径覆盖有向无环图(DAG)G的所有顶点，这就是DAG图的最小路径覆盖问题。
结论：DAG图的最小路径覆盖数 = 节点数（n）- 最大匹配数（m）

(3)二分图的最大独立集
最大独立集问题： 在Ｎ个点的图G中选出m个点，使这m个点两两之间没有边．求m最大值
结论：二分图的最大独立集数 = 节点数（n）— 最大匹配数（m）



#### km算法



```c++
const int N=305;
int w[N][N];
int n;
int link[N];
int lx[N],ly[N];//顶标
int slk[N]; //slk为一个优化函数，表示在DFS增广过程中，所有搜到的与该Y方点关联的边的(lx+ly-W)的最小值
bool visx[N],visy[N];
bool find( int u)
{
    visx[u] = true;
    for ( int v = 1 ; v <= n ; v++) //这道题特殊：每两个点都有边相连。
    {                    //对于有些题目中可能两个集合某些点没有边相连，我们可以看作有权值为0的边。
    if (visy[v]) continue;
    int tmp = lx[u] + ly[v] - w[u][v]; //要时刻保证tmp>=0，并称一样一组点标为可行的。
//    cout<<"tmp:"<<tmp<<endl;
    if (tmp==0)
    {
	visy[v] = true;
	if (link[v]==-1||find(link[v]))
	{
	link[v] = u;
	return true;
	}
    }
    else
	if (tmp<slk[v]) slk[v] = tmp; //顺便（？）更新slk
    }
    return false;
}
int KM()
{

    ms(link,-1);//初始没有找到匹配，同hungary
    ms(ly,0);
    ms(lx,0);//因为要使得所有lx[i]+ly[j]-w[i][j]>=0,所以初始化的时候（不妨）lx[i]=max(w[i][j]),ly[i]=0;
    for ( int i = 1 ;  i <= n ; i++)
    for ( int j = 1 ; j <= n ; j++)
	lx[i] = max(w[i][j],lx[i]);
    for ( int i =  1 ; i <= n ; i++)
    {
//    ms(slk,0x3f);
    for ( int j = 1 ; j <= n ; j++) slk[j] = inf;
    while (true)
    {
    //  cout<<"mio mio mio "<<endl;
	ms(visx,false);
	ms(visy,false);

	if (find(i)) break;
	int d = inf;
	for ( int j = 1 ; j <= n ; j++)
	{
	if (!visy[j]&&slk[j]<d) d= slk[j]; //d取所有slk值的最小值。
	                    //这样有两个作用，一个是可以保证所有所有【点标对】仍然可行。
	                    //另一个是这样的d每次都可以增加一条<可行边>进入相等子图。
	}
	for (int j = 1 ; j <= n ; j++) if (visx[j]) lx[j]-=d;
	for (int j = 1 ; j <= n ; j++) if (visy[j]) ly[j]+=d;else slk[j]-=d;
    }
    }
    int res = 0 ;
    for ( int i = 1 ; i <= n ; i++)
    {
    if (link[i]>-1)
    {
	res += w[link[i]][i];
    }
    }
    return res;
}
int main()
{
    #ifndef  ONLINE_JUDGE

    freopen("code/in.txt","r",stdin);
  #endif
    while (scanf("%d",&n)!=EOF)
    {
	for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= n ; j++)
	    scanf("%d",&w[i][j]);
	int ans = KM();
	printf("%d\n",ans);
    }
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  #endif
    return 0;
}
```

####spfa算法
	vector < pi > edge[N];


```c++
int d[N];
bool inq[N];
int posi[N];
vector <int>ans;
void spfa( int s)
{
    ms(inq,false);
    ms(d,0x3f);
```


	    queue<int>q;
	    q.push(s);
	    d[s] =  0;
	    inq[s] = true;


```c++
    while (!q.empty())
    {
    int u = q.front();
    q.pop();
    inq[u] = false;
```


	    int siz = edge[u].size();


```c++
    for ( int i = 0 ; i < siz ; i ++)
    {
	int v = edge[u][i].fst;
	if (d[v]>d[u]+edge[u][i].sec)
	{
	d[v] = d[u] + edge[u][i].sec;
	if (inq[v]) continue;
	inq[v] = true;
	q.push(v);
```


		}
	    }


	    }
	}
##计算几何
####n个圆面积交，可以求出交恰好k次的面积(k属于1..n)

```c++
const double eps = 1e-10;  
const int MAXN = 1E3+7;  
const double PI = acos(-1.0);  
#define sqr(x) ((x)*(x))  
const int N = 1010;  
double area[N];  
int n;  
  
int dblcmp(double d){ return d<-eps?-1:d>eps;}  
struct point
{
    double x,y;
    double ang;
    int d;
    point(){}
    point(double x,double y):x(x),y(y){}
    point(double _x,double _y,double _ang,int _d)
    {
    x = _x;
    y = _y;
    ang = _ang;
    d = _d;
    }
    void input(){scanf("%lf%lf",&x,&y);}
    double angle(){ return atan2(y,x);}
    point operator + (const point &rhs)const{ return point(x+rhs.x,y+rhs.y);}
    point operator - (const point &rhs)const{ return point(x-rhs.x,y-rhs.y);}
    point operator * (double t)const{ return point(t*x,t*y);}
    point operator / (double t)const{ return point(x/t,y/t);}
    double length() const { return sqrt(x*x+y*y);};
    point unit()const { double l = length();return point(x/l,y/l); }
}tp[N*2];
double cross (const point a,point b){ return a.x*b.y-a.y*b.x ;}
double dist(const point p1,point p2) { return (p1-p2).length();}
struct circle  
{ 
    point c;
    double r;
    int d; 
    void input()  
    {  
    c.input();
    scanf("%lf",&r);
	d = 1;  
    }
    bool contain (const circle & cir)const{ return dblcmp(dist(cir.c,c)+cir.r-r)<=0;}
    bool interect (const circle & cir)const{ return dblcmp(dist(cir.c,c)-cir.r-r)<0;}
} cir[N];// tp[N * 2];  
  
double dis(point a, point b)  {return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));} 
int CirCrossCir(circle cir1,circle cir2, point &p1, point &p2)  
{  
    point m = cir2.c-cir1.c;
    point s = cir2.c+cir1.c;
    point m2 = point(sqr(m.x),sqr(m.y));
    double dis2 = m2.x + m2.y, d = -(dis2 - sqr(cir1.r - cir2.r)) * (dis2 - sqr(cir1.r + cir2.r));  
    if (d + eps < 0) return 0;  
    if (d < eps) d = 0;  
    else d = sqrt(d);
    double x = m.x * ((cir1.r + cir2.r) * (cir1.r - cir2.r) + m.x * s.x) + s.x * m2.y;  
    double y = m.y * ((cir1.r+ cir2.r) * (cir1.r - cir2.r) + m.y * s.y) + s.y * m2.x;  
    point dp = m*d;
    dis2 *= 2;
    p1 = point (x-dp.y,y+dp.x)/dis2;
    p2 = point (x+dp.y,y-dp.x)/dis2;
    if (d > eps) return 2;  
    else return 1;  
}  
bool circmp(const circle& u, const circle& v)  
{  
    return dblcmp(u.r - v.r) < 0;  
}  
bool cmp(const point& u, const point& v)  
{  
    if (dblcmp(u.ang - v.ang)) return u.ang < v.ang;  
    return u.d > v.d;  
}  
  
double calc(circle cir, point p1, point p2)  
{  
    double ans = (p2.ang - p1.ang) * sqr(cir.r)
	 - cross ( (p1-cir.c),(p2-cir.c)) + cross( p1,p2);
    return ans *0.5; 
}  
  
void CirUnion(circle cir[], int n)  
{  
    circle cir1, cir2;  
    point p1,p2;
    sort(cir, cir + n, circmp);  
    for (int i = 0; i < n; ++i)  
	for (int j = i + 1; j < n; ++j)  
	if (cir[j].contain(cir[i]))
	        cir[i].d++;  
    for (int i = 0; i < n; ++i)  
    {  
	int tn = 0, cnt = 0;  
	for (int j = 0; j < n; ++j)  
	{  
	    if (i == j) continue;  
	    if (CirCrossCir(cir[i],cir[j],p2, p1) < 2) continue;  
	p1.ang = (p1-cir[i].c).angle();
	p2.ang = (p2-cir[i].c).angle();
	    p1.d = 1;  
	    tp[tn++] = p1;  
	    p2.d = -1;  
	    tp[tn++] = p2;  
	    if (dblcmp(p1.ang - p2.ang) > 0) cnt++;  
	}  
	tp[tn++] = point(cir[i].c.x - cir[i].r, cir[i].c.y, PI, -cnt);  
	tp[tn++] = point(cir[i].c.x - cir[i].r, cir[i].c.y, -PI, cnt);  
	sort(tp, tp + tn, cmp);  
	int p, s = cir[i].d + tp[0].d;  
	for (int j = 1; j < tn; ++j)  
	{  
	    p = s;  
	    s += tp[j].d;  
	    area[p] += calc(cir[i], tp[j - 1], tp[j]);  
	}  
    }  
}  
void solve()  
{  
    scanf("%d", &n);  
    for (int i = 0; i < n; ++i)  
	cir[i].input();  
    memset(area, 0, sizeof(area));  
    CirUnion(cir, n);  
    //去掉重复计算的  
    for (int i = 1; i <= n; ++i)  
    {  
	area[i] -= area[i + 1];  
    }  
    //area[i]为重叠了i次的面积 
    for ( int i = 1 ; i <= n ; i++) printf("[%d] = %.3f\n",i,area[i]+eps);
    //tot 为总面积  
    //double tot = 0;  
    //for(int i=1; i<=n; i++) tot += area[i];  
    //printf("%f\n", tot);  
}  
  
int main()  
{  
   // freopen("./in.txt", "r", stdin);  
    solve();
    return 0;  
}
```

####n个圆面积并
```c++
const double PI = acos(-1.0);
const int N =1e3+7;
inline int dblcmp( double d) { return d<-eps?-1:d>eps;}
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void input(){scanf("%lf%lf",&x,&y);}
    double angle(){ return atan2(y,x);}
    point operator + (const point &rhs)const{ return point(x+rhs.x,y+rhs.y);}
    point operator - (const point &rhs)const{ return point(x-rhs.x,y-rhs.y);}
    point operator * (double t)const{ return point(t*x,t*y);}
    point operator / (double t)const{ return point(x/t,y/t);}
    double length() const { return sqrt(x*x+y*y);};
    point unit()const { double l = length();return point(x/l,y/l); }
};
double cross (const point a,point b){ return a.x*b.y-a.y*b.x ;}
double dist(const point p1,point p2) { return (p1-p2).length();}
point rotate(point p,double angle,point o = point(0,0))
{   point t = p-o;
    double x = t.x * cos(angle) - t.y*sin(angle);
    double y = t.y * cos(angle) + t.x*sin(angle);
    return point (x,y)+o;
}
struct region{
    double st,ed;
    region(){}
    region(double st,double ed):st(st),ed(ed){}
    bool operator < (const region & rhs)const
    {   if (dblcmp(st-rhs.st)) return st<rhs.st;
    return ed<rhs.ed;
    }
};
struct circle{
    point c;
    double r;
    vector <region>reg;
    circle(){}
    circle(point c,double r):c(c),r(r){}
    void input()
    {
    c.input();
    scanf("%lf",&r);
    }
    void add(const region &r){ reg.PB(r);}
    bool contain (const circle & cir)const{ return dblcmp(dist(cir.c,c)+cir.r-r)<=0;}
    bool interect (const circle & cir)const{ return dblcmp(dist(cir.c,c)-cir.r-r)<0;}
};
double sqr( double x){ return x*x;}
void intersection(circle cir1,circle cir2,point &p1,point &p2)
{
    double l = dist(cir1.c,cir2.c);
    double d = (sqr(l)-sqr(cir2.r) + sqr(cir1.r))/(2*l);
    double d2 = sqrt(sqr(cir1.r)-sqr(d));
    point mid = cir1.c + (cir2.c-cir1.c).unit() * d;
    point v = rotate(cir2.c-cir1.c,PI/2).unit()*d2;
    p1 = mid + v,p2 = mid -v;
}
point calc(const circle &cir,double angle)
{
    point p = point (cir.c.x+cir.r,cir.c.y);
    return rotate(p,angle,cir.c);
}
 
circle cir[N];
bool del[N];
int n;
 
double solve()
{
    double ans = 0 ;
    for ( int i = 0 ; i < n ;  i++){
    for ( int j = 0 ; j < n ; j++) if (!del[j]){
	if (i==j) continue;
	if (cir[j].contain(cir[i]))
	{   del[i] = true;
	break;
	}
    }
    }
    for ( int i = 0 ; i < n ; i++) if (!del[i]){
    circle &mc = cir[i];
    point p1,p2;
    bool flag = false;
    for ( int j = 0 ; j < n ; j++) if (!del[j]){
	if (i==j) continue;
	if (!mc.interect(cir[j])) continue;
	flag = true;
	intersection(mc,cir[j],p1,p2);
	double rs = (p2-mc.c).angle(),rt = (p1-mc.c).angle();
	if (dblcmp(rs)<0) rs+=2*PI;
	if (dblcmp(rt)<0) rt+=2*PI;
	if (dblcmp(rs-rt)>0) mc.add(region(rs,PI*2)),mc.add(region(0,rt));
	else mc.add(region(rs,rt));
    }
    if (!flag) { ans += PI*sqr(mc.r); continue;}
    sort(mc.reg.begin(),mc.reg.end());
    int cnt = 1;
    for ( int j = 1 ; j < mc.reg.size() ; j++)
    {
	if (dblcmp(mc.reg[cnt-1].ed - mc.reg[j].st)>=0)
	mc.reg[cnt-1].ed = max(mc.reg[cnt-1].ed,mc.reg[j].ed);
	else mc.reg[cnt++] = mc.reg[j];
    }
	mc.add(region());
	mc.reg[cnt]=mc.reg[0];
	for ( int j = 0 ; j < cnt ; j++)
	{
	p1 = calc(mc,mc.reg[j].ed);
	p2 = calc(mc,mc.reg[j+1].st);
	ans +=cross(p1,p2)/2;
	double angle = mc.reg[j+1].st - mc.reg[j].ed;
	if (dblcmp(angle)<0) angle+=2*PI;
	ans+=0.5*sqr(mc.r)*(angle-sin(angle));
	}
    }
    return ans;
    
}
int main() 
{
    #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
 
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++) cir[i].input();
    printf("%.3f\n",solve());
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```


​	 

##字符串

#### 后缀自动机



![img](http://111qqz.com/wp-content/uploads/2017/11/%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20171110203549.png)

##### SAM模板

```c++
const int N=5E5+7;
struct SAM
{
    #define MAXALP 30
    struct state
    {
    int len, link, nxt[MAXALP];
    int leftmost; //某个状态的right集合中r值最小的
    int rightmost;//某个状态的right集合的r的最大值
    int Right; //right集合大小
    };
    state st[N*2];
    char S[N];
    int sz, last,rt;
    LL tot_str; //子串总数   每个状态本质不同的子串数*出现的次数
    LL tot_unique_str; //本质不同的子串总数  st[v].len - st[st[v].link].len  (v属于1..sz)
    int cnt[2*N],rk[2*N];//for radix sort
    int idx(char c)
    {
    if (c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
    }
    void init()
    {
    sz = 0;
    ms(st,0);
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    st[1].rightmost=0;
    ms(st[1].nxt,-1);
    }
    void extend(int c,int head)
    {
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    st[cur].leftmost = st[cur].rightmost = head;
    memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
    int p;
    for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
        st[p].nxt[c] = cur;
    if (p == -1) {
        st[cur].link = rt;
    } else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len) {
 
        st[cur].link = q;
        } else {
        int clone = ++sz ;
        st[clone].len = st[p].len + 1;
        st[clone].link = st[q].link;
        memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
        st[clone].leftmost = st[q].leftmost;
        st[clone].rightmost = st[q].rightmost;
        for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
            st[p].nxt[c] = clone;
        st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
    }
    void build()
    {
    init();
    for ( int i = 0,_len = strlen(S) ; i < _len ; i++)
    {
        st[sz+1].Right = 1;
        extend(idx(S[i]),i);
    }
    }
    void topo()
    {
    ms(cnt,0); 
    for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
    for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
    //rk[1]是len最小的状态的标号
    for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
    }
    void pre()  //跑拓扑序，预处理一些东西
    {
    tot_str = tot_unique_str = 0;
    for ( int i = sz ; i >= 2 ; i--)
    {
        int v = rk[i];
        int fa = st[v].link;
        if (fa==-1) continue;
        tot_str += 1LL*st[v].Right*(st[v].len-st[fa].len);
        tot_unique_str += 1LL*(st[v].len-st[fa].len);
        st[fa].rightmost = max(st[fa].rightmost,st[v].rightmost);
        st[fa].Right += st[v].Right;
    }
    }
    void solve()
    {
    LL ans = 0 ;
    for ( int i = sz ; i >= 2 ; i--)
    {
        int v = rk[i];
        if (st[v].link==-1) continue;
        ans = ans + 1LL * st[v].Right*(st[v].Right+1)/2 * (st[v].len-st[st[v].link].len);
    }
    printf("%lld\n",ans);
    }
    int LCS(char *s)
    {
    int ans = 0,len = 0 ;
    int p = rt;
    for ( int i = 0 ,_len = strlen(s) ; i < _len ; i++)
    {
        int ID = s[i]-'a';
        if (st[p].nxt[ID]!=-1) p = st[p].nxt[ID],len++;
        else
        {
        while (p!=-1&&st[p].nxt[ID]==-1) p = st[p].link;
        if (p==-1) p=rt,len=0;else len = st[p].len+1,p = st[p].nxt[ID];
        }
      //  printf("len:%d\n",len);
        ans = max(ans,len);
    }
    return ans;
    }
 
    //把原串复制一遍到后面，然后构建后缀自动机。
    //从初始状态开始，每次走字典序最小的转移，走|S|之后得到的就是最小循环表示。
    //如果求的是最小后缀，就在原串后加入一个比字符集中所有字符的字典序都小的字符作为终止后，再添加一遍原串。
    int smallest_string()  //求一个串的最小循环表示，返回起始位置下标
    {
    int p = 1;
    int slen = strlen(S);
    for ( int i = 0 ; i < slen ; i++)
    {
        bool flag = false;
        for ( int j = 0 ; j < 26 ; j++) //找字典序最小的
        if (st[p].nxt[j])
        {
            flag = true;
            p = st[p].nxt[j];
            break;
        }
        if (!flag) break;
    }
    return st[p].len + 1 - slen;
    }
}A;
```

##### hdu 4416

###### 给出一个字符串A和n个字符串B,问A的子串中，不在任何一个B中出现的本质不同的子串有多少。

```c++
#define MAXALP 30
const int mod = 2012;
struct state
{
    int len, link, nxt[MAXALP];
};
const int N =1E5+7;
state st[N*2];
int sz, last,rt;
char s[N];
int cnt[2*N],rk[2*N];//for radix sort
int dp[2*N];
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
}
void sa_extend(int c)
{
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
    int p;
    for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
        st[p].nxt[c] = cur;
    if (p == -1) {
        st[cur].link = rt;
    } else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = ++sz ;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
            for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                st[p].nxt[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void topo()
{
    ms(cnt,0); 
    for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
    for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
    for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
}
char ST[N];
int n;
int main()
{
#ifndef  ONLINE_JUDGE 
        freopen("./in.txt","r",stdin);
#endif
 
    int T;
    int cas = 0 ;
    cin>>T;
    while (T--)
    {
    scanf("%d",&n);
    scanf("%s",ST);
    sa_init();
    for (int i = 0,len = strlen(ST);  i < len ; i++)
    {
        sa_extend(ST[i]-'a');
    }
    topo();
    ms(dp,0);
    for ( int i = 0 ; i < n ; i++)
    {
        scanf("%s",ST);
        int now = rt,len = 0;
        for ( int i = 0,_len = strlen(ST) ; i < _len ; i++)
        {
        if (st[now].nxt[ST[i]-'a']!=-1)
        {
            now = st[now].nxt[ST[i]-'a'];
            len++;
            dp[now] = max(dp[now],len);
          //  printf("now:%d dp[now]:%d len: %d\n",now,dp[now],len);
        }
        else 
        {
            while (now!=-1&&st[now].nxt[ST[i]-'a']==-1) now = st[now].link;
            if (now==-1) now=rt,len=0;else len = st[now].len + 1,now=st[now].nxt[ST[i]-'a'],dp[now] = max(dp[now],len);
        }
        }
    }
    LL ans = 0 ;
    for ( int i = sz ; i >= 1 ; i-- )
    {
        int v = rk[i];
        if (dp[v])
        {
        dp[st[v].link] = max(dp[st[v].link],dp[v]);
        if (dp[v]<st[v].len) ans += st[v].len-dp[v]; // 长度为[dp[v]+1,st[v].len]的串不在n个B串中出现，可以贡献答案。
        }else ans += st[v].len - st[st[v].link].len;
    }
    printf("Case %d: %lld\n",++cas,ans);
    }
 
 

```

#### 

##### poj3415（lazy标记沿parent树上传）

###### 给出两个字符串，问公共长度大于等于k的子串个数（只要两个串的位置不同就认为是不同）

```c++
#define MAXALP 55 //还有大写字母orz
int k;
struct state
{
    int len, link, nxt[MAXALP];
};
const int N =1E5+7;
state st[N*2];
int sz, last,rt;
char s[N];
int Right[2*N];
int cnt[2*N],rk[2*N];//for radix sort
int dp[2*N],lazy[2*N];
void sa_init()
{
    sz = 0;
    last = rt = ++sz;
    st[1].len = 0;
    st[1].link=-1;
    ms(st[1].nxt,-1);
}
void sa_extend(int c)
{
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    memset(st[cur].nxt, -1, sizeof(st[cur].nxt));
    int p;
    for (p = last; p != -1 && st[p].nxt[c] == -1; p = st[p].link)
        st[p].nxt[c] = cur;
    if (p == -1) {
        st[cur].link = rt;
    } else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = ++sz ;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            memcpy(st[clone].nxt, st[q].nxt, sizeof(st[q].nxt));
            for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                st[p].nxt[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
void topo()
{
    ms(cnt,0); 
    for (int i = 1 ; i <= sz ; i++) cnt[st[i].len]++;
    for ( int i = 1 ; i <= sz ; i++) cnt[i]+=cnt[i-1];
    for (int i = 1 ; i <= sz  ;i++) rk[cnt[st[i].len]--] = i;
}
char ST[N];
int idx( char c)
{
    if (c>='a'&&c<='z') return c-'a';
    return c-'A'+26;
}
int main()
{
#ifndef  ONLINE_JUDGE 
        freopen("./in.txt","r",stdin);
#endif
    while (~scanf("%d",&k)!=EOF)
    {
    if (k==0) break;
    ms(Right,0);
    ms(lazy,0); //parent树上的lazy标记，最后子底向上更新
    scanf("%s",ST);
//  cout<<"ST:"<<ST<<endl;
    sa_init();
    for (int i = 0,len = strlen(ST);  i < len ; i++)
    {
        Right[sz+1] = 1;
        sa_extend(idx(ST[i]));
    }
    topo();
    for ( int i = sz ; i >=1 ; i--) if (st[rk[i]].link!=-1)Right[st[rk[i]].link]+=Right[rk[i]];
    //check right
//  for ( int i = sz ; i >=1 ; i--) printf("right:%d\n",Right[i]);
    scanf("%s",ST);
    int now = rt,len = 0;
    LL ans = 0 ;
    for ( int i = 0,_len = strlen(ST) ; i < _len ; i++)
    {
        int id = idx(ST[i]);
        if (st[now].nxt[id]!=-1)
        {
        now = st[now].nxt[id];
        len++;
        //  printf("now:%d dp[now]:%d len: %d\n",now,dp[now],len);
        }
        else 
        {
        while (now!=-1&&st[now].nxt[id]==-1) now = st[now].link;
        if (now==-1) now=rt,len=0;else len = st[now].len + 1,now=st[now].nxt[id];
        }
//      printf("len:%d\n",len);
        if (len>=k)
        {
        if (st[now].link==-1) continue;
        ans += 1LL*(len-max(k,st[st[now].link].len+1)+1)*Right[now];
        if (st[st[now].link].len>=k) lazy[st[now].link]++;
        }
    }
 
    for ( int i = sz ; i >= 1 ; i-- )
    {
        int v = rk[i];
        if (st[v].link==-1) continue;
        ans += 1LL*lazy[v]*(st[v].len-max(k,st[st[v].link].len+1)+1)*Right[v];
        if (st[st[v].link].len>=k) lazy[st[v].link] += lazy[v]; //lazy标记沿着parent树向上传递
    }
    printf("%lld\n",ans);
    }
```



####kmp算法
kmp算法中nxt[i]的含义：
next[i]的含义是,i之前的整个前缀中，最长的该前缀的前缀和后缀相同的长度。
需要注意的是，模板串不变的话，nxt数组求一次就行了。

```c++
void getnxt( int n)
{
    int i = 0;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||b[i]==b[j]) nxt[++i]=++j;
    else j = nxt[j];
}
 
void kmp( int n,int m)
{
    int i = 0 ;
    int j = 0 ;
    getnxt(m);
   // for ( int i = 0 ; i < m ; i++) cout<<i<<" "<<nxt[i]<<endl;
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
	if (j==m) ans++,j=nxt[j];
 
//        cout<<"n:"<<n<<" i:"<<i<<" j:"<<j<<endl;
    }
```
}
如果不允许重叠。。。
其实只要每次找到的时候j=0一下就好咯。

######最小覆盖子串：对于某个字符串s，它的最小覆盖子串指的是长度最小的子串p，p满足通过自身的多次连接得到q，最后能够使s成为q的子串。

结论先行：最小覆盖子串（串尾多一小段时，用前缀覆盖）长度为n-next[n]（n-pre[n]），其中n为串长，串的最后一位为为s[n-1].



####AC自动机
```c++
struct Trie
{
    struct Node
    {
    Node *nxt[26];
    Node *fail;
    int cnt;
    Node()
    {
	for ( int i = 0 ; i < 26 ; i++) nxt[i] = NULL;
	cnt = 0 ;
	fail=NULL;
    }
    };
    Node *root;
    void init()
    {
    root = new Node();
    }
    void Insert(char *s)
    {
    int len = strlen(s);
    Node *u = root;
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'a';
	if (u->nxt[v]==NULL) u->nxt[v] = new Node();
	u = u->nxt[v];
    }
    u->cnt++;
    }
    void getFail()
    {
    root->fail = root;
    queue<Node*>Q;
    for ( int i = 0 ; i < 26 ; i++)
    {
	if (root->nxt[i]==NULL)
	root->nxt[i] = root;
	else
	{
	root->nxt[i]->fail = root;
	Q.push(root->nxt[i]);
	}
    }
    while (!Q.empty())
    {
	Node *cur = Q.front();
	Q.pop();
	for ( int i = 0 ; i < 26 ; i++)
	if (cur->nxt[i]==NULL)
	{
	    cur->nxt[i] = cur->fail->nxt[i];
	}
	else
	{
	    cur->nxt[i]->fail = cur->fail->nxt[i];
	    Q.push(cur->nxt[i]);
	}
    }
    }
    int Search(char *s)
    {
    int len = strlen(s);
    Node *u = root;
    int res = 0 ;
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'a';
	u = u->nxt[v];
	Node *tmp = u;
	while (tmp!=root)
	{
	res = res + tmp->cnt;
	tmp->cnt = 0 ;
	tmp = tmp->fail;
	}
    }
    return res;
    }
}ac;
```


####trie 树
#####带删除的静态trie树模板
```c++
int n;
char s[N][12];
int tot;
struct Trie
{
    int nxt[10];
    int cnt;
 
    void init()
    {
	ms(nxt,0);
	cnt = 0;
    }
}trie[N];
int add()
{
    memset(&trie[tot],0,sizeof(Trie));
    return tot++;
}
void Insert(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'0';
	if (!trie[rt].nxt[v]) trie[rt].nxt[v] = add();
	rt = trie[rt].nxt[v];
	trie[rt].cnt++;
    }
}
void Delete(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ; i++)
    {
	int v = s[i]-'0';
	if (trie[rt].nxt[v])
	{
	    rt = trie[rt].nxt[v];
	    trie[rt].cnt--;
	}
    }
}
bool Find(char *s)
{
    int rt = 0 ;
    int len = strlen(s);
    for ( int i = 0 ; i < len ;i++)
    {
	int v = s[i]-'0';
	if (!trie[rt].nxt[v]||trie[trie[rt].nxt[v]].cnt==0) return false;
	rt = trie[rt].nxt[v];
    }
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T ; 
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    tot = 1;
	    trie[0].init();
	    for ( int i = 1 ; i <= n ; i++)
	    {
	        scanf("%s",s[i]);
	        Insert(s[i]);
	    }
	    bool ok = true;
	    for ( int i = 1 ; i <= n ; i++)
	    {
	        Delete(s[i]);
	        if (Find(s[i]))
	        {
	            ok = false;
	            break;
	        }
	        Insert(s[i]);
	    }
	    if (ok)
	    {
	        puts("YES");
	    }
	    else
	    {
	        puts("NO");
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
```



####manacher算法
复杂度:O(n)
可以求一个字符串中的最长回文子串
求回文子串的最大长度模板：

```c++
int p[2*N];
int manachar( char *s)
{
    int len = strlen(s);
    int id = 0; //id表示之前位置的能延伸到最远位置的字符串的中心位置。
    int maxlen = 0 ;  //maxlen是为了更新答案而用。。。就是记录了一个最大值。。。
    int mx = 0 ;//mx为当前位置之前的回文串能延伸到的最远位置 即：max(p[j]+j) (j<i)
	        //如果知道之前能延伸到最远位置的字符串的中心位置的下标为id，那么就是p[id]+id;
    for ( int i = len ; i >= 0 ; i--)  //插入'#'是为了将字符串长度奇偶性不同的统一考虑。
    {
	s[i+i+2] = s[i];
	s[i+i+1] = '#';
    }
    s[0]='*'; //s[0] ='*'以及用字符数组最后默认的s[len+len+2]='\0'是为了下面while 循环的时候不溢出。。
	        //两边的字符一定要不一样。。用string的话记得两边都加字符。。。
    for ( int i = 2 ; i < 2*len+1 ; i++)
    {
	if (p[id]+id>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;
	while (s[i-p[i]]==s[i+p[i]]) p[i]++;
	if (id+p[id]<i+p[i]) id = i;
	if (maxlen<p[i]) maxlen = p[i];
    }
    return maxlen-1;  
    //这道题是问最长回文串的长度。。。如果是问回文串是什么的话。。。根据id和maxlen也可以构造出来。。。
}
```

manacher求最长回文子串的开始结束位置

```c++
void manacher(char *s)
{
    int len = strlen(s);
 
    for ( int i = len ;  i>= 0 ; i--)
    {
	s[i*2+2] = s[i];
	s[i*2+1] = '#';
    }
 
    int id = 0 ;
    int maxlen = 0 ;
    int center = 0 ;
    s[0]='%';
    for ( int i = 2 ; i < 2*len+1 ; i++)
    {
	if (id+p[id]>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;
 
	while (s[p[i]+i]==s[i-p[i]]) p[i]++;
 
	if (id+p[id]<i+p[i]) id = i;
	if (p[i]>maxlen)
	{
	    maxlen = p[i];
	    center = i;
	}
    }
    int ans = (maxlen-1);
   // cout<<"ans:"<<ans<<" center:"<<center<<endl;
    if (ans<2)
    {
	puts("No solution!");
    }
    else
    {
	int left = center/2-1-ans/2+(ans%2==0);
	int right = center/2-1+ans/2;
	printf("%d %d\n",left,right);
	for ( int  i = left ; i <= right ; i++) printf("%c",st2[i]);
	printf("\n");
    }
    
}
```



#### 回文自动机

**在构建完PAM之后，沿着回文链（类比后缀链)从底向上跑一遍得到的cnt，才是真正的cnt**



```c++
struct PAM
{
    //cnt表示某个节点的回文串的数量
    //len表示的是该状态所表示的回文串的长度
    //PAM有２个根，分别为状态０和状态１
    //初２个根外，其余每个状态表示一个本质不同的回文串,总数为sz-1
    struct state
    {
    int fail,cnt,len;
    int nxt[26];
    }st[N];
    char S[N],RS[N];
    int n,now,sz;
    int Right[N];//Right[i]表示以i结尾的最长回文串的长度
    int Left[N]; //Left[i]表示以i开头的最长回文串的长度...只需要倒序构建PAM就行了
    void init()
    {
    ms(st,0);
    now = 0 ;
    st[0].fail = st[1].fail = 1;
    st[1].len = -1;
    sz = 1;
    }
    void extend(int c,int pos)  
    {
    int p = now;
    while (S[pos-st[p].len-1]!=S[pos]) p = st[p].fail;
    if (!st[p].nxt[c]){
        int np=++sz,q=st[p].fail;
        st[np].len=st[p].len+2;
        while (S[pos-st[q].len-1]!=S[pos]) q=st[q].fail;
        st[np].fail=st[q].nxt[c];
        st[p].nxt[c] = np;
    }
    now=st[p].nxt[c];
    Right[pos] = st[now].len;
    st[now].cnt++;
    }
    void Cnt() //构建之后跑cnt得到的才是真正的cnt
    {
    for ( int i = sz ; i >= 2;  i--) st[st[i].fail].cnt += st[i].cnt;
    }
    void build ()
    {
    init();
    int len = strlen(S+1);
    for ( int i = 1 ; i <= len ; i++) extend(S[i]-'a',i);
    }
}A,B;
```



####后缀数组

#####给出一个字符串，问所有不同的字串的个数。

```c++
const int N=1E3+7;
int n;
char s[N];
int sa[N],rk[N],t[N],t2[N],cnt[N];
int height[N];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
 
void getSa(int n,int m)
{
    int *x = t,*y = t2;
    ms(cnt,0);
    for ( int i = 0 ; i < n ; i++) cnt[x[i]=s[i]]++;
    for ( int i = 1 ; i < m ; i++) cnt[i] += cnt[i-1];
    for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[i]]] = i ;
    for ( int k = 1 ; k <=  n;  k <<=1 )
    {
	int p = 0 ;
	for ( int i = n-k ; i < n; i ++) y[p++] = i;
	for (  int i = 0 ; i < n ; i++) if (sa[i]>=k) y[p++] = sa[i]-k;
	ms(cnt,0);
	for ( int i = 0 ; i < n ; i++) cnt[x[y[i]]]++;
	for ( int i = 0 ; i < m ; i++) cnt[i]+=cnt[i-1];
	for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[y[i]]]] = y[i];
	swap(x,y);
	p = 1;
	x[sa[0]] = 0;
	for ( int i = 1 ; i < n ; i++)
	    x[sa[i]] = cmp(y,sa[i-1],sa[i],k)?p-1:p++;
	if (p>=n) break;
	m = p;
    }
}
 
void getHeight( int n)
{
    int k = 0 ;
    for ( int i = 0 ; i < n ;i ++) rk[sa[i]] = i ;
    height[0] = 0 ;
    for ( int i = 0 ; i < n;  i++)
    {
	if (rk[i]==0) continue;
	if (k) k--;
	int j = sa[rk[i]-1];
	while (s[i+k]==s[j+k]) k++;
	height[rk[i]] = k ;
    }
}
 
int getSuffix( char s[])
{
    int len = strlen(s);
    int up = 0;
    for ( int i = 0 ; i < len ; i++)
    {
	int val = s[i];
	up = max(up,val);
    }
    s[len++]='$';
    getSa(len,up+1);
    getHeight(len);
    return len;
}
 
int solve( int n)
{
  //  for ( int i = 0 ; i < n ; i++) cout<<"i:"<<i<<" height[i]:"<<height[i]<<endl;
    
    ms(cnt,0); //cnt在求完sa之后就没用了，所以拿来用一下，嘿嘿嘿
    int up = 0 ;
    for ( int i = 0 ; i < n; i++) cnt[height[i]]++,up=max(up,height[i]);
 
    for ( int i = up-1 ; i >=1 ; i--) cnt[i] = cnt[i]+cnt[i+1];
    int res = 0 ;
    //for ( int i = 1 ; i <= up; i++) cout<<"cnt[i]:"<<cnt[i]<<endl;
    for ( int i = 1 ; i <= up ; i++ )
	res += cnt[i];
    return res;
}
 
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
 
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%s",s);
	   int len = getSuffix(s);
	   int ans = len*(len-1)/2;
	    ans-=solve(len);
	    printf("%d\n",ans);
 
	}
```

#####给出两个字符串，问最长的公共连续字串	（模板题）
首先要理解后缀，后缀数组（sa[]），名次数组(rk[])，height数组，lcp 这些概念

先从定义入手，得到sa数组的n2logn的求法...

由于复杂度爆炸，所以有了两个算法来优化求sa的过程，一个是nlogn的倍增，还有一个是O(n)的dc3。。。

倍增的算法中用到了radix sort

上面这些，都是在说如何求sa,但是如果只有sa一个数组的话，就没有办法很好感受 后缀数组的power.

于是引入了height数组。

定义 height[i]=suffix(sa[i-1])和 suffix(sa[i])的最长公
共前缀,也就是排名相邻的两个后缀的最长公共前缀。那么对于 j 和 k,不妨设
rank[j]<rank[k],则有以下性质:
suffix(j) 和 suffix(k) 的 最 长 公 共 前 缀 为 height[rank[j]+1],
height[rank[j]+2], height[rank[j]+3], ... ,height[rank[k]]中的最小值。

有很多问题都是基于height数组的，慢慢感受。

 

再说这道题：我们可以把两个字符串中间用一个特殊符号连接起来。

那么两个字符串的最长公共字串，就变成了求合并后的字符串的所有后缀的最长公共前缀。（原因是字符串的任何一个字串都可以看成是该字符串的某个后缀的前缀）

那么容易知道，该最长公共前缀的长度一定是某个height值（原因是，height[i]表示的是排名相邻的两个后缀的最长公共前缀的长度，如果不相邻，那么取的是他们排名之间所有height的最小值，只会越来越小。）

还需要注意的是，必须满足得到该height的两个后缀分别出现在原来的两个字符串中...

要怎么办到呢？ 其实很容易，由于sa[i]数组存放的是排名第i的后缀是后缀几(定义从第x个字符开始的后缀就是后缀x)

设初始第一个字符串的长度为len1,那么如果是第一个字符串的后缀，一定有sa[i]<len1,如果是第二个字符串的后缀，就一定有sa[i]>len1  (sa[i]==len1的是插入的特殊符号开始的后缀)

```c++
const int N=2E5+7;
char s[N];
int sa[N],t[N],t2[N],cnt[N],n;
int c[N];
int w[N];
int rk[N],height[N];
int cmp( int *r,int a,int b,int l){ return r[a]==r[b]&&r[a+l]==r[b+l] ;};
void build_sa(int n,int m) //其实我觉得。。。sa怎么得到的不用管。。这部分讲道理不会变。。。反正知道能nlogn得到sa就对了2333
{
    int *x=t,*y=t2;
    // 基数排序（不是计数排序！） radix sort...
    for ( int i = 0 ; i < m ; i++) c[i] = 0 ; //ms(cnt,0);
    for ( int i = 0 ; i < n;  i++) c[x[i]=s[i]]++; //x[i]相当于保存了rank的相对大小，由于只是为了比较大小，所以没必要求出真实的rank值。
    for ( int i = 1 ; i < m ; i++) c[i]+=c[i-1];
    for ( int i = n-1 ; i >= 0 ;i--) sa[--c[x[i]]] =  i;
```


```c++
    for ( int k = 1 ; k <= n ; k<<=1)  //进行若干次基数排序，每次对长度为k的字符串排序
    {
	int p  = 0 ;
	for ( int i = n-k ; i < n ; i++)  y[p++] = i;  
	for ( int i = 0 ; i < n ; i++) if (sa[i]>=k) y[p++] = sa[i]-k; //y保存对第二关键字排序的结果，可以直接用上一次求得的sa算出。
	for ( int  i = 0 ; i < m  ;  i++) c[i] = 0;
	for ( int i = 0 ; i < n ; i++) c[x[y[i]]]++;
	for ( int i = 0 ; i < m ; i++) c[i]+=c[i-1];
	for ( int i = n-1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];
	swap(x,y);
	p = 1;
	x[sa[0]] = 0 ;
	for ( int i = 1 ; i < n ; i++)
	    x[sa[i]]= cmp(y,sa[i-1],sa[i],k)?p-1:p++;
	if (p>=n) break;
	m = p;
    }
}
void getHeight( int n)
{
    int k = 0 ;
    for ( int i = 0 ; i < n ; i++) rk[sa[i]] = i;
    height[0] = 0 ;
    for ( int i = 0 ; i < n ; i++) 
    {
	if (rk[i]==0) continue;
	if (k) k--;
	int j = sa[rk[i]-1];
	while (s[i+k]==s[j+k]) k++;
	height[rk[i]] = k;
    }
}
int getSuffix(char s[])
{
    int len = strlen(s);
    int up = 0 ;
    for ( int i =  0 ; i < len ; i++)
    {
	w[i] = s[i];
	up = max(up,w[i]);
    }
    w[len++] = 0 ;
    build_sa(len,up+1);
    getHeight(len);
    return len;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	string st1,st2,st;
	cin>>st1>>st2;
	int len1 = st1.length();
	st = st1 + "$" + st2;
	strcpy(s,st.c_str());
	int len = getSuffix(s);
//        cout<<"s:"<<s<<endl;
//        for ( int i = 0 ; i < len ; i++) cout<<s[i]<<" "<<w[i]<<endl;
//        for ( int i = 0 ; i < len ; i++) cout<<"sa[i]:"<<sa[i]<<endl;
//        for ( int i = 0 ; i < len ; i++) cout<<"height[i]:"<<height[i]<<endl;
	
	int ans = 0 ;
     //  cout<<"len1:"<<len1<<endl;        
	for ( int i = 2 ; i < len ; i++)
	if (height[i]>ans)
	{
	    if (0<=sa[i-1]&&sa[i-1]<len1&&len1<sa[i]) ans = height[i];
	    if (0<=sa[i]&&sa[i]<len1&&len1<sa[i-1]) ans = height[i];
	}
	printf("%d\n",ans);
```
#####给一个字符串，要求找出至少出现k次的最长重复子串...
然后再次用到了根据height数组对后缀进行分组的套路...二分判定合法性，对于当前的最长长度x,分组使得每组中的height[i]都大于等于x,所不同的是，判定变成了存在一个组，后缀的个数至少为k个（因为这样，就可以对于大于等于k个的后缀，同时取前x长度，得到的就是出现了至少k次且长度为x的前缀）1A,蛤蛤蛤



```c++
const int N=2E4+7;
const  int M=2E6+11;
const int C = 5;
int n,sa[N],rk[N],t[N],t2[N],cnt[M];
int height[N];
int s[N];
int k;
int cmp(int *r,int a,int b,int l){ return r[a]==r[b]&&r[a+l]==r[b+l];}
void getSa( int n,int m)
{
    int *x = t;
    int *y = t2;
    ms(cnt,0);
    for ( int i = 0 ; i < n;  i++) cnt[x[i]=s[i]]++;
    for ( int i = 1 ; i < m ; i++) cnt[i]+=cnt[i-1];
    for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[i]]] =  i;
    for ( int k = 1 ; k <= n ; k<<=1)
    {
	int p = 0;
	for ( int i = n-k ; i < n;  i++) y[p++] = i ;
	for ( int i = 0 ; i < n;  i++) if (sa[i]>=k) y[p++] = sa[i]-k;
	ms(cnt,0);
	for ( int i = 0 ; i <n ; i++) cnt[x[y[i]]]++;
	for ( int i = 0 ; i <m ; i++) cnt[i]+=cnt[i-1];
	for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[y[i]]]] = y[i];
	swap(x,y);
	p = 1;
	x[sa[0]] = 0 ;
	for ( int i = 1 ; i < n; i++)
	    x[sa[i]] = cmp(y,sa[i-1],sa[i],k)?p-1:p++;
	if (p>=n) break;
	m = p;
    }
}
void getHeight( int n)
{
    int k = 0 ;
    for ( int i = 0 ; i < n; i++) rk[sa[i]] = i ;
    height[0] =  0;
    for ( int i = 0 ; i < n; i ++)
    {
	if (rk[i]==0) continue;
	if (k) k--;
	int j = sa[rk[i]-1];
	while (s[i+k]==s[j+k]) k++;
	height[rk[i]] = k ;
    }
}
int getSuffix( int s[],int len)
{
    int up = 0 ;
    for ( int i = 0 ; i < len ; i++)
    {
	up = max(up,s[i]);
    }
    s[len++] = 0 ;
    getSa(len,up+1);
    getHeight(len);
    return len;
}
bool check( int x,int k,int n)
{
    int cnt = 1 ;
    for ( int i = 2; i  <= n ; i++)
    {
	if (height[i]>=x&&i<n)
	{
	    cnt++;
	    continue;
	}
	if (cnt>=k) return true;
	cnt = 1;
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d %d",&n,&k);
	for ( int i = 0 ; i < n ; i++) scanf("%d",&s[i]),s[i]+=C;
	n = getSuffix(s,n);
//        for ( int i = 0 ; i < n; i++) cout<<"s[i]:"<<s[i]<<endl;
	int l = 1,r = n;
	int ans = 0 ;
	while (l<=r)
	{
	    int mid = (l+r)/2;
	    if (check(mid,k,n))
	    {
	        ans = mid;
	        l = mid + 1;
	    }
	    else r = mid-1;
	}
	printf("%d\n",ans);
```
##dp
####最大连续前缀和
```c++
for ( int i = 1 ; i <= n ; i++ )
{
    last = max(0,last)+a[i];
    ans = max(ans,last);
}
```


####数位dp
#####hdu 2089 问区间[n,m]中，不含数字4，也不含数字串“62”的所有数的个数。

```c++
int n,m;
int dp[30][2];
int digit[30];
 
	int dfs (int pos,bool preis6,bool limit)  //pos表示从低到高的第几位，是从高位往低位递归的（也就是从左到又）
			                          // preis6 表示上一个数字是否为6，
			                          // limit表示该位置是否有限制。
	{
	//    cout<<pos<<" "<<preis6<<" "<<limit<<" "<<endl;
	    if (pos==0) return 1; //到该位置表明找到了一个解.
	 
	    int res = 0 ;
	    if (!limit&&dp[pos][preis6]!=-1) return dp[pos][preis6];  //如果不是limit位置，表示结果是通用的，而之前又算过的话，就可以直接调用这个结果。
	    int mx = limit?digit[pos]:9; //mx第pos位置能取到的最大的数字..如果不是limit,则可以0..9任意取。
	//    cout<<"mx:"<<mx<<endl;
	    
	    for ( int i = 0 ; i <= mx;  i++)
	    {
		if (i==4||(i==2&&preis6)) continue;
		res += dfs(pos-1,i==6,limit&&i==mx); 
		//(limit&&i==mx)中limit的含义是。。如果当前一位不是limit位（即0..9可以随便取的位置）
		//，那么之后的位置也一定不是limit位置。
		//而i==mx部分的意思是，在当前位置的数字小于当前位置的数字能取的最大值（mx）之前，
		//后面位的数字随便取也不会超过上界。
	    }
	    
	    if (!limit) dp[pos][preis6]=res;  //记忆化. 非limit位的结果才通用，不然没必要存。
	 
	    return res;
 
}
int solve ( int n)
{
    ms(digit,0);  //将数按照每一位存到digit数组中
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % 10;
	n/=10;
    }
 
    return dfs(len,false,true);
 
}
 
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
 
	while (~scanf("%d %d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    
	    ms(dp,-1);
	    int ans = solve (m)-solve(n-1);
 
	    printf("%d\n",ans);
	}
```


​	

#####不允许前导0的数位dp

hdu 5787 :给出l,r,k(k<=5)求区间[l,r]中满足任意相邻k个数字都不相同的数的个数.

```c++
	LL l,r;
	int k;
	LL digit[25];
	LL dp[22][11][11][11][11];
	int LEN;
	LL dfs(int pos,int k1,int k2,int k3,int k4,bool limit,bool prehasnonzero)
	{
	    if (pos==0) return 1;
	    if (prehasnonzero&&!limit&&dp[pos][k1][k2][k3][k4]!=-1LL) return dp [pos][k1][k2][k3][k4];
	 
    int mx = limit?digit[pos]:9;
    LL res = 0LL;
    if (!prehasnonzero)
    {
	for  (int i = 0 ; i <= mx ;i++)
	{
	    res +=dfs(pos-1,i,10,10,10,limit&&i==mx,i==0?false:true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	   // if (i==k1||i==k2||i==k3||i==k4) continue;
	    if (k>=2&&i==k1) continue;
	    if (k>=3&&i==k2) continue;
	    if (k>=4&&i==k3) continue;
	    if (k>=5&&i==k4) continue;
 
	    res +=dfs(pos-1,i,k1,k2,k3,limit&&i==mx,true);
	}
    }
 
    if (prehasnonzero&&!limit) dp[pos][k1][k2][k3][k4] = res;
    return res;
}
LL solve ( LL n)
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n%10;
	n/=10;
    }
    LEN = len;
    return dfs(len,10,10,10,10,true,false);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%d",&l,&r,&k))
	{
	    ms(dp,-1);
//            cout<<"solve(100):"<<solve(100)<<endl;
//            cout<<"solve(r):"<<solve(r)<<" solve(l-1):"<<solve(l-1)<<endl;
	    LL ans = solve(r)-solve(l-1);
	    printf("%lld\n",ans);
	}
```

#####带整除的数位dp

hdu3652：给出n,问[1,n]中，满足包含“13”且这个数（不是各位的和）能被13整除的数的个数。做法是把能被13整除的数考虑成全集U,然后在U中做分划，一部分是含13的，另一部分是不含13的。dfs要一个参数记录从最高位到现在的pos位置的数字之和%13的结果

```c++
LL n;
LL dp[20][15];
LL dp2[20][2][15];
int digit[20];
```


```c++
LL dfs (int pos,int sum,bool limit)
{
    if (pos==0) return sum==0;
    
    if (!limit&&dp[pos][sum]!=-1) return dp[pos][sum];
 
    int mx = limit ? digit[pos]:9;
 
    LL res = 0LL ;
    for ( int i = 0 ; i  <=  mx ; i++)
    {
	res+=dfs(pos-1,(sum*10+i)%13,limit&&i==mx);
    }
    
    if(!limit) dp[pos][sum] = res;
    return res;
}
LL dfs2(int pos,bool preis1,int sum,bool limit)
{
    if (pos==0) return sum==0;
 
    if (!limit&&dp2[pos][preis1][sum]!=-1) return dp2[pos][preis1][sum];
 
    int mx = limit? digit[pos]:9;
    LL res = 0 ;
    for ( int i = 0 ; i <=  mx ; i++)
    {
	if (preis1&&i==3) continue;
	res+=dfs2(pos-1,i==1,(sum*10+i)%13,limit&&i==mx);
    }
 
    if (!limit) dp2[pos][preis1][sum] = res;
    return res;
}
 
LL solve ( LL n)
{
    ms(digit,0);
 
    int len =  0;
    while (n)
    {
	digit[++len] = n%10;
	n/= 10;
    }
    return dfs(len,0,true)-dfs2(len,false,0,true); //在能被13整除的数里划分，减去不含“13”的，就是含“13”的。
	                                          //因为含“13”的情况太复杂了。。。
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	ms(dp,-1); //dp数组子啊外面清空就好。。。。因为dp数组是所有数据公用的啊。。。。
	ms(dp2,-1);
	while (~scanf("%lld",&n))
	{
	    LL ans = solve (n);
	    printf("%lld\n",ans);
	}
```

#####b进制数位dp

```c++
int l,r;
int k,base;
int digit[700];
int dp[700][700];
```


```c++
int dfs( int pos , int cnt, bool limit)
{
    if (pos==0) return cnt==0;
    if (cnt<0) return 0;
 
    if (!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
 
    int mx = limit?digit[pos]:1;
   // int mx = 1;
    int res = 0 ;
    for ( int i = 0 ; i <= mx ; i ++)
    {
	if (i>1) continue;
	res += dfs(pos-1,i==1?cnt-1:cnt,limit&&i==mx);
    }
    return limit?res:dp[pos][cnt] = res;
}
int solve(int n )
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % base;
	n/=base;
    }
 
    return dfs(len,k,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
	 #endif
//        ios::sync_with_stdio(false);
	ms(dp,-1);
	cin>>l>>r;
	cin>>k>>base;
//        cout<<"solve(r):"<<solve(r)<<" solve(l-1):"<<solve(l-1)<<endl;
	int ans = solve (r) - solve (l-1);
	cout<<ans<<endl;
 int l,r;
int k,base;
int digit[700];
int dp[700][700];
```


```c++
int dfs( int pos , int cnt, bool limit)
{
    if (pos==0) return cnt==0;
    if (cnt<0) return 0;
 
    if (!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
 
    int mx = limit?digit[pos]:1;
   // int mx = 1;
    int res = 0 ;
    for ( int i = 0 ; i <= mx ; i ++)
    {
	if (i>1) continue;
	res += dfs(pos-1,i==1?cnt-1:cnt,limit&&i==mx);
    }
    return limit?res:dp[pos][cnt] = res;
}
int solve(int n )
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % base;
	n/=base;
    }
 
    return dfs(len,k,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
	 #endif
//        ios::sync_with_stdio(false);
	ms(dp,-1);
	cin>>l>>r;
	cin>>k>>base;
//        cout<<"solve(r):"<<solve(r)<<" solve(l-1):"<<solve(l-1)<<endl;
	int ans = solve (r) - solve (l-1);
	cout<<ans<<endl;
```

##博弈论

一、巴什博弈

> 1、问题模型：只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个，最后取光者得胜。
>
> 2、解决思路：当n=m+1时，由于一次最多只能取m个，所以无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜，所以当一方面对的局势是n%(m+1)=0时，其面临的是必败的局势。所以当n=（m+1)*r+s，（r为任意自然数，s≤m)时,如果先取者要拿走s个物品，如果后取者拿走x（≤m)个，那么先取者再拿走m+1-k个，结果剩下（m+1）（r-1）个，以后保持这样的取法，那么先取者肯定获胜。总之，要保持给对手留下（m+1）的倍数，就能最后获胜。
>
> 3、变形：条件不变，改为最后取光的人输。
>
> 结论：当（n-1）%（m+1）==0时后手胜利。
>
> 4、题目练习：HDOJ：2188 2149 1849

二、威佐夫博奕

> 1、问题模型：有两堆各若干个物品，两个人轮流从某一堆或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。
>
> 2、解决思路：A：设（ai,bi）（ai ≤bi  ,i=0，1，2，…,n)表示两堆物品的数量并称其为局势，如果甲面对（0，0），那么甲已经输了，这种局势我们称为奇异局势。前几个奇异局势是：（0，0）、（1，2）、（3，5）、（4，7）、（6，10）、（8，13）、（9，15）、（11，18）、（12，20）。任给一个局势（a，b），如下公式判断它是不是奇异局势： ak =[k（1+√5）/2]，bk= ak + k  （k=0，1，2，…,n 方括号表示取整函数）。（证明见百度百科）
>
> B：详见 [http://www.freopen.com/?p=10512）](http://www.freopen.com/?p=10512%EF%BC%89)
>
> 3、满足上公式的局势性质：
>
> （1）任何自然数都包含在一个且仅有一个奇异局势中。
>
> ​     由于ak是未在前面出现过的最小自然数，所以有ak > ak-1 ，而 bk= ak + k > ak-1 + k-1 = bk-1 > ak-1 。所以性质成立。
>
> （2）任意操作都可将奇异局势变为非奇异局势。
>
> ​    若只改变奇异局势（ak，bk）的某一个分量，那么另一个分量不可能在其他奇异局势中，所以必然是非奇异局势。如果使（ak，bk）的两个分量同时减少，则由于其差不变，且不可能是其他奇异局势的差，因此也是非奇异局势
>
> （3）采用适当的方法，可以将非奇异局势变为奇异局势。
>
> ​     假设面对的局势是（a,b），若 b = a，则同时从两堆中取走 a 个物体，就变为了奇异局势（0，0）；如果a = ak ，b > bk，那么，取走b  – bk个物体，即变      为奇异局势；如果 a = ak ，  b < bk ,则同时从两堆中拿走 ak – ab – ak个物体,变为奇异局势（ ab – ak , ab – ak+ b – ak）；如果a > ak ，            b= ak + k,则从第一堆中拿走多余的数量a – ak 即可；如果a < ak ，b= ak + k,分两种情况，第一种，a=aj （j < k）,从第二堆里面拿走 b – bj 即可； 第      二种，a=bj （j < k）,从第二堆里面拿走 b – aj 即可。
>
> 4、结论：两个人如果都采用正确操作，那么面对非奇异局势，先拿者必胜；反之，则后拿者取胜。
>
> 5、练习：poj 1067

三、Fibonacci博弈

> 1、问题模型：
>
>  有一堆个数为n的石子，游戏双方轮流取石子，满足： 
>
> （1）先手不能在第一次把所有的石子取完； 
>
> （2）之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚取的石子数的2倍）。 约定取走最后一个石子的人为赢家。
>
> 2、解决思路：
>
>   当n为Fibonacci数时，先手必败。即存在先手的必败态当且仅当石头个数为Fibonacci数。 
>
> ​    证明：根据“Zeckendorf定理”（齐肯多夫定理）：任何正整数可以表示为若干个不连续的Fibonacci数之和。如n=83 = 55+21+5+2，我们看看这个分解有什么指导意义：假如先手取2颗，那么后手无法取5颗或更多，而5是一个Fibonacci数，那么一定是先手取走这5颗石子中的最后一颗，同理，接下去先手取走接下来的后21颗中的最后一颗，再取走后55颗中的最后一颗，那么先手赢。
>
> ​    反证：如果n是Fibonacci数，如n=89：记先手一开始所取的石子数为y
>
> ​    （1）若y>=34颗（也就是89的向前两项），那么一定后手赢，因为89-34=55=34+21<2*34。
>
> ​    （2）y<34时剩下的石子数x介于55到89之间，它一定不是一个Fibonacci数，把x分解成Fibonacci数：x=55+f[i]+…+f[j]，若，如果f[j]<=2y，那么对B就是面临x局面的先手，所以根据之前的分析，后手只要先取f[j]个即可，以后再按之前的分析就可保证必胜。
>
> 3、练习题目：NYOJ 取石子游戏

四、尼姆博弈

> 1、问题模型：有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者得胜。
>
> 2、解决思路：用（a，b，c）表示某种局势，显证（0，0，0）是第一种奇异局势，无论谁面对奇异局势，都必然失败。第二种奇异局势是（0，n，n），只要与对手拿走一样多的物品，最后都将导致（0，0，0）。
>
>   搞定这个问题需要把必败态的规律找出：(a,b,c)是必败态等价于a^b^c=0(^表示异或运算）。
>
>   证明:(1)任何p(a,b,c)=0的局面出发的任意局面(a,b,c’);一定有p(a,b,c’)不等于0。否则可以得到c=c’。
>
> ​      （2）任何p(a,b,c)不等于0的局面都可以走向 p(a,b,c)=0的局面
>
> ​       (3）对于 (4,9,13) 这个容易验证是奇异局势 
>
> ![img](http://img.blog.csdn.net/20131113104212515)             
>
> ​       其中有两个8，两个4，两个1，非零项成对出现，这就是尼姆和为  零的本质。别人要是拿掉13里的8或者1，那你就拿掉对应的9  中的那个8或者1；别人要是拿        掉13里的4，你就拿掉4里的4；  别人如果拿掉13里的3，就把10作分解，然后想办法满 足非零项成对即可。
>
> 3、推广一：如果我们面对的是一个非奇异局势（a，b，c），要如何变为奇异局势呢？假设 a < b< c,我们只要将 c 变为 a^b,即可,因为有如下的运算结果: a^b^(a^b)=(a^a)^(b^b)=0^0=0。要将c 变为a^b，只从 c中减去 c-（a^b）
>
> 4、推广二：当石子堆数为n堆时，则推广为当对每堆的数目进行亦或之后值为零是必败态。
>
> 5、练习：hdoj 1847

五、公平组合博弈（Impartial Combinatori Games）

> 1、定义：
>
> （1）两人参与。
>
> （2）游戏局面的状态集合是有限。
>
> （3）对于同一个局面，两个游戏者的可操作集合完全相同
>
> （4）游戏者轮流进行游戏。
>
> （5）当无法进行操作时游戏结束，此时不能进行操作的一方算输。
>
> （6）无论游戏如何进行，总可以在有限步数之内结束。
>
> 2、模型：给定一个有向无环图和一个起始顶点上的一枚棋子，两名选手交替的将这枚棋子沿有向边进行移动，无法移动者判负。事实上，这个游戏可以认为是所有公平组合游戏（Impartial Combinatori Games）的抽象模型。其实，任何一个ICG都可以通过把每个局势看成一个顶点，对每个局势和它的子局势连一条有向边来抽象成这个“有向图游戏”。
>
> 3、解决思路：
>
> 现在，假定我们给出两个游戏G1 和 G2。如果我们只知道单个游戏的P-状态和N-状态我们能够正确地玩好游戏和G1 + G2吗？答案是否定的。不难看出两个P-状态的和总是P-状态，P-状态和N-状态的和总是N-状态。但是两个N-状态的和既可能是P-状态也可能是N-状态。因此，只知道单个游戏的P-状态和N-状态是不够的。
>
> 为了正确地玩好游戏和我们需要推广P-状态和N-状态，它就是Sprague-Grudy函数（或者简称为g函数）
>
> 4、Sprague-Grudy定理：
>
> 令N = {0, 1, 2, 3, …} 为自然数的集合。Sprague-Grundy 函数给游戏中的每个状态分配了一个自然数。结点v的Grundy值等于没有在v的后继的Grundy值中出现的最小自然数.
>
> 形式上：给定一个有限子集 S ⊂ N,令mex S(最小排斥值)为没有出现在S中的最小自然数。定义mex(minimal excludant)运算，这是施加于一个集合的运算，表示最小的不属于这个集合的非负整数。例如mex{0,1,2,4}=3、mex{2,3,5}=0、mex{}=0。
>
> 对于一个给定的有向无环图，定义关于图的每个顶点的Sprague-Garundy函数g如下：g(x)=mex{ g(y) | y是x的后继 }。
>
> 5、性质：
>
> （1）所有的终结点所对应的顶点，其SG值为0，因为它的后继集合是空集——所有终结点是必败点（P点）。
>
> （2）对于一个g(x)=0的顶点x，它的所有后继y都满足g(y)!=0——无论如何操作，从必败点（P点）都只能进入必胜点（N点）//对手走完又只能把N留给我们。
>
> （3）对于一个g(x)!=0的顶点，必定存在一个后继点y满足g(y)=0——从任何必胜点（N点）操作，至少有一种方法可以进入必败点（P点）//就是那种我们要走的方法。
>
> 6、应用：
>
> （1）可选步数为1-m的连续整数，直接取模即可，SG(x) = x % (m+1); 
>
> （2）可选步数为任意步，SG(x) = x; 
>
> （3）可选步数为一系列不连续的数，用mex(计算每个节点的值) 


##数值/不确定性算法
####模拟退火
给出一个矩形区域的长宽，给出区域中若干点，问距离所有点的最近距离的最大值是多少。

```c++
#define INF 1e8
#define MAX 1e6
#define MAXN 1005
double X,Y;
int n;
struct Point {
    double x, y;
    double d;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator +(const Point &p) const {
	return Point(x + p.x, y + p.y);
    }
    Point operator -(const Point &p) const {
	return Point(x - p.x, y - p.y);
    }
    Point operator *(double k) const {
	return Point(x * k, y * k);
    }
    bool ok ()
    {
	if (x<0||y<0||x>X||y>Y) return false;
	return true;
    }
} p[MAXN];
const Point d[4] = {Point(-1, 0), Point(0, -1), Point(1, 0), Point(0, 1)};
double dis(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve(const Point *p, int n, Point &ret) {
    int i, j;
    double x, cur, ans = 0;
    const double delta = 0.95;
    bool tag;
    Point nxt;
    for (ret = p[0], x = (X+Y)/10; x > eps; x *= delta) {
	for (tag = true; tag;) {
	    for (tag = (i = 0); i < 4; ++i) {
	        nxt.x = ret.x + dx4[i] * x * X;
	        nxt.y = ret.y + dy4[i] * x * Y;
	        if (!nxt.ok()) continue;
	        for (cur=inf, j = 0; j < n; ++j) cur = min(cur,dis(nxt,p[j]));
	        if (cur > ans) {
	            ans = cur; ret = nxt; tag = true;
	            break;
	        }
	    }
	}
    }
    
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%lf%lf%d",&X,&Y,&n);
	for ( int i = 0 ;  i < n ; i++)
	    scanf("%lf %lf",&p[i].x,&p[i].y);
	Point ans;
	solve(p,n,ans);
 
	printf("The safest point is (%.1f, %.1f).\n",ans.x,ans.y);
 
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
```


##数学结论


####降幂公式

 a^x =  a ^{x mod phi(c)+phi(c)) }mod c )

其中phi(c)为欧拉函数：

```
LL euler( LL x)
{
    LL ret = 1;
    for ( LL i = 2 ; i * i <= x ; i++)
    {
        if (x%i==0)
        {
            x/=i;
            ret*=(i-1);
            while (x%i==0)
            {
                x/=i;
                ret*=i;
            }
        }
    }
    if (x>1) ret*=(x-1);
    return ret;
}
```



####Fibonacci	数列性质

##### GCD( fib[i] , fib[j] )= fib[ GCD(i , j) ] 

##### GCD(f[i],f[i-1])=1

##### f[n+m]=f[n]*f[m-1] + f[n+1]*f[m]

#### miller_rabin 素数测试



```c++
long long mod2(long long a,long long b,long long n)
{
    long long  exp = a%n, res = 0;
    while(b)
    {
        if(b&1)
        {
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n)
            exp -= n;

        b>>=1;
    }
    return res;
}
// ret = (a^b)%n
long long mod(long long a,long long p,long long m)
{
    long long exp=a%m, res=1; //
    while(p>=1)
    {
        if(p&1)//
            res=mod2(res,exp,m);
        exp = mod2(exp,exp,m);
        p>>=1;
    }
    return res;
}
//miller-rabin法测试素数, time 测试次数
bool miller_rabin(long long n)
{
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;

    long long a, u=n-1, x, y;
    int t=0;
    while(u%2==0){
        t++;
        u/=2;
    }
    srand(time(0));
    for(int i=0;i<8;i++)
    {
        a = rand() % (n-1) + 1;
        x = mod(a, u, n);
        for(int j=0;j<t;j++)
        {
            y = mod2(x, x, n);
            if ( y == 1 && x != 1 && x != n-1 )
                return false; //must not
            x = y;
        }
        if( y!=1) return false;
    }
    return true;
}
```



####     O(n)求逆元



```c++
inv[0]=1; inv[1]=1;
for(int i=2;i<maxn;i++){
    inv[i]=(-mod/i)*(long long)inv[mod%i]%mod;
    if(inv[i]<0)inv[i]+=mod;
}
```



#### 欧拉函数

##### 单个值

```c++
int eular(int x){
    int ret=1;
    for(int i=2;i*i<=x;++i)
            if (x % i==0){
                  x/=i;ret*=i-1;
                  while (x % i ==0){
                        x/=i;
                        ret*=i;
                  }
            }
    if (x>1) ret*=x-1;
    return ret;
}
```

##### 表

```c++
const int limit=1000000;
int E[limit+1];
bool mark[limit+1];
int prime[limit+1];
void eulartable(){
     CLR(mark);
     for(int i=2;i<=limit;i++){
         if(mark[i]==0) {
             prime[++prime[0]]=i;
             E[i]=i-1;
         }
         for(int j=1;j<=prime[0]&&prime[j]*i<=limit;j++){
             mark[prime[j]*i]=1;
             if(i%prime[j]==0){
                 E[i*prime[j]]=E[i]*prime[j];  
                 break;
             }
             else
                 E[i*prime[j]]=E[i]*(prime[j]-1);
         }
     }
}
```



#### 快速傅里叶变换(FFT)

```c++
#define L(x) (1 << (x))
const double PI = acos(-1.0);
const int N = 17, Maxn = L(N + 1);
double ax[Maxn], ay[Maxn], bx[Maxn], by[Maxn]
struct FFT
{
    private :
    int revv(int x, int bits) {
        int ret = 0;
        for (int i = 0; i < bits; i++) {
            ret <<= 1;
            ret |= x & 1;
            x >>= 1;
        }
        return ret;
    }
    void fft(double * a, double * b, int n, bool rev) 
    {
        int bits = 0;
        while (1 << bits < n) ++bits;
        for (int i = 0; i < n; i++) 
        {
            int j = revv(i, bits);
            if (i < j) 
            {
                double t = a[i];
                a[i] = a[j];
                a[j] = t;
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
        for (int len = 2; len <= n; len <<= 1) 
        {
            int half = len >> 1;
            double wmx = cos(2 * PI / len);
            double wmy = sin(2 * PI / len);
            if (rev)
                wmy = -wmy;
            for (int i = 0; i < n; i += len) 
            {
                double wx = 1;
                double wy = 0;
                for (int j = 0; j < half; j++) 
                {
                    double cx = a[i + j];
                    double cy = b[i + j];
                    double dx = a[i + j + half];
                    double dy = b[i + j + half];
                    double ex = dx * wx - dy * wy;
                    double ey = dx * wy + dy * wx;
                    a[i + j] = cx + ex;
                    b[i + j] = cy + ey;
                    a[i + j + half] = cx - ex;
                    b[i + j + half] = cy - ey;
                    double wnx = wx * wmx - wy * wmy;
                    double wny = wx * wmy + wy * wmx;
                    wx = wnx;
                    wy = wny;
                }
            }
        }
        if (rev) 
        {
            for (int i = 0; i < n; i++) 
            {
                a[i] /= n;
                b[i] /= n;
            }
        }
    }
    public:
    int solve(int a[],int na,int b[],int nb,long long ans[])
    {
        int len = max(na, nb), ln;
        for(ln=0; L(ln)<len; ++ln);
        len=L(++ln);
        for (int i = 0; i < len ; ++i)
        {    
            if (i >= na) ax[i] = 0, bx[i] =0;
            else ax[i] = a[i], bx[i] = 0;
        }
        fft(ax, ay, len, 0);
        for (int i = 0; i < len; ++i)
        {
            if (i >= nb) bx[i] = 0, by[i] = 0;
            else bx[i] = b[i], by[i] = 0;
        }
        fft(bx, by, len, 0);
        for (int i = 0; i < len; ++i)
        {
            double cx = ax[i] * bx[i] - ay[i] * by[i];
            double cy = ax[i] * by[i] + ay[i] * bx[i];
            ax[i] = cx, ay[i] = cy;
        }
        fft(ax, ay, len, 1);
        for (int i = 0; i < len; ++i)
            ans[i] = ax[i] + 0.01;
        return len;
    }
    int solve(int a[], int na, long long ans[])
    {
        int len = na, ln;
        for(ln = 0; L(ln) < na; ++ln);
        len=L(++ln);
        for(int i = 0;i < len; ++i)
        {
            if (i >= na) ax[i] = 0, ay[i] = 0;
            else ax[i] = a[i], ay[i] = 0;
        }
        fft(ax, ay, len, 0);
        for(int i=0;i<len;++i)
        {
            double cx = ax[i] * ax[i] - ay[i] * ay[i];
            double cy = 2 * ax[i] * ay[i];
            ax[i] = cx, ay[i] = cy;
        }
        fft(ax, ay, len, 1);

        for(int i=0;i<len;++i)
            ans[i] = ax[i] + 0.5;
        return len;
    }
 };
```

#### Catalan数

##### 公式

令h(1)=1,h(0)=1，catalan数满足递归式：

　　h(n)=h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (其中n>=2)

　　另类递归式：

　　h(n)=h(n-1)*(4*n-2)/(n+1);

　　该递推关系的解为：

h(n)=C(2n,n)/(n+1)(n=1,2,3,...)

##### 应用

**括号化问题**

矩阵链乘：P=a1×a2×a3×……×an，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案？(h(n)种)

**出栈次序问题**

一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列?

类似问题

有2n个人排成一行进入剧场。入场费5元。其中只有n个人有一张5元钞票，另外n人只有10元钞票，剧院无其它钞票，问有多少中方法使得只要有10元的人买票，售票处就有5元的钞票找零？(将持5元者到达视作将5元入栈，持10元者到达视作使栈中某5元出栈)

**凸多边形的三角剖分问题**

求将一个凸多边形区域分成三角形区域的方法数。

类似：一位大城市的律师在她住所以北n个街区和以东n个街区处工作。每天她走2n个街区去上班。如果她从不穿越（但可以碰到）从家到办公室的对角线，那么有多少条可能的道路？

类似：在圆上选择2n个点,将这些点成对连接起来使得所得到的n条线段不相交的方法数?

**用给定节点组成二叉树的问题**

给定N个节点，能构成多少种不同的二叉树？（能构成h（N）个）

#### Bell数

B(n)是包含n个元素的集合的划分方法的数目。

递推公式为，
B(0) = 1,
B(n+1) = Sum(0,n) C(n,k)B(k). n = 1,2,...
其中，Sum(0,n)表示对k从0到n求和，C(n,k) = n!/[k!(n-k)!]



#### Stirling数

##### 第一类Stirling数

第一类Stirling数是有正负的，其绝对值是包含n个元素的集合分作k个环排列的方法数目。

　　递推公式为，

　　S(n,0) = 0,S(1,1) = 1.

　　S(n+1,k) =S(n,k-1) + nS(n,k)。

##### 第二类 Stirling数

```c++
第二类Stirling数是把包含n个元素的集合划分为正好k个非空子集的方法的数目。
memset(stirling,0,sizeof(stirling));
    for (int i=1;i<=MaxInt;++i)
    {
        stirling[i][i]=1;
        stirling[i][1]=1;
    }
    for (int i=2;i<=MaxInt;++i)
        for (int j=2;j<i;++j)
            stirling[i][j]=(stirling[i-1][j-1]+j*stirling[i-1][j])%modo;
```



####哥德巴赫猜想

任何一个大于２的偶数可以写成两个素数的和。
####构造勾股数
勾股数公式一：（2n+1,2n²+2n,2n²+2n+1）（n为正整数）
勾股数公式二：（2n,n²-1,n²+1）（n≥2且n为正整数）

####错排公式
d[n] = (n-1)*(d[n-1]+d[n-2]) （d[1]=0,d[2]=1）
d[n]表示n个数错排的方案数。
错排的意思是，每个数都不在原来的位置。。

####快速乘 （解决long long * long long %mod）
log版本

```c++
ll fastMultiplication(ll a,ll b,ll mod){
    ll ans = 0;
    while(b){
	if(b%2==1){
	    b--; 
	    ans = ans + a;
	                ans %= mod;
	}else{
	                b /= 2;
	    a = a + a;
	                a %= mod;
	}
    }
    return ans;
}
```


O(1)版本：

```c++
inline long long multi(long long x,long long y,long long mod)  
{  
long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);  
return tmp<0 ? tmp+mod : tmp;  
}
```


####组合数奇偶性
  如果(n&m)==m，那么C(n,m)为奇数，否则为偶数
  求C(n,0),C(n,1)...C(n,n)中有多少个奇数 (1=< n <=1E8),答案就是：1<<(n的二进制表示中1的个数)

#####统计一段区间中某数出现的次数
建一个val和该val对应下标的pair，然后排序（pair默认按照val第一关键字，pair第二关键字升序排）

排序之后，val相同的都在一起了，我们只需要找一段最大的区间，使得这段区间中的第二关键字在[l,r]范围内，然后这段区间的长度就是[l,r]区间中该数出现的次数.


####BSGS算法
B^L == N (mod P)，求L,保证B，p 互质

```c++
  LL p,b,n;
map<LL,LL>Hash;
map<LL,LL>::iterator it;
inline LL ksm(LL a,LL b,LL MOD)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) res = (res*a)%MOD;
	b = b >> 1;
	a = (a*a)%MOD;
    }
    return res;
}
LL BSGS(LL a,LL b ,LL p) // a^x = b (mod p),求x 
{
    a%=p;
    b%=p;
    if (!a&&!b) return 1;
    if (!a) return -1;
    Hash.clear();
    LL m = ceil(sqrt(double(p)));
    LL tmp = b;
    for (LL j = 0 ; j <= m ; j++)
    {
	Hash[tmp]=j;
	tmp = (tmp*a)%p;
    }
    tmp = ksm(a,m,p);
    LL ret = 1;
 
    for (LL i = 1  ; i <= m+1 ; i++)
    {
	ret = ret*tmp%p;
	if (Hash[ret]) return i*m-Hash[ret]; //注意处理下%....虽然其实不处理也没关系...
    }
    return -1;
 
}
int main()
{
	#ifndef  ONLINE_JUDGE 
       // freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%lld%lld%lld",&p,&b,&n))   // B^L = n(mod p)
	{
	    LL ans = BSGS(b,n,p);
	    if (ans==-1) printf("no solution\n");
	    else printf("%lld\n",(ans%p+p)%p);
	}
```


​		
####扩展BSGS算法       
已知数a,p,b，求满足a^x≡b(mod p)的最小自然数x。需要注意这里没有保证(a,p)=1，因此不能直接使用BSGS算法。

```c++
map<LL,LL>mp;
LL a,b,p;
LL ksm(LL a,LL b,LL p)
{
    LL res = 1LL;
    while (b)
    {
	if (b&1) res = res * a % p;
	b = b>>1LL;
	a = a * a % p;
    }
    return res;
}
LL gcd( LL a,LL b){return b?gcd(b,a%b):a;}
LL BSGS(LL a,LL b,LL p)
{
    a%=p;
    b%=p;
    if (a==0&&b==0) return 0;
    if (a==0) return -1;
    if (b==1) return 0;
    int cnt = 0 ;
    LL t = 1;
    for (int g = gcd(a,p); g!=1 ; g = gcd(a,p))
    {
	if (b%g) return -1;
	p/=g;
	b/=g;
	t=t*a/g%p;
	cnt++;
	if (b==t) return cnt;
    }
    mp.clear();
    int m = ceil(sqrt(double(p)));
    LL base = b ;
    for ( int i = 0 ; i < m ; i++)
    {
	mp[base] =  i;
	base = base * a % p;
    }
    base = ksm(a,m,p);
    LL ret = t ;
    for ( int i = 1 ; i <= m+1 ; i++)
    {
	ret = ret * base % p;
	if (mp.count(ret)) return i*m-mp[ret]+cnt;
    }
    return -1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//        freopen("./in.txt","r",stdin);
  #endif
    while (scanf("%lld%lld%lld",&a,&p,&b))
    {
	if (a==0&&b==0&&p==0) break;
	LL ans = BSGS(a,b,p);
	if (ans==-1) puts("No Solution");
	else printf("%lld\n",ans);
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}    
```
#### 自适应辛普森积分公式
```c++
double f(double x){return sin(x)*x;}//这是被积函数
double simpson(double l,double r){return (r-l)*(f(l)+f(r)+4*f((l+r)/2))/6;}
double di(double l,double r){//越二分以得到更精确的结果
    double m=(l+r)/2;
    double ans=simpson(l,r);
    if(sgn(ans-simpson(l,m)-simpson(m,r))==0)return ans; //在误差之内
    return di(l,m)+di(m,r); //不再误差之内就继续将区间缩小
}
```


####矩阵
#####构造矩阵的一般思路

* 对于求和的式子，如 s[n] = sum{F[1]..F[n]}类似的式子，我们只需要考虑如何构造F[n]即可。
* 尽量将要构造的表达式展开成，第n项，与前面项(第n-1项等)有关的形式。
* 观察2中展开的表达式的系数，每一个系数都亚奥出现在转移矩阵M中。
* 观察2中展开的表达式的项，基本每一项都要整体或者以其他形式出现在初始矩阵M1中
* 我们并不很关心初始项。
* 难点其实在于构造M1矩阵，也就是说哪些项是重要的。一般而言，可能有的项是，s[n],f[n],常数项，以及为了构造出f[n]的辅助项。

#####矩阵快速幂
```c++
struct Mat
{
    LL mat[8][8];
    void clear()
    {
    ms(mat,0);
    }
}M,M1;
 
Mat operator * (Mat a,Mat b)
{
    Mat c;
    c.clear();
    for ( int i = 0 ; i < 3 ; i++)
    for ( int j  = 0 ; j < 3 ; j++)
	for ( int k = 0 ; k < 3 ; k++)
	c.mat[i][j] = (c.mat[i][j] + a.mat[i][k]%mod*b.mat[k][j]%mod)%mod;
    return c;
}
Mat operator ^ (Mat a,int b)
{
    Mat ret;
    ret.clear();
    for ( int i = 0 ; i < 3 ; i++) ret.mat[i][i] = 1;
    
    while (b>0)
    {
    if (b&1) ret = ret * a;
    a = a * a;
    b=b>>1;
    }
    return ret;
}
```


#####给定一个有向图，问从A点恰好走k步（允许重复经过边）到达B点的方案数mod p的值
 把给定的图转为邻接矩阵，即A(i,j)=1当且仅当存在一条边i->j。令C=A*A，那么C(i,j)=ΣA(i,k)*A(k,j)，实际上就等于从点i到点j恰好经过2条边的路径数（枚举k为中转点）。类似地，C*A的第i行第j列就表示从i到j经过3条边的路径数。同理，如果要求经过k步的路径数，我们只需要快速幂求出A^k即可






