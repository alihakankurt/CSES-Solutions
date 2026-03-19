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
    auto indegree = vector<u32>(n + 1);

    while (m--)
    {
        u32 a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ++indegree[b];
    }

    queue<u32> qu;
    for (u32 node = 1; node <= n; ++node)
    {
        if (indegree[node] == 0)
        {
            qu.push(node);
        }
    }

    auto answer = vector<u32>();
    while (!qu.empty())
    {
        auto node = qu.front();
        qu.pop();

        answer.push_back(node);

        for (u32 next : graph[node])
        {
            if (--indegree[next] == 0)
            {
                qu.push(next);
            }
        }
    }

    if (answer.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (u32 course : answer)
        {
            cout << course << ' ';
        }
    }

    return 0;
}
