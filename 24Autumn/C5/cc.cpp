#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point {
    double x, y;
};
double crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
bool onSegment(Point A, Point B, Point C) {
    return min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y);
}
bool segmentsIntersect(Point A, Point B, Point C, Point D) {
    double d1 = crossProduct(C, D, A);
    double d2 = crossProduct(C, D, B);
    double d3 = crossProduct(A, B, C);
    double d4 = crossProduct(A, B, D);
    if ((d1 * d2 < 0) && (d3 * d4 < 0)) {
        return true;
    }
    if (d1 == 0 && onSegment(C, D, A)) return true;
    if (d2 == 0 && onSegment(C, D, B)) return true;
    if (d3 == 0 && onSegment(A, B, C)) return true;
    if (d4 == 0 && onSegment(A, B, D)) return true;
    return false;
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        Point A,B,C,D;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
        if (segmentsIntersect(A, B, C, D)) {
            printf("intersect\n");
        } else {
            if((B.y-A.y)*(D.x-C.x)==(B.x-A.x)*(D.y-C.y))
            printf("parallel\n");
            else printf("neither\n");
        }
    }

    return 0;
}
