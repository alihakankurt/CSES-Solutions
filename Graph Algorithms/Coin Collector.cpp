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

    auto coins = vector<u32>(n);
    for (u32 room = 0u; room < n; ++room)
    {
        cin >> coins[room];
    }

    auto tunnelGraph = vector<vector<u32>>(n);
    while (m--)
    {
        u32 from, to;
        cin >> from >> to;
        tunnelGraph[--from].push_back(--to);
    }

    u32 timer = 0u;
    auto timeIn = vector<u32>(n, 0u);
    auto timeLow = vector<u32>(n, 0u);
    auto recents = stack<u32>();

    u32 groups = 0u;
    auto groupLabels = vector<u32>(n, 0u);
    auto groupCoins = vector<u64>(1);

    function<void(u32)> collect = [&](u32 room) {
        timeLow[room] = timeIn[room] = ++timer;
        recents.push(room);

        for (u32 neighbor : tunnelGraph[room])
        {
            if (timeIn[neighbor] == 0u)
            {
                collect(neighbor);
            }

            if (groupLabels[neighbor] == 0u)
            {
                timeLow[room] = min(timeLow[room], timeLow[neighbor]);
            }
        }

        if (timeLow[room] < timeIn[room])
        {
            return;
        }

        u32 label = ++groups;
        u64 collected = 0ul;
        for (;;)
        {
            u32 member = recents.top();
            recents.pop();

            groupLabels[member] = label;
            collected += coins[member];

            if (member == room)
            {
                groupCoins.push_back(collected);
                break;
            }
        }
    };

    for (u32 room = 0u; room < n; ++room)
    {
        if (timeIn[room] == 0u)
        {
            collect(room);
        }
    }

    auto condensationGraph = vector<vector<u32>>(groups + 1);
    for (u32 room = 0u; room < n; ++room)
    {
        u32 labelRoom = groupLabels[room];
        for (u32 neighbor : tunnelGraph[room])
        {
            u32 labelNeighbor = groupLabels[neighbor];
            if (labelRoom != labelNeighbor)
            {
                condensationGraph[labelRoom].push_back(labelNeighbor);
            }
        }
    }

    u64 answer = 0ul;
    auto dp = vector<u64>(groups + 1, 0ul);
    for (u32 group = 1u; group <= groups; ++group)
    {
        u64 best = 0ul;
        for (u32 other : condensationGraph[group])
        {
            best = max(best, dp[other]);
        }

        dp[group] = groupCoins[group] + best;
        answer = max(answer, dp[group]);
    }

    cout << answer;

    return 0;
}
