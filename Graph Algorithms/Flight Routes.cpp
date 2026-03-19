#include <bits/stdc++.h>
using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using uptr = uintptr_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = make_signed_t<size_t>;
using iptr = intptr_t;

using f32 = float_t;
using f64 = double_t;

constexpr i32 Modulus = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u32 n, m, k;
    cin >> n >> m >> k;

    auto graph = vector<vector<pair<u32, u32>>>(n + 1);
    while (m--)
    {
        u32 a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    auto paths = vector<u32>(n + 1, 0);
    auto qu = priority_queue<pair<u64, u32>, vector<pair<u64, u32>>, greater<>>();
    qu.emplace(0, 1);

    while (!qu.empty() && paths.back() < k)
    {
        auto [cost, node] = qu.top();
        qu.pop();

        ++paths[node];

        if (node == n)
        {
            cout << cost << ' ';
        }

        if (paths[node] <= k)
        {
            for (auto [next, price] : graph[node])
            {
                qu.emplace(cost + price, next);
            }
        }
    }

    return 0;
}
