#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}
bool isIntersect(Point a, Point b, Point c, Point d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(a, c, b)) return true;
    if (o2 == 0 && onSegment(a, d, b)) return true;
    if (o3 == 0 && onSegment(c, a, d)) return true;
    if (o4 == 0 && onSegment(c, b, d)) return true;
    return false;
}

bool isParallel(Point a, Point b, Point c, Point d) {
    return orientation(a, b, c) == orientation(a, b, d) && 
           orientation(c, d, a) == orientation(c, d, b);
}

signed main() {
    int t;
    cin>>t;
    while (t--) {
        Point a, b, c, d;
        cin>>a.x>>a.y>>b.x>>b.y>>c.x >>c.y>>d.x>>d.y;
        if (isIntersect(a, b, c, d)) {
            printf("intersect\n");
        } else if (isParallel(a, b, c, d)) {
            printf("parallel\n");
        } else {
            printf("neither\n");
        }
    }

    return 0;
}
