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

    u32 n, m;
    cin >> n >> m;

    auto graph = vector<vector<u32>>(n + 1);
    while (m--)
    {
        u32 a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    u32 timer = 0u;
    auto timeIn = vector<u32>(n + 1, 0u);
    auto timeLow = vector<u32>(n + 1, 0u);
    auto recents = stack<u32>();

    u32 kingdoms = 0u;
    auto labels = vector<u32>(n + 1, 0u);

    std::function<void(u32)> dfs = [&](u32 u) {
        timeLow[u] = timeIn[u] = ++timer;
        recents.push(u);

        for (u32 v : graph[u])
        {
            if (timeIn[v] == 0u)
            {
                dfs(v);
            }

            if (labels[v] == 0u)
            {
                timeLow[u] = min(timeLow[u], timeLow[v]);
            }
        }

        if (timeLow[u] < timeIn[u])
        {
            return;
        }

        u32 label = ++kingdoms;
        for (;;)
        {
            u32 v = recents.top();
            recents.pop();

            labels[v] = label;

            if (v == u)
            {
                break;
            }
        }
    };

    for (u32 u = 1u; u <= n; ++u)
    {
        if (timeIn[u] == 0u)
        {
            dfs(u);
        }
    }

    cout << kingdoms << '\n';
    for (u32 u = 1u; u <= n; ++u)
    {
        cout << labels[u] << ' ';
    }

    return 0;
}
