#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
    double x, y;
};

double polygonArea(const vector<point>& points,int n) {
   //int n = points.size();
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int next = (i + 1) % n;
        area += points[i].x * points[next].y - points[i].y * points[next].x;
    }
    //printf("%lf\n",area);
    return fabs(area); 
}
int main(){
    int n;
    cin>>n;
    vector<point> ps(n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf",&ps[i].x,&ps[i].y);
    }
    //printf("^^^\n");
    double ans=polygonArea(ps,n);
    printf("%.0lf\n",ans);
}