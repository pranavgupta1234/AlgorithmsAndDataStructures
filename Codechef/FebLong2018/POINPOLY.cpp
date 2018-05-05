#include <bits/stdc++.h>

using namespace std;

template <class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}

  void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
  template <class F1> explicit operator Point<F1> () const {
    return Point<F1>(static_cast<F1>(x), static_cast<F1>(y)); }
  template <class F1> Point& operator = (const Point<F1>& other) {
    x = other.x; y = other.y; return *this; }
  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
  template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
  template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
  template <class F1> Point& operator /= (const F1& factor) {
    x /= factor; y /= factor; return *this; }
};

template <class F> using Polygon = vector<Point < F > >;

template <class F1,class F2>
int pointVsConvexPolygon(const Point<F1>& point, const Polygon<F2>& poly, int top) {
    if (point < poly[0] || point > poly[top]) return 1;
    auto orientation = ccw(point, poly[top], poly[0]);
    if (orientation == 0) {
        if (point == poly[0] || point == poly[top]) return 0;
            return top == 1 || top + 1 == poly.size() ? 0 : -1;
    }else if (orientation < 0) {
        auto itRight = lower_bound(begin(poly) + 1, begin(poly) + top, point);
        return sgn(ccw(itRight[0], point, itRight[-1]));
    } else {
        auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
        return sgn(ccw(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Polygon<int> poly;
        map<int,int> m;
        int miny = INT_MAX;
        for(int i=0 ; i<n ; i++){
            int s,d;
            cin>>s>>d;
            m[s] = d;
            miny = min(miny,s);
            poly.push_back(Point<int>(s,d));
        }
        int points = floor(n/10);
        for(auto it = m.begin() ; it != m.end() ; it++){
            int x = it -> first;
            while(pointVsConvexPolygon(Point<int>(x,m[x]),poly,))
        }

        for(int )
    }
}