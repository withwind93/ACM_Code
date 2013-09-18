#include<cstdio>
#include<cmath>
using namespace std;

#define eps 1e-6
struct point3{
    double x, y, z;
    point3() {}
    point3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
}p1, p2, p3, p4;
struct line3{
    point3 a, b;
    line3() {}
    line3(point3 pa, point3 pb):a(pa), b(pb) {}
};

inline point3 xmult(const point3& u, const point3& v){
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}
inline double dmult(const point3& u, const point3& v){
    return u.x * v.x + u.y * v.y + u.z * v.z;
}
inline point3 subt(const point3 u, const point3 v){
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}
inline double vlen(const point3 p){
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
inline double linetoline(const line3& u, const line3& v){
    point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
    return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
double f0(double x){
    if (fabs(x) <= eps)
        return fabs(x);
    return x;
}
double rd(double x){
    if (x > eps)
        return f0(x + 0.00000001);
    else
        return f0(x - 0.00000001);
}
int main()
{
    /*
    double x;
    scanf("%lf", &x);
    x = rd(x);
    printf("%lf\n", x);
    */
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p1.z, &p2.x, &p2.y, &p2.z, &p3.x, &p3.y, &p3.z, &p4.x, &p4.y, &p4.z);
        double dis = linetoline(line3(p1, p2), line3(p3, p4));

        double f1ab = (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z);
        double f1cd = (p3.x-p4.x)*(p3.x-p4.x)+(p3.y-p4.y)*(p3.y-p4.y)+(p3.z-p4.z)*(p3.z-p4.z);
        double f2   = (p2.x-p1.x)*(p4.x-p3.x)+(p2.y-p1.y)*(p4.y-p3.y)+(p2.z-p1.z)*(p4.z-p3.z);
        double f3ab = (p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y)+(p2.z-p1.z)*(p3.z-p1.z);
        double f3cd = (p4.x-p3.x)*(p3.x-p1.x)+(p4.y-p3.y)*(p3.y-p1.y)+(p4.z-p3.z)*(p3.z-p1.z);

        double xm = (p2.x-p1.x)*(f3ab*f1cd-f3cd*f2)/(f1ab*f1cd-f2*f2)+p1.x;
        double ym = (p2.y-p1.y)*(f3ab*f1cd-f3cd*f2)/(f1ab*f1cd-f2*f2)+p1.y;
        double zm = (p2.z-p1.z)*(f3ab*f1cd-f3cd*f2)/(f1ab*f1cd-f2*f2)+p1.z;

        double xn = (p4.x-p3.x)*(f3cd*f1ab-f3ab*f2)/(f2*f2-f1ab*f1cd)+p3.x;
        double yn = (p4.y-p3.y)*(f3cd*f1ab-f3ab*f2)/(f2*f2-f1ab*f1cd)+p3.y;
        double zn = (p4.z-p3.z)*(f3cd*f1ab-f3ab*f2)/(f2*f2-f1ab*f1cd)+p3.z;

        printf("%lf\n", rd(dis));
        printf("%lf %lf %lf %lf %lf %lf\n", rd(xm), rd(ym), rd(zm), rd(xn), rd(yn), rd(zn));
    }
    return 0;
}

