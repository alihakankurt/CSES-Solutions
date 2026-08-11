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

    u16 n;
    cin >> n;
    --n;

    if (n == 0)
    {
        cout << 0b0 << 0b1;
        return 0;
    }

    u16 mask = (0b1u << n) - 1u;

    auto graph = vector<vector<u16>>(0b1u << n);
    for (u16 u = 0u; u <= mask; ++u)
    {
        u16 v = (u << 1u) & mask;
        graph[u].push_back(v | 0b0u);
        graph[u].push_back(v | 0b1u);
    }

    ostringstream oss;

    auto path = stack<u32>({0u});
    while (!path.empty())
    {
        u32 u = path.top();

        if (graph[u].empty())
        {
            oss << (u & 0b1u);
            path.pop();
            continue;
        }

        path.push(graph[u].back());
        graph[u].pop_back();
    }

    for (u16 i = 1u; i < n; ++i)
    {
        oss << 0b0;
    }

    cout << oss.str();

    return 0;
}
