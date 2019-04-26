#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
pdd operator-(const pdd &p, const pdd &q){
    return {p.x-q.x, p.y-q.y};
}
pdd operator+(const pdd &p, const pdd &q){
    return {p.x+q.x, p.y+q.y};
}
pdd operator*(const double f, const pdd &q){
    return {f*q.x, f*q.y};
}
double operator*(const pdd &p, const pdd &q){
    return p.x*q.x+p.y*q.y;
}
struct Mcc{
    // return pair of center and r^2
    static const int MAXN = 1000100;
    int n;
    pdd p[MAXN],cen;
    double r2;
    void init(int _n, pdd _p[]){
        n = _n;
        memcpy(p,_p,sizeof(pdd)*n);
    }
    double sqr(double a){ return a*a; }
    double abs2(pdd a){ return a*a; }
    pdd center(pdd p0, pdd p1, pdd p2) {
        pdd a = p1-p0;
        pdd b = p2-p0;
        double c1=abs2(a)*0.5;
        double c2=abs2(b)*0.5;
        double d = a.x*b.y-b.x*a.y;
        double x = p0.x + (c1 * b.y - c2 * a.y) / d;
        double y = p0.y + (a.x * c2 - b.x * c1) / d;
        return pdd(x,y);
    }
    pair<pdd,double> solve(){
        random_shuffle(p,p+n);
        r2=0;
        for (int i=0; i<n; i++){
            if (abs2(cen-p[i]) <= r2) continue;
            cen = p[i];
            r2 = 0;
            for (int j=0; j<i; j++){
                if (abs2(cen-p[j]) <= r2) continue;
                cen = 0.5 * (p[i]+p[j]);
                r2 = abs2(cen-p[j]);
                for (int k=0; k<j; k++){
                    if (abs2(cen-p[k]) <= r2) continue;
                    cen = center(p[i],p[j],p[k]);
                    r2 = abs2(cen-p[k]);
                }
            }
        }
        return {cen,r2};
    }
}mcc;
int main(){
    pdd p[6];
    while(scanf("%lf %lf %lf %lf %lf %lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)!=EOF){
        mcc.init(3,p);
        pair<pdd,double> pp=mcc.solve();
        printf("%.12f %.12f %.12f\n",pp.x.x,pp.x.y,sqrt(pp.y));
    }
}