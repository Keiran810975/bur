#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

// 欧几里得
double oujilide(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dis(Point a, Point b, Point c) {
    double up = fabs((c.y - b.y) * a.x - (c.x - b.x) * a.y + b.x * c.y - c.x * b.y);
    double down = sqrt((c.y - b.y) * (c.y - b.y) + (c.x - b.x) * (c.x - b.x));
    return up / down;
}

Point findCircumcenter(Point A, Point B, Point C) {
    double a1 = 2 * (B.x - A.x);
    double b1 = 2 * (B.y - A.y);
    double c1 = B.x * B.x + B.y * B.y - A.x * A.x - A.y * A.y;
    double a2 = 2 * (C.x - B.x);
    double b2 = 2 * (C.y - B.y);
    double c2 = C.x * C.x + C.y * C.y - B.x * B.x - B.y * B.y;
    
    Point O;
    O.x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    O.y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
    
    return O;
}

double ans(Point a, Point b, Point c, Point d, Point e) {
    Point o = findCircumcenter(a, b, c);
    double r = oujilide(a, o);
    double chui = dis(o, d, e); 
    return max(0.0, chui - r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Point a, b, c, d, e;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> e.x >> e.y;
        
        double mmax = 0;
        mmax = max(ans(a, b, c, d, e), mmax);
        mmax = max(ans(a, b, d, c, e), mmax);
        mmax = max(ans(a, b, e, c, d), mmax);
        mmax = max(ans(a, c, d, b, e), mmax);
        mmax = max(ans(a, c, e, b, d), mmax);
        mmax = max(ans(a, d, e, b, c), mmax);
        mmax = max(ans(b, c, d, a, e), mmax);
        mmax = max(ans(b, c, e, a, d), mmax);
        mmax = max(ans(b, d, e, a, c), mmax);
        mmax = max(ans(c, d, e, a, b), mmax);

        printf("%.3lf\n", mmax);
    }

    return 0;
}
