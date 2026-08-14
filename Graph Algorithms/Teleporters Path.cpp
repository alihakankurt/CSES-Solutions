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

    auto graph = vector<vector<u32>>(n + 1u);
    auto indegree = vector<u32>(n + 1u, 0u);
    auto outdegree = vector<u32>(n + 1u, 0u);
    for (u32 i = 0u; i < m; ++i)
    {
        u32 a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ++indegree[b];
        ++outdegree[a];
    }

    for (u32 u = 2u; u < n; ++u)
    {
        if (indegree[u] != outdegree[u])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    if (indegree[1u] + 1u != outdegree[1u] || indegree[n] != outdegree[n] + 1u)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    auto path = vector<u32>();

    auto st = stack<u32>({1u});
    while (!st.empty())
    {
        u32 u = st.top();

        if (graph[u].empty())
        {
            path.push_back(u);
            st.pop();
            continue;
        }

        st.push(graph[u].back());
        graph[u].pop_back();
    }

    if (path.size() != m + 1u)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto it = path.rbegin(); it != path.rend(); ++it)
    {
        cout << *it << ' ';
    }

    return 0;
}
