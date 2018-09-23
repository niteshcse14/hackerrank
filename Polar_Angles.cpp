#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef pair<int64_t, int64_t> Point;
int64_t cross_p(Point p1, Point p2) {
    return p1.first * p2.second - p1.second * p2.first;
}
int getQuad(const Point &p) {
    if (p.first >= 0 && p.second >= 0) {
        return 0;
    } else if (p.first <= 0 && p.second >= 0) {
        return 1;
    } else if (p.first <= 0 && p.second <= 0) {
        return 2;
    } else if (p.first >= 0 && p.second <= 0) {
        return 3;
    }
    
    return 100;
}
bool cmp(Point p1, Point p2) {
    int q1 = getQuad(p1);
    int q2 = getQuad(p2);
    if (q1 != q2) {
        return q1 < q2;
    }
    int64_t cross = cross_p(p1, p2);
    if (cross != 0) {
        //cout << cross << "\n";
        return cross > 0;
    }
    return p1.first * p1.first + p1.second * p1.second - p2.first * p2.first - p2.second * p2.second < 0;
}
int main() {
    vector<Point> v;
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;

    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << v[i].first <<" " << v[i].second << endl;
    }
}