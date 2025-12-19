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

    constexpr string_view IMPOSSIBLE = "IMPOSSIBLE";

    u32 computerCount, connectionCount;
    cin >> computerCount >> connectionCount;

    vector<vector<u32>> network(computerCount + 1);
    while (connectionCount > 0)
    {
        u32 computer1, computer2;
        cin >> computer1 >> computer2;

        network[computer1].push_back(computer2);
        network[computer2].push_back(computer1);

        connectionCount -= 1;
    }

    if (network.back().empty())
    {
        cout << IMPOSSIBLE;
        return 0;
    }

    queue<pair<u32, u32>> qu;
    vector<u32> from(computerCount + 1, 0);

    qu.emplace(1, 1);
    from[1] = 1;

    while (!qu.empty())
    {
        auto [computer, cost] = qu.front();
        qu.pop();

        if (computer == computerCount)
        {
            vector<u32> route{computer};
            while (computer != 1)
            {
                computer = from[computer];
                route.push_back(computer);
            }

            cout << cost << '\n';
            for (auto it = route.rbegin(); it != route.rend(); ++it)
            {
                cout << *it << ' ';
            }

            return 0;
        }

        for (u32 destination : network[computer])
        {
            if (from[destination] == 0)
            {
                qu.emplace(destination, cost + 1);
                from[destination] = computer;
            }
        }
    }

    cout << IMPOSSIBLE;

    return 0;
}
