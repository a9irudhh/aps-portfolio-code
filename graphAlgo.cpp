#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct Hash {
    size_t operator()(const Point& p) const {
        return p.x * 31 + p.y;
    }
};

int rows = 5, cols = 5;
vector<vector<int>> grid = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1}
};

vector<Point> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool valid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y];
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Point> dijkstra(Point start, Point goal) {
    unordered_map<Point, int, Hash> dist;
    unordered_map<Point, Point, Hash> parent;
    priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<>> q;

    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (u == goal) break;

        for (auto& delta : dir) {
            int nx = u.x + delta.x, ny = u.y + delta.y;
            if (!valid(nx, ny)) continue;
            Point v = {nx, ny};
            int nd = d + 1;

            if (!dist.count(v) || nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                q.push({nd, v});
            }
        }
    }

    vector<Point> path;
    if (!parent.count(goal)) return path;

    for (Point at = goal; !(at == start); at = parent[at])
        path.push_back(at);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

vector<Point> astar(Point start, Point goal) {
    unordered_map<Point, int, Hash> g;
    unordered_map<Point, Point, Hash> parent;
    priority_queue<pair<int, Point>, vector<pair<int, Point>>, greater<>> q;

    g[start] = 0;
    q.push({heuristic(start, goal), start});

    while (!q.empty()) {
        auto [f, u] = q.top();
        q.pop();

        if (u == goal) break;

        for (auto& delta : dir) {
            int nx = u.x + delta.x, ny = u.y + delta.y;
            if (!valid(nx, ny)) continue;
            Point v = {nx, ny};
            int ng = g[u] + 1;

            if (!g.count(v) || ng < g[v]) {
                g[v] = ng;
                parent[v] = u;
                int h = heuristic(v, goal);
                q.push({ng + h, v});
            }
        }
    }

    vector<Point> path;
    if (!parent.count(goal)) return path;

    for (Point at = goal; !(at == start); at = parent[at])
        path.push_back(at);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    Point start = {0, 0}, goal = {4, 4};

    auto path1 = dijkstra(start, goal);
    for (auto& p : path1)
        cout << "(" << p.x << "," << p.y << ") ";
    cout << endl;

    auto path2 = astar(start, goal);
    for (auto& p : path2)
        cout << "(" << p.x << "," << p.y << ") ";
    cout << endl;

    return 0;
}
