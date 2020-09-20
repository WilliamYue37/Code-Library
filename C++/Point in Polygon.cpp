pair<int, int> points[MAXN];

int area(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
    return (y.first-x.first)*(z.second-x.second)-(y.second-x.second)*(z.first-x.first);
}

bool on(pair<int, int> x, pair<int, int> y, pair<int, int> z) {
    if (area(x,y,z) != 0) return 0;
    return min(x,y) <= z && z <= max(x,y);
}

double get(pair<int, int> x, pair<int, int> y, int z) {
    return double((z-x.second)*y.first+(y.second-z)*x.first)/(y.second-x.second);
}

bool inPolygon(pair<int, int> z) {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        pair<int, int> x = points[i], y = points[(i+1) % N];
        if (on(x, y, z)) return true;
        if (x.second > y.second) swap(x, y);
        if (x.second <= z.second && y.second > z.second) {
            double t = get(x, y, z.second);
            if (t > z.first) ans++;
        }
    }
    if (ans % 2 == 1) return true;
    return false;
}
