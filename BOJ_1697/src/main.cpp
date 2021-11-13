#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist(100'001, 999'999'999);

int solve(int N, int K) {
    if (N == K)
        return 0;

    queue<pair<int, int>> q{};
    q.push({ N, 0 });

    while (!q.empty()) {
        const auto f = q.front();
        q.pop();

        if (f.first == K)
            return f.second;

        auto d = f.second + 1;
        auto v1 = 2 * f.first;
        auto v2 = f.first - 1;
        auto v3 = f.first + 1;

        if (v1 <= 100000 && d < dist[v1]) {
            dist[v1] = d;
            q.push({ v1, d });
        }

        if (0 <= v2 && d < dist[v2]) {
            dist[v2] = d;
            q.push({ v2, d });
        }

        if (v3 <= 100000 && d < dist[v3]) {
            dist[v3] = d;
            q.push({ v3, d });
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    cout << solve(N, K);

    return 0;
}