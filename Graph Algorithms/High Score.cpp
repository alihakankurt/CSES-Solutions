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

    u16 roomCount, tunnelCount;
    cin >> roomCount >> tunnelCount;

    auto graph = vector<vector<pair<u16, i32>>>(roomCount + 1);
    while (tunnelCount--)
    {
        u16 start, end;
        i32 score;
        cin >> start >> end >> score;
        graph[start].emplace_back(end, score);
    }

    auto maxScores = vector<i64>(roomCount + 1, numeric_limits<i64>::min());
    maxScores[1] = 0;

    auto reachable = vector<bool>(roomCount + 1, false);
    queue<u16> qu;

    u16 relaxations = roomCount;
    while (relaxations--)
    {
        for (u16 start = 1; start <= roomCount; ++start)
        {
            if (maxScores[start] != numeric_limits<i64>::min())
            {
                for (auto [end, score] : graph[start])
                {
                    i64& maxScore = maxScores[end];
                    i64 newScore = maxScores[start] + score;
                    if (maxScore < newScore)
                    {
                        maxScore = newScore;
                        if (relaxations == 0)
                        {
                            reachable[end] = true;
                            qu.emplace(end);
                        }
                    }
                }
            }
        }
    }

    while (!qu.empty())
    {
        auto room = qu.front();
        qu.pop();
        for (auto [next, _] : graph[room])
        {
            if (!reachable[next])
            {
                reachable[next] = true;
                qu.emplace(next);
            }
        }
    }

    i64 answer = reachable.back() ? -1 : maxScores.back();
    cout << answer;

    return 0;
}
