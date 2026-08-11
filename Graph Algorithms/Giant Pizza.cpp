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

    auto graph = vector<vector<u32>>(m * 2);
    auto transpose = vector<vector<u32>>(m * 2);
    while (n--)
    {
        char s1, s2;
        u32 x1, x2;
        cin >> s1 >> x1 >> s2 >> x2;

        x1 = (x1 - 1) * 2;
        if (s1 == '-')
            x1 ^= 1;

        x2 = (x2 - 1) * 2;
        if (s2 == '-')
            x2 ^= 1;

        graph[x1 ^ 1].push_back(x2);
        graph[x2 ^ 1].push_back(x1);
        transpose[x2].push_back(x1 ^ 1);
        transpose[x1].push_back(x2 ^ 1);
    }

    auto visited = vector<bool>(m * 2);
    function<void(const vector<vector<u32>>&, vector<u32>&, u32)> dfs = [&](auto& graph, auto& output, u32 u) {
        visited[u] = true;
        for (auto v : graph[u])
        {
            if (!visited[v])
            {
                dfs(graph, output, v);
            }
        }

        output.push_back(u);
    };

    auto order = vector<u32>();
    for (u32 u = 0; u < m * 2; ++u)
    {
        if (!visited[u])
        {
            dfs(graph, order, u);
        }
    }

    visited.assign(m * 2, false);
    reverse(order.begin(), order.end());

    auto roots = vector<u32>(m * 2);
    u32 components = 0;

    for (u32 u : order)
    {
        if (!visited[u])
        {
            vector<u32> component;
            dfs(transpose, component, u);
            ++components;

            for (u32 v : component)
            {
                roots[v] = components;
            }
        }
    }

    for (u32 x = 0; x < m * 2; x += 2)
    {
        if (roots[x] == roots[x ^ 1])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (u32 x = 0; x < m * 2; x += 2)
    {
        char status = (roots[x ^ 1] < roots[x]) ? '+' : '-';
        cout << status << ' ';
    }

    return 0;
}
