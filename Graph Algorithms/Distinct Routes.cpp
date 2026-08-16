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

struct Edge
{
    u16 Id;
    u16 Target;
    u16 RevIndex;
    u16 Capacity;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr u16 INF = numeric_limits<u16>::max();

    u16 n, m;
    cin >> n >> m;

    auto graph = vector<vector<Edge>>(n + 1u);
    for (u16 id = 1u; id <= m; ++id)
    {
        u16 a, b;
        cin >> a >> b;

        Edge ae{id, b, static_cast<u16>(graph[b].size()), 1u};
        Edge be{0u, a, static_cast<u16>(graph[a].size()), 0u};

        graph[a].push_back(ae);
        graph[b].push_back(be);
    }

    auto depth = vector<u16>(n + 1u);
    auto iter = vector<u16>(n + 1u);

    auto dfs = [&](auto&& self, u16 u, u16 flow) -> u16 {
        if (u == n)
        {
            return flow;
        }

        for (u16& i = iter[u]; i < graph[u].size(); ++i)
        {
            Edge& edge = graph[u][i];
            if (depth[edge.Target] == depth[u] + 1u && edge.Capacity > 0u)
            {
                u16 nflow = self(self, edge.Target, min(flow, edge.Capacity));
                if (nflow > 0u)
                {
                    edge.Capacity -= nflow;
                    graph[edge.Target][edge.RevIndex].Capacity += nflow;
                    return nflow;
                }
            }
        }

        return static_cast<u16>(0u);
    };

    u16 maxFlow = 0u;
    for (;;)
    {
        queue<u16> qu;
        fill(depth.begin(), depth.end(), 0u);

        qu.emplace(1u);
        depth[1u] = 1u;
        while (!qu.empty())
        {
            u16 u = qu.front();
            qu.pop();
            for (Edge& edge : graph[u])
            {
                if (depth[edge.Target] == 0u && edge.Capacity > 0u)
                {
                    depth[edge.Target] = depth[u] + 1u;
                    qu.push(edge.Target);
                }
            }
        }

        if (depth[n] == 0u)
        {
            break;
        }

        fill(iter.begin(), iter.end(), 0u);
        while (auto flow = dfs(dfs, 1u, INF))
        {
            maxFlow += flow;
        }
    }

    cout << maxFlow << '\n';
    vector<u16> path;
    while (maxFlow--)
    {
        path.clear();
        path.push_back(1u);

        u16 u = 1u;
        while (u != n)
        {
            for (Edge& edge : graph[u])
            {
                if (edge.Id > 0u && graph[edge.Target][edge.RevIndex].Capacity > 0u)
                {
                    u = edge.Target;
                    graph[u][edge.RevIndex].Capacity -= 1u;
                    path.push_back(u);
                    break;
                }
            }
        }

        cout << path.size() << '\n';
        for (u16 v : path)
        {
            cout << v << ' ';
        }

        cout << '\n';
    }

    return 0;
}
